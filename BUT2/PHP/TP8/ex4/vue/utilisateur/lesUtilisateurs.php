<?php 
echo '<main>';
foreach($usr as $cle=>$valeur){
    echo '<br>utilisateur avec comme login '. $valeur->get("login").'<a href=routeur.php?controleur=controleurUtilisateur&action=lireUtilisateur&login='.$valeur->get("login").'>détails</a>';
    }
    echo '</main>';
    