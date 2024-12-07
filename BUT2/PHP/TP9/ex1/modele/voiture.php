<?php 

require_once(__DIR__."/modele.php");
class Voiture extends Modele{


    protected string $marque;
    protected string $couleur;
    protected string $immatriculation;

    protected static $objet="voiture";

    protected static $key="immatriculation";
  

    public function afficher(){
        echo 'voiture '. $this->immatriculation. ', de marque '.$this->couleur.', et de couleur '.$this->immatriculation;
    }

 

    
    









}

