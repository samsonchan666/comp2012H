#include <stdio.h>
#include <math.h>
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
/* TODO: define Server member functions here */

void Server::error(const char *msg){
	perror(msg);
	exit(1);

}
Server::Server() {
        reqcount = 0;        
        key = 5672;
        key2 = 5680;
        key3 = 5681;        
        master_flag = false;        

        if ((shm_id = shmget(key, shm_size, PARM)) < 0) {
                 perror("shmget");         
         }
        if ((shm_addr = (char*)shmat(shm_id, NULL, 0)) == (char *) -1) {
                perror("shmat");           
        }
        s = shm_addr;
        if ((shm_id2 = shmget(key2, shm_size, PARM)) < 0) {
                 perror("shmget");
        }
        if ((shm_addr2 = (bool*)shmat(shm_id2, NULL, 0)) == (bool *) -1) {
                  perror("shmat");
        }
        s2 = shm_addr2;
        *s2 = master_flag;
        if ((shm_id3 = shmget(key3, shm_size, PARM)) < 0) {
                 perror("shmget");
        }
        if ((shm_addr3 = (int*)shmat(shm_id3, NULL, 0)) == (int *) -1) {
                  perror("shmat");
        }
        s3 = shm_addr3;
        *s3 = 0;
        if (pipe (mypipe)){

                fprintf (stderr, "Pipe failed.\n");       
        }        

         sockfd = socket(AF_INET, SOCK_STREAM, 0);         
         if (sockfd < 0){
         	perror("ERROR opening socket"); 
         	exit(1);
         }         	        
         bzero((char *) &serv_addr, sizeof(serv_addr));
         portno = 5001;
         serv_addr.sin_family = AF_INET;
         serv_addr.sin_addr.s_addr = INADDR_ANY;
         serv_addr.sin_port = htons(portno);
         if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) <0 ){
         	perror("ERROR on binding");
         	exit(1);
         }
         	

}

int Server::sock() {        
        return sockfd;
}

void Server::gen_price (int newsockfd){
                
        time_t rawtime;
        int count, n;
                
        bzero(buffer,256);
        struct tm * timeinfo;
        bool is_master = false;

        if (!*s2) { *s2 = true; is_master = true; }
        if (counter == 0 ){ close(mypipe[0]); counter++; } 
        while(1){
        count = 0;              
        if(is_master){
        price = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        
        while(count != 10){                        
                time(&rawtime);         
                timeinfo = localtime (&rawtime);
                sprintf(buffer, "$%3.2f %s", price, asctime(timeinfo));
                strcpy(s,buffer);          
                printf("%s",buffer);  
                n = write(newsockfd,buffer,strlen(buffer)+1);
                if (n < 0) {error("ERROR writing to socket");}
                sleep(1);
                count++;
                }                             
        }
        else {
                n = write(newsockfd,s,strlen(s)+1);
                if (n < 0) {error("ERROR writing to socket");}
                sleep(1);
        }
        }
        

}

void Server::process_buy_request(int newsockfd){

        int n, m;
        char reqbuffer[256], sendbuffer[256], reqtemp[256],readtemp[256];
        bzero(reqbuffer,256);
        bzero(sendbuffer,256);
        bzero(reqtemp,256);
        bzero(readtemp,256);

        n = read(newsockfd,reqbuffer,255);    
        if (n < 0)
                error("ERROR reading from socket");
        if (reqbuffer){
                char buf[100];

                (*s3)+=1; 
                sprintf(buf,"num buy attempts =  %d \n", *s3);                
                write(1, buf, strlen(buf));

                write(1, s,strlen(s));
                write(1, reqbuffer, strlen(reqbuffer));
                
                      
                sprintf(reqtemp,"%.5s", reqbuffer);;
                sprintf(readtemp,"%.5s", s);

                //write(1,reqtemp,strlen(reqtemp));
                //write(1,readtemp,strlen(readtemp));
                if (strcmp(reqtemp,readtemp)==0){

                sprintf(sendbuffer,"client buy at %s \n server sell at %s \n all times approx \n buy SUCCESS\n",reqbuffer,s);
                //write(1,sendbuffer,strlen(sendbuffer));
                               
                } 
                else {sprintf(sendbuffer,"Buying FAIL\n");}
                sendbuffer[250]='!';
                sleep(2);
                m = write(newsockfd,sendbuffer, sizeof(sendbuffer));
                if (m < 0) {error("ERROR writing to socket");}

                
        }
        

        
}

