package exo3;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;

import javax.swing.BorderFactory;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class MainBibiotheque {

	public static void main(String[] args) {
		JFrame fenetre=new JFrame("Bibliothèque");

		PanelButton pb=new PanelButton();
		PanelInfos pi=new PanelInfos();
		PanelListesOuvrage pl =new PanelListesOuvrage();
		
		JPanel panelLeft=new JPanel();
		JPanel panelRight=new JPanel();
		panelLeft.setLayout(new BorderLayout());
		panelLeft.add(pl,BorderLayout.NORTH);
		panelLeft.add(pb,BorderLayout.CENTER);
		panelRight.add(pi);
		
		fenetre.setLayout(new GridLayout(1,2));
		
		fenetre.add(panelLeft);
		fenetre.add(panelRight);
		
		
        fenetre.getRootPane().setBorder(BorderFactory.createMatteBorder(4, 4, 4, 4, Color.cyan));
		
		fenetre.setSize(1080,1600);
		fenetre.setVisible(true);
	}





}