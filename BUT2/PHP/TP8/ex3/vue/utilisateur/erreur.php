<?php
echo '<main>';
    echo "<p>Oups une erreur s'est produite :(</p>";
    echo "<p>L'utilisateur avec pour login ". $_GET["login"] ." n'existe pas dans la base</p>";
    echo '</main>';