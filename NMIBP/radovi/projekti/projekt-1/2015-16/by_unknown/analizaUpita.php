<?php
    ini_set("display_errors", 1);
?>
<!DOCTYPE html>
<html>
<head>
    <title>Pretraživač datoteka DZ1</title>
    <link rel="stylesheet" type="text/css" href="dizajn.css">
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
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
        <form action="analizaUpita.php" method="post" accept-charset="utf-8">
                <p>Od kada:</p> <input type="date" name="datOd">
                <p>Do kada:</p> <input type="date" name="datDo">    
            <br>
            <br>
            <div style="border:1px solid black">
                <p>Granulacija</p>
                <input type="radio" name="granulacija" value="dan" checked>Dan
                <input type="radio" name="granulacija" value="sat">Sat
            </div>
            <button type="submit" class="btn btn-info">Search</button>                    
        </form>
        
        <?php
            if(empty($_POST["datOd"])||empty($_POST["datDo"])){
                echo '<script type="text/javascript"> alert("Unesite datum!"); </script>'; 
            }else{
                //uspostava komunikacije s bazom podataka
                 $connection_handler=pg_connect("dbname=james_bond user=postgres password=0036470102");
                //deklariranje varijabli za manipulaciju unešenih podataka
                 $datumOd = $_POST["datOd"];
                 $datumDo = $_POST["datDo"];

                 $granulacija = $_POST["granulacija"];

                 $datumOd.=" 00:00:01";
                 $datumDo.=" 23:00:00";

                 $elemPivot = "";
                 $ispis = array();

                 switch ($granulacija) {
                     case 'sat':
                         $sqlQuery = "SELECT DISTINCT vrijeme FROM searchhistory WHERE vrijeme BETWEEN '".$datumOd."' AND '".$datumDo."'ORDER BY vrijeme";
                         $podaci = pg_query($connection_handler, $sqlQuery);
                         $sati = pg_fetch_all($podaci);
                         if(is_array($sati)){
                            for($i=0; $i<count($sati); $i++) {
                                $iduciSat = date("H", strtotime($sati[$i]["vrijeme"]))+1;
                                $iduciSati = true;
                                if($iduciSat<10){
                                    $iduciSat="0".$iduciSat;
                                }
                                $kategorija[$i] = "\"Sat: ".date("H", strtotime($sati[$i]["vrijeme"]))."-".$iduciSat."\"";
                                $brojSat=count($sati);
                                $elemPivot .=  " " . $kategorija[$i] . " integer";
                                if($i < count($sati)-1){
                                    $elemPivot .= ",";
                                } 
                            }
                            
                            $sqlQuery = "SELECT * FROM crosstab ('SELECT upit,
                                                                    vrijeme,
                                                                    CAST(SUM(id) AS integer) AS id
                                                                FROM searchhistory
                                                                GROUP BY upit, vrijeme
                                                                ORDER BY upit, vrijeme'
                                                        ,   'SELECT DISTINCT vrijeme
                                                                FROM searchhistory
                                                                ORDER BY vrijeme')
                                        AS pivotTable (upit text,".$elemPivot.")
                                    ORDER BY upit";
                            $podaci = pg_query($connection_handler, $sqlQuery);
                            $ispis = pg_fetch_all($podaci);
                            
                         }
                         break;

                     default:
                    
                         $sqlQuery = "SELECT DISTINCT date(vrijeme) as date FROM searchhistory WHERE vrijeme BETWEEN '".$datumOd."' AND '".$datumDo."'ORDER BY date";
                         $podaci = pg_query($connection_handler, $sqlQuery);
                         $dan = pg_fetch_all($podaci);
                         if(is_array($dan)){
                            for($i =0; $i<count($dan); $i++){
                              $dani=true;  
                              $kategorija[$i] = "Dan".date("dmY", strtotime($dan[$i]["date"]));
                                
                                $elemPivotMaker = "Broj dana";
                                $elemPivot .= " " . $kategorija[$i] . " integer";
                                if($i < count($dan)-1){
                                    $elemPivot .= ",";  
                                }   
                            }

                            $sqlQuery = "SELECT * FROM crosstab ('SELECT upit,
                                 date(vrijeme) AS date, CAST(SUM(id) AS integer) AS id FROM searchhistory
                                 GROUP BY upit, date
                                 ORDER BY upit, date' , 'SELECT DISTINCT date(vrijeme) AS date FROM searchhistory
                                 ORDER BY date') AS pivotTable (upit text,".$elemPivot.") ORDER BY upit"; 
                            $podaci = pg_query($connection_handler, $sqlQuery);
                            $ispis = pg_fetch_all($podaci);
                         }
                         break;
                 }


                 pg_close($connection_handler);
                 if(is_array($ispis)){
                      ?>
                        <table>
                            <thead>
                                <tr>
                                    <th>Upit</th>
                                        <?php
                                            foreach($kategorija as $kat){
                                                echo "<th>".$kat."</th>";
                                            } 
                                        ?>
                                </tr>
                            </thead>
                            <tbody>
                            <?php
                            foreach($ispis as $rezultat) {
                                echo "<tr>";
                                foreach($rezultat as $stupac){
                                    echo "<td>".$stupac."</td>";
                                } 
                                echo "</tr>";
                            }
                            ?>
                            </tbody>
                        </table>
                    <?php
                 }

            }
            /*
            if(empty($datumDo))||empty($datumDo)){
                echo '<script type="text/javascript"> alert("Niste unijeli datum!"); </script>'; 
            }
           */
        ?>


    </div>
    <div id="footer">
        <b>Copyright &copy; petarilijasic@fer.hr, Powered by FER Agency.</b>
    </div>
</body>
</html>