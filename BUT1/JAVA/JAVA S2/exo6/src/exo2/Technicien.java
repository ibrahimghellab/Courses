package exo2;

public class Technicien extends Employe {

	private int nbUniteVendusParMois;

	Technicien(String nom,String prenom,int age, int anneEntre,int nbUniteVendu){
		super(nom,prenom,age,anneEntre);
		nbUniteVendusParMois=nbUniteVendu;
	}
	@Override
	public float calculerSalaire() {
		// TODO Auto-generated method stub
		return nbUniteVendusParMois*10;
	}

}