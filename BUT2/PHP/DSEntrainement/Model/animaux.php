<?php
require_once(__DIR__ . "./../Model/modele.php");
class Animaux extends Modele
{
    public $id;
    public $nom;
    public $espece;
    public $age;
    public $description;
    public $statut;

    public static function getAnimauxDisponibles()
    {
        require_once(__DIR__ . "/../config/connexion.php");
        Connexion::connect();
        $requeteAvecTags = 'SELECT * FROM Animaux WHERE statut="disponible";';
        $requetePreparee = Connexion::pdo()->prepare($requeteAvecTags);
        try {
            $requetePreparee->execute();
            return $requetePreparee->fetchAll(PDO::FETCH_CLASS, 'Animaux');
        } catch (PDOException $e) {
            echo $e->getMessage();
        }
    }

}
?>