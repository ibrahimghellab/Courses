package banqueAL;

public abstract class Salarie {

	private float salaire;


	
	Salarie(float salaire){
		this.salaire=salaire;
	}

	public float getSalaire() {
		return salaire;
	}
	
	abstract void verserSalaire();
	
	}
