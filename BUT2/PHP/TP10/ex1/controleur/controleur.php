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

}
?>