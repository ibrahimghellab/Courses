<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>TP4-ex2</title>
</head>
<body>
    <?php
    require_once("Voiture.php");
    echo "<pre>";
    print_r($_GET);
    echo "<pre>";

    $imma=$_GET["immatriculation"];
    $ma=$_GET["marque"];
    $coul=$_GET["couleur"];

    $voiture= new Voiture(m:$ma,c:$coul,i:$imma);

    $voiture->afficher();

    

    ?>
    
    <a href="formulaireVoiture.php">retour au formulaire</a>
</body>
</html>