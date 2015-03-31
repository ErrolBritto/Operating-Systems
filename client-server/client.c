/**
 * COE 518 - Operating Systems 
 * Lab 10
 * @author Errol Britto, 500529490
 */

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h> 

#if !defined __cplusplus
typedef enum {true, false} bool ;
#endif

int try_a_password(void); 
void create_random_password(char []); 

static const char alphanum[] = "ABCDEFGHIJ";
bool pass_found =false;
char *server_ip;

int main(int argc, char *argv[])
{
	srand(time(0)); 
	if(argc != 2)
	{
		printf("\n Usage: %s <ip of server> \n",argv[0]);
		return 1;
	} 

	server_ip =argv[1]; 

	while(1){
		int flag;
		flag = try_a_password();
		if (flag == 1){
			break;
			printf("Password Match!");
		}
	}
	
	
	return 0;
}

int try_a_password(void)
{
	int sock_id = 0; 
	char random_pass[1024];	
	char recv_buff[1024]; 
        
	create_random_password(random_pass); 
	printf("Trying %s ...\n\r",random_pass);

	
	sock_id = socket(AF_INET,SOCK_STREAM,0);

	 
	struct sockaddr_in serv_addr;
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(5000);
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
 
	printf("Starting...\n");
	
	if(connect(sock_id,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0){
		printf("\n Failed to Connect!\n");
	}else{
		send(sock_id,random_pass,3,0);	
		printf("Delivery Success!\n");
                int n = 0;
		while(( n = read(sock_id, recv_buff, sizeof(recv_buff)-1)) > 0){
			recv_buff[n] = 0;
			if(recv_buff[0] == 'T'){
				printf("Password is: %s\n", random_pass);
				return 1;
			}
			else{
				return 0;
			}
		}
	}
	
	
	close(sock_id); 
}
void create_random_password(char rndStr[])
{
	unsigned int i;
	int stringLength = sizeof(alphanum) - 1; 
 	for(i = 0; i < 3; ++i) 
	{
	 rndStr[i]= alphanum[rand() % stringLength]; 
	}
	rndStr[3]=0;
	
}
