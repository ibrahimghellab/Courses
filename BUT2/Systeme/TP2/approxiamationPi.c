#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <time.h>


int main(){

    srandom(time(NULL));
    int sfd[2];
    double x,y;
    if(socketpair(AF_LOCAL,SOCK_STREAM,0, sfd)==-1){
        perror("socketpair() error");
        exit(1);
    }
    
    pid_t id=fork();
    if(id==0){
        //tirage
        close(sfd[0]);
        while(1){
        
        for(int i=0;i<=2;i++){
            double z = ((double)random()/RAND_MAX);
            write(sfd[1],&z,sizeof(z));
        }
        read(sfd[1],NULL,0);
        
        }
        
        exit(1);
    }
    close(sfd[1]);
    int n=0,m=0;
    while(1){
        write(sfd[0],"",0);
        read(sfd[0],&x,sizeof(x));
        read(sfd[0],&y,sizeof(y));
        if(x*x+y*y<=1){
            m++;
        }
        n++;
        double pi=(double)(4*m)/n;
        printf("pi = %f\n",pi);
        
    }
    
    
    
    
    
}