<?php 
echo '<main>';
foreach($usr as $cle=>$valeur){
    echo '<br>utilisateur avec comme login '. $valeur->getLogin().'<a href=routeur.php?controleur=controleurUtilisateur&action=lireUtilisateur&login='.$valeur->getLogin().'>détails</a>';
    }
    echo '</main>';
    