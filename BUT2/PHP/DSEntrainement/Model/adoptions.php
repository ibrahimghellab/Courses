<?php
require_once(__DIR__ . "./../Model/modele.php");
class Adoptions extends Modele
{
    public $id;
    public $nom_demandeur;
    public $email;
    public $telephone;
    public $idAnimal;
    public $statut;


    public static function adoptionDemande()
    {
        require_once(__DIR__ . "/../config/connexion.php");

        if (isset($_GET["nom_demandeur"], $_GET["email"], $_GET["telephone"], $_GET["id_animal"])) {
            $requeteAvecTags = 'INSERT INTO Adoptions(nom_demandeur, email, telephone, id_animal, statut) 
                            VALUES(:nom_demandeur, :email, :telephone, :id_animal, "En attente")';

            try {
                $requetePreparee = Connexion::pdo()->prepare($requeteAvecTags);

                // Liaison des paramètres
                $requetePreparee->bindParam(":nom_demandeur", $_GET["nom_demandeur"], PDO::PARAM_STR);
                $requetePreparee->bindParam(":email", $_GET["email"], PDO::PARAM_STR);
                $requetePreparee->bindParam(":telephone", $_GET["telephone"], PDO::PARAM_STR);
                $id_animal = (int) $_GET["id_animal"]; // Conversion en entier pour éviter toute injection
                $requetePreparee->bindParam(":id_animal", $id_animal, PDO::PARAM_INT);

                // Exécution de la requête
                $requetePreparee->execute();
            } catch (PDOException $e) {
                echo "Erreur : " . $e->getMessage();
            }
        } else {
            echo "erreur";
        }


    }

    public static function validerAdoption()
    {
        require_once(__DIR__ . "/../config/connexion.php");
        $requeteAvecTags = 'UPDATE Adoptions SET statut="Adopté" WHERE id=:id';
        $requetePreparee = connexion::pdo()->prepare($requeteAvecTags);
        $requetePreparee->bindParam(":id", $_GET["id"], PDO::PARAM_INT);

        try {
            $requetePreparee->execute();
        } catch (PDOException $e) {
            echo $e->getMessage();
        }
    }

    public static function supprimerAdoption()
    {
        $requeteAvecTags = 'DELETE FROM Adoptions WHERE id=:id;';
        $requetePreparee = connexion::pdo()->prepare($requeteAvecTags);
        $requetePreparee->bindParam(":id", $_GET["id"], PDO::PARAM_INT);

        try {
            $requetePreparee->execute();
        } catch (PDOException $e) {
            echo $e->getMessage();
        }
    }
    public static function getAll()
    {
        require_once(__DIR__ . "/../config/connexion.php");
        Connexion::connect();
        $requeteAvecTags = 'SELECT * FROM Adoptions WHERE statut="En attente";';
        $requetePreparee = Connexion::pdo()->prepare($requeteAvecTags);
        try {
            $requetePreparee->execute();
            return $requetePreparee->fetchAll(PDO::FETCH_CLASS, 'Adoptions');
        } catch (PDOException $e) {
            echo $e->getMessage();
        }
    }

}
?>