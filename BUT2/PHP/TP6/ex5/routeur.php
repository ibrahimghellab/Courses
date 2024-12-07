<?php 
    require_once(__DIR__."/config/connexion.php");
    Connexion::connect();
    $controleur="controleurVoiture";
    if(isset($_GET["controleur"])){
        $controleur=$_GET["controleur"];
    }
    require_once(__DIR__."/controleur/$controleur.php");
