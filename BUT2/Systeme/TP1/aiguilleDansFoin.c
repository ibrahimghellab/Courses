#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(){
    int trv= 0;
    int status;
    unsigned char arr[TABSIZE];
    srandom(time(NULL));
    // entasser du foin
    for (int i = 0; i < TABSIZE; i++)
    arr[i] = (unsigned char) (random() % 255) + 1;
    // cacher l'aiguille
    printf("Enter a number between 0 and %d: ", TABSIZE);
    scanf(" %d", &i);
    if (i >= 0 && i < TABSIZE) arr[i] = 0;
    
    
    
    pid_t cpid=fork();
    if(cpid==0){
        for (int i = 0; i < TABSIZE/2; i++){
            if(arr[i]==0){
                trv=1;
                break;
            }
            
        }
        exit(trv);
    }else{
        for (int i = TABSIZE/2; i < TABSIZE; i++){
            if(arr[i]==0){
                trv=1;
                break;
            }
        }
    }
        wait(&status);
        if(WIFEXITED(status)){
                if(WEXITSTATUS(status)==1){
                    trv=1;
                }    
        }
        if(trv)
            printf("Got a needle!\n"); 
        else printf("No needles.\n");
        
    


        
    







    return 0;
}
