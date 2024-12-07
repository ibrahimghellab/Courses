<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>TP4-ex2</title>
</head>
<body>
    <?php
    require_once("Utilisateur.php");
   

    $log=$_GET["login"];
    $mdp=$_GET["mdp"];
    $pre=$_GET["prenom"];
    $nom=$_GET["nom"];
    $mail=$_GET["email"];


    $user= new Utilisateur(l:$log,md:$mdp,p:$pre,n:$nom,ma:$mail);

    $user->afficher();

    

    ?>
    <br>
    <a href="formulaireUtilisateur.php">retour au formulaire</a>
</body>
</html>