package exo3;

import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;

public class PanelListesOuvrage extends JPanel{

	JList JLSListeOuvrage;
	JLabel listeOuvrages;
	String ouvrages[]= {"Au guet !","La Huitieme Couleur","Le Dernier Restaurant avant la fin du monde","Le guide du voyageur galactique","Mortimer","Sandman : Préludes et Nocturnes"};
	
	public PanelListesOuvrage() {
		JLSListeOuvrage = new JList(ouvrages);
		listeOuvrages=new JLabel("Listes ouvrages : ");
		add(listeOuvrages);
		add(JLSListeOuvrage);
	}
	
}