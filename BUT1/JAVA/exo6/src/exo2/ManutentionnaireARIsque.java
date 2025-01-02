package exo2;

public class ManutentionnaireARIsque extends Manutentionnaire implements EmployeARisque{
	
	
	
	public ManutentionnaireARIsque(String nom, String prenom, int age, int anneEntre,int nbHeures){
		super(nom, prenom, age, anneEntre,nbHeures);
	}
	
	public float calculerSalaire() {
		return super.calculerSalaire()+primeMensuelleFixe;
		
	}
	
	
}
