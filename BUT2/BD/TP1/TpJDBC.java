package tp2;

import java.sql.CallableStatement;
import java.sql.Connection;
import java.sql.Date;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

public class TpJDBC {
	
	public static Connection openConnection(String url) {
		Connection co = null;
		try {
			Class.forName("oracle.jdbc.driver.OracleDriver");
			co = DriverManager.getConnection(url);
		} catch (ClassNotFoundException e) {
			System.out.println("il manque le driver oracle");
			System.exit(1);
		} catch (SQLException e) {
			System.out.println("impossible de se connecter à l'url : " + url);
			System.exit(1);
		}
		return co;
	}

	public static ResultSet exec1Requete(String requete, Connection co, int type) {
		ResultSet res = null;
		try {
			Statement st;
			if (type == 0) {
				st = co.createStatement();
			} else {
				st = co.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_READ_ONLY);
			}
			;
			res = st.executeQuery(requete);
		} catch (SQLException e) {
			System.out.println("Problème lors de l'exécution de la requete : " + requete);
		}
		;
		return res;
	}

	public static void closeConnection(Connection co) {
		try {
			co.close();
			System.out.println("Connexion fermée!");
		} catch (SQLException e) {
			System.out.println("Impossible de fermer la connexion");
		}
	}
	
	public static ResultSetMetaData getMetaData(String tableName, Connection c) throws SQLException {
		ResultSet rs = exec1Requete("SELECT * FROM " + tableName, c, 0);
		return rs.getMetaData();
	}
	
	//Question 1
	public static void displayMetaData(String tableName, Connection c) throws SQLException {
		ResultSetMetaData rsmd = getMetaData(tableName, c);
		
		String leftAlignFormat = "| %-25s | %-10s | %-20s | %n";

		System.out.format("+---------------------------+------------+----------------------+%n");
		System.out.format("| Name                      | Null?      | Type                 |%n");
		System.out.format("+---------------------------+------------+----------------------+%n");
		
		int numberOfColumns = rsmd.getColumnCount ( );
		for (int i = 1; i <= numberOfColumns; i++) {
			String colName = rsmd.getColumnName(i);
			String type = rsmd.getColumnTypeName(i) + "(" + rsmd.getPrecision(i) + ")" ;
			String isNull;
			if(rsmd.isNullable(i) == 1) {
				isNull = "";
			}else {
				isNull = "NOT NULL";
			}
			System.out.format(leftAlignFormat, colName, isNull, type);
		}
		System.out.format("+---------------------------+------------+----------------------+%n");
		
	}
	
	//Question 2
	public static void displayFilms(String name, Connection c) throws SQLException {
		String sql = "SELECT prenomIndividu" +
				   " FROM ens2004.Individu" +
				   " WHERE nomIndividu = '" + name + "'";
		
		ResultSet acteurs = exec1Requete(sql, c, 0);
		
		sql = "SELECT titre" +
			  " FROM ens2004.Film f" +
			  " INNER JOIN ens2004.Acteur a ON a.numFilm = f.numFilm" +
			  " INNER JOIN ens2004.Individu i ON i.numIndividu = a.numIndividu" +
			  " WHERE nomIndividu = ? AND prenomIndividu = ?";
		
		PreparedStatement ps = c.prepareStatement(sql);
		ResultSet films;
		
		while(acteurs.next()) {
			String currentFirstName = acteurs.getString("prenomIndividu");
			System.out.println();
			System.out.println(currentFirstName + " " + name + " a joué dans les films suivant :");
			
			ps.setString(1, name);
			ps.setString(2, currentFirstName);
			films = ps.executeQuery();
			while(films.next()) {
				System.out.println(films.getString("titre"));
			}
		}
	}
	
	//Question 3
	public static void displayNbFilm(String name, Connection c) throws SQLException {
		String sql = "SELECT numIndividu, prenomIndividu" +
					" FROM ens2004.Individu" +
					" WHERE nomIndividu = '" + name + "'";
		
		ResultSet rs = exec1Requete(sql, c, 0);
		
		CallableStatement cs = c.prepareCall("{? = call nbreFilms1(?)}");
		cs.registerOutParameter (1,java.sql.Types.INTEGER);
		
		while(rs.next()) {
			String firstName = rs.getString("prenomIndividu");
			int id = rs.getInt("numIndividu");
			cs.setInt(2, id);
			cs.execute();
			int nbFilm = cs.getInt(1);
			System.out.println("L'acteur "+firstName+" "+name+" a joué dans "+nbFilm+" films");
			
		}
		cs.close();
	}
	
	//Question 4
	public static void DisplayNbFilmsByRealisatorName(String name, Connection c) throws SQLException {
		CallableStatement cs = c.prepareCall("{? = call nbreFilms2(?)}");
		
		cs.setString(2, name);
		cs.registerOutParameter (1,java.sql.Types.INTEGER);
		cs.execute ( );
		int rNb = cs.getInt (1);
		cs.close();
		System.out.println(name + " a réalisé " + rNb + " films");
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
	
	//Question 5 
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
		

	public static void main(String[] args) throws SQLException {
		String requete;
		String nom = "FONDA";
		Scanner sc = new Scanner(System.in);

		// Question 1
		String url = "jdbc:oracle:thin:otugrul/20060719@oracle.iut-orsay.fr:1521:etudom";
		Connection co = openConnection(url);
		
		displayMetaData("ens2004.Exemplaire", co);
		
		//Question 2
		//

		System.out.println("Entrer le nom d'un acteur : ");
		//nom = sc.next();
		nom = nom.toUpperCase();
		
		displayFilms(nom, co);
		
		
		//Question 3

		System.out.println("Entrer le nom d'un acteur : ");
		//nom = sc.next();
		nom = nom.toUpperCase();
		displayNbFilm(nom, co);
		
		//Question 4
		System.out.println();
		DisplayNbFilmsByRealisatorName("ABE", co);
		
		//Question 5
		System.out.println();
		displayTitreByName("FONDA", co);
		
		//Question 6
		System.out.println();
		displayTitreComedieByName("EMER", co);
		
		System.out.println();
		closeConnection(co);
		
		
		
	};

}
