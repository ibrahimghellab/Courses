
public class Magasin {

	
	final static int NB_MAX=5;
	String _nomMagasin;
	Table []_tableauTables;
	int _nbTablesStockees;
	
	Magasin(String nom,int nbMax){
		_nomMagasin=nom;
		_nbTablesStockees=nbMax;
		_tableauTables= new Table[5];
	}
	
	void add(Table t) {
		int cpt=0;
		for(int i=0;i<_tableauTables.length;i++) {
			if(_tableauTables[i]!=null) {
				cpt++;
			}
			
		}
		_tableauTables[cpt+1]=t;
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Magasin ikeaEvry;
		ikeaEvry=new Magasin("ikeaEvry",10);
		Magasin ikea=new Magasin("ikea",5);
		Table t1;
		t1= new Table();
		Table t2;
		t2= new Table (3);
		Table t3 = new Table (6,"noir");
		Table t4=t3;
		ikeaEvry.add(t1);
		ikeaEvry.add(t2);
		ikea.add(t2);
		ikea.add(t4);
		for(int i=0;i<NB_MAX;i++) {
			if(ikeaEvry._tableauTables[i]!=null) {
			System.out.println (ikeaEvry._tableauTables[i].nbPieds);
	    	System.out.println (ikeaEvry._tableauTables[i].couleurTable);
	    	System.out.println (ikeaEvry._tableauTables[i].prixTable);
	    	System.out.println ();

		}
	}
		
		for(int i=0;i<NB_MAX;i++) {
			if(ikea._tableauTables[i]!=null) {
				System.out.println();
			System.out.println (ikea._tableauTables[i].nbPieds);
	    	System.out.println (ikea._tableauTables[i].couleurTable);
	    	System.out.println (ikea._tableauTables[i].prixTable);
	    	System.out.println ();


			}
		}
	}
}