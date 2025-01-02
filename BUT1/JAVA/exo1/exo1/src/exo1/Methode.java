package exo1;

public class Methode {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		char a='a';
		char b='b';
		System.out.println("avant l'appel a = "+a + " et b = "+b);
		echangeetafficheChar(a,b);
		System.out.println("après l'appel a = "+a + " et b = "+b);
		
		float tab[]= {1};
		System.out.println(tab[0]);
		metFloatDansTableau(tab);
		System.out.println(tab[0]);
		
		System.out.println(tab);
		modifierAdresseTableau(tab);
		System.out.println(tab);
		
	
	}

	
	static void echangeetafficheChar(char a, char b) {
		
		char temp;
		temp=a;
		a=b;
		b=temp;
		System.out.println("pendant l'appel a = "+a + " et b = "+b);
	}
	
	static void metFloatDansTableau(float[] f){
		f[0]=150.7f;
		for(int i=0;i<f.length;i++) {
			System.out.println(f[0]);
		}
	}
	
	
	static void modifierAdresseTableau(float[] f) {
		f=null;
		System.out.println(f);
	}
	
}
