import java.io.File;


public class Folder{
    /* Construire l'arbre des dossiers à partir de l'adresse indiquée */
    public static Tree<String> buildTree(File dir){




        File[] fileTab = dir.listFiles();



        return null;
    }
    /* Uun algorithme qui modifie l'arbre parmi ceux proposés.
     * Vous pouvez changer le nom en fonction */
    public static void update (Tree<String> hierarchy, String name){



        return;
    }

    /* Créer les répertoires à partir de l'arbre */
    public static void createFolders(File dir, Tree<String> hierarchy){

        /* Pour créer un nouveau répertoire, créer un nouvel objet File
         * puis utiliser file.mkdirs (ou mkdir)
         * A noter : on peut contruire un fichier dans un repertoire existant
         * avec new File(File rep, String name)
         */
        return;
    }


    public static void main(String... args){
        File currentDir = new File("test");

        /* Un objet File de java. Le point de départ est le repertoire contenant le fichier source.
         * Pour avoir son nom, dir.getName().
         * On teste que c'est un dossier avec f.isDirectory().
         */
        System.out.println(currentDir.isDirectory());
        Tree<String> hierarchy = buildTree(currentDir);
        hierarchy.display();
        update(hierarchy, "name");
        hierarchy.display();
        currentDir = new File("test");
        createFolders(currentDir, hierarchy);
    }
}