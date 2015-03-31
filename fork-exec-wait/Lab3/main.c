/* 
 * File:   main.c
 * Author: ebritto
 *
 * Created on September 29, 2014, 12:06 PM
 */

#
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>





int main(int argc, char** argv) {
 
 char todo[100]; 
 char end;
 int length;
 int status;
 
 while(1){
        printf("Your Command > \n");
        fgets(todo,100,stdin);
        length = strlen(todo);
        end = todo[length-2];
        
 
    if(fork() == 0){
        system(todo);
        exit(0);

    }
    
    
   
    if(end != '&'){
        wait(&status);
        
        
    }
        
    else
    {        
        continue;
    }
 
    }



    return 0;
}