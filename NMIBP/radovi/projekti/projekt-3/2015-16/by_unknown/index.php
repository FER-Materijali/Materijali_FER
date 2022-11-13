<?php
  ini_set('display_errors', 1);
  ini_set('display_startup_errors', 1);
  error_reporting(E_ALL);
  /*mb_internal_encoding("UTF-8");*/
  include('mongoDBconnection.php');					
?>
<!DOCTYPE html>
<html lang="en">

<head>

    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="">
    <meta name="author" content="">

    <title>NMBP - Projekt3</title>

    <!-- Bootstrap Core CSS -->
    <link href="css/bootstrap.min.css" rel="stylesheet">

    <!-- Custom CSS -->
    <link href="css/grayscale.css" rel="stylesheet">

    <!-- Custom Fonts -->
    <link href="font-awesome/css/font-awesome.min.css" rel="stylesheet" type="text/css">
    <link href="http://fonts.googleapis.com/css?family=Lora:400,700,400italic,700italic" rel="stylesheet" type="text/css">
    <link href="http://fonts.googleapis.com/css?family=Montserrat:400,700" rel="stylesheet" type="text/css">

</head>

<body id="page-top" data-spy="scroll" data-target=".navbar-fixed-top">

    <!-- Navigation -->
    <nav class="navbar navbar-custom navbar-fixed-top" role="navigation">
        <div class="container">
            <div class="navbar-header">
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-main-collapse">
                    <i class="fa fa-bars"></i>
                </button>
                <a class="navbar-brand page-scroll" href="#page-top">
                    <i class="fa fa-play-circle"></i>  <span class="light">Napredni modeli i baze podataka</span> Projekt III
                </a>
            </div>

            <!-- Collect the nav links, forms, and other content for toggling -->
            <div class="collapse navbar-collapse navbar-right navbar-main-collapse">
                <ul class="nav navbar-nav">
                    <!-- Hidden li included to remove active class from about link when scrolled up past about section -->
                    <li class="hidden">
                        <a href="#page-top"></a>
                    </li>
                    <li>
                        <a class="page-scroll" href="#download">O aplikaciji</a>
                    </li>
                </ul>
            </div>
            <!-- /.navbar-collapse -->
        </div>
        <!-- /.container -->
    </nav>

    <!-- Intro Header -->
    <header class="intro">
        <div class="intro-body">
            <div class="container">
                <div class="row">
                    <div class="col-md-8 col-md-offset-2">
                    	<!--<img src="/Projekt3/img/FER.png">-->
                        <h1 class="brand-heading">FERnews</h1>
                        <p class="intro-text">Vijesti Fakulteta elektrotehnike i računarstva.<br>Samo za vas.</p>
                        <a href="#about" class="btn btn-circle page-scroll">
                            <i class="fa fa-angle-double-down animated"></i>
                        </a>
                    </div>
                </div>
            </div>
        </div>
    </header>

    <!-- About Section -->
    <section id="about" class="container content-section text-center">
        <div class="row">
            <div class="col-lg-8 col-lg-offset-2">
                <h2>Aktualno:</h2>
                <?php
                $cursor = $collection->find();
                $cursor->sort(array('datumClanka' => -1));
                $cursor->limit(10);
               	foreach ($cursor as $document) {
                ?>
               	<div class="row">
               		<div class="col-md-4">
               			<img src="<?php  echo $document['slika']; ?>" width="100%" height="50%">
               		</div>
               		<div class="col-md-8">
               			<h3><?php echo $document["naslov"]; ?></h3>
               			<p><?php echo $document['datumClanka']; ?></p>
               			<p style:"text-align:inline"><?php echo $document["sadrzaj"]; ?></p>
               			<ul style="list-style-type:none; text-align:left;">
               				<?php
               				 $brojKomentara=0;
               				 foreach ($document["komentari"] as $komentar) {
               				 	$brojKomentara++;
               				 ?>
               				  	<li><?php echo $komentar["datum"]." ".$komentar["komentar"];?></li><br>
               				 <?php
               				  } 
               				?>
               			</ul>
               			<!--<input type="text" id="komentar">
						<button id="submit" onclick="komentiraj()" class="btn btn-primary btn-xl page-scroll">Komentiraj</button>-->
						<form action="komentiranje.php" method="post">
							<input type="text" name="komentar" style="color:black">	
							<input type = "hidden" name="_id" value="<?php echo $document['_id']; ?>">
							<input type = "hidden" name="id" value="<?php echo $brojKomentara; ?>">					
						<input type="submit" value="Komentiraj" style="color:black;">
						</form>
							
						<br>
						<br>
               		</div>
               	</div>
               	<hr>
               	<?php 
                }
                ?>
            </div>
        </div>
        <br>
        <br>
    </section>

    <!-- Download Section -->
    <section id="download" class="content-section text-center">
        <div class="download-section">
            <div class="container">
                <div class="col-lg-8 col-lg-offset-2">
                    <h2>O aplikaciji</h2>
                    <p>Aplikacija je kreirana u sklopu kolegija <i>Napredni modeli i baze podataka</i> na četvrtoj godini studija Fakulteta elektrotehnike i računarstva u Zagrebu</p>
                    <a href="http://fer.unizg.hr" class="btn btn-default btn-lg">Posjetite službenu stranicu</a>
                </div>
            </div>
        </div>
    </section>

    <!-- Footer -->
    <footer>
        <div class="container text-center">
            <p>Copyright &copy; Petar Ilijašić 0036470102</p>
        </div>
    </footer>

    <!-- jQuery -->
    <script src="js/jquery.js"></script>

    <!-- Bootstrap Core JavaScript -->
    <script src="js/bootstrap.min.js"></script>

    <!-- Plugin JavaScript -->
    <script src="js/jquery.easing.min.js"></script>

    <!-- Google Maps API Key - Use your own API key to enable the map feature. More information on the Google Maps API can be found at https://developers.google.com/maps/ -->
    <script type="text/javascript" src="https://maps.googleapis.com/maps/api/js?key=AIzaSyCRngKslUGJTlibkQ3FkfTxj3Xss1UlZDA&sensor=false"></script>

    <!-- Custom Theme JavaScript -->
    <script src="js/grayscale.js"></script>

</body>

</html>
