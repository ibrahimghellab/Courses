<?php 


class Modele{   

    public function get($attribut){
        return $this->$attribut;
    }
    public function set($attribut,$valeur){
        $this->$attribut=$valeur;
    }

    public function __construct($donnees=NULL){
        if(!is_null($donnees)){
            foreach($donnees as $attribut=>$valeur){
                $this->set($attribut,$valeur);
            }
        }
    }

    public static function getAll(){
        require_once(__DIR__."/../config/connexion.php");
        require_once(__DIR__."/Utilisateur.php");
        require_once(__DIR__."/voiture.php");
        
        $table=static::$objet;
        
        Connexion::connect();
        $requete="SELECT * FROM ".$table.";";
       
        $resultat=Connexion::pdo()->query($requete);
        $resultat->setFetchmode(PDO::FETCH_CLASS,$table);
        $lesResult=$resultat->fetchAll();
        return $lesResult;
    }

    public static function getObjetById($k){
        $table=static::$objet;
        $requeteAvecTags="SELECT * FROM $table WHERE ".static::$key."=:k;";
        $requetePreparee=connexion::pdo()->prepare($requeteAvecTags);


        $valeurs=array();
        if(strlen($k)>0){
            $valeurs["k"]=$k;
        }else{
            $valeurs["k"]=NULL;
        }

        try{
            $requetePreparee->execute($valeurs);
            $requetePreparee->setFetchmode(PDO::FETCH_CLASS,$table);
            return $requetePreparee->fetch();
            
        }catch(PDOException $e){
            echo $e->getMessage();
        }
    }

    public static function deleteObjetById($id){
        $table=static::$objet;
        $requeteAvecTags='DELETE FROM '.$table.' WHERE '.static::$key.'=:id;';
        $requetePreparee=connexion::pdo()->prepare($requeteAvecTags);

        $valeurs=array();
        if(strlen($id)>0){
            $valeurs["id"]=$id;
        }else{
            $valeurs["id"]=NULL;
        }

        try{
            $requetePreparee->execute($valeurs);
        }catch(PDOException $e){
            echo $e->getMessage();
        }
    }

    public static function addObjet(){
        require_once(__DIR__."/../config/connexion.php");
        $proprieties=$_GET;

        if(static::$objet=="utilisateur"){
            $requeteAvecTags='INSERT INTO utilisateur VALUES(:login,:mdp,:nom,:prenom,:email,0)';
        }else{
            $requeteAvecTags='INSERT INTO voiture(immatriculation,marque,couleur) VALUES(:immatriculation,:marque,:couleur)';
        }


       
        $requetePreparee=connexion::pdo()->prepare($requeteAvecTags);
        
        $valeurs=array();
        foreach($proprieties as $cle=>$propriete){
            if($cle != "action" && $cle!="controleur"){
                if(strlen($propriete)>0){
                    $valeurs[$cle]=$propriete;
                }else{
                    $valeurs[$cle]=NULL;
                }
            }
            
        }

        try{
            $requetePreparee->execute($valeurs);
            return true;
        }catch(PDOException $e){
            return false;
        }
    }



    public static function updateObjet(){
        require_once(__DIR__."/../config/connexion.php");
        $proprieties=$_GET;

        if(static::$objet=="utilisateur"){
            $requeteAvecTags='UPDATE utilisateur SET mdp=:m, nom=:n, prenom=:p, email=:e WHERE login=:l';
        }else{
            $requeteAvecTags='UPDATE voiture SET marque=:marque, couleur=:couleur WHERE immatriculation=:immatriculation';
        }
        $requetePreparee=connexion::pdo()->prepare($requeteAvecTags);
        $valeurs=array();
        foreach($proprieties as $cle=>$propriete){
            if($cle != "action" && $cle!="controleur"){
                if(strlen($propriete)>0){
                    $valeurs[$cle]=$propriete;
                }else{
                    $valeurs[$cle]=NULL;
                }
            }
        }
        try{
            $requetePreparee->execute($valeurs);
        }catch(PDOException $e){
            echo $e->getMessage();
        }
    }


    public function affichable(){
        return true;
    }

}