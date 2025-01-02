
public class PileObjet {

	static final int NB_MAX=100;
	int nbValeurs=0;
	 int[] tableau = new int[NB_MAX]; 
	
	 
	 void empiler(int i) {
			
			
			
			tableau[nbValeurs]=i;
			nbValeurs++;
		
		
		
	}
	 void afficherSommet() {
			
			System.out.println(tableau[nbValeurs-1]);
		}
	 
	 void empiler (int i, int j) {
			empiler(i);
			empiler(j);
		}
	 
	 void depiler () {
			nbValeurs--;
		}
	 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		PileObjet Ibrahim =new PileObjet();
		PileStatic p1 =new PileStatic();
		PileStatic p2 =new PileStatic();
		p1.empiler(5,20);
		p1.afficherSommet();

	}

}
