<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Les voitures</title>
</head>
<body>
    <?php 
    require_once("voiture.php");
    require_once("connexion.php");
    require_once("menu.html");
    Connexion::connect();
    

    $voi=Voiture::getAllVoitures();

 
    echo '<ul>';
    foreach($voi as $cle=>$valeur){
        echo '<li>';    
        $valeur->afficher();
        echo '</li>';
    }
    echo '</ul>';
?>

</body>
</html>