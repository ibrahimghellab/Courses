<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Les utilisateurs</title>
</head>
<body>
    <?php 
    require_once("Utilisateur.php");
    require_once("connexion.php");
    Connexion::connect();
    

    $usr=Utilisateur::getAllUsers();

    echo '<pre>';
    print_r($usr);
    echo '</pre>';

    echo '<ul>';
    foreach($usr as $cle=>$valeur){
        echo '<li>';    
        $valeur->afficher();
        echo '</li>';
    }
    echo '</ul>';
?>

</body>
</html>