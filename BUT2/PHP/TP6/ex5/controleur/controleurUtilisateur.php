<?php

require_once(__DIR__ ."/../modele/Utilisateur.php");
$title="Les utilisateurs";
$usr=Utilisateur::getAllUsers();

require_once(__DIR__."/../vue/debut.php");
require_once(__DIR__."/../vue/menu.html");
require_once(__DIR__."/../vue/utilisateur/lesUtilisateurs.php");
require_once(__DIR__."/../vue/fin.html");
