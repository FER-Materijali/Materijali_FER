<?php
	ini_set("display_errors", 1);
?>
<!DOCTYPE html>
<html>
<head>
    <title>Pretraživač datoteka DZ1</title>
    <link rel="stylesheet" type="text/css" href="dizajn.css">
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
     <script src="js/jquery-1.7.1.min.js" type="text/javascript"></script>
    <script src="js/modernizr-2.0.6.min.js" type="text/javascript"></script>

</head>
<body class="naslovna"> 

    <div id="header">
         <a href="index.html"></a>
    </div>

    <div id="nav">
        <ul class="photo-grid">
            <li><a href="add.php"><span title="Naslovna"><img src="images/home-variant.png" alt="Naslovnica"></span></a></li>
            <li><a href="search.php"><span title="Pretraživanje"><img src="images/magnify.png" alt="Pretrazivanje"></span></a></li>
            <li><a href="analizaUpita.php"><span title="Analiza upita"><img src="images/information-outline.png" alt="Pretrazivanje"></span></a></li>
        </ul>   
    </div>

    <div id="section">  
    <form name ="search" method ="POST" action = "search.php">
        <input type="text" name="search" id ="search" size="135">
        <input type = "SUBMIT" name = "search_btn" value = "Search!">
        <br>
        <br>
        <div style="border:1px solid black;">
            <input type="radio" name="operator" id="AND" value="AND" checked>AND
            <input type="radio" name="operator" id="OR" value="OR">OR
        </div>
        <br>
        <div style="border:1px solid black;">
            <input type="radio" name="nacin" id="identical" value="identical" checked>Exact string matching
            <input type="radio" name="nacin" id="wordbook" value="wordbook">Use dictionaries
            <input type="radio" name="nacin" id="fuzzy" value="fuzzy">Fuzzy string matching
        </div>
        <br>
        <br>
        SQL string:<br/>
        <textarea name="sqlQuery" id="sqlQuery" style="width:1000px; height:210px; margin-top:2px;"></textarea>
    </form>

    <?php
    if(isset($_POST['search'])) {
    	$search = $_POST['search'];
    	if(isset($_POST['operator'])){
    		$logop = $_POST['operator'];
    		if(isset($_POST['nacin'])){

    			//*******************deklaracija varijabli i spajanje s bazom**************
    			$connection_handler=pg_connect("dbname=james_bond user=postgres password=0036470102");
    			$nacin = $_POST['nacin'];
    	
		        $duljinaStringa = strlen($search);
		       
		        if($duljinaStringa == 0){
		            echo '<script type="text/javascript"> alert("Molim, unesite nekakav kriterij upita :("); </script>'; 
		        }else echo '<script type="text/javascript"> alert("Hvala :)"); </script>';
		        
    			$query = "";
    			$sqlQuery = "";
    			$timestamp = date("Y-m-d H").":00:00";
    			//var_dump($timestamp);

    			//************************************analiza******************************
    			$sqlQuery="SELECT id FROM searchhistory WHERE upit = '".$search."' AND vrijeme = '".$timestamp."'";
    			$podaci=pg_query($connection_handler, $sqlQuery);
    			$ID=pg_fetch_all($podaci);
    			if(!is_array($ID)){
    				$sqlQuery = "INSERT INTO searchhistory(upit, vrijeme, id) VALUES ('".$search."', '".$timestamp."', 1)";
    				pg_query($connection_handler, $sqlQuery);
    			}
    			else{
    				$ID = $ID[0]["id"]+1;
    				$sqlQuery = "UPDATE searchhistory SET id =".$ID."WHERE upit = '".$search."' AND vrijeme = '".$timestamp."'";
    				pg_query($connection_handler, $sqlQuery);
    			}


    			//************************************upiti********************************

    			if($logop == 'OR'){
    				$operator = "|";
    				$syntaxOperator = 'OR';
    			}else{
    				$operator = "&";
    				$syntaxOperator = 'AND';
    			} 

    			$trazeniString=str_getcsv($search, ' ', '"');
    			$tokeni = array();
    			for($i = 0; $i < count($trazeniString); $i++) {
                    $element = explode(" ", $trazeniString[$i]);
                    if(count($element) > 1){
                    	$query .= "(";
                    }
                    $splitano = str_replace(" ", " & ", $trazeniString[$i]);
                    $query .= $splitano;
                    $tokeni[$i] = $splitano;
                    if(count($element) > 1){
                    	$query .= ")";
                    } 
					if($i < count($trazeniString)-1) $query .= " ".$operator." ";
                }
                   			
        		$sqlQuery ="SELECT movie_id, ts_headline(movie_name, to_tsquery('".$query."')), "."movie_name, ts_rank(name_tsvector, to_tsquery('".$query."')) rank "."FROM movies WHERE";
   
                if($nacin == 'fuzzy'){
                	for($i = 0; $i < count($trazeniString); $i++) {
                        $sqlQuery .= " movie_name % '".$trazeniString[$i]."'";
                        if($i < count($trazeniString)-1){
                        	$sqlQuery .= " ".$syntaxOperator." ";
                        } 
                    }
                $sqlQuery .= " ORDER BY rank DESC";
                }else if($nacin == 'identical'){
                	for($i = 0; $i < count($trazeniString); $i++) {
                        $sqlQuery .= " movie_name LIKE '%".$trazeniString[$i]."%'";
                        if($i < count($trazeniString)-1){
                        	$sqlQuery .= " ".$syntaxOperator." ";
                        } 
                    }
                    $sqlQuery .= " ORDER BY rank DESC";
                }else{
                	for($i=0; $i < count($trazeniString); $i++) {
							$sqlQuery .= " name_tsvector @@ to_tsquery('english','".$tokeni[$i]."')"; //$tokeni
							if($i < count($tokeni)-1){
                        		$sqlQuery .= " ".$syntaxOperator." ";
                        	} 
						   
                    }
                    $sqlQuery .= " ORDER BY rank DESC";
                }
                
                $connection_handler=pg_connect("dbname=james_bond user=postgres password=0036470102");
                //pg_query($connection_handler, "CREATE EXTENSION fuzzystrmatch;");
                //pg_query($connection_handler, "CREATE EXTENSION pg_trgm;");
                //pg_query($connection_handler, "CREATE EXTENSION tablefunc;");

                $podaci = pg_query($connection_handler, $sqlQuery);
                //var_dump($sqlQuery);
                echo '<script type="text/javascript"> document.getElementsByTagName("TEXTAREA")[0].value = "'.$sqlQuery.'"; </script>';
               	$rows = pg_fetch_all($podaci);
               	var_dump($rows);
               	$brojRedova = count($rows);
               	echo '<script type="text/javascript"> alert("Broj dohvaćenih podataka: '.$brojRedova.'"); </script>';

               	echo "<table>";
        		if(is_array($rows) && count($rows)!=0){
			        foreach($rows as $row)
			        {
			        	echo "<tr>";
			        	echo "<td>". $row["ts_headline"] . " [" . $row["rank"] . "]"."</td>";
			        	echo "</tr>";
			           
			        }
			    }
		        print("</table>");
		        pg_close($connection_handler); 
    		}
    	}
    }
    ?>
    </div>
    <div id="footer">
        <b>Copyright &copy; petarilijasic@fer.hr, Powered by FER Agency.</b>
    </div>
</body>
</html>