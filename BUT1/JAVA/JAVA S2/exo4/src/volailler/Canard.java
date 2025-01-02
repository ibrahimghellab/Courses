package volailler;

public class Canard extends Volaille{

	private static float prixKg = (float) 8;
	private static float poidsAbattage=(float) 0.250;
	
	
	
	
	
	
	
	public float getPoidsAbattage() {
		return poidsAbattage;
	}
	public static void setPoidsAbattage(float poidsAbattage) {
		Canard.poidsAbattage = poidsAbattage;
	}
	Canard(double poids, int id){
		super(poids,id);
		setPrixVente();
		
	}
	void setPrixVente() {
		prixVente=(float) (prixKg*poids);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	public static float getPrixKg() {
		return prixKg;
	}
	public static void setPrixKg(float prixKg) {
		Canard.prixKg = prixKg;
	}

}
