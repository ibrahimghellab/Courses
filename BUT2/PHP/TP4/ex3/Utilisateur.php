<?php class Utilisateur{
    private string $login;
    private string $mdp;
    private string $prenom;
    private string $nom;
    private string $mail;



    public function getLogin(){return $this->$login;}
    public function setLogin($value){$this->$login=$value;}

    public function getMdp(){return $this->$mdp;}
    public function setMdp($value){$this->$mdp=$value;}

    public function getPrenom(){return $this->$prenom;}
    public function setPrenom($value){$this->$prenom=$value;}

    public function getNom(){return $this->$nom;}
    public function setNom($value){$this->$nom=$value;}

    public function getMail(){return $this->$mail;}
    public function setMail($value){$this->$mail=$value;}

    

    public function __construct(string $l,string $md,string $p,string $n,string $ma){
        $this->login=$l;
        $this->mdp=$md;
        $this->prenom=$p;
        $this->nom=$n;
        $this->mail=$ma;
    }

    public function afficher(){
        echo 'utilisateur '. $this->login. ' ( '.$this->prenom.' '.$this->nom.' )'.', email = '.$this->mail;
    }








}

