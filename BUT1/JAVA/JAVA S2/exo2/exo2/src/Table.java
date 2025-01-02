public class Table {
	
	final static String NOIR="Noir";

	int nbPieds;
	String couleurTable;
	float prixTable;
	
	Table() {
		nbPieds=4;
		couleurTable="Marron";
		prixTable=(float) 0.0;
		
	}
	
	Table(int nbPieds){
		this.nbPieds=nbPieds;
		couleurTable="Marron";
		prixTable=(float) 0.0;
	}
	
	Table(int nbPieds,String couleur){
		this.nbPieds=nbPieds;
		couleurTable=couleur;
		prixTable=(float) 0.0;
	}
	
	
	
	public static void main (String args []) {
		
		

		Table t1;
		t1=new Table();
		System.out.println (t1.nbPieds);
    	System.out.println (t1.couleurTable);
    	System.out.println (t1.prixTable);
    	System.out.println ();

    	Table t2 = new Table (3);
    	System.out.println (t2.nbPieds);
    	System.out.println (t2.couleurTable);
    	System.out.println (t2.prixTable);
    	System.out.println ();
    	
    	Table t3 = new Table (6, Table.NOIR);
    	System.out.println (t3.nbPieds);
    	System.out.println (t3.couleurTable);
    	System.out.println (t3.prixTable);
    	System.out.println ();
    	
    	Table t4;
    	t4=t3;
    	System.out.println(t3.prixTable);
    	t3.prixTable=80;
    	System.out.println(t4.prixTable);
    	t4.prixTable=20;
    	System.out.println(t3.prixTable);
    	
    	Table tableau [];
    	tableau= new Table [4];
    	tableau[0]=t1;
    	tableau[1]=t2;
    	tableau[2]=t3;
    	
    	for(int i=0;i<tableau.length;i++) {
    		if(tableau[i]!=null) {
    		System.out.println (tableau[i].prixTable);
        	System.out.println ();
    		}
        	
    	}
	}
		 
}
	

	