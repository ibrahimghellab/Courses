<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    
</head>
<body>
<?php
    
        echo "<h1>tableau des capitaux successifs</h1>";
        $capital=array(10000);

        for($i =1;$i<10;$i++){
            $capital[]=floor($capital[$i-1]+(5/100)*($capital[$i-1]));
        }
        for($i=0;$i<10;$i++){
            echo "<p>C[$i]=". $capital[$i] ."€ </p>";
        }
        
?>
</body>
</html>

