package exo2;

public class VendeurARisque extends Vendeur implements EmployeARisque{

	VendeurARisque(String nom, String prenom, int age, int anneEntre, float CAMensuel){
		super(nom,prenom,age,anneEntre,CAMensuel);
	}
	
	public float calculerSalaire() {
		return super.calculerSalaire()+primeMensuelleFixe;
	}
}
