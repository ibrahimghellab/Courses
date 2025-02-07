<?php
require_once(__DIR__ . "/../Controller/AdoptionsController.php");
require_once(__DIR__ . "/debut.php");
$tab = AdoptionsController::getAll();
echo '<h1>Tableau de bord</h1>';
foreach ($tab as $cle => $valeur) {
    echo $valeur->get("nom_demandeur") . ' avec comme email ' . $valeur->get("email") . ' et comme numéro de téléphone ' . $valeur->get("telephone") . " veut recruter l'animal ayant comme id : " . $valeur->get("id_animal") . '<a href="index.php?controleur=AdoptionsController&action=validerAdoption&id=' . $valeur->get("id") . '">Valider adoption</a> <a href="index.php?controleur=AdoptionsController&action=supprimerAdoption&id=' . $valeur->get("id") . '">Supprimer adoption</a>';
    echo '<br>';
}
require_once(__DIR__ . "/fin.php");

?>