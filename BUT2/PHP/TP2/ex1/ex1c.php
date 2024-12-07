<!DOCTYPE html>
<html lang="fr">
  <head>
    <meta charset="utf-8">
    <title>TP2 - ex1a</title>
  </head>
  <body>
    <h2>Palmarès de la coupe du monde de football depuis 1930</h2>
    <?php
      $palmares = array(
        2022 => "Argentine",
        2018 => "France",
        2014 => "Allemagne",
        2010 => "Espagne",
        2006 => "Italie",
        2002 => "Brésil",
        1998 => "France",
        1994 => "Brésil",
        1990 => "Allemangne",
        1986 => "Argentine",
        1982 => "Italie",
        1978 => "Argentine",
        1974 => "Allemangne",
        1970 => "Brésil",
        1966 => "Angleterre",
        1962 => "Brésil",
        1958 => "Brésil",
        1954 => "Allemagne",
        1950 => "Uruguay",
        1938 => "Italie",
        1934 => "Italie",
        1930 => "Uruguay"

      );

      

      
        $vainqeurs=array();
        foreach($palmares as $cle => $valeur){
          
          if(!in_array($valeur,$vainqeurs)){
            $vainqeurs[]=$valeur;
          }
        }
        
      

      echo "<pre>";
      print_r($vainqeurs);
      echo "</pre>";
    ?>

  </body>
</html>