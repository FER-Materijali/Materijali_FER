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
    <script src="js/SQL.js" type="text/javascript"></script>
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

</div>
<!-- end container -->

    <!-- forma -->
<div id="main">
    <form name ="forma_pretraga" method ="POST" action = "pretraga.php">
        <input type="text" name="pretraga" id ="pretraga" size="40">
        <input type = "SUBMIT" name = "dugme_trazi" value = "Trazi!"><br/>
        <input type="radio" name="odabir1" id="i" value="a" onclick="SQL()">i
        <input type="radio" name="odabir1" id="ili" value="a" onclick="SQL()">ili<br/>
        <input type="radio" name="odabir2" id="identicni" value="a" onclick="SQL()">Identicni stringovi
        <input type="radio" name="odabir2" id="rjecnik" value="a" onclick="SQL()">Koristi rjecnike
        <input type="radio" name="odabir2" id="fuzzy" value="a" onclick="SQL()">Fuzzy sparivanje<br/><br/><br/>
        Generirani SQL:<br/>
        <textarea name="sql" id="sql" style="width:450px;height:150px;"></textarea>
    </form>
    <!-- kraj forme-->

    <?php
    if(isset($_POST['pretraga'])) {
        $pretraga = $_POST['pretraga'];
        if (strlen($pretraga) == 0) {
            die("Greska: Pretraga nije unesena!");
        }
        $sql = $_POST['sql'];
        if (strlen($sql) == 0) {
            die("Greska: SQL je prazan!");
        }
        $database_name = "nmbplab1";	// STAVI SVOJU BAZU
        $database_user = "postgres";	// STAVI SVOG KORISNIKA
        $database_password = "admin";	// STAVI PASS OD BAZE
        $conn = pg_connect("dbname=" . $database_name . " user= " . $database_user . " password=" . $database_password);
        $result = pg_query($conn, $sql);
        $svi_retci = pg_fetch_all($result);

        print("Broj hitova: " . pg_num_rows($result) . "\n\n\n\n");

        if(pg_num_rows($result) == 0) {
            // ako nema rezultata ne iscrtavamo tablicu
            return;
        }

        echo "<table border=\'1\' cellpadding=\'20\'>";
        echo("<tr> <td>ts_headline</td>  <td>naziv serije</td> <td>rang </td> </tr>");
        foreach($svi_retci as $redak)
        {
            echo'<tr>';
            echo'<td>'. $redak['ts_headline']."</td>";
            echo'<td>'. $redak['serija_naziv'].'</td>';
            echo'<td>'. $redak['rank'].'</td>';
            echo'</tr>';
        }
        print("</table>");
        pg_close($conn);
    }
    ?>
</div>
</body>
</html>