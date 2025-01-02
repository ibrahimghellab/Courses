package banqueAL;
import java.awt.* ; 

public class Employe extends Salarie{
	
	Employe(float salaire){
		super(salaire);
	}
	void verserSalaire(){
		Frame frame = new Frame("Cheque ");
		 Label labelNom ;
		 labelNom=new Label("Versement de salaire sur compte externe +"+this.getSalaire());
		 frame.add(labelNom);
		 frame.setSize (800, 500);
		 frame.setVisible (true);
		 
	}
}
