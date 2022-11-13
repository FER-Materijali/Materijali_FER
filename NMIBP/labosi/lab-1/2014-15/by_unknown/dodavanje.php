<!DOCTYPE html>

<html>
<head>

    <!-- begin CSS -->
    <link href="css/style.css" type="text/css" rel="stylesheet">
    <link href="css/html5-reset.css" type="text/css" rel="stylesheet">
    <!-- end CSS -->

    <!-- begin JS -->
    <script src="js/jquery-1.7.1.min.js" type="text/javascript"></script>
    <script src="js/modernizr-2.0.6.min.js" type="text/javascript"></script>
    <!-- end JS -->
</head>

<body style="background: url(images/bgnoise_lg.png) repeat left top;">
<!-- begin container -->
<div id="container" style="width: 600px; margin: 28px auto 0;">

    <!-- begin navigation -->
    <nav id="navigation">
        <ul>
            <li><a href="dodavanje.php">Dodavanje</a></li>
            <li><a href="pretraga.php">Pretraga</a></li>
        </ul>
    </nav>
    <!-- end navigation -->


<div id="main">
    <form name ="dodavanje_forma" method ="POST" action = "dodavanje.php">
        <textarea name="serija_naziv" style="width:300px; height:100px;"></textarea>
        <input type = "SUBMIT" name = "blabla" value = "Dodaj novu seriju!">
    </form>

    <?PHP
        if(isset($_POST['serija_naziv'])) {
            $serija_naziv = $_POST['serija_naziv'];
            $database_name = "nmbplab1";
            $database_user = "postgres";
            $database_password = "admin";
            $conn = pg_connect("dbname=" . $database_name . " user= " . $database_user . " password=" . $database_password);
            $result=pg_query($conn, "INSERT INTO serije(serija_naziv, naziv_tsvector) VALUES  ('" . $serija_naziv . "', to_tsvector('english', '" . $serija_naziv . "'))");
            pg_close($conn);
            echo('Nova epizoda dodana!');
        }
    ?>


</div>

</body>
</html> 