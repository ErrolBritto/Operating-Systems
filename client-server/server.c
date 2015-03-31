/**
 * COE 518 - Operating Systems 
 * Lab 10
 * @author: Errol Britto, 500529490
 */

#include "md5.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <pthread.h>

void *handle_connection(void *); 
int verify_password(char s[]); 




int main(int argc, char *argv[])
{
    int listenfd = 0, conn_id = 0;   
     
	listenfd = socket(AF_INET,SOCK_STREAM,0);
	printf("Socket found!\n");

    
	struct sockaddr_in serv_addr;
    	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(5000);
    	bind(listenfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

    
	if(listen(listenfd,10) == -1){
		printf("Listening Failure!\n");
		return -1;
	}
	printf("Listening Success!\n");
    while(1) 
    {
		int conn_id = 0;        
        	conn_id = accept(listenfd,(struct sockaddr*)NULL,NULL);
		printf("conn_id%d\n",conn_id);
		
		if(conn_id < 0){
			printf("Not Accepted!\n");
		}else{
			printf("Thread Created!\n");
			pthread_t connection;
			pthread_create(&connection,NULL,&handle_connection,&conn_id);	
			pthread_join(connection,NULL);
			pthread_detach(connection);
		}
		
        
     }
}
void* handle_connection(void *arg )
{
	int conn_id =* (int *) arg;
	char recv_buff[1024]; 
	int n=0; 
        int correct;
	if(fputs(recv_buff,stdout) == EOF){
		printf("Fputs Error!\n");
	}
        else{
		n = read(conn_id,recv_buff,sizeof(recv_buff)-1);
        }
                if(n <0){
			printf("Socket Read Error!");
		}
                else{
			correct	= verify_password(recv_buff);
                }
			if(correct == 1){
				send(conn_id,"T",1,0);
			}
                        else
                        {
				send(conn_id,"F",1,0);
			}
		}
		close(conn_id);

                int verify_password(char s[])
{
	char md5_hashed_password[33] ="24af484e92082ad450a63a69f924f10a"; 
	char md5_hashed_text[33]; 
	size_t len = strlen(s);
	md5((uint8_t*)s, len, md5_hashed_text); 
	if(strncmp(md5_hashed_text,md5_hashed_password,32)==0) 
        return 0;
}
