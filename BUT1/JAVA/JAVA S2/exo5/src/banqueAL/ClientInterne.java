package banqueAL;



public class ClientInterne extends Salarie{
	private Compte compte=new CompteCourant(0, 500);
	
	ClientInterne(float salaire){
		super(salaire);
	}
	
	void verserSalaire() {
		compte.crediter(getSalaire());
	}
}
