<?php 

echo "<h1>affichage de la voiture</h1>";

echo "<pre>";
print_r($_GET);
echo "<pre>";

echo 'voiture '. $_GET["immatriculation"]. ' de marque '.$_GET["marque"].' et de couleur '.$_GET["couleur"];

?>