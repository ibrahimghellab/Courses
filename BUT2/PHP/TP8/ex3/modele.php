<?php 


class Modele{
    
    

    public function get($attribut){
        return $this->$attribut;
    }
    public function set($attribut,$valeur){
        $this->$attribut=$valeur;
    }

    public function __construct($donnees=NULL){
        if(!is_null($donnees)){
            foreach($donnees as $attribut=>$valeur){
                $this->set($attribut,$valeur);
            }
        }
    }

    public static function getAll(){
        require_once(__DIR__."/../config/connexion.php");
        require_once(__DIR__."/Utilisateur.php");
        require_once(__DIR__."/voiture.php");
        
        $table=static::$objet;
        
        Connexion::connect();
        #$requete="SELECT * FROM $table;";
        #$resultat=Connexion::pdo()->query($requete);
        #$resultat->setFetchmode(PDO::FETCH_CLASS,$$table);
        #$lesResult=$resultat->fetchAll();
        #return $lesResult;
    }
}