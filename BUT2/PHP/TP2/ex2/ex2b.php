<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="ex2b.css">
    
</head>
<body>
<?php
    
        $capital=array(10000);

        for($i =1;$i<10;$i++){
            $capital[]=floor($capital[$i-1]+(5/100)*($capital[$i-1]));
        }
        echo "<h1>tableau des capitaux successifs</h1>";
?>
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
            for($i=0;$i<10;$i++){
                echo "<tr><td>$i</td><td>" . $capital[$i] . "€</td></tr>";
            }
                
                ?>
        </tr>
    </tbody>
</table>

</body>
</html>

