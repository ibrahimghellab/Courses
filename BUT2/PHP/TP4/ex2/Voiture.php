<?php class Voiture{
    private string $marque;
    private string $couleur;
    private string $immatriculation;


    public function getMarque(){return $this->$marque;}
    public function setMarque($value){$this->$marque=$value;}

    public function getCouleur(){return $this->$couleur;}
    public function setCouleur($value){$this->$couleur=$value;}

    public function getImmatriculation(){return $this->$immatriculation;}
    public function setImmatriculation($value){$this->$immatriculation=$value;}

    public function __construct(string $m,string $c,string $i){
        $this->marque=$m;
        $this->couleur=$c;
        $this->immatriculation=$i;
    }

    public function afficher(){
        echo 'voiture '. $this->immatriculation. ', de marque '.$this->couleur.', et de couleur '.$this->immatriculation;
    }








}

