import java.util.Arrays;

public class List<T> extends BTree<T> implements ListI<T> {

    private T data;
    private List<T> tail;
    private List<T> parent;

    @SafeVarargs
    public List(T head, T... data) {
        this.data = head;
        if (data.length == 0){
            this.tail = null;
        }
        else{
            this.tail = new List<T>(data[0], Arrays.copyOfRange(data, 1, data.length));
            this.parent = null;
            this.tail.parent = this;
        }
    }

    public T data(){
        return this.data;
    }

    public List<T> tail(){
        return this.tail;
    }

    public int length(){
        if (this.tail() == null){return 1;}
        return 1+ this.tail().length();
    }

    public List<T> parent(){
        return this.parent;
    }

    public void setTail(List<T> l){
        this.tail = l;
    }

    public String toString(){
        if (this.tail == null){
            return this.data().toString();
        }
        else{
            return this.data().toString() + ";" + this.tail().toString();
        }
    }

    public void display(){
        System.out.println(this.toString());
    }
    /* Pour la compatibilité avec BTree<T> */

    public List<T> left(){
        return this.tail();
    }

    public List<T> right(){
        return null;
    }

    public void setLeft(List<T> child){
        setTail(child);
    }

    public List<T> child(int i){
        if (i == 0) return this.tail();
        else return null;
    }

    public int nbChildren(){
        if (this.tail() == null) return 0;
        else return 1;
    }

    @SafeVarargs
    public final void addChildren(List<T>... childs){
        if (childs.length == 0) System.out.print("bla");
        this.setTail(childs[0]);
    }

    public void setChild(int i, List<T> child){
        if (i==0) setTail(child);
        else throw new IndexOutOfBoundsException();
    }

    List<T> addFirstElement(T val){

        List<T> tmp=new List<>(val);
        tmp.setTail(this);

        return tmp;
    }

    void addLastElement(T val){
        List<T> tmp=new List<>(val);
        if(this.tail==null){
            this.tail=tmp;
        }else {
            this.tail().addLastElement(val);
        }
    }

   public boolean isSorted(){
        boolean sorted=true;

        for(int i=0;i<length();i++) {
            if (this.tail != null) {
                if ((int) data > (int) tail.data) {
                    sorted = false;
                }
            }
        }
        if(this.tail!=null){
            return sorted && tail.isSorted();
        }else{
            return sorted ;
        }


    }

    public static List<Integer> addSortedValue(List<Integer> l,Integer val){
        List<Integer> tmp=new List<>(val);
        if(l.tail == null){
            l.tail=tmp;
            return l;
        }
        if (val <= l.data){

            tmp.setTail(l);;
            l=tmp;
            return l;
        }
        l.tail = addSortedValue(l.tail,val);
        return l;
    }

    public List<T> sort() {

        if (this.tail == null) {
            return this;
        }


        this.tail = this.tail.sort();


        if (this.tail != null && (Integer) this.tail.data < (Integer) this.data) {
            T temp = this.data;
            this.data = this.tail.data;
            this.tail.data = temp;


            this.tail = this.tail.sort();
        }

        return this;
    }

    public List<T> reverse() {
        List<T> previous = null;
        List<T> current = this;
        List<T> next;

        // Inversion des liens
        while (current != null) {
            next = current.tail;  // Sauvegarde de l'élément suivant
            current.tail = previous;  // Inverse le lien
            previous = current;  // Avance previous
            current = next;  // Avance current
        }

        return previous;  // "previous" devient le nouveau premier élément de la liste
    }



    public static void main(String[] args){



        List<Integer> l=new List<Integer>(4,5,5,7,8,9,10);
        l=addSortedValue(l,5);
        l.display();

    }

}