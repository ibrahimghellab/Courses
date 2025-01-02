<?php 
require_once(__DIR__."/modele.php");
class Utilisateur extends Modele{
    protected string $login;
    protected string $mdp;
    protected string $prenom;
    protected string $nom;
    protected string $email;
    public static $objet="utilisateur";
    protected static $key="login";

    

    public function afficher(){
        echo 'utilisateur '. $this->login. ' ( '.$this->prenom.' '.$this->nom.' )'.', email = '.$this->email;
    }

    public static function addUtilisateur($l,$m,$n,$p,$e){
        require_once(__DIR__."/../config/connexion.php");
        $requeteAvecTags='INSERT INTO utilisateur VALUES(:l,:m,:n,:p,:e)';
        $requetePreparee=connexion::pdo()->prepare($requeteAvecTags);

        $valeurs=array();
        if(strlen($l)>0){
            $valeurs["l"]=$l;
        }else{
            $valeurs["l"]=NULL;
        }
        
        if(strlen($m)>0){
            $valeurs["m"]=$m;
        }else{
            $valeurs["m"]=NULL;
        }

        if(strlen($n)>0){
            $valeurs["n"]=$n;
        }else{
            $valeurs["n"]=NULL;
        }

        if(strlen($p)>0){
            $valeurs["p"]=$p;
        }else{
            $valeurs["p"]=NULL;
        }

        if(strlen($e)>0){
            $valeurs["e"]=$e;
        }else{
            $valeurs["e"]=NULL;
        }

        try{
            $requetePreparee->execute($valeurs);
            return true;
        }catch(PDOException $e){
            return false;
        }
    }


}

