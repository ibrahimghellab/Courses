
import java.sql.*;
import java.util.Scanner;
public class OutilsJDBC {
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
public static void main(String[] args) throws SQLException{
	
	//Question 1
	
	Connection c=openConnection("jdbc:oracle:thin:ighella/20060803@oracle.iut-orsay.fr:1521:etudom");
	ResultSet r=exec1Requete("SELECT * FROM ens2004.FILM WHERE ROWNUM <= 10 ", c, 0);
	while(r.next()) {
		int numFilm=r.getInt("numFilm");
		String titre=r.getString("titre") ;
		String realisateur=r.getString("realisateur");
		System.out.println(numFilm);
		System.out.println(titre);
		System.out.println(realisateur);
		System.out.println();
	}
	//Question 2
		ResultSet r2=exec1Requete("SELECT * FROM ens2004.INDIVIDU WHERE nomIndividu='FONDA'", c, 0);
		while(r2.next()) {
			int numIndividu=r2.getInt("numIndividu");
			String nomIndividu=r2.getString("nomIndividu") ;
			String prenomIndividu=r2.getString("prenomIndividu");
			System.out.println(numIndividu);
			System.out.println(nomIndividu);
			System.out.println(prenomIndividu);
			System.out.println();
		}
		
		//Question 3
		
		ResultSet r3=exec1Requete("SELECT * FROM LOCATIONBUT2 L INNER JOIN ens2004.FILM F ON L.idFilm=F.numFilm WHERE dateRetour='17/10/24'" , c, 0);
		
		while(r3.next()) {
			String titre=r3.getString("titre");
			Date dateDemande=r3.getDate("dateEmprunt");
			System.out.println("Titre :"+titre+" Date demande : "+dateDemande);	
		}
		
		//Question 4
		
		
		Scanner sc= new Scanner(System.in);
		
		System.out.println("Entrer le nom d'un acteur : ");
		String nom = sc.next();
		nom=nom.toUpperCase();
		ResultSet r41=exec1Requete("SELECT * FROM ens2004.INDIVIDU WHERE nomIndividu='"+nom+"'", c, 1);
		int cpt=0;
		while(r41.next()) {
			
			String nomIndividu=r41.getString("nomIndividu") ;
			String prenomIndividu=r41.getString("prenomIndividu");
			
			System.out.println(++cpt +" " +prenomIndividu +" "+nomIndividu);
			
			
			
			
		}
		System.out.println("Votre choix : ");
		Scanner sc2= new Scanner(System.in);
		int choix=sc2.nextInt();
		r41.absolute(choix);
		String prenomIndividu=r41.getString("prenomIndividu");
		int numIndividu=r41.getInt("numIndividu");
		System.out.println("Vous avez choisi : "+prenomIndividu);
		System.out.println("Il a joué dans : ");
		ResultSet r42=exec1Requete("SELECT * FROM ens2004.FILM F INNER JOIN ens2004.ACTEUR A ON F.numFilm=A.numFilm WHERE numIndividu='"+numIndividu+"' ORDER BY titre", c, 1);
		cpt=0;
		while(r42.next()) {
			String titre=r42.getString("titre");
			System.out.println(++cpt +" "+titre);
			
		}
		System.out.println("Votre choix : ");
		Scanner sc3= new Scanner(System.in);
		choix=sc3.nextInt();
		r42.absolute(choix);
		String titre=r42.getString("titre");
		int numFilm=r42.getInt("numFilm");
		System.out.println("Vous avez choisi : "+titre);
		System.out.println("Voici les exemplaires de ce film : ");
		ResultSet r43=exec1Requete("SELECT numExemplaire FROM ens2004.Exemplaire WHERE numFilm='"+numFilm+"'",c, 1);
		while(r43.next()) {
			int exemplaire=r43.getInt("numExemplaire");
			System.out.println(exemplaire);
			
		}
		
		closeConnection(c);
		
	
	}
};