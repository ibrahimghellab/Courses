package photos.modeles;
import java.util.ArrayList;

public interface EnsemblePhotos {
	void ajouterPhoto(Photo p);
	void trierPhotos();
	ArrayList<Photo> rechercherPhotoCommentaire(String mot);
}
