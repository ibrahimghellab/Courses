package exo3;

import java.awt.Button;

import javax.swing.JButton;
import javax.swing.JPanel;

public class PanelButton extends JPanel{

	JButton BTNEmprunt;
	JButton BTNRetour;
	
	public PanelButton() {
		BTNEmprunt=new JButton("Emprunt");
		BTNRetour=new JButton("Retour");
		add(BTNEmprunt);
		add(BTNRetour);
	}
	
}
