<?php

require_once(__DIR__."/../modele/voiture.php");

class controleurVoiture{
    public static function lireVoitures(){
        $title="Les voitures";

        $voi=Voiture::getAllVoitures();

        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.html");
        require_once(__DIR__."/../vue/voiture/lesVoitures.php");
        require_once(__DIR__."/../vue/fin.html");
    }
}
