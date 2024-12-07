import java.util.ArrayList;
import java.util.Objects;

public class HashTable {


    private int size;
    private String[] list;

    public HashTable(int size) {
        this.size = size;
        this.list = new String[size];
    }

    public int hash(String key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++) {
            hash += key.charAt(i);
        }
        return hash % size;
    }

    public void insert(String key) {
        int cpt = hash(key);

        while (list[cpt] != null) {
            cpt++;
            if (cpt == size) {
                System.out.println("Plus de place");
                return;
            }
        }
        list[cpt] = key;
    }

    public boolean check(String key) {
        int cpt = hash(key);

        while (list[cpt] != null) {
            if (Objects.equals(list[cpt], key)) {
                return true;
            }
            cpt++;
            if (cpt == size) {
                break;
            }
        }
        return false;
    }

    public void remove(String key) {
        int cpt = hash(key);
        while (list[cpt] != null) {
            if (Objects.equals(list[cpt], key)) {
                list[cpt] = null;
                System.out.println(key + " supprimé");
                return;
            }
            cpt++;
            if (cpt == size) {
                break;
            }
        }
        System.out.println("Key '" + key + "' not found.");
    }
    public static void main (String... args){
        HashTable T = new HashTable(100);
        T.insert("Osman");
        T.insert("Osman");
        System.out.println(T.check("Osman"));
        System.out.println(T.check("Namso"));

        T.remove("Osman");
        System.out.println(T.check("Osman"));


            T.insert("Hellol"); T.insert("World");
            System.out.printf("Test insert / check : vous renvoyez %b (true attendu) %b (false attendu) %b (false attendu) \n", T.check("Hello"), T.check("Wrold"), T.check("test"));
            T.insert("Wolrd"); T.insert("Hello");
            System.out.printf("Test insert / check avec collision : vous renvoyez %b (true attendu) %b (true attendu) %b (false attendu) \n", T.check("World"), T.check("Wolrd"), T.check("Wrold"));
            T.insert("test"); T.remove("Wolrd");T.remove("Wolrd"); T.remove("Uh ?"); T.remove("Hello"); T.remove("test"); T.insert("Wolrd");
            System.out.printf("Test remove / check avec collision : vous renvoyez %b (false attendu) %b (true attendu) %b (false attendu) \n", T.check("test"), T.check("Wolrd"), T.check("Hello"));



    }

}
