<?php
require_once(__DIR__ . "/../Model/animaux.php");

class AnimauxController
{

    public static function getAll()
    {
        $tab = Animaux::getAnimauxDisponibles();
        require_once(__DIR__ . "/../View/lesAnimaux.php");

        return $tab;
    }


}

?>