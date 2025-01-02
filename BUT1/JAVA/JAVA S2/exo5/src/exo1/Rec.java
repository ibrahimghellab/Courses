package exo1;


public class Rec extends FormeGeometrique{

	private float longueur, largeur;
	
	Rec(float longueur, float largeur,int x, int y){
		this.setX(x);
		this.setY(y);
		this.longueur=longueur;
		this.largeur=largeur;
	}
	
	
	float perimetre () {
		
		return 	2*longueur+2*largeur;
	}
	
	
	float surface() {
		return longueur*largeur;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
