<?php
require_once("controleur.php");
require_once(__DIR__ ."/../modele/Utilisateur.php");
class controleurUtilisateur extends Controleur{
    protected static $objet="utilisateur";
    protected static $class="Utilisateur";
    protected static $key="login";
    protected static $delete="supprimerObjet&login=";
    protected static $read="lireObjet&login=";
    protected static $edit="afficherFormulaireModification&login=";
    protected static $link='<a href=routeur.php?controleur=controleurUtilisateur&action=';
    protected static $txt='<br>utilisateur avec comme login ';
    protected static $errorpart1="<p>L'utilisateur avec pour login ";
    protected static $errorpart2=" n'existe pas dans la base</p>";


    public static function afficherFormulaireConnexion(){
        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/formulaireConnexion.html");
        require_once(__DIR__."/../vue/fin.html");
    }

}

