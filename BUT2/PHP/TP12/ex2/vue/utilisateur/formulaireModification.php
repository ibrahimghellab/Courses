<main>
    <form method="get" action="routeur.php">
        <input type="hidden" name="controleur" value="controleurUtilisateur">
        <input type="hidden" name="action" value="modifierObjet">
        <div>
            <label for="login">login</label>
            <input type="text" name="login" value=<?php echo $l ?> >
        </div>
        <div>
            <label for="mdp">mdp</label>
            <input type="password" name="mdp" value=<?php echo $m ?> >
        </div>
        <div>
            <label for="nom">nom</label>
            <input type="text" name="nom" value=<?php echo $n ?> >
        </div>
        <div>
            <label for="prenom">prenom</label>
            <input type="text" name="prenom" value=<?php echo $p ?> >
        </div>
        <div>
            <label for="email">email</label>
            <input type="email" name="email" value=<?php echo $e ?> >
        </div>
        <button type="submit">Modifier</button >
    </form>
</main>