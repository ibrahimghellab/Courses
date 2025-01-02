package exo7;

import java.awt.Frame;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class PanelPerimetre extends JPanel{
	JLabel longe;
	JLabel largeu;
	JLabel resultatTitle;
	JLabel resulatValue;
	
	JTextField longueur;
	JTextField largeur;
	
	JButton calculer;
	JButton effacer;
	
	public PanelPerimetre() {
		
		longe=new JLabel("Longueur");
		largeu=new JLabel("Largeur");
		resultatTitle=new JLabel("Résultat : ");
		resulatValue=new JLabel("0");
		longueur=new JTextField(20);
		largeur=new JTextField(20);
		calculer=new JButton("Calculer");
		effacer=new JButton("Supprimer");
		
		add(longe);
		add(longueur);
		add(largeu);
		add(largeur);
		add(resultatTitle);
		add(resulatValue);
		add(calculer);
		add(effacer);
		
	}
	
	public static void main(String[] args) {
		
		JFrame fenetre=new JFrame("Perimètre");
		
		PanelPerimetre p=new PanelPerimetre();
		fenetre.setSize(600,200);
		fenetre.add(p);
		fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		fenetre.setVisible(true);
		
	
	}
	
	
	
	
	
	
	
}
