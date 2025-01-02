package exo1;
	
import java.util.Scanner;
import java.util.Random;

public class AfficherSaisir {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	
				
				System.out.println("Bonjour");
				
				System.out.printf("%3.3f",Math.PI);
				
				Scanner sc = new Scanner(System.in);
				int n=sc.nextInt();
				System.out.println(n);
				
				Random random=new Random();
				int aleatoire=random.nextInt(n);
				System.out.println(aleatoire);
				
					
					
				
				
			}
			
		

	}

