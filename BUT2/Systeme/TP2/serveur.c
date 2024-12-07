/* SERVEUR. Lancer ce programme en premier (pas d'arguments). */

#include <stdio.h>                  /* fichiers d'en-tête classiques */
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/socket.h>             /* fichiers d'en-tête "réseau" */
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT_SERVEUR 5015           /* Numéro de port pour le serveur */
#define MAX_CLIENTS   128           /* Nombre maximum de clients */
#define BUFFER_SIZE  1024           /* Taille maximum des messages */

int main(int argc, char *argv[]) {
printf("Osman");
  /* 1. On déroute les signaux */
    //SIG


  /* 2. On crée la socket d'écoute. */

  int secoute=socket(AF_INET, SOCK_STREAM, 0);

  /* 3. On prépare l'adresse du serveur. */

  struct sockaddr_in addr = {0}; // initialiser à zéro
  addr.sin_family = AF_INET; // domaine IPv4
  addr.sin_port = htons(PORT_SERVEUR); // port en format réseau
  addr.sin_addr.s_addr = htonl(INADDR_ANY); 

  /* 4. On attache la socket a l'adresse du serveur. */

  if(bind(secoute,(struct sockaddr*) &addr,sizeof(addr))==-1){
    perror("Bind echoue");
  }
  printf("Osman");
  listen(secoute,MAX_CLIENTS);
  /* 5. Enregistrement auprès du système. */
    printf("Serveur en attente de nouveaux clients ou messages.\n");
    fd_set ensemble, temp; // déclarer les ensembles
    char message[BUFFER_SIZE]; // déclarer le tampon
    FD_ZERO(&ensemble); // vider l’ensemble principal
    FD_SET(secoute,&ensemble); // ajouter la socket d’écoute
    int max = secoute; // n◦ maximum de descripteur
    int nbLus;
  while (1) {
    
  
    temp = ensemble; // copier l’ensemble
    select(max+1, &temp, NULL, NULL, NULL);
    for (int fd = 0; fd <= max; fd++) {
      if (!FD_ISSET(fd, &temp)) continue; // fd pas prêt
      if (fd == secoute) { // demande de connexion
        int ss = accept(secoute, NULL, NULL);
        FD_SET(ss, &ensemble); // ajouter socket de service
        if (ss > max) max = ss; // mettre max à jour
        continue; /* au suivant */ }
      if ((nbLus = read(fd, message, BUFFER_SIZE)) <= 0) {
        FD_CLR(fd, &ensemble); // retirer socket de service
        shutdown(fd, SHUT_RDWR); // fermer la connexion
        close(fd); continue; /* au suivant */ }
        
      for(int i=0;i<=max;i++){
        if(FD_ISSET(i, &ensemble)&& i!=secoute){
          write(i, message, nbLus);
        }
        
      }
      
      /* 6. Si on a reçu une demande sur la socket d'écoute... */

      /* 7. Si on a reçu des données sur une socket de service... */

  }
}
  /* 8. On termine et libère les ressources. */
    close(secoute);
  return 0;
}
