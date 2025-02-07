<?php
    session_start();
    echo "<pre>Session courante : <br>";
    print_r($_SESSION);
    echo "</pre>";
    require_once("controleur/routeur.php")
?>