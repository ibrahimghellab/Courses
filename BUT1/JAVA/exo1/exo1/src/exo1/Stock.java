package exo1;

public class Stock {
	


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		final int NB_ARTICLES=3;
		char[] codearticles= {'A','B','C'};
		double[] prix={10.5 , 2.5  ,21.5};
		
		for(char x:codearticles) {
			System.out.println(x);
		}
		for(double x:prix) {
			System.out.println(x);
		}
		
		boolean verifie=true;
		int i=0;
		while (verifie) {
			
			System.out.println(codearticles[i]+" - "+ prix[i]+"Euros");
			i++;
			verifie=i<NB_ARTICLES;
		}
		
		for(int j=0;j<NB_ARTICLES;j++) {
			System.out.println(codearticles[j]+" - "+ prix[j]+"Euros");
		}
		
		
	
	

		
	}

}
