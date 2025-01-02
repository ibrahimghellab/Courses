<?php class Utilisateur{
    private string $login;
    private string $mdp;
    private string $prenom;
    private string $nom;
    private string $email;



    public function getLogin(){return $this->login;}
    public function setLogin($value){$this->login=$value;}

    public function getMdp(){return $this->mdp;}
    public function setMdp($value){$this->mdp=$value;}

    public function getPrenom(){return $this->prenom;}
    public function setPrenom($value){$this->prenom=$value;}

    public function getNom(){return $this->nom;}
    public function setNom($value){$this->nom=$value;}

    public function getMail(){return $this->email;}
    public function setMail($value){$this->email=$value;}

    

    public function __construct(string $l=NULL,string $md=NULL,string $p=NULL,string $n=NULL,string $ma=NULL){
        if(!is_null($l)){
            $this->login=$l;
            $this->mdp=$md;
            $this->prenom=$p;
            $this->nom=$n;
            $this->email=$ma;
        }
        
    }

    public function afficher(){
        echo 'utilisateur '. $this->login. ' ( '.$this->prenom.' '.$this->nom.' )'.', email = '.$this->email;
    }

    public static function getAllUsers(){
        require_once(__DIR__."/../config/connexion.php");
        Connexion::connect();
        $requete="SELECT * FROM utilisateur;";
        $resultat=Connexion::pdo()->query($requete);
        $resultat->setFetchmode(PDO::FETCH_CLASS,"utilisateur");
        $lesUtilisateurs=$resultat->fetchAll();
        return $lesUtilisateurs;
    }






}

