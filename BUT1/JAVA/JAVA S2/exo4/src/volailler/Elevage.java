package volailler;

import java.util.ArrayList;

public class Elevage {

	ArrayList<Volaille> ele = new ArrayList<Volaille>();



	public void afficherBetesAAbattre() {
		for(int i=0;i<ele.size();i++) {
			if(ele.get(i).poids>=ele.get(i).getPoidsAbattage()) {
				System.out.println(ele.get(i).numIdentification+" "+ele.get(i).poids+" "+ele.get(i).prixVente);
			}
		}
	}

	public float evaluerBetesAAbattre() {
		float prix=0;
		for(int i=0;i<ele.size();i++) {
			if(ele.get(i).poids>=ele.get(i).getPoidsAbattage()) {
				prix+=ele.get(i).prixVente;
			}
		}
		return prix; 
	}


	public void ajouter(Volaille v) {
		ele.add(v);	
	}
	public void ecrire() {
		for(int i=0;i<ele.size();i++) {
			System.out.println(ele.get(i).numIdentification+" "+ele.get(i).poids+" "+ele.get(i).getPoidsAbattage()+" " +ele.get(i).prixVente);
		}
	}

	public void changePoids(int id,float nvPoids) {
		for(Volaille v : ele) {
			if(v.numIdentification==id) {
				v.poids=nvPoids;
			}
		}
	}



	public ArrayList<Volaille> envoyerALAbattoir(){
		ArrayList<Volaille> abattoir = new ArrayList<Volaille>();

		int i=0;
		while( i<ele.size()) {
			if(ele.get(i).poids>=ele.get(i).getPoidsAbattage()) {
				abattoir.add(ele.get(i));
				ele.remove(i);
			}else {
				i++;
			}
		}
		return abattoir;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}


//Il manque les fonction : 

/*
Les constructeurs
 */