package exo7;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class exo1 {

	public static void main(String[] args) {
		JFrame fenetre=new JFrame("Calcul Périmètre");
		
		fenetre.setSize(600,400);
		fenetre.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		fenetre.setVisible(true);
		fenetre.setResizable(false);
		
		
		JPanel txb=new JPanel();
		
		JPanel plongeur=new JPanel();		
		
		JLabel per=new JLabel("Longueur");
		plongeur.add(per);
		
		JTextField tlong=new JTextField(20);
		plongeur.add(tlong);
		
		
		
		JPanel plargeur=new JPanel();
		
		JLabel plo=new JLabel("Largeur");
		
		plargeur.add(plo);
		
		JTextField tlar=new JTextField(20);
		plargeur.add(tlar);
		
		txb.add(plargeur);
		txb.add(plongeur);
		
		
		
		JPanel perimetre=new JPanel();
		
		JLabel perimet=new JLabel("Périmètre : ");
		JLabel valeurp=new JLabel("0");
		
		perimetre.add(perimet);
		perimetre.add(valeurp);
	
		txb.add(perimetre);
		
		fenetre.add(txb);
		
		
		JButton calculer=new JButton("Calculer");
		JButton nettoyer =new JButton("Nettoyer");
		
		perimetre.add(calculer);
		perimetre.add(nettoyer);
				
				
				
				
		fenetre.setVisible(true);
		
	}

}