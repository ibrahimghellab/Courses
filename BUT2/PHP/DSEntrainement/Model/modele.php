<?php
require_once(__DIR__ . "./../Model/modele.php");
class Modele
{

    public function get($att)
    {
        return $this->$att;
    }


}