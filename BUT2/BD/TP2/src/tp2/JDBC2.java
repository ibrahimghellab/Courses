package tp2;


import java.sql.*;
import java.util.Scanner;

public class JDBC2 {

	public static Connection openConnection (String url) {
		Connection co=null;
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			co= DriverManager.getConnection(url);
		}
		catch (ClassNotFoundException e){
			System.out.println("il manque le driver oracle");
			System.exit(1);
		}
		catch (SQLException e) {
			System.out.println("impossible de se connecter à l'url : "+url);
			System.exit(1);
		}
		return co;
	}
	public static ResultSet exec1Requete (String requete, Connection co, int type){
		ResultSet res=null;
		try {
			Statement st;
			if (type==0){
				st=co.createStatement();}
			else {
				st=co.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE,
						ResultSet.CONCUR_READ_ONLY);
			};
			res= st.executeQuery(requete);
		}
		catch (SQLException e){
			System.out.println("Problème lors de l'exécution de la requete : "+requete);
		};
		return res;
	}
	public static void closeConnection(Connection co){
		try {
			co.close();
			System.out.println("Connexion fermée!");
		}
		catch (SQLException e) {
			System.out.println("Impossible de fermer la connexion");
		}
	}
	
	
	
	//Question 1
	public static ResultSetMetaData getMetaData(String nomTable,Connection c) throws SQLException {
		ResultSet r1=exec1Requete("SELECT * FROM "+nomTable, c, 1);
		return r1.getMetaData();
	}
	
	public static void displayMetaData(String nomTable,Connection c) throws SQLException {
		System.out.println("Name                      Null?     Type");
		System.out.println("------------------------ --------- -------------------");
		ResultSetMetaData rsmd=getMetaData(nomTable, c);
		for(int i=1;i<=rsmd.getColumnCount();i++) {                                       
			String colName = rsmd.getColumnName(i);    
			String colType = rsmd.getColumnTypeName(i);
			int isNull=rsmd.isNullable(i);
			String format="%-24s %-9s %-20s %n";
			if(isNull==0) {
				System.out.format(format,colName,"NOT NULL",colType+"("+rsmd.getPrecision(i)+")");
			}else {
				System.out.format(format,colName,"",colType+"("+rsmd.getPrecision(i)+")");
			}
			
		}
	}
	
	//Question 2
	public static void displayFilmByName(String name,Connection c) throws SQLException {

		
		ResultSet acteurs=exec1Requete("SELECT prenomIndividu FROM ens2004.INDIVIDU WHERE nomIndividu='"+name+"'", c, 0);
		PreparedStatement ps=c.prepareStatement("SELECT titre FROM ens2004.FILM F INNER JOIN ens2004.ACTEUR A ON F.numFilm=A.numFilm INNER JOIN ens2004.INDIVIDU I ON A.numIndividu=I.numIndividu WHERE prenomIndividu=? AND nomIndividu='"+name+"'");
		ResultSet films;
		while(acteurs.next()) {
			String prenom=acteurs.getString("prenomIndividu");
			ps.setString(1, prenom);
			System.out.println();
			System.out.println("Pour "+name+" "+prenom);
			System.out.println();
			films=ps.executeQuery();
			while(films.next()) {
				String film=films.getString("titre");
				System.out.println(film);
			}
			
		}

	}
	
	//Question 3
	public static void displayNbFilmsActeursById(int id,Connection c) throws SQLException {
		System.out.println("Saisir un nom d'acteur pour savoir dans combien de films il a joué : ");
		Scanner sc=new Scanner(System.in);
		String nomuser=sc.next();
		CallableStatement cs;
		cs=c.prepareCall("{?= call nbreFilms1( ? )}");
		ResultSet rs=exec1Requete("SELECT numIndividu,prenomIndividu FROM ens2004.INDIVIDU WHERE nomIndividu='"+nomuser+"'", c, 0);
		while(rs.next()) {
			cs.setInt(2, rs.getInt("numIndividu"));
			cs.registerOutParameter(1, java.sql.Types.INTEGER);
			cs.execute();
			int nb=cs.getInt(1);
			String prenom=rs.getString("prenomIndividu");
			System.out.println("L'acteur "+nomuser+" "+prenom+" a joue dans "+nb+" films" );
		}
		
	}
	
	
	//Question 4
	
	public static void displayNbFilmsRealisateursByName(String name,Connection c) throws SQLException {
		CallableStatement cs=c.prepareCall("{?= call nbreFilms2( ? )}");
		cs.setString(2, name);
		cs.registerOutParameter(1, java.sql.Types.INTEGER);
		cs.execute();
		int nb=cs.getInt(1);
		System.out.println("Le réalisateur "+name+" a realise "+nb+" films" );
	}
		
	//Question 5 
	public static void displayTitreByName(String name, Connection c) throws SQLException {
		CallableStatement cs = c.prepareCall("{call unTitre(?, ?, ?)}");
		
		cs.setString(1, name);
		cs.registerOutParameter (2,java.sql.Types.VARCHAR);
		cs.registerOutParameter (3,java.sql.Types.VARCHAR);
		cs.execute ( );
		String prenom = cs.getString (2);
		String titre = cs.getString (3);
		cs.close();
		System.out.println(name + " " + prenom + " a jouer dans le film  " + titre);
	}
	
	//Question 6.2
	public static void displayTitreComedieByName(String name, Connection c) throws SQLException {
		CallableStatement cs = c.prepareCall("{? = call uneComedie(?, ?)}");
		
		cs.setString(2, name);
		cs.registerOutParameter (3,java.sql.Types.VARCHAR);
		cs.registerOutParameter (1,java.sql.Types.VARCHAR);
		cs.execute ( );
		String prenom = cs.getString (3);
		String titre = cs.getString (1);
		cs.close();
		System.out.println(name + " " + prenom + " a jouer dans la comédie  " + titre);
	}
	//Question 6.3
	public static void displayTitreComedieByNameWithGenre(String name, Connection c) throws SQLException {
		CallableStatement cs = c.prepareCall("{? = call uneComedie2(?, ?, ?)}");
		
		cs.setString(2, name);
		cs.registerOutParameter (3,java.sql.Types.VARCHAR);
		cs.registerOutParameter (1,java.sql.Types.VARCHAR);
		cs.registerOutParameter (4, java.sql.Types.VARCHAR);
		cs.execute ( );
		String prenom = cs.getString (3);
		String titre = cs.getString (1);
		String genre=cs.getString(4);
		cs.close();
		System.out.println(name + " " + prenom + " a jouer dans la comédie  " + titre+ " qui est de genre "+genre);
	}

	
	
	
	public static void main(String[] args) throws SQLException{
		
		Connection c=openConnection("jdbc:oracle:thin:ighella/20060803@oracle.iut-orsay.fr:1521:etudom");
/*
		//Question 1
		displayMetaData("ens2004.Exemplaire", c);
		//Question 2
		displayFilmByName("FONDA", c);
		//Question 3
		displayNbFilmsActeursById(500,c);
		//Question 4
		displayNbFilmsRealisateursByName("ABE", c);
		//Question 5
		System.out.println();
		displayTitreByName("FONDA", c);
		//Question 6.2*/
		displayTitreComedieByName("FONDA", c);
		//Question 6.3
		displayTitreComedieByNameWithGenre("FOSSEY", c);
		closeConnection(c);

	}
}