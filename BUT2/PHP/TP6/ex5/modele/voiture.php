<?php class Voiture{


    private string $marque;
    private string $couleur;
    private string $immatriculation;

    


    public function getMarque(){return $this->marque;}
    public function setMarque($value){$this->marque=$value;}

    public function getCouleur(){return $this->couleur;}
    public function setCouleur($value){$this->couleur=$value;}

    public function getImmatriculation(){return $this->immatriculation;}
    public function setImmatriculation($value){$this->immatriculation=$value;}

    public function __construct(string $m=NULL,string $c=NULL,string $i=NULL){
        if(!is_null($i)){
            $this->marque=$m;
            $this->couleur=$c;
            $this->immatriculation=$i;
        }
    }

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









}

