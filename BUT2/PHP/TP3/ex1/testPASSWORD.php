<?php 
echo "<h1>test passord</h1>";
if(isset($_GET["password"])){
    echo "<p>l'entrée <i>password</i> existe :</p>";
    echo '$GET["password"]'." = ". $_GET["password"];
}else{

    echo "<p>l'entrée <i>password</i> n'existe pas !</p>";
}