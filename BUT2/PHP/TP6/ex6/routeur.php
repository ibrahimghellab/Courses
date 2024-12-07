<?php 


    $tableauControleurs=["controleurVoiture","controleurUtilisateur"];
    $actionParDefaut=array(
        "controleurVoiture"=>"lireVoitures",
        "controleurUtilisateur"=>"lireUtilisateurs"
    );


    require_once(__DIR__."/config/connexion.php");
    Connexion::connect();
    $controleur="controleurVoiture";
    $action="lireVoitures";
    if(isset($_GET["controleur"])&&in_array($_GET["controleur"],$tableauControleurs)){
        $controleur=$_GET["controleur"];
    }
    require_once(__DIR__."/controleur/$controleur.php");
    if(isset($_GET["action"])&&in_array($_GET["action"],get_class_methods($controleur))){
        $action=$_GET["action"];
    }
    if(!(isset($_GET["action"])&&in_array($_GET["action"],get_class_methods($controleur)))){
        $action=$actionParDefaut[$controleur];
    }
    
    $controleur::$action();
