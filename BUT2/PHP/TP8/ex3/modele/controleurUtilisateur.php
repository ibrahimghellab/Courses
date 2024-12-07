<?php

require_once(__DIR__ ."/../modele/Utilisateur.php");
require_once(__DIR__ ."/../modele/modele.php");
class controleurUtilisateur{
    public static function lireUtilisateurs(){
    $title="Les utilisateurs";
    $usr=Modele::getAll();
    
    require_once(__DIR__."/../vue/debut.php");
    require_once(__DIR__."/../vue/menu.html");
    require_once(__DIR__."/../vue/utilisateur/lesUtilisateurs.php");
    require_once(__DIR__."/../vue/fin.html");
    }

    public static function lireUtilisateur(){
        $title="Les utilisateurs";
            
        $u=Utilisateur::getUserByLogin($_GET["login"]);

        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.html");
        if(!$u){
            require_once(__DIR__."/../vue/utilisateur/erreur.php");
        }else{
            require_once(__DIR__."/../vue/utilisateur/unUtilisateur.php");
        }
        
        require_once(__DIR__."/../vue/fin.html");
    }
}

