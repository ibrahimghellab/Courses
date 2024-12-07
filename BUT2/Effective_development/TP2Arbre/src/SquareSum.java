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

    public static Tree<Integer> remplirArbre(Tree<Integer> t){
        if(t.data()==0){
            return t;
        }
        int plusGrand=(int)Math.floor(Math.sqrt(t.data()));
        for (int i=plusGrand;i>0;i--){
            Tree<Integer> tChild=new Tree<>(t.data()-(i*i));
            tChild=remplirArbre(tChild);
            t.addChildren(tChild);
        }
        return t;
    }

    public static int profondeurMin(Tree<Integer> t){
        int min=t.data();
        for(int i=0;i<t.nbChildren();i++){
            int val=1+profondeurMin(t.child(i));
            if(min>val)min=val;
        }
        return min;
    }

    public static int nbCarresBruteForce(int soldats){
        Tree<Integer> t=new Tree<>(soldats);
        t=remplirArbre(t);

        return profondeurMin(t);
    }



    public static void main(String... args){
        decomposerEnCarresForceBrute(2).display();
        System.out.printf("Pour %d soldats, vous trouvez %d soldats (le minimum est %d)\n", 21, nbCarresGlouton(21), 3);
        System.out.printf("Pour %d soldats, vous trouvez %d soldats (le minimum est %d)\n", 27, nbCarresGlouton(27), 3);
        System.out.printf("Pour %d soldats, vous trouvez %d soldats (le minimum est %d)\n", 33, nbCarresGlouton(33), 3);

        System.out.printf("Pour %d soldats, vous trouvez %d soldats (le minimum est %d)\n", 21, nbCarresBruteForce(21), 3);

        System.out.printf("Pour %d soldats, vous trouvez %d soldats (le minimum est %d)\n", 27, nbCarresBruteForce(27), 3);
        System.out.printf("Pour %d soldats, vous trouvez %d soldats (le minimum est %d)\n", 33, nbCarresBruteForce(33), 3);




    }

}
