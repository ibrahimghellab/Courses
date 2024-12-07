<?php

require_once(__DIR__."/../modele/voiture.php");
require_once(__DIR__ ."/../modele/modele.php");

class controleurVoiture{

    public static function lireVoitures(){
        $title="Les voitures";

        $voi=Voiture::getAll();
        $ligne=array();
        foreach($voi as $cle=>$valeur){
            array_push($ligne,'<br>voiture immatriculée '. $valeur->get("immatriculation").'<a href=routeur.php?controleur=controleurVoiture&action=lireVoiture&immatriculation='.$valeur->get("immatriculation").'>détails</a>');
        }

        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.html");
        require_once(__DIR__."/../vue/lesObjets.php");
        require_once(__DIR__."/../vue/fin.html");
    }

    public static function lireVoiture(){
        $title="Les voitures";
            
        $o=Voiture::getObjetById($_GET["immatriculation"]);

        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.html");
        if(!$o){
            require_once(__DIR__."/../vue/voiture/erreur.php");
        }else{
            require_once(__DIR__."/../vue/unObjet.php");
        }
        
        require_once(__DIR__."/../vue/fin.html");
        }

    }

