package banqueAL;

public class CompteCourant extends Compte {

	//-----------------------------------------
	// ATTRIBUTS
	//-----------------------------------------
	private static final double SEUIL_SECURITE = 1000;
	
	private static int nbCompteCourants = 0 ; // Compteur d'instances (Q11)
	
	
	private double seuiDecouvertAutorise; // nombre positif

	//-----------------------------------------
	// CONSTRUCTEUR 
	//-----------------------------------------
	// Q2 Définir un constructeur public CompteCourant  avec paramètres (un des paramètres aura le même nom qu’un des attributs) 
	public CompteCourant(double nouveauSolde, double seuiDecouvertAutorise) {
		// Incrementer le compteur d'instances 
		nbCompteCourants ++ ; 
		
		// Affecter automatiquement un numéro différent à chaque compte créé
		numero = nbCompteCourants; 
		
		this.seuiDecouvertAutorise = seuiDecouvertAutorise;
		setSolde (nouveauSolde); 
	}

	//-----------------------------------------
	// METHODES
	//-----------------------------------------
	void crediter (double montant) {
		solde = solde + montant + montant * Banque.getTauxRemuneration();
	}

	// méthode débiter qui vérifie que le solde (- le montant) est supérieur au seuil de découvert autorisé avant de débiter.
	void debiter (double montant) {
		if (solde - montant > -seuiDecouvertAutorise)
			solde = solde - montant ; 
	}
	
	void afficher () {
		System.out.println ("no = " +  numero + "solde = " + solde);
	}
	
	// Q14 Prévoir dans chacune de ces classes une méthode toString() :
	// Méthode retournant une chaîne de caractères décrivant la valeur des attributs de cet objet
	public String toString () {
		return "Compte Courant : no = " +  numero + ", solde = " + solde;
	}

	//-----------------------------------------
	// ACCESSEURS
	//-----------------------------------------
	// Q3 : Ajouter un test dans le setter de l’attribut solde : 
	// si on essaye d’y mettre une nouvelle valeur qui est supérieure à une 
	// constante static final SEUIL_SECURITE (que vous fixerez à 1000), 
	// afficher un message « ATTENTION tentative d’affectation suspecte d’un nouveau solde : compte no … » et ne modifiez alors pas cet attribut. 
	public void setSolde(double nouveauSolde) {
		if (nouveauSolde > SEUIL_SECURITE)
			System.out.println ("ATTENTION tentative d’affectation suspecte d’un nouveau solde : compte no" + numero + " - tentative nouveau solde = "+ nouveauSolde);
		else 
			solde = nouveauSolde ; 
	}
	
	public Banque getSaBanque() {

		return saBanque;
	}
	public void setSaBanque(Banque saBanque) {
		this.saBanque = saBanque;
	}
	public Client getProprietaire() {
		return sonProprietaire;
	}
	public void setProprietaire(Client proprietaire) {
		this.sonProprietaire = proprietaire;
	}
	public int getNumero() {
		return numero;
	}
	public void setNumero(int numero) {
		this.numero = numero;
	}
	public double getSolde() {
		return solde;
	}


	public double getSeuiDecouvertAutorise() {
		return seuiDecouvertAutorise;
	}
	public void setSeuiDecouvertAutorise(double seuiDecouvertAutorise) {
		this.seuiDecouvertAutorise = seuiDecouvertAutorise;
	}

}