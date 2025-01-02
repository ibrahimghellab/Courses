package exo2;

public class Vendeur extends Commercial {

	Vendeur(String nom, String prenom, int age, int anneEntre, float CAMensuel) {
		super(nom, prenom, age, anneEntre, CAMensuel);
		// TODO Auto-generated constructor stub
	}

	@Override
	public float calculerSalaire() {
		// TODO Auto-generated method stub
		return (float) (0.8*CAMensuel+200) ;
	}
}
