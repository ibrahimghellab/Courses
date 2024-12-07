import java.util.ArrayList;

public class Tree<T>{

    private T data;
    private ArrayList<Tree<T>> children;
    private Tree<T> parent;

    public Tree(){}

    @SafeVarargs
    public Tree(T data, Tree<T>... childs) {
        this.data = data;
        this.children = new ArrayList<Tree<T>>();
        for (Tree<T> child : childs){
            this.children.add(child);
        }
        this.parent = null;
    }

    public T data(){
        return this.data;
    }

    public Tree<T> child(int n) {
        try{
            return this.children().get(n);
        }
        catch (IndexOutOfBoundsException e){
            return null;
        }
    }

    private ArrayList<Tree<T>> children(){
        return this.children;
    }

    public int nbChildren(){
        return this.children().size();
    }

    public Tree<T> parent(){
        return this.parent;
    }

    @SafeVarargs
    public final void addChildren(Tree<T>... childs) {
        for (Tree<T> child : childs){
            child.parent = this;
            this.children.add(child);
        }
    }

    /* Attention : la méthode suivante ne peut que modifier un enfant existant */
    public void setChild(int i, Tree<T> child) {
        this.children.set(i, child);
    }



    /* Adapted from VasiliNovikov@StackOverflow */

    private void print(StringBuilder buffer, String prefix, String childrenPrefix) {
        buffer.append(prefix);
        buffer.append(this.data());
        buffer.append('\n');
        for (int i = 0; i < nbChildren(); i++) {
            Tree<T> next = this.child(i);
            if (i < nbChildren() -1) {
                next.print(buffer, childrenPrefix + "├── ", childrenPrefix + "│   ");
            } else {
                next.print(buffer, childrenPrefix + "└── ", childrenPrefix + "    ");
            }
        }
    }

    public String toString() {
        StringBuilder buffer = new StringBuilder(50);
        print(buffer, "", "");
        return buffer.toString();
    }

    public void display() {
        System.out.println(this.toString());
    }

    public int profondeur(){
        int max = 0;
        for(int i = 0; i < this.nbChildren(); i++){
            int val = 1 + this.child(i).profondeur();
            if (max < val) max = val;
        }
        return max;
    }

    public int nbSommet(){
        int somme = 1;
        for(int i = 0; i < this.nbChildren(); i++)
            somme += this.child(i).nbSommet();

        return somme;
    }

    public int maxValue(){
        int max = (int)this.data;

        for (int i = 0; i < this.nbChildren(); i++){
            int val = this.child(i).maxValue();
            if (max < val) max = val;
        }

        return max;
    }

    public boolean creatGitFolder(String folderName){
        boolean found = false;
        if(this.data == folderName){
            this.addChildren((Tree<T>) new Tree<String>(".git"));
            return true;
        }
        if (this.nbChildren() == 0) {
            return false;
        }

        for(int i = 0; i<this.nbChildren(); i++){
            if(this.children.get(i).creatGitFolder(folderName)){
                found = true;
            }
        }

        return found;
    }

    public boolean creatGitFolderWithExeption(String folderName) throws Exception {
        return creatGitFolderWithExeption(folderName, true);
    }

    private boolean creatGitFolderWithExeption(String folderName, boolean firstIteration) throws Exception {
        boolean found = false;
        if(this.data == folderName){
            this.addChildren((Tree<T>) new Tree<String>(".git"));
            return true;
        }
        if (this.nbChildren() == 0) {
            return false;
        }

        for(int i = 0; i<this.nbChildren(); i++){
            if(this.children.get(i).creatGitFolderWithExeption(folderName, false)){
                found = true;
            }
        }
        if(firstIteration && !found){
            throw new Exception("folder not found");
        }

        return found;
    }

    public int minProfondeur() {
        // Si l'arbre est vide (pas de nœud), retourner 0
        if (this == null) {
            return 0;
        }

        // Si un nœud est une feuille (pas d'enfants), retourner 1
        if (nbChildren() == 0) {
            return 1;
        }

        int minProf = Integer.MAX_VALUE; // Initialiser avec une valeur maximale

        // Récursion sur chaque enfant pour trouver la profondeur minimale
        for (int i = 0; i < nbChildren(); i++) {
            int profondeurEnfant = this.child(i).minProfondeur(); // Appel récursif
            minProf = Math.min(minProf, profondeurEnfant); // Mettre à jour la profondeur minimale
        }

        return minProf + 1; // Retourner la profondeur (en ajoutant 1 pour le nœud courant)
    }
}