#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "proj1.h"
#define shm_size 32
#define PARM IPC_CREAT | 0666
/* TODO: define Client member functions */
void Client::error(const char *msg){
	perror(msg);
	exit(1);

}
Client::Client(char *name, int portno){
    key = 5683;

    if ((shm_id = shmget(key, shm_size, PARM)) < 0) {
            perror("shmget");         
        }
    if ((shm_addr = (char*)shmat(shm_id, NULL, 0)) == (char *) -1) {
            perror("shmat");           
    }
    s = shm_addr;  
    if (pipe (mypipe))
     {
       fprintf (stderr, "Pipe failed.\n");       
     }	      

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        perror("ERROR opening socket");  
        exit(1);
    }
    server = gethostbyname(name);  
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0){
        perror("ERROR connecting");
        exit(1);
    }
    

}

void Client::get_price (){     
    
    int n;
    bzero(buffer, 256);
	n = read(sockfd,buffer,255);    
	if (n < 0)
		error("ERROR reading from socket");
    printf("%s",buffer);
    strcpy(s,buffer);  
}

void Client::gen_buy_request (){   
    char ch;    
    int n,m;
    ch = getchar();
                    
    if (ch == '\n')  {
        bzero(reqbuffer,256);
        
        sleep(1);      
        printf("from client: client buy at %s", s);       
        strcpy(reqbuffer, s);

        m = write(sockfd,reqbuffer, sizeof(reqbuffer));
        if (m < 0) {error("ERROR writing to socket");}
    }
}
