#ifndef PROJ1_H 
#define PROJ1_H

/* TODO: Server and Client classes */
#define ABCD
class Server {
	int sockfd, newsockfd, portno, pid, counter, counter2,shmcounter;
	int mypipe[2];
	char buffer[256], writebuffer[256], readbuffer[256];
	float price;
	socklen_t clilen;
	struct sockaddr_in serv_addr;
	char c;
    int shm_id, shm_id2, shm_id3;
    int *shm_addr3, *s3;
    char *shm_addr, *s, *shm;    
 	key_t key, key2, key3;
 	bool master_flag;
 	bool *s2, *shm_addr2, *shm2;
 	int reqcount;
	
public:	
	Server();
	void error(const char *msg);
	int sock();
	void gen_price (int newsockfd);
	void process_buy_request(int newsockfd);
};

class Client {
	int sockfd, portno, counter, counter2;
	int mypipe[2];
	char buffer[256],readbuffer[256],reqbuffer[256];	
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int shm_id;
    char *shm_addr, *s;
    key_t key;
    
public:
	Client(char *name, int portno);
	void error(const char *msg);
	void get_price ();
	void gen_buy_request ();
};

#endif