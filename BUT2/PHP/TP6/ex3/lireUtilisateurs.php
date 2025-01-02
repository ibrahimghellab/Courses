<?php

    $title="Les utilisateurs";

    require_once(__DIR__."/vue/debut.php");
    require_once(__DIR__ ."/modele/Utilisateur.php");
    require_once(__DIR__ ."/config/connexion.php");
    require_once(__DIR__."/vue/menu.html");
    Connexion::connect();
    

    $usr=Utilisateur::getAllUsers();

    require_once(__DIR__."/vue/utilisateur/lesUtilisateurs.php");

    require_once(__DIR__."/vue/fin.html");
?>

