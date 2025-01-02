package banqueAL;

public class TestSalarie {
	public static void main (String args[]) {
		Salarie moi = new Employe(14000);
		moi.verserSalaire();
		
		ClientInterne sanda = new ClientInterne(2500);
		sanda.verserSalaire();
		
		
	}
}
