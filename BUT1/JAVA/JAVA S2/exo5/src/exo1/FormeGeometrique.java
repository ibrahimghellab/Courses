package exo1;


public abstract class FormeGeometrique {
	private int x;
	private int y;
	
	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	public void déplacer(int newX, int newY) {
		setX(newX);
		setY(newY);
	}
	
	public void afficher() {
		System.out.println("x : " +getX());
		System.out.println("y : " +getY());
	}
	
	abstract float perimetre();
	abstract float surface();

}