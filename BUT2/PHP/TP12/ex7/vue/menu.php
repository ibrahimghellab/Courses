<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="css/style.css">
    <title>ex6-7</title>
</head>
<body>
    <header>
        <h1>Bienvenue <?php echo $_SESSION["login"];?> <a href="index.php?controleur=controleurUtilisateur&action=deconnecterUtilisateur">Se déconnecter</a></h1>
        <nav>
            <a href="index.php?controleur=controleurVoiture&action=lireObjets">Liste des voitures</a>
            <a href="index.php?controleur=controleurUtilisateur&action=lireObjets">Liste des utilisateurs</a>        
            <a href="index.php?controleur=controleurVoiture&action=afficherFormulaireCreation">Ajouter une voiture</a>
            <a href="index.php?controleur=controleurUtilisateur&action=afficherFormulaireCreation">Ajouter un utilisateur</a>
        </nav>
    </header>
    </body>
</html>