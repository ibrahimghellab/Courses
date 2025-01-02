package banqueAL;

import java.util.ArrayList;

public class Banque {

	//-----------------------------------------
	// ATTRIBUTS
	//-----------------------------------------
	final static int NB_MAX_COMPTES = 1000 ; 
	final static int NB_MAX_CLIENTS = 1000 ; 
	
	private static double tauxRemuneration = 0.01 ; // Q12
	
	private String nom;
	
	// Q15 
	// Dupliquez votre package banque en un package banqueAL. Nous allons maintenant changer l’implémentation (les déclarations d’attributs et les instructions du corps des méthodes) de la classe Banque sans en changer l’interface (les entêtes des méthodes). => Remplacez les tableaux par des instances de la classe ArrayList (http://docs.oracle.com/javase/7/docs/api/index.html)
	// private CompteCourant[] sesComptesCourants;
	// private int nbComptesCourants ;
	private ArrayList<CompteCourant> sesComptesCourants;
	
	private Client[] sesClients;
	private int nbClients ;

	// Q13
	private CompteEpargne[] sesComptesEpargne;
	private int nbComptesEpargne ;

	//-----------------------------------------
	// CONSTRUCTEUR 
	//-----------------------------------------
	public Banque(String nom) {
		// Q15
		sesComptesCourants = new ArrayList<CompteCourant>();
		
		sesClients = new Client[NB_MAX_CLIENTS];
		this.nom = nom ; 
		
		// Q13
		sesComptesEpargne = new CompteEpargne[NB_MAX_COMPTES];
	}

	//-----------------------------------------
	// METHODES
	//-----------------------------------------
	public void ajouterClient(Client client) {
		sesClients[nbClients] = client ;
		nbClients++ ;

		// (on en profitera pour mémoriser que le propriétaire de ce compte est justement ce client!)
		client.setSaBanque(this);
	}

	//-----------------------------------------
	public void ajouterCompteCourant(CompteCourant compte) {
		// Q15
		sesComptesCourants.add(compte) ;

		// (on en profitera pour mémoriser que le propriétaire de ce compte est justement ce client!)
		compte.setSaBanque(this);
	}

	//-----------------------------------------
	public void ajouterCompteEpargne(CompteEpargne compte) {
		sesComptesEpargne[nbComptesEpargne] = compte ;
		nbComptesEpargne++ ;
		
		// (on en profitera pour mémoriser que le propriétaire de ce compte est justement ce client!)
		compte.setSaBanque(this);
	}

	//-----------------------------------------
	// Q8 : Ecrire une méthode qui parcourt tous les comptes d’une banque et affiche les informations sur chaque compte. Est-ce mieux d’écrire une méthode de classe (static) ou une méthode d’objet ? ………une méthode d’objet qu’on appellera sur un objet de type Banque
	void afficher () {
		
		// Pour chaque compte courant de cette banque
		// Q15 
		System.out.println ("\t Comptes courants:" );
		for (CompteCourant compte : sesComptesCourants)
			// Afficher ce compte (on délègue cela à la classe CompteCourant!)
			compte.afficher ();

		// Pour chaque compte epargne de ce client
		System.out.println ("\n\t Comptes epargne:" );
		for (int i = 0 ; i < nbComptesEpargne ; i++ )
			// Afficher ce compte (on délègue cela à la classe CompteEpargne!)
			sesComptesEpargne[i].afficher ();
	}
	
	//-----------------------------------------
	// Q9 : Ecrire les méthodes qui permettent d’afficher les informations sur tous les comptes d’un client spécifié par son nom (on supposera pour simplifier qu’il n’y a pas d’homonymes) : numéro du compte et solde.
	void afficherComptesClientNom (String nomClient) {
		// Chercher le client qui a ce nom
		for (int i = 0 ; i < nbClients ; i++ )
			
			// Si c'est ce client le client qu'on recherche
			if (sesClients[i].getNom().equals(nomClient)) // "==" rend vrai seulement si les chaines sont à la meme adresse ! 

				// Afficher tous les comptes de ce client
				sesClients[i].afficher();
	}
	
	//-----------------------------------------
	// Q10 : Ecrire une méthode qui, à partir d’un numéro de compte, affiche toutes les informations sur le propriétaire de ce compte.  
	void afficherProprietaireCompteNumero (int numeroCompte) {
		// Chercher le compte qui a ce numéro
		// Pour chaque compte de cette banque
		for (CompteCourant compte : sesComptesCourants)
			
			// Si c'est ce compte que l'on cherche
			if (compte.getNumero() == numeroCompte)
		
				// Afficher le proprietaire de ce compte
				compte.getProprietaire().afficher();
	}
	
	//-----------------------------------------
	public static void main (String args []) {

		// déclarez et crééz quelques instances des classes Client et CompteCourant. 
		// Initialisez les attributs de ces comptes et de ces clients à l’aide de leurs constructeurs. 
		Client clientDurand = new Client (1, "Durand", "Orsay");
		Client clientDupont = new Client (2, "Dupont", "Velizy");

		CompteCourant cpt1Durand = new CompteCourant (0, 100);
		CompteCourant cpt2Durand = new CompteCourant (100, 0);
		CompteCourant cpt1Dupont = new CompteCourant (1000, 500);

		// Ajouter les comptes aux clients
		clientDurand.ajouterCompteCourant(cpt1Durand);
		clientDurand.ajouterCompteCourant(cpt2Durand);
		clientDupont.ajouterCompteCourant(cpt1Dupont);

		// Q5 : Dans le main() de la classe Banque, essayez de modifier le solde de ces comptes en accédant directement à leurs attributs. 
		//cpt1Durand.solde = 2000 ; 
		// Est-ce possible ? NON
		// Si ce n’est pas possible : Est-ce une erreur de compilation ou d’exécution ?  COMPILATION
		// Quel est le message d’erreur ? "The field CompteCourant.solde is not visible"
		// => Il faut passer par la méthode setSolde qui peut faire des vérifications
		cpt1Durand.setSolde (2000) ; 
			
		// Q7 : Dans la méthode main () de Banque, créez deux banques, des comptes que vous ajoutez à l’une ou l’autre banque.
		Banque CL = new Banque ("CL");
		CL.ajouterClient(clientDurand);
		CL.ajouterCompteCourant(cpt1Durand);
		CL.ajouterCompteCourant(cpt2Durand);

		Banque BNP = new Banque ("BNP");
		BNP.ajouterClient(clientDupont);
		BNP.ajouterCompteCourant(cpt1Dupont);
		
		// Q12
		cpt1Dupont.afficher();
		cpt1Dupont.crediter(1000);
		cpt1Dupont.afficher();
		setTauxRemuneration(.02);
		cpt1Dupont.crediter(1000);
		cpt1Dupont.afficher();
		
		// Q13
		System.out.println ("Comptes epargnes :");
		CompteEpargne cpt3Dupont = new CompteEpargne (0, .01);
		clientDupont.ajouterCompteEpargne(cpt3Dupont);
		BNP.ajouterCompteEpargne(cpt3Dupont);
		cpt3Dupont.afficher();
		cpt3Dupont.crediter(1000);
		cpt3Dupont.afficher();
		
		// Q14
		// Test de la méthode toString() sur un compte courant
		System.out.println (cpt1Dupont);
	}
	
	//-----------------------------------------
	// ACCESSEURS
	//-----------------------------------------
	public static double getTauxRemuneration() {
		return tauxRemuneration;
	}

	public static void setTauxRemuneration(double tauxRemuneration) {
		Banque.tauxRemuneration = tauxRemuneration;
	}

}