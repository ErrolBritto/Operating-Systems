/* 
 * File:   main.c
 * Author: ebritto
 *
 * Created on September 16, 2014, 2:30 PM
 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
 
    
   if (argc == 1) {
        if (strcmp(argv[0], "hello")==0)
                printf("Hello UNKNOWN\n");
        else
                printf("Bye UNKNOWN\n");
        exit(1);
    }
   
    else if (argc == 2) {
        if (strcmp(argv[0], "hello")==0)
                printf("Hello %s\n", argv[1]);
        else
                printf("Bye %s\n", argv[1]);
        exit(0);
    }
   
    else if (argc > 2) {
        if (strcmp(argv[0], "hello")==0)
                printf("Hello %s\n", argv[1]);
        else 
                printf("Bye %s\n", argv[1]);
        exit(2);
    }
   
    
   
    return (EXIT_SUCCESS);
}
