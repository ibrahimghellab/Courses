public class Server {

    private static class position{
        int x;
        int y;

        public position(int x, int y){
            this.x = x; this.y = y;
        }
    }

    private static class server{
        position pos;
        int capacite;

        public server(position pos, int capacite){
            this.pos = pos; this.capacite = capacite;
        }
    }

    public static List<Integer> assign(server S1, server S2, List<position> utilisateurs){
        /* A vous de jouer ! */
        return new List<>(1,2,1,1,2);
    }

    public static void main(String... args){
        server S1 = new server(new position(0,0), 25);
        server S2 = new server(new position(10,10), 25);
        List<position> utilisateurs = null;
        for (int i = 0; i < 50; i++){
            position pos = new position(-10 + (int)(31*Math.random()), -10 + (int)(31*Math.random()));
            if (i == 0){
                utilisateurs = new List<>(pos);
            } else {
                utilisateurs.add(0, pos);
            }
        }
        List<Integer> result = assign (S1, S2, utilisateurs);
        for (int i = 0; i<result.length(); i++){
            System.out.printf("User %d (position %d %d), go to server %d.\n", i, utilisateurs.get(i).x, utilisateurs.get(i).y, result.get(i));
        }
    }

}