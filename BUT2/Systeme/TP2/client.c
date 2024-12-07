/* CLIENT. Donner l'adresse IP et un pseudo en paramètre */
/* exemple "client 127.0.0.1 dr.ced", lancer en dernier. */

#include <stdio.h>             /* fichiers d'en-tête classiques */
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#include <sys/socket.h>        /* fichiers d'en-tête "réseau" */
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT_SERVEUR 5015      /* Numéro de port pour le serveur */
#define BUFFER_SIZE  1024      /* Taille maximum des messages */

int main(int argc, char *argv[]) {

  /* 1. On crée la socket du client. */

  int sclient=socket(AF_INET,SOCK_STREAM,0);

  /* 2. On prépare l'adresse du serveur. */

  struct sockaddr_in addr = {0}; // initialiser à zéro
  addr.sin_family = AF_INET; // domaine IPv4
  addr.sin_port = htons(PORT_SERVEUR); // port en format réseau
  addr.sin_addr.s_addr = inet_addr(argv[1]); 


  /* 3. On demande une connexion au serveur, tant qu'on y arrive pas. */

  int ok = connect(sclient, (struct sockaddr*) &addr, sizeof(addr));
  while(ok==-1){
    printf("tentative de connexion\n");
    ok = connect(sclient, (struct sockaddr*) &addr, sizeof(addr));

  }

  printf("trouve\n");


  /* 4. On communique. */

  fd_set ensemble, temp; // déclarer les ensembles
  char message[BUFFER_SIZE]; // déclarer le tampon
  FD_ZERO(&ensemble); // vider l’ensemble principal
  FD_SET(0,&ensemble); // ajouter l’entrée standard
  FD_SET(sclient,&ensemble); // ajouter la socket
  while (1) {
    temp = ensemble; // copier l’ensemble
    select(sclient+1, &temp, NULL, NULL, NULL);
    if (FD_ISSET(0, &temp)) { // l’entrée standard est prête
      int lus = read(0, message, BUFFER_SIZE);
    if (lus > 0) write(sclient, message, lus); else break; }
    if (FD_ISSET(sclient, &temp)) { // la socket est prête
      int lus = read(sclient, message, BUFFER_SIZE);
    if (lus > 0) write(1, message, lus); else break; } 
  }


  /* 5. On termine et libère les ressources. */
  shutdown(sclient, SHUT_RDWR); 
  close(sclient);
  return 0;
}
