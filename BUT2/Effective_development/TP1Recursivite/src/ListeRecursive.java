public class ListeRecursive {

    ListeRecursive li;
    Integer value;

    ListeRecursive(Integer v, ListeRecursive l) {
        li = l;
        value = v;
    }

    boolean vide() {
        return li == null;
    }

    ListeRecursive reste() {
        return this.li;
    }

    /*fonction prefixer(val) retourne ListeRecursive
    {Retourne la liste obtenue en inserant val en tete}
    Parametre (D) cible : ListeRecursive
            (D) val : INFO*/

    Integer nbElements() {
        if (vide()) {
            return 1;
        }
        return 1 + reste().nbElements();
    }

    ListeRecursive ajouterDebutListe(Integer i) {
        return new ListeRecursive(i, this);
    }

    void ajouterFinListe(Integer i) {
        if (vide()) {
            this.li = new ListeRecursive(i, null);
        } else {
            reste().ajouterFinListe(i);
        }

    }


    Integer sumElements() {
        if (vide()) {
            return value;
        }
        return value + reste().sumElements();
    }


    public static void main(String[] args) {


        ListeRecursive l = new ListeRecursive(
                5, new ListeRecursive(12, new ListeRecursive(25, new ListeRecursive(8, null)))
        );
        System.out.println(l.nbElements());
        l = l.ajouterDebutListe(15);
        System.out.println(l.value);
        System.out.println(l.sumElements());
        l.ajouterFinListe(50);
        System.out.println(l.sumElements());
        System.out.println(l.li.li.li.li.li.value);
    }
}