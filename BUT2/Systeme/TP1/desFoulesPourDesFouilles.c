#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
int main(int argc,char **argv){
    int trv= 0;
    int status;
    int TABSIZE=10000;
    unsigned char arr[TABSIZE];
    int i;
    int N;
    srandom(time(NULL));
    // entasser du foin
    for (int i = 0; i < TABSIZE; i++)
    arr[i] = (unsigned char) (random() % 255) + 1;
    // cacher l'aiguille
    printf("Enter a number between 0 and %d: ", TABSIZE);
    
    scanf(" %d", &i);
    if (i >= 0 && i < TABSIZE) arr[i] = 0;
    
    if (argc > 1) N = atoi(argv[1]);
    if (N < 1 || N > 100) N = 1;
    
    

    
    
  
    


for(int i=0;i<N;i++){
    
    pid_t father=getpid();

    
        if(father==getpid()){
            pid_t cpid2=fork();
        
        if(cpid2==0){
        for (int j = i*(TABSIZE/N); j < (i+1)*(TABSIZE/N); j++){
            if(arr[j]==0){
                trv=1;
                break;
            }
            
        }
        exit(trv);
        }
        }
        wait(&status);
        if(WIFEXITED(status)){
                if(WEXITSTATUS(status)==1){
                    trv=1;
                }    
        }
    
    }
    
        if(trv)
            printf("Got a needle!\n"); 
        else printf("No needles.\n");
        return 0;
    }
        
    


        
    







   
