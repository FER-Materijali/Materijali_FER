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
		<p>Molimo korisnika da doda film u bazu podataka:</p>	
		<form name="dodavanje_forma" method="post" action="add.php">
	        <textarea name="movie_name" style="width:720px; height:210px; margin-top:10px;";></textarea>
	        <input type="submit" name="nekavrijednost" value="Dodaj agenta!">
	    </form>
	    <?php
	    	ini_set('display_errors', 1);
	        if(isset($_POST['movie_name'])) {
	            $movie_name = $_POST['movie_name'];
	            $connection_handler=pg_connect("dbname=james_bond user=postgres password=0036470102");
	            $result=pg_query($connection_handler, "INSERT INTO movies(movie_name, name_tsvector) VALUES  ('" . $movie_name . "', to_tsvector('english', '" . $movie_name . "'))");
	            pg_close($connection_handler);
	            if(isset($_POST['movie_name'])) {
	            	echo '<script type="text/javascript"> alert("Dodan je novi film "'.$movie_name.'"! Zahvaljujem :)");</script>';
	            }
	        }
	    ?>
	    	
	</div>
	<div id="footer">
		<b>Copyright &copy; petarilijasic@fer.hr, Powered by FER Agency.</b>
	</div>
</body>
</html>