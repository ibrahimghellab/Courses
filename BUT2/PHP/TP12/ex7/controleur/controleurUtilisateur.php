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
    protected static $link='<a href=index.php?controleur=controleurUtilisateur&action=';
    protected static $txt='<br>utilisateur avec comme login ';
    protected static $errorpart1="<p>L'utilisateur avec pour login ";
    protected static $errorpart2=" n'existe pas dans la base</p>";


    public static function afficherFormulaireConnexion(){
        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/formulaireConnexion.html");
        require_once(__DIR__."/../vue/fin.html");
    }

    public static function connecterUtilisateur(){
        if(Utilisateur::checkMDP($_GET["login"],$_GET["mdp"])){
            $_SESSION["login"]=$_GET["login"];
            $o=Utilisateur::getObjetById($_GET["login"]);
            $_SESSION["isAdmin"]=$o->get("isAdmin");

            require_once(__DIR__."/../vue/debut.php");
            require_once(__DIR__."/../vue/menu.php");
            require_once(__DIR__."/../vue/unObjet.php");
            require_once(__DIR__."/../vue/fin.html");
        }else{
            static::afficherFormulaireConnexion();
        }
    }

    public static function deconnecterUtilisateur(){
        session_unset();
        session_destroy();
        setcookie(session_name(),'',time()-1);
        self::afficherFormulaireConnexion();
    }

}

