package exo2;

public abstract class Commercial extends Employe {

	Commercial(String nom, String prenom, int age, int anneEntre,float CAMensuel) {
		super(nom, prenom, age, anneEntre);
		this.CAMensuel=CAMensuel;
		
	}

	protected float CAMensuel;

}