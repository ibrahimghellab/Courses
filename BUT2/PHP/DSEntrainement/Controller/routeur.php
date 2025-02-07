<?php
require_once(__DIR__ . "/AnimauxController.php");
require_once(__DIR__ . "/AdoptionsController.php");
require_once(__DIR__ . "/EmployesController.php");


$tableauControleurs = ["AnimauxController", "AdoptionsController", "EmployesController"];
$actionParDefaut = array(
    "AnimauxController" => "getAll",
    "AdoptionsController" => "afficherFormulaire",
    "EmployesController" => "afficherFormulaire"
);


require_once(__DIR__ . "/../config/connexion.php");
Connexion::connect();
$controleur = "AnimauxController";
$action = "getAll";
if (isset($_GET["controleur"]) && in_array($_GET["controleur"], $tableauControleurs)) {
    $controleur = $_GET["controleur"];
}
echo $controleur;
if (isset($_GET["action"]) && in_array($_GET["action"], get_class_methods($controleur))) {
    $action = $_GET["action"];
}
if (!(isset($_GET["action"]) && in_array($_GET["action"], get_class_methods($controleur)))) {
    $action = $actionParDefaut[$controleur];
}

$controleur::$action();