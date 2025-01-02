package exo2;

public class Manutentionnaire extends Employe {

	Manutentionnaire(String nom, String prenom, int age, int anneEntre,int nbHeures) {
		super(nom, prenom, age, anneEntre);
		nbHeuresMensuel=nbHeures;
		
	}



	private int nbHeuresMensuel;

	
	
	@Override
	public float calculerSalaire() {
		// TODO Auto-generated method stub
		return nbHeuresMensuel*15;
	}
	

}