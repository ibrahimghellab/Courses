package photos.modeles;

import java.util.ArrayList;
import java.util.Collections;

public class AlbumPhoto implements EnsemblePhotos{

	
	
	
	ArrayList<Photo> album=new ArrayList<Photo>();
	
	public AlbumPhoto(ArrayList<Photo> p) {
		this.album=p;
		
	}
	
	
	@Override
	public void ajouterPhoto(Photo p) {
		album.add(p);
		
	}

	@Override
	public void trierPhotos() {
		Collections.sort(album);
		
	}

	@Override
	public ArrayList<Photo> rechercherPhotoCommentaire(String mot) {
		
		ArrayList<Photo> p=new ArrayList<Photo>();
		for(int i=0;i<album.size();i++) {
			if(album.get(i).commentaire.indexOf(mot)!=-1) {
				p.add(album.get(i));
				System.out.println("C'est la photo qui est "+album.get(i).nomFichier);
			}
			
		}
		return p;
	}
	
	
	
}