package banque;

public class CompteEpargne {
	private static int nbComptesEpargne = 0 ;
	Banque saBanque;
	private int numCE;
	private float soldeCE;
	private float tauxInteret;
	private Client Proprio;
	
	
	
	
	public CompteEpargne(float nouveauSolde, float tauxInteret) {
		// Incrementer le compteur d'instances 
		nbComptesEpargne ++ ; 
		
		// Affecter automatiquement un numéro différent à chaque compte créé
		numCE = nbComptesEpargne; 
		
		this.tauxInteret =  tauxInteret;
		setSoldeCE(nouveauSolde); 

	}
	
	
	
	
	
	
	
	
	
	public void crediter(float argentRajouter) {
		
		setSoldeCE(getSoldeCE()+argentRajouter*saBanque.getTauxRemuneration()+argentRajouter*tauxInteret);
	}
	
	public void debiter(float argentEnleve) {
		if(getSoldeCE()-argentEnleve>=0) {
		setSoldeCE(getSoldeCE()-argentEnleve);
		}
		
	}
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//Getters et setters
	
	@Override
	public String toString() {
		return "CompteEpargne [saBanque=" + saBanque + ", numCE=" + numCE + ", soldeCE=" + soldeCE + ", tauxInteret="
				+ tauxInteret + ", Proprio=" + Proprio + "]";
	}









	public Banque getSaBanque() {
		return saBanque;
	}

	public void setSaBanque(Banque saBanque) {
		this.saBanque = saBanque;
	}

	public int getNumCE() {
		return numCE;
	}

	public void setNumCE(int numCE) {
		this.numCE = numCE;
	}

	public float getSoldeCE() {
		return soldeCE;
	}

	public void setSoldeCE(float soldeCE) {
		this.soldeCE = soldeCE;
	}

	public float getTauxInteret() {
		return tauxInteret;
	}

	public void setTauxInteret(float tauxInteret) {
		this.tauxInteret = tauxInteret;
	}

	public Client getProprio() {
		return Proprio;
	}

	public void setProprio(Client proprio) {
		Proprio = proprio;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
