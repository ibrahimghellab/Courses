package banqueAL;

/* a) Complétez la classe Client générée depuis le diagramme des classes de Visual Paradigm. 
 * Ajouter un constructeur allouant le tableau de comptes de ce client 
 * et une méthode ajoutant un compte à ce client 
 * (on en profitera pour mémoriser que le propriétaire de ce compte est justement ce client!).
 * 
 */
public class Client {

	//-----------------------------------------
	// ATTRIBUTS
	//-----------------------------------------
	final static int NB_MAX_COMPTES = 10 ; 
	private Banque saBanque;

	private CompteCourant[] sesComptesCourants;
	private int nbComptesCourant ;
	
	// Q13
	private CompteEpargne[] sesComptesEpargne;
	private int nbComptesEpargne ;
	
	private int numero;
	private String nom;
	private String adresse;

	//-----------------------------------------
	// CONSTRUCTEUR 
	//-----------------------------------------
	public Client(int numero, String nom, String adresse) {
		this.numero = numero;
		this.nom = nom;
		this.adresse = adresse;
		sesComptesCourants = new CompteCourant[NB_MAX_COMPTES];
		sesComptesEpargne = new CompteEpargne[NB_MAX_COMPTES];
	}

	//-----------------------------------------
	// METHODES
	//-----------------------------------------
	public void ajouterCompteCourant(CompteCourant compte) {
		sesComptesCourants[nbComptesCourant] = compte ;
		nbComptesCourant++ ;
		
		// (on en profitera pour mémoriser que le propriétaire de ce compte est justement ce client!)
		compte.setProprietaire(this);
	}
	
	public void ajouterCompteEpargne(CompteEpargne compte) {
		sesComptesEpargne[nbComptesEpargne] = compte ;
		nbComptesEpargne++ ;
		
		// (on en profitera pour mémoriser que le propriétaire de ce compte est justement ce client!)
		compte.setProprietaire(this);
	}
	
	//-----------------------------------------
	public void afficher() {
		System.out.println ("Client : nom = " + nom );
		
		// Pour chaque compte courant de ce client
		System.out.println ("\t Comptes courants:" );
		for (int i = 0 ; i < nbComptesCourant ; i++ )
			// Afficher ce compte (on délègue cela à la classe CompteCourant!)
			sesComptesCourants[i].afficher ();

		// Pour chaque compte epargne de ce client
		System.out.println ("\n\t Comptes epargne:" );
		for (int i = 0 ; i < nbComptesEpargne ; i++ )
			// Afficher ce compte (on délègue cela à la classe CompteEpargne!)
			sesComptesEpargne[i].afficher ();
	}
	
	//-----------------------------------------
	// ACCESSEURS
	//-----------------------------------------
	public int getNumero() {
		return numero;
	}
	public void setNumero(int numero) {
		this.numero = numero;
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public String getAdresse() {
		return adresse;
	}
	public void setAdresse(String adresse) {
		this.adresse = adresse;
	}
	public int getNbComptes() {
		return nbComptesCourant;
	}
	public void setSaBanque(Banque banque) {
		this.saBanque = banque ;
	}
}