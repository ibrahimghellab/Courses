<?php 
echo '<main>';
foreach($voi as $cle=>$valeur){
    
    echo '<br>voiture immatriculée '. $valeur->get("immatriculation").'<a href=routeur.php?controleur=controleurVoiture&action=lireVoiture&immatriculation='.$valeur->get("immatriculation").'>détails</a>';
    
}
echo '</main>'
?>