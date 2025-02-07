<?php
require_once(__DIR__ . "./../Model/modele.php");
class Employes extends Modele
{
    public $id;
    public $nom;
    public $email;
    public $mot_de_passe;

    public static function checkEmploye()
    {
        if (isset($_GET["email"]) && isset($_GET["mot_de_passe"])) {
            $requetePreparee = Connexion::pdo()->prepare("SELECT * FROM Employes WHERE email=:email AND mot_de_passe=:mdp");
            $requetePreparee->bindParam(":email", $_GET["email"], PDO::PARAM_STR);
            $requetePreparee->bindParam(":mdp", $_GET["mot_de_passe"], PDO::PARAM_STR);
            $requetePreparee->execute();
            return $requetePreparee->rowCount() > 0;
        }

    }
}
?>