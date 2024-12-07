
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>TP4-ex1</title>
</head>
<body>
    <h1>test de construction d'objet Voiture</h1>

    <?php 
    require_once("Voiture.php");
    
    $v1=new Voiture(m : "Renault",c : "bleu",i : "123AB45");
    $v2=new Voiture(m:"Ferrari",c:"rouge",i:"456CD78");
    $v3=new Voiture(m:"Aston martin",c:"gris",i:"JB007");

    echo '<p>'.$v1->afficher().'</p>';
    echo '<p>'.$v2->afficher().'</p>';
    echo '<p>'.$v3->afficher().'</p>';

    
    ?>
</body>
</html>