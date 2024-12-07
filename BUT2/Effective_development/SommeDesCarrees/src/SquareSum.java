import java.util.ArrayList;

public class SquareSum {

    /* Le programme suivant doit renvoyer le nombre de carrés.
     * Vous pourrez ensuite l'améliorer pour afficher la liste des carrés choisis.
     */

    public static int nbCarresGlouton (int soldats){

        int nbC=0;

        if(soldats!=0) {
            System.out.println(Math.floor(Math.sqrt(soldats)));
            nbC += 1+nbCarresGlouton((int) (soldats - (Math.floor(Math.sqrt(soldats))*Math.floor(Math.sqrt(soldats)))));
        }
        return nbC;
    }


    public static Tree<Integer> decomposerEnCarresForceBrute(int soldats) {
        if (soldats == 0) {
            return new Tree<>(0);
        }

        Tree<Integer> racine = new Tree<>(soldats);


        for (int i = 1; i * i <= soldats; i++) {
            int carre = i * i;
            Tree<Integer> decompositionRestante = decomposerEnCarresForceBrute(soldats - carre);

            Tree<Integer> noeudCarre = new Tree<>(carre);
            noeudCarre.addChildren(decompositionRestante);

            racine.addChildren(noeudCarre);
        }

        return racine; 
    }

    public static int nbCarresForceBrute(int soldats){
        return decomposerEnCarresForceBrute(soldats).minProfondeur();
    }



    public static void main(String... args){
        decomposerEnCarresForceBrute(2).display();
        System.out.printf("Pour %d soldats, vous trouvez %d soldats (le minimum est %d)\n", 21, nbCarresGlouton(21), 3);
        System.out.printf("Pour %d soldats, vous trouvez %d soldats (le minimum est %d)\n", 27, nbCarresGlouton(27), 3);
        System.out.printf("Pour %d soldats, vous trouvez %d soldats (le minimum est %d)\n", 33, nbCarresGlouton(33), 3);

        System.out.printf("Pour %d soldats, vous trouvez %d soldats (le minimum est %d)\n", 21, nbCarresForceBrute(21), 3);
        System.out.printf("Pour %d soldats, vous trouvez %d soldats (le minimum est %d)\n", 27, nbCarresForceBrute(27), 3);
        System.out.printf("Pour %d soldats, vous trouvez %d soldats (le minimum est %d)\n", 33, nbCarresForceBrute(33), 3);

    }

}
