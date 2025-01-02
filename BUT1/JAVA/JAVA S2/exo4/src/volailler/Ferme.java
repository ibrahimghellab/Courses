package volailler;

public class Ferme {

	public static void main(String[] args) {
		// Creer et ajouter quelques animaux
				Elevage laFerme = new Elevage();

				for(int i=0; i<15; i++){
					// Parametre du constructeur de Poulet : poids et identifiant 
					laFerme.ajouter(new Poulet(0.3,150+i));
				}

				for(int i=0; i<15; i++){
					laFerme.ajouter(new Canard(0.3,380+i));
				}

				for (int i=0; i<10; i++){
					laFerme.ajouter(new Poulet(0.250,700+i));
				}   	 
				laFerme.ajouter(new Canard(0.750,825));

				// Changer le poids de quelques animaux
				// 1er paramètre de changePoids : identifiant
				// 2ème paramètre : nouveau poids
				/*for (int i=0; i<8; i++){
					laFerme.changePoids(155+i,(float)1.3);
					laFerme.changePoids(382+i,(float) 1.55);
				}*/

				// Afficher l'etat du volailler
				laFerme.ecrire();
				
				System.out.println("liste des animaux a abattre: ");
				laFerme.afficherBetesAAbattre();
				
				System.out.println("Valeur des animaux a abattre: ");
				System.out.println(laFerme.evaluerBetesAAbattre()); 

				laFerme.envoyerALAbattoir(); // Retourne aussi un tableau avec les betes abattues
				laFerme.ecrire();

				System.out.println("Valeur des animaux a abattre: ");
				System.out.println(laFerme.evaluerBetesAAbattre()); 
				
				System.out.println("liste des animaux a abattre: ");
				laFerme.afficherBetesAAbattre();
				

	}

}
