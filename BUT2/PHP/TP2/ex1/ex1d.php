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
        1990 => "Allemagne",
        1986 => "Argentine",
        1982 => "Italie",
        1978 => "Argentine",
        1974 => "Allemagne",
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

      



        $nbVainqueurs=0;
        $vainqeurs=array();
        foreach($palmares as $cle => $valeur){
          
          if(!in_array($valeur,$vainqeurs)){
            $vainqeurs[]=$valeur;
            $nbVainqueurs++;
          }
        }



        foreach($palmares as $cle => $valeur){
          if(isset($nbTitres[$valeur])){
            $nbTitres[$valeur]+=1;
          }else{
            $nbTitres[$valeur]=1;
          }
          
        }


        

    echo "<h2>Il y en en tout $nbVainqueurs vainqueurs</h2>";
      

      echo "<pre>";
      print_r($nbTitres);
      echo "</pre>";
    ?>

  </body>
</html>