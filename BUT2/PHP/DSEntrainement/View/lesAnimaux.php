<?php
require_once(__DIR__ . "/../Controller/AnimauxController.php");
require_once(__DIR__ . "/debut.php");
$tab = AnimauxController::getAll();
echo '<a href=index.php?controleur=AdoptionsController&action=afficherFormulaire>+ Adoptez un animal</a>';
echo '<h1>Animaux à adopter</h1>';
foreach ($tab as $animal) {
    echo 'Le ' . $animal->get("espece") . ' ayant pour nom ' . $animal->get("nom") . ', pour age ' . $animal->get("age") . ' et pour description ' . $animal->get("description");
    echo '<br>';
}
echo '<a href=index.php?controleur=EmployesController&action=afficherFormulaire>Vous êtes employées ? Connectez vous !</a>';
require_once(__DIR__ . "/fin.php");

?>