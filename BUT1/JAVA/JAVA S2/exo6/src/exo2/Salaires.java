package exo2;
import java.util.*;

public class Salaires {

	public static void main(String[] args) {
		
		
		ArrayList<EmployeARisque> employéesARisque;
		
		Employe Vinesh = new ManutentionnaireARIsque("Viensh","We",15,2,80);
		System.out.println(Vinesh.calculerSalaire());
		System.out.println(Vinesh.getNom());
		
		Employe e1= new Manutentionnaire("Sansa","Mahatsangy",15,2,80);
		System.out.println(e1.calculerSalaire());
		System.out.println(e1.getNom());
		
		Employe e2 = new Representant("Troles","Thomas",7,6,14000);
		System.out.println(e2.calculerSalaire());
		System.out.println(e2.getNom());
	
	}

}
