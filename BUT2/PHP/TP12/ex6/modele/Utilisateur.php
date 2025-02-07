<?php 
require_once(__DIR__."/modele.php");
class Utilisateur extends Modele{
    protected string $login;
    protected string $mdp;
    protected string $prenom;
    protected string $nom;
    protected string $email;
    protected int $isAdmin;
    public static $objet="utilisateur";
    protected static $key="login";

    

    public function afficher(){
        echo 'utilisateur '. $this->login. ' ( '.$this->prenom.' '.$this->nom.' )'.', email = '.$this->email;
    }

    public function isAdmin(){
        return $this->isAdmin==1;
    }

    public function affichable(){
        return !$this->isAdmin;
    }

    public static function checkMDP($l,$m){
        $o=Utilisateur::getObjetById($l);
        if(!$o){
            return false;
        }else{
            if($o->get("mdp")==$m){
                return true;
            }
        }
        return false;
        
    }
    

}

