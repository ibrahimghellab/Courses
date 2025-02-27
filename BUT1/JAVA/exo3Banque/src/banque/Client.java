package banque;

import java.util.*;

public class Client {

	CompteCourant sonCompteCourant [];
	Banque saBanque;
	private String nomClient;
	private int numClient;
	private String adrClient;
	private int compteurCompteClient=-1;
	
	


	public Client(Banque bClient,String nom,int num, String adr, int nbCompte) {
		setSaBanque(bClient);
		setNomClient(nom);
		setNumClient(num);
		setAdrClient(adr);
		CompteCourant tab[] = new CompteCourant[nbCompte];
		setSonCompteCourant(tab);
		
		
	}
	
	public void ajouterCompte(CompteCourant c) {
		compteurCompteClient++;
		sonCompteCourant[compteurCompteClient]=c;
		c.setSonProprietaire(this);
		
	}

	public void afficherCompte() {
		for(int i=0;i<sonCompteCourant.length;i++) {
			System.out.println(sonCompteCourant[i]);
		}
		
	}
	
	
	
	
	@Override
	public String toString() {
		return "Client [ saBanque=" + saBanque.getNomBanque()
				+ ", nomClient=" + nomClient + ", numClient=" + numClient + ", adrClient=" + adrClient + "]";
	}
	
	

	public int getCompteurCompteClient() {
		return compteurCompteClient;
	}

	public void setCompteurCompteClient(int compteur) {
		this.compteurCompteClient = compteur;
	}
	
	public CompteCourant[] getSonCompteCourant() {
		return sonCompteCourant;
	}

	public void setSonCompteCourant(CompteCourant[] sonCompteCourant) {
		
		this.sonCompteCourant = sonCompteCourant;
	}

	public Banque getSaBanque() {
		return saBanque;
	}

	public void setSaBanque(Banque saBanque) {
		this.saBanque = saBanque;
	}

	public String getNomClient() {
		return nomClient;
	}

	public void setNomClient(String nomClient) {
		this.nomClient = nomClient;
	}

	public int getNumClient() {
		return numClient;
	}

	public void setNumClient(int numClient) {
		this.numClient = numClient;
	}

	public String getAdrClient() {
		return adrClient;
	}

	public void setAdrClient(String adrClient) {
		this.adrClient = adrClient;
	}
	

	public static void main(String[] args) {
	
	}

}