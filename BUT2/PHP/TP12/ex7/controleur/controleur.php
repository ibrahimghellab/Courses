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
            if($valeur->affichable()){
                array_push($ligne,static::$txt . $valeur->get(static::$key) . static::$link . static::$read. $valeur->get(static::$key).'>détails</a>'.static::$link . static::$delete. $valeur->get(static::$key).'>Delete</a>'.static::$link . static::$edit. $valeur->get(static::$key).'> Modifier </a>');
            }
        }
    
        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.php");
        require_once(__DIR__."/../vue/lesObjets.php");
        require_once(__DIR__."/../vue/fin.html");
    }
    public static function lireObjet(){
        $title='Un '.static::$objet;
            
        $o=(static::$class)::getObjetById($_GET[static::$key]);

        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.php");
        if(!$o){
            
            $err=static::$errorpart1. $_GET[static::$key] .static::$errorpart2;
            
            require_once(__DIR__."/../vue/erreur.php");
        }else{
            require_once(__DIR__."/../vue/unObjet.php");
        }
        
        require_once(__DIR__."/../vue/fin.html");
    }

    public static function supprimerObjet(){
        (static::$class)::deleteObjetById($_GET[static::$key]);
        static::lireObjets();
    }


    public static function afficherFormulaireCreation(){
        $title='Création de '.static::$objet;
        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.php");
        require_once(__DIR__."/../vue/".static::$objet."/formulaireCreation.html");
        require_once(__DIR__."/../vue/fin.html");
    }


    public static function creerObjet(){
        $isWorking=(static::$class)::addObjet();
        if($isWorking){
            self::lireObjets();
        }else{
            self::afficherFormulaireCreation();
        }
        
    }



    public static function afficherFormulaireModification(){
        $k=$_GET[static::$key];
        $objet=(static::$class)::getObjetById($k);
        if(static::$class=="Voiture"){
            $i=$objet->get("immatriculation");
            $m=$objet->get("marque");
            $c=$objet->get("couleur"); 
        }else{
            $l=$objet->get("login");
            $m=$objet->get("mdp");
            $n=$objet->get("nom"); 
            $p=$objet->get("prenom"); 
            $e=$objet->get("email");
        }
        
        require_once(__DIR__."/../vue/debut.php");
        require_once(__DIR__."/../vue/menu.php");
        require_once(__DIR__."/../vue/".static::$objet."/formulaireModification.php");
        require_once(__DIR__."/../vue/fin.html");
        
    }



public static function modifierObjet(){
    
    (static::$class)::updateObjet();
    self::lireObjets();
}

}
?>