<?php 

require_once(__DIR__."/modele.php");
class Voiture extends Modele{


    protected string $marque;
    protected string $couleur;
    protected string $immatriculation;

    protected static $objet="voiture";

    protected static $key="immatriculation";
  

    public function afficher(){
        echo 'voiture '. $this->immatriculation. ', de marque '.$this->marque.', et de couleur '.$this->couleur;
    }

 

    
    public static function addVoiture($i,$m,$c){
        require_once(__DIR__."/../config/connexion.php");
        $requeteAvecTags='INSERT INTO voiture(immatriculation,marque,couleur) VALUES(:i,:m,:c)';
        $requetePreparee=connexion::pdo()->prepare($requeteAvecTags);

        $valeurs=array();
        if(strlen($i)>0){
            $valeurs["i"]=$i;
        }else{
            $valeurs["i"]=NULL;
        }
        
        if(strlen($m)>0){
            $valeurs["m"]=$m;
        }else{
            $valeurs["m"]=NULL;
        }

        if(strlen($c)>0){
            $valeurs["c"]=$c;
        }else{
            $valeurs["c"]=NULL;
        }

        try{
            $requetePreparee->execute($valeurs);
            return true;
        }catch(PDOException $e){
            return false;
        }

    }


    public static function updateVoiture($i,$m,$c){
        require_once(__DIR__."/../config/connexion.php");
        $requeteAvecTags='UPDATE voiture SET marque=:m, couleur=:c WHERE immatriculation=:i';
        $requetePreparee=connexion::pdo()->prepare($requeteAvecTags);

        $valeurs=array();
        if(strlen($i)>0){
            $valeurs["i"]=$i;
        }else{
            $valeurs["i"]=NULL;
        }
        
        if(strlen($m)>0){
            $valeurs["m"]=$m;
        }else{
            $valeurs["m"]=NULL;
        }

        if(strlen($c)>0){
            $valeurs["c"]=$c;
        }else{
            $valeurs["c"]=NULL;
        }

        try{
            $requetePreparee->execute($valeurs);
        }catch(PDOException $e){
        }
    }







}

