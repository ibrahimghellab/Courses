<?php

require_once(__DIR__."/../modele/voiture.php");

$title="Les voitures";

$voi=Voiture::getAllVoitures();

require_once(__DIR__."/../vue/debut.php");
require_once(__DIR__."/../vue/menu.html");
require_once(__DIR__."/../vue/voiture/lesVoitures.php");
require_once(__DIR__."/../vue/fin.html");