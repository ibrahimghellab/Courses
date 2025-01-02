package salarie;

public abstract class Employe {

	private String nomEmploye;
	private String prenomEmploye;
	private int ageEmploye;
	private int anneEntreEntreprise;

	public String getNom() {
		// TODO - implement Employe.getNom
		throw new UnsupportedOperationException();
	}

	public abstract float calculerSalaire();

}