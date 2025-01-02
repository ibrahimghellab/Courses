<?php 

require_once(__DIR__."/modele.php");
class Voiture extends Modele{


    protected string $marque;
    protected string $couleur;
    protected string $immatriculation;

  

    public function afficher(){
        echo 'voiture '. $this->immatriculation. ', de marque '.$this->couleur.', et de couleur '.$this->immatriculation;
    }

    public static function getAllVoitures(){
        require_once(__DIR__."/../config/connexion.php");
        Connexion::connect();
        $requete="SELECT * FROM voiture;";
        $resultat=Connexion::pdo()->query($requete);
        $resultat->setFetchmode(PDO::FETCH_CLASS,"voiture");
        $lesVoitures=$resultat->fetchAll();
        return $lesVoitures;
    }

    public static function getVoitureByImmat($i){
        $requeteAvecTags="SELECT * FROM voiture WHERE immatriculation=:i;";
        $requetePreparee=connexion::pdo()->prepare($requeteAvecTags);


        $valeurs=array();
        if(strlen($i)>0){
            $valeurs["i"]=$i;
        }else{
            $valeurs["i"]=NULL;
        }

        try{
            $requetePreparee->execute($valeurs);
            $requetePreparee->setFetchmode(PDO::FETCH_CLASS,"voiture");
            return $requetePreparee->fetch();
            
        }catch(PDOException $e){
            echo $e->getMessage();
        }
    }









}

