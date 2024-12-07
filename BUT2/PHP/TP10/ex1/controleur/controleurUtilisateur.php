<?php
require_once("controleur.php");
require_once(__DIR__ ."/../modele/Utilisateur.php");
class controleurUtilisateur extends Controleur{
    protected static $objet="utilisateur";
    protected static $class="Utilisateur";
    protected static $key="login";
    protected static $link='<a href=routeur.php?controleur=controleurUtilisateur&action=lireUtilisateur&login=';
    protected static $txt='<br>utilisateur avec comme login ';
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

