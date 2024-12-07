<?php

require_once(__DIR__ ."/../modele/Utilisateur.php");
require_once(__DIR__ ."/../modele/modele.php");
class controleurUtilisateur{
    public static function lireUtilisateurs(){
    $title="Les utilisateurs";
    $usr=Utilisateur::getAll();
    $ligne=array();
    foreach($usr as $cle=>$valeur){
        array_push($ligne,'<br>utilisateur avec comme login '. $valeur->get("login").'<a href=routeur.php?controleur=controleurUtilisateur&action=lireUtilisateur&login='.$valeur->get("login").'>détails</a>');
    }
    require_once(__DIR__."/../vue/debut.php");
    require_once(__DIR__."/../vue/menu.html");
    require_once(__DIR__."/../vue/lesObjets.php");
    require_once(__DIR__."/../vue/fin.html");
    }

    public static function lireUtilisateur(){
        $title="Les utilisateurs";
            
        $o=Utilisateur::getObjetById($_GET["login"]);

        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.html");
        if(!$o){
            $err="<p>L'utilisateur avec pour login ". $_GET["login"] ." n'existe pas dans la base</p>";
            
            require_once(__DIR__."/../vue/erreur.php");
        }else{
            require_once(__DIR__."/../vue/unObjet.php");
        }
        
        require_once(__DIR__."/../vue/fin.html");
    }
}

