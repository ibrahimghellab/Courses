<?php
require_once("controleur.php");
require_once(__DIR__."/../modele/voiture.php");

class controleurVoiture extends Controleur{
    protected static $objet="voiture";
    protected static $class="Voiture";
    protected static $key="immatriculation";
    protected static $link='<a href=routeur.php?controleur=controleurVoiture&action=lireVoiture&immatriculation=';
    protected static $txt='<br>voiture immatriculée ';
    public static function lireVoiture(){
        $title="Les voitures";
            
        $o=Voiture::getObjetById($_GET["immatriculation"]);
        $err="<p>la voiture immatriculée ". $_GET["immatriculation"] ." n'existe pas dans la base</p>";
        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.html");
        if(!$o){

            require_once(__DIR__."/../vue/erreur.php");
        }else{
            require_once(__DIR__."/../vue/unObjet.php");
        }
        
        require_once(__DIR__."/../vue/fin.html");
        }

    }

