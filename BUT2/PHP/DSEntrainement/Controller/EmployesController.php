<?php
require_once(__DIR__ . "/../Model/employes.php");
class EmployesController
{
    public static function connect()
    {
        if (Employes::checkEmploye()) {
            require_once(__DIR__ . "/../View/tableau_de_bord.php");
        } else {
            require_once(__DIR__ . "/../View/login.php");
        }
    }

    public static function afficherFormulaire()
    {
        require_once(__DIR__ . "/../View/login.php");
    }
}
?>