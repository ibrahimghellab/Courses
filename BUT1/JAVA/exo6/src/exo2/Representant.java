package exo2;

public class Representant extends Commercial {

	Representant(String nom, String prenom, int age, int anneEntre, float CAMensuel) {
		super(nom, prenom, age, anneEntre, CAMensuel);
		// TODO Auto-generated constructor stub
	}

	@Override
	public float calculerSalaire() {
		// TODO Auto-generated method stub
		return (float) (CAMensuel*0.7+500);
	}
}