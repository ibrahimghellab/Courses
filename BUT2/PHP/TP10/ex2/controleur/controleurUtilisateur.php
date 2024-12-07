<?php
require_once("controleur.php");
require_once(__DIR__ ."/../modele/Utilisateur.php");
class controleurUtilisateur extends Controleur{
    protected static $objet="utilisateur";
    protected static $class="Utilisateur";
    protected static $key="login";
    protected static $link='<a href=routeur.php?controleur=controleurUtilisateur&action=lireObjet&login=';
    protected static $txt='<br>utilisateur avec comme login ';
    protected static $errorpart1="<p>L'utilisateur avec pour login ";
    protected static $errorpart2=" n'existe pas dans la base</p>";
}

