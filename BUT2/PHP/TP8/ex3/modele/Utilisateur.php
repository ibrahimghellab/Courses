<?php 
require_once(__DIR__."/modele.php");
class Utilisateur extends Modele{
    protected string $login;
    protected string $mdp;
    protected string $prenom;
    protected string $nom;
    protected string $email;
    protected static $objet="utilisateur";

    

    public function afficher(){
        echo 'utilisateur '. $this->login. ' ( '.$this->prenom.' '.$this->nom.' )'.', email = '.$this->email;
    }



    public static function getUserByLogin($l){
        $requeteAvecTags="SELECT * FROM utilisateur WHERE login=:l;";
        $requetePreparee=connexion::pdo()->prepare($requeteAvecTags);


        $valeurs=array();
        if(strlen($l)>0){
            $valeurs["l"]=$l;
        }else{
            $valeurs["l"]=NULL;
        }

        try{
            $requetePreparee->execute($valeurs);
            $requetePreparee->setFetchmode(PDO::FETCH_CLASS,"utilisateur");
            return $requetePreparee->fetch();
            
        }catch(PDOException $e){
            echo $e->getMessage();
        }
    }






}

