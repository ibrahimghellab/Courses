
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

        if (objets == null) {
            return null;
        }

        if (contenance >= objets.data()) {
            List<Integer> sac = new List<>(objets.data());
            sac.setTail(backPackPremierDisponible(contenance - objets.data(), objets.tail()));
            return sac;
        } else {
            return backPackPremierDisponible(contenance, objets.tail());
        }
    }


    public static List<Integer> backPackplusGros(int contenance, List<Integer> objets) {

        if(objets.tail()==null){return null;}
        objets.sort();
        objets=objets.reverse();
        if(contenance-objets.data()>0){
            List<Integer> sac = new List<>(objets.data());
            sac.setTail(backPackPremierDisponible(contenance - objets.data(), objets.tail()));
            return sac;
        }else{

            return backPackPremierDisponible(contenance, objets.tail());

        }
    }

//    public static List<Integer> backBackBruteForce(int contenance, List<Integer> objets){
//
//
//
//
//        return l;
//    }

    public static void main (String... args){
        List<Integer> result = null;

        result = backPackPremierDisponible(20, new List<>(3, 5, 13, 2));
        if (result != null) result.display();
        System.out.printf("Votre fonction choisit des objets de volume total %d, l'optimal est 20\n", sum(result));

        result = backPackPremierDisponible(11, new List<>(3, 3, 3, 2, 2, 2, 2, 2));
        if (result != null) result.display();
        System.out.printf("Votre fonction choisit des objets de volume total %d, l'optimal est 10\n", sum(result));



        result = backPackplusGros(20, new List<>(3, 5, 13, 2));
        if (result != null) result.display();
        System.out.printf("Votre fonction choisit des objets de volume total %d, l'optimal est 20\n", sum(result));

        result = backPackplusGros(11, new List<>(3, 3, 3, 2, 2, 2, 2, 2));
        if (result != null) result.display();
        System.out.printf("Votre fonction choisit des objets de volume total %d, l'optimal est 10\n", sum(result));





    }
}

