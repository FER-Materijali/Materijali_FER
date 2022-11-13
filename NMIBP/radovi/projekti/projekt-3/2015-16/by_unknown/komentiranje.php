<?php
	if(isset($_POST['komentar'])){
		$komentar = array();
		$newIndex=$_POST['id']+1;
		$komentar['datum'] = date("Y-m-d H:i:s");
		$komentar['id'] = $newIndex;
		$komentar['komentar'] = $_POST['komentar'];								   
		$id = $_POST['_id'];
		$connection = new MongoClient( "mongodb://192.168.56.12");
		$db = $connection->nmbp;
		$collection = $db->vijesti;									
		$collection->update(array("_id"=>$id),array('$push'=>array('komentari'=>$komentar)));
		header('Location: http://192.168.56.12/Projekt3/');
	}
?>