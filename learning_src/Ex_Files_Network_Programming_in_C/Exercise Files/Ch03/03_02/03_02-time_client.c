#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
	const char *hostname = "time.nist.gov";
	const char *servname = "daytime";
	int r,sockfd;
	struct addrinfo hints,*host;
	const int buffer_size = 1024;
	char buffer[buffer_size];

	memset(&hints, 0, sizeof(struct addrinfo));	/* use memset_s() */
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	r = getaddrinfo( hostname, servname, &hints, &host);
	if( r!=0 )
	{
		perror("time client");
		exit(1);
	}

	/* create a socket */
	sockfd = socket(host->ai_family,host->ai_socktype,host->ai_protocol);
	if( sockfd==-1 )
	{
		perror("time client");
		exit(1);
	}

	/* connect and get the info */
	r = connect( sockfd, host->ai_addr, host->ai_addrlen);
	if( r == -1)
	{
		perror("time client");
		exit(1);
	}

	r = read(sockfd, buffer, buffer_size);
	buffer[r] = '\0';
	printf("Read %d bytes: %s\n",r,buffer);

	freeaddrinfo(host);
	close(sockfd);

	return(0);
}
