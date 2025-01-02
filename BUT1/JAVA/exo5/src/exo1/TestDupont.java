package exo1;

public class TestDupont {
	
		  public static void main (String args[]) {

		    // Dupont cree un rectangle 
			  FormeGeometrique rectangle=new Rec(2,5,8,8);
		    // Dupont appelle les methodes developpees par Pasquier 
		    // Il est *oblige* de passer a la methode afficherStats un objet instance d'une classe implementant la classe abstraite FormeGeometrique
		    Editeur ed = new Editeur ();
		    ed.afficherStats(rectangle);
		    
			// Afficher dans la console en appelant la méthode afficher sur cette forme
		    rectangle.afficher();
		    // Changer les coordonnées de la forme en appelant la méthode déplacer
		    rectangle.déplacer(2,2);
			// Afficher dans la console en appelant la méthode afficher sur cette forme
		    rectangle.afficher();
		     // Demander de nouveau d’afficher des statistiques sur cette forme
		    ed.afficherStats(rectangle);                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		    // Idem avec un cercle 
		    FormeGeometrique cercle = new Cercle(3,4,5);
		    Editeur edcercle = new Editeur();
		    ed.afficherStats(cercle);
		    cercle.afficher();
		    cercle.déplacer(7,7);
		    cercle.afficher();
		    edcercle.afficherStats(cercle);
		    
		    
		    
		  }
		

}
