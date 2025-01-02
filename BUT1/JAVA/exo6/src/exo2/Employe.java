package exo2;

public abstract class Employe {

	protected String nomEmploye;
	protected String prenomEmploye;
	protected int ageEmploye;
	protected int anneEntreEntreprise;

	Employe(String nom,String prenom,int age,int anneEntre){
		nomEmploye=nom;
		prenomEmploye=prenom;
		age=ageEmploye;
		anneEntre=anneEntreEntreprise;
	}
	
	public String getNom() {
		
		
		return   "L'employé "+nomEmploye+" "+prenomEmploye;
	}

	public abstract float calculerSalaire();

}





