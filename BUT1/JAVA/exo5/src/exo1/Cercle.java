package exo1;

public class Cercle extends FormeGeometrique {

	private float rayon;

	
	Cercle(float rayon,int x, int y){
		this.setX(x);
		this.setY(y);
		this.rayon=rayon;
	}
	
	
	float perimetre () {

		return 	(float) (2*Math.PI*rayon);
	}


	float surface() {
		return (float) (Math.PI*Math.pow(rayon,2));
	}

}
