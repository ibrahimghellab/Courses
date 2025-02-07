<form action="index.php" method="GET">
    <input type="hidden" name="action" value="demandeAdoption">
    <input type="hidden" name="controleur" value="AdoptionsController">

    <label for="nom">Nom : </label>
    <input type="text" id="nom" name="nom_demandeur" required>

    <label for="email ">Email : </label>
    <input type="email" id="email" name="email" required>

    <label for="telephone ">Telephone : </label>
    <input type="text" id="telephone" name="telephone" required>


    <!-- Si t'as le temps fais une requete pour recuperer l'id des animaux en fonction de leur noms et fais un select input-->

    <label for="id_animal ">Id de l'animal : </label>
    <input type="number" id="id_animal" name="id_animal" required>

    <input type="submit">



</form>