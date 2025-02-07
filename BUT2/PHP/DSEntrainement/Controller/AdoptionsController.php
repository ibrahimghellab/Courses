<?php
require_once(__DIR__ . "/../Model/adoptions.php");
class AdoptionsController
{

    public static function demandeAdoption()
    {
        Adoptions::adoptionDemande();
        require_once(__DIR__ . "/../View/lesAnimaux.php");
    }

    public static function afficherFormulaire()
    {
        require_once(__DIR__ . "/../View/formulaireDemandeAdoption.php");
    }

    public static function getAll()
    {
        return Adoptions::getAll();
    }

    public static function supprimerAdoption()
    {
        Adoptions::supprimerAdoption();
        require_once(__DIR__ . "/../View/tableau_de_bord.php");
    }

    public static function validerAdoption()
    {
        Adoptions::validerAdoption();
        require_once(__DIR__ . "/../View/tableau_de_bord.php");
    }

}


?>