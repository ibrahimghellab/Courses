package banqueAL;

/* Un compte d’épargne est représenté par un numéro, un solde, un taux d'intérêt (qui varie selon chaque compte) et une référence vers le client propriétaire de ce compte. Il n’y a pas de découvert autorisé pour les comptes d’épargne. Créez la classe CompteEpargne.  
Dans la méthode créditer, pour chaque versement ajouter le taux d'intérêt appliqué au montant versé. 
Ajoutez la gestion d’un tableau de comptes d’épargne dans la banque. 
Dans le main de Banque, créer quelques comptes d’épargne et les ajouter à la banque.
*/
public class CompteEpargne extends Compte {

	//-----------------------------------------
	// ATTRIBUTS
	//-----------------------------------------

	private static int nbComptesEpargne = 0 ; // Compteur d'instances (Q11)
	

	private double tauxInteret;

	//-----------------------------------------
	// CONSTRUCTEUR 
	//-----------------------------------------
	public CompteEpargne(double nouveauSolde, double tauxInteret) {
		// Incrementer le compteur d'instances 
		nbComptesEpargne ++ ; 
		
		// Affecter automatiquement un numéro différent à chaque compte créé
		numero = nbComptesEpargne; 
		
		this.tauxInteret = tauxInteret;
		setSolde (nouveauSolde); 

	}

	//-----------------------------------------
	// METHODES
	//-----------------------------------------
	void crediter (double montant) {
		solde = solde + montant + montant * Banque.getTauxRemuneration() + montant * tauxInteret;
	}

	// méthode débiter qui vérifie que le solde (- le montant) est supérieur au seuil de découvert autorisé avant de débiter.
	void debiter (double montant) {
		if (solde - montant > 0)
			solde = solde - montant ; 
	}
	
	void afficher () {
		System.out.println ("no = " +  numero + 
							" solde = " + solde);
	}

	//-----------------------------------------
	// ACCESSEURS
	//-----------------------------------------
	public void setSolde(double nouveauSolde) {
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
	public double getTauxInteret() {
		return tauxInteret;
	}

	public void setTauxInteret(double tauxInteret) {
		this.tauxInteret = tauxInteret;
	}

	public static int getNbComptesEpargne() {
		return nbComptesEpargne;
	}
}