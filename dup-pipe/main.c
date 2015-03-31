#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
char ins[100];
char ins1[100];
char ins2[100];
int main(int argc, char** argv) {
    printf("enter pipe instruction:\n");
    fgets(ins,100,stdin);
    string_parser();
    int fd[2], pid;
    pipe(fd);
    switch(pid=fork()){
        case 0:
            dup2(fd[1],1);
            close(fd[0]);
            system(ins1);
            exit(0);
            
        
      
        
        default:
            dup2(fd[0],0);
            close(fd[1]);
            system(ins2);
            
    }
    
 
   
    
    
    
    return (EXIT_SUCCESS);
}

void string_parser(){
    int i,len,j=0,z=0,fl=0;
    len=strlen(ins)-1;
    for(i=0;i<len;i++){
        if(ins[i]!='|'&& fl==0){
            ins1[j]=ins[i];
            j++;
        }
        else if(ins[i]=='|' ){
            fl=1;
            i++;
        }
        else{
            ins2[z]=ins[i];
            z++;
            
        }
        
        
    }
}
