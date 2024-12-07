<?php
require_once("controleur.php");
require_once(__DIR__."/../modele/voiture.php");

class controleurVoiture extends Controleur{
    protected static $objet="voiture";
    protected static $class="Voiture";
    protected static $key="immatriculation";
    protected static $delete="supprimerObjet&immatriculation=";
    protected static $read="lireObjet&immatriculation=";
    protected static $link='<a href=routeur.php?controleur=controleurVoiture&action=';
    protected static $txt='<br>voiture immatriculée ';
    protected static $errorpart1="<p>la voiture immatriculée ";
    protected static $errorpart2=" n'existe pas dans la base</p>";



    public static function afficherFormulaireCreation(){
        $title='Création de voiture';
        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.html");
        require_once(__DIR__."/../vue/voiture/formulaireCreation.html");
        require_once(__DIR__."/../vue/fin.html");
      
    }

    public static function creerVoiture(){
        $isWorking=Voiture::addVoiture($_GET["immatriculation"],$_GET["marque"],$_GET["couleur"]);
        if($isWorking){
            self::lireObjets();
        }else{
            static::afficherFormulaireCreation();
        }
        
    }


    public static function afficherFormulaireModification(){
        $i=$_GET["immatriculation"];
        $voiture=self::getObjetById($i);
        require_once(__DIR__."/../vue/voiture/formulaireModification.html");
        
    }
}
