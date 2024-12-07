<?php 
require_once(__DIR__."/modele.php");
class Utilisateur extends Modele{
    protected string $login;
    protected string $mdp;
    protected string $prenom;
    protected string $nom;
    protected string $email;
    protected static $objet="utilisateur";
    protected static $key="login";

    

    public function afficher(){
        echo 'utilisateur '. $this->login. ' ( '.$this->prenom.' '.$this->nom.' )'.', email = '.$this->email;
    }



}

