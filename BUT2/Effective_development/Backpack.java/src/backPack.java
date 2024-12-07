public class backPack {
    public static int sum(List<Integer> objets){
        if (objets == null){
            return 0;
        }
        else{
            return objets.data() + sum(objets.tail());
        }
    }

    public static List<Integer> backPackPremierDisponible(int contenance, List<Integer> objets) {
        // Vérifie si on a atteint la fin de la liste d'objets
        if (objets == null) {
            return null; // Le sac est vide ici
        }

        // Si l'objet courant peut entrer dans le sac
        if (contenance >= objets.data()) {
            // On ajoute l'objet au sac
            List<Integer> sac = new List<>(objets.data());
            // On fait un appel récursif pour ajouter les autres objets avec la nouvelle capacité
            sac.setTail(backPackPremierDisponible(contenance - objets.data(), objets.tail()));
            return sac;
        } else {
            // Si l'objet ne peut pas entrer, on passe au suivant
            return backPackPremierDisponible(contenance, objets.tail());
        }
    }



    public static List<Integer> backPackplusGros(int contenance, List<Integer> objets) {

        if(objets.tail()==null){return null;}




    }

    public static void main (String... args){
        List<Integer> result = null;

        result = backPackPremierDisponible(20, new List<>(3, 5, 13, 2));
        if (result != null) result.display();
        System.out.printf("Votre fonction choisit des objets de volume total %d, l'optimal est 20\n", sum(result));

        result = backPackPremierDisponible(11, new List<>(3, 3, 3, 2, 2, 2, 2, 2));
        if (result != null) result.display();
        System.out.printf("Votre fonction choisit des objets de volume total %d, l'optimal est 10\n", sum(result));

    }
}

