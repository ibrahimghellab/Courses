
    <?php 
    $title="Les voitures";

    require_once(__DIR__."/vue/debut.php");
    require_once(__DIR__."/modele/voiture.php");
    require_once(__DIR__."/config/connexion.php");
    require_once(__DIR__."/vue/menu.html");
    Connexion::connect();
    

    $voi=Voiture::getAllVoitures();

 
    require_once(__DIR__."/vue/voiture/lesVoitures.php");

    require_once(__DIR__."/vue/fin.html");
?>

