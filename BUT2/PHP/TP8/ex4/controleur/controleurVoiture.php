<?php

require_once(__DIR__."/../modele/voiture.php");
require_once(__DIR__ ."/../modele/modele.php");

class controleurVoiture{
    public static function lireVoitures(){
        $title="Les voitures";

        $voi=Voiture::getAll();

        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.html");
        require_once(__DIR__."/../vue/voiture/lesVoitures.php");
        require_once(__DIR__."/../vue/fin.html");
    }

    public static function lireVoiture(){
        $title="Les voitures";
            
        $v=Voiture::getObjetById($_GET["immatriculation"]);

        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.html");
        if(!$v){
            require_once(__DIR__."/../vue/voiture/erreur.php");
        }else{
            require_once(__DIR__."/../vue/voiture/uneVoiture.php");
        }
        
        require_once(__DIR__."/../vue/fin.html");
        }

    }

