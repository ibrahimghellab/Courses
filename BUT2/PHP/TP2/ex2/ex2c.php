<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="ex2c.css">
    
</head>
<body>

<?php
    
        $capital=array(10000);
        $seuil=13000;
        $taux=5;
        $capitalInit=10000;

        for($i =1;$i<10;$i++){
            $capital[]=floor($capital[$i-1]+(5/100)*($capital[$i-1]));
        }
        echo "<h1>tableau des capitaux successifs</h1>";
        echo "
            <ul>
                <li>capital initial = $capitalInit €</li>
                <li>taux = $taux %</li>
                <li>seuil = $seuil €</li>
            </ul>
            "; ?>
<table>
    <thead>
        <tr>
            <th>année n</th>
            <th>capital en début d année</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <?php   
            $i=0;
                while($capital[$i]<$seuil && $i<10):
                    echo "<tr><td>$i</td><td>" . $capital[$i] . "€</td></tr>";
                    $i++;
                    
                endwhile;
                    if($i<10){
                        echo "<tr><td>$i</td><td class=red>" . $capital[$i] . "€</td></tr>";
                    }
                

            
                
                ?>
        </tr>
    </tbody>
</table>

</body>
</html>