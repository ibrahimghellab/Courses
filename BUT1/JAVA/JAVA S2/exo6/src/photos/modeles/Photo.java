package photos.modeles;
import java.io.File;
import java.util.ArrayList;

public class Photo implements Comparable{


	public String nomFichier;
	String nomPays;
	int annePrise;
	String commentaire;
	double tailleFichier;


	Photo(String nomFichier,String nomPays,int annePrise,String commentaire){
		this.nomFichier=nomFichier;
		this.nomPays=nomPays;
		this.annePrise=annePrise;
		this.commentaire=commentaire;
		tailleFichier(nomFichier);
	}

	public void tailleFichier(String nomFichier) {
		File file =new File(nomFichier);
		if(file.exists()){ 
			tailleFichier = file.length();
		}else {
			System.out.println("Le fichier saisi n'existe pas");
		}
	}



	public double getTailleFichier() {
		return tailleFichier;
	}

	public int compareTo(Object p) {
		Photo photo=(Photo)p;
		if(this.tailleFichier<photo.tailleFichier)
		{
			return -1;
		}else {
			if(this.tailleFichier>photo.tailleFichier) {
				return 1;
			}else {
				return 0;
			}
		}

	}		

	public static void main(String [] args) {
		Photo sanda =new Photo("Sunflower_from_Silesia2.jpg","sanda",2015,"Non Oui");
		Photo zema = new Photo("téléchargement.jpg","sansa",2020,"Non merci");
		System.out.println(zema.getTailleFichier());
		System.out.println(sanda.getTailleFichier());
		System.out.println(zema.compareTo(sanda));
		ArrayList<Photo> al=new ArrayList<Photo>();
		AlbumPhoto ap=new AlbumPhoto(al);
		
		ArrayList<Photo> phoot=new ArrayList<Photo>();		
		ap.ajouterPhoto(zema);
		ap.ajouterPhoto(sanda);
		ap.trierPhotos();
		phoot=ap.rechercherPhotoCommentaire("Non");
		phoot.toString();		
		
	}




}


