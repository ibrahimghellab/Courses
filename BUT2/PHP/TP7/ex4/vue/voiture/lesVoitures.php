<?php 
foreach($voi as $cle=>$valeur){
    
    echo '<br>voiture immatriculée '. $valeur->getImmatriculation().'<a href=routeur.php?controleur=controleurVoiture&action=lireVoiture&immatriculation='.$valeur->getImmatriculation().'>détails</a>';
    
}
?>