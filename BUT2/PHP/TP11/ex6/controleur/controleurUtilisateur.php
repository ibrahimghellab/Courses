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
   
    public static function afficherFormulaireCreation(){
        $title="Création d utilisateur";
        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.html");
        require_once(__DIR__."/../vue/utilisateur/formulaireCreation.html");
        require_once(__DIR__."/../vue/fin.html");
      
    }

    public static function creerUtilisateur(){
        $isWorking=Utilisateur::addUtilisateur($_GET["login"],$_GET["mdp"],$_GET["nom"],$_GET["prenom"],$_GET["email"]);
        if($isWorking){
            self::lireObjets();
        }else{
            static::afficherFormulaireCreation();
        }
        
    }



    public static function afficherFormulaireModification(){
        $l=$_GET["login"];
        $utilisateur=Utilisateur::getObjetById($l);
        $l=$utilisateur->get("login");
        $m=$utilisateur->get("mdp");
        $n=$utilisateur->get("nom"); 
        $p=$utilisateur->get("prenom"); 
        $e=$utilisateur->get("email");
        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.html");
        require_once(__DIR__.'/../vue/utilisateur/formulaireModification.php');
        require_once(__DIR__."/../vue/fin.html");
        
    }



    public static function modifierUtilisateur(){
        Utilisateur::updateUtilisateur($_GET["login"],$_GET["mdp"],$_GET["nom"],$_GET["prenom"],$_GET["email"]);
        self::lireObjets();
    }



}

