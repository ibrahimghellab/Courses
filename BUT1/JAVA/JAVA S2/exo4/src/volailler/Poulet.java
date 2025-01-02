package volailler;

public class Poulet extends Volaille{

	private static float prixKg = (float) 1.5;
	private static float poidsAbattage=(float) 0.250;
	
	
	
	
	
	
	Poulet(double poids, int id){
			super(poids,id);
			setPrixVente();
			
	}
	
	public float getPoidsAbattage() {
		return poidsAbattage;
	}

	public static void setPoidsAbattage(float poidsAbattage) {
		Poulet.poidsAbattage = poidsAbattage;
	}

	void setPrixVente() {
		prixVente=(float) (prixKg*poids);
	}
	
	public static float getPrixKg() {
		return prixKg;
	}

	public static void setPrixKg(float prixKg) {
		Poulet.prixKg = prixKg;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	}

}
