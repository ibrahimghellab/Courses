package banque;

import java.util.Arrays;

public class Banque {

	private Client sesClients[];
	private CompteCourant sesComptesCourants[];
	private CompteEpargne sesComptesEpargnes[];
	private String nomBanque;
	private int compteurCompteCourant=0;
	private int compteurClient=0;
	final static int NB_MAX_COMPTES = 1000 ; 
	final static int NB_MAX_CLIENTS = 1000 ; 
	static private  float tauxRemuneration=2;
	
	
	
	
	
	


	public Banque(String nom) {
		sesComptesCourants = new CompteCourant[NB_MAX_COMPTES];
		sesComptesEpargnes = new CompteEpargne[NB_MAX_COMPTES];
		sesClients = new Client[NB_MAX_CLIENTS];
		this.nomBanque = nom ; 
	}

	public static void main(String[] args) {
		Banque LCL =new Banque("LCL");
		Banque SG =new Banque("SG");
		Client Thomas= new Client(LCL,"Thomas",1,"Orsay",2);
		Client Ibrahim=new Client(SG,"Ibrahim",2,"Morsang",5);
		Client Sanda=new Client(LCL,"Sanda",3,"Orsay",1);
		CompteCourant compte1=new CompteCourant(1000 , 500);
		CompteCourant compte2=new CompteCourant(700 , 100);
		CompteCourant compte3=new CompteCourant(50 , 0);
		CompteCourant compte4=new CompteCourant(1000 , 44000);
		CompteCourant compte5=new CompteCourant(780 , 200);
		
		CompteEpargne compteE1=new CompteEpargne(500,5);
		CompteEpargne compteE2=new CompteEpargne(400,2);
		CompteEpargne compteE3=new CompteEpargne(1500,20);
		
		System.out.println(compteE1);
		
		
		//LCL.toString();
		Ibrahim.ajouterCompte(compte1);
		Thomas.ajouterCompte(compte2);
		Sanda.ajouterCompte(compte3);
		Ibrahim.ajouterCompte(compte4);
		Thomas.ajouterCompte(compte5);
		LCL.ajouterClient(Sanda);
		SG.ajouterClient(Ibrahim);
		SG.ajouterCompte(compte4);
		
		
		LCL.ajouterCompte(compte3);
		LCL.afficherPropriétaire(3);
		
		
		
	/*	System.out.println(Thomas);
		
		System.out.println(Sanda);
		
		System.out.println(compte1);
		
		System.out.println(LCL);*/
		
		//SG.afficherInfosCompteClient("Ibrahim");
		
		compte1.crediter(100);
		
	}
	
	public int getCompteurCompteCourant() {
		return compteurCompteCourant;
	}

	public void setCompteurCompteCourant(int compteurCompteCourant) {
		this.compteurCompteCourant = compteurCompteCourant;
	}

	public int getCompteurClient() {
		return compteurClient;
	}

	public void setCompteurClient(int compteurClient) {
		this.compteurClient = compteurClient;
	}

	public void ajouterCompte(CompteCourant c) {
		
		sesComptesCourants[compteurCompteCourant]=c;
		compteurCompteCourant++;
	}
	
	public void ajouterClient(Client C) {
		
		sesClients[compteurClient]=C;
		compteurClient++;
	}

	
	@Override
	public String toString() {
		return "Banque [sesClients=" + Arrays.toString(sesClients) + ", sesComptesCourants="
				+ Arrays.toString(sesComptesCourants) + ", nomBanque=" + nomBanque + "]";
	}


	public String getNomBanque() {
		return nomBanque;
	}


	public void setNomBanque(String nomBanque) {
		this.nomBanque = nomBanque;
	}
	
	
	public void afficherInfosCompteClient(String nomClient) {
	
		
		for(int i=0;i<compteurClient;i++){
			if((sesClients[i].getNomClient()).equals(nomClient)) {
				sesClients[i].afficherCompte();
				
			}
		}
	}
	
	public void afficherPropriétaire(int numC) {
		for(int i=0;i<compteurClient;i++) {
			if(sesComptesCourants[i].getNumCC()==numC) {
				System.out.println(sesComptesCourants[i].getSonProprietaire());
			}
		}
	}
	
	public static float getTauxRemuneration() {
		return tauxRemuneration;
	}

	public static void setTauxRemuneration(float tauxRemuneration) {
		Banque.tauxRemuneration = tauxRemuneration;
	}
	
}






