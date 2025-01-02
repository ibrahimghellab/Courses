
public class PileStatic {

		
	static int nbValeurs=0;
	static final int NB_MAX=100;
	static  int[] tableau = new int[NB_MAX];
	
	static void empiler(int i) {
		
		
			
			tableau[nbValeurs]=i;
			nbValeurs++;
		
		
		
	}
	
	
	static void afficherSommet() {
		
		System.out.println(tableau[nbValeurs-1]);
	}
	
	static void empiler (int i, int j) {
		empiler(i);
		empiler(j);
	}
	
	static void depiler () {
		
		nbValeurs--;
	}
	
	public static void main(String[] args) {
		
		PileStatic p1 =new PileStatic();
		PileStatic p2 =new PileStatic();
		empiler(5,20);
		depiler();
		afficherSommet();
		

	}

}
