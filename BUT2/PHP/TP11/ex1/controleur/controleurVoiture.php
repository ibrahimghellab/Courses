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
    }
