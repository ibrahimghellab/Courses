<?php 

require_once("./modele/modele.php");
require_once("./modele/Utilisateur.php");
require_once("./modele/voiture.php");

class Controleur{
    public static function lireObjets(){
        $title='Les '.static::$objet.'s';
        $obj=(static::$class)::getAll();
        $ligne=array();
        
        foreach($obj as $cle=>$valeur){
            array_push($ligne,static::$txt . $valeur->get(static::$key) . static::$link . $valeur->get(static::$key).'>détails</a>');
        }
    
        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.html");
        require_once(__DIR__."/../vue/lesObjets.php");
        require_once(__DIR__."/../vue/fin.html");
    }
    public static function lireObjet(){
        $title='Un '.static::$objet;
            
        $o=(static::$class)::getObjetById($_GET[static::$key]);

        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.html");
        if(!$o){
            
            $err=static::$errorpart1. $_GET[static::$key] .static::$errorpart2;
            
            require_once(__DIR__."/../vue/erreur.php");
        }else{
            require_once(__DIR__."/../vue/unObjet.php");
        }
        
        require_once(__DIR__."/../vue/fin.html");
    }
}
?>