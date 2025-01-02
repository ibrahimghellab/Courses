package banqueAL;


public abstract class Compte {

	protected Banque saBanque;
	protected Client sonProprietaire;
	protected int numero;
	protected double solde;
	
	
	abstract void debiter(double montant);
	abstract void crediter(double montant);
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
	}

}
