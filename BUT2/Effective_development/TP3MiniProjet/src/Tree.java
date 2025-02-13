import java.util.ArrayList;
import java.util.Collections;


public class Tree<T> implements TreeI<T>{

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
        if (this.nbChildren()!=0) {
            ArrayList<Integer> prof = new ArrayList<Integer>(this.nbChildren());
             for (int i = 0; i < nbChildren(); i++) {
                    prof.add(children.get(i).profondeur());
                }
             return Collections.max(prof) + 1;
        }
        return 0;
    }

    public int nbSommets(){
        int nb=1;
        if(this.nbChildren()!=0) {
            for (int i = 0; i < nbChildren(); i++) {
               nb += this.children.get(i).nbSommets();
            }
        }
          return nb;
    }

    public int maxValue(){
        int max=(int)this.data;
        if(this.nbChildren()!=0) {
            for (int i = 0; i < nbChildren(); i++) {
               max=Math.max(max,children.get(i).maxValue());
            }
        }
        return max;
    }




    public static void main(String[] args) {

        Tree<Integer> t=new Tree<Integer>(1,new Tree<>(5,new Tree<>(10,new Tree<>(15,new Tree<>(10)))),new Tree<>(5));

        System.out.println(t);
        System.out.println(t.profondeur());
        System.out.println(t.nbSommets());
        System.out.println(t.maxValue());
    }

}