/* 
 * File:   main.c
 * Author: EB
 *
 * Created on September 22, 2014, 1:54 AM
 */

#include <stdio.h>
#include <stdlib.h>

#define N_REPS 100
#define DEFAULT_SLOWDOWN 1000000
int main(int argc, char * argv[]) {
 int i, j;
 int slow_down = DEFAULT_SLOWDOWN;
 if (argc == 1) {
 fprintf(stderr, "Usage: %s string [delay]\n", argv[0]);
 return 1;
 }
 if (argc >= 3) {
 slow_down = atoi(argv[2]);
 }
 for (i = 0; i < N_REPS; i++) {
 char * cp = argv[1];
 while (system("mkdir junk 2> /dev/null")!= 0);
 while (*cp) {
 printf("%c", *cp++);
 fflush(stdout);
 for (j = 0; j < slow_down; j++);
 }
 system ("mkdir junk");
 }
 return EXIT_SUCCESS;
}