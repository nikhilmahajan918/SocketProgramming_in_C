#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//It contain data type,declaration, macros and functions regarding the socket.
#include <sys/socket.h>
//It defines the structure that required for the network programming 
#include <sys/types.h>

//header files required for working of program
#include <netinet/in.h>
#include <arpa/inet.h>

//defining the port 
#define PORT 4455

void main(){
        //creating all variables 
        int sockfd;
        struct sockaddr_in serverAddr;
        
        int newSocket;
        struct sockaddr_in newAddr;
        
        socklen_t addr_size;
        char buffer[1024];
        
        //Creating socket descripting file
        sockfd=socket(PF_INET, SOCK_STREAM, 0);
        memset(&serverAddr, '\0', sizeof(serverAddr));
        
        //Filling all the entries 
        serverAddr.sin_family=AF_INET;
        serverAddr.sin_port=htons(PORT);
        serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
        
        //using bind so that the client program connects to a specific port on the server
        bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
        
        //Integer 5 represents how many clients we want to connect.
        listen(sockfd, 5);
        addr_size = sizeof(newAddr);
        
        newSocket= accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
        
        //sending data to the client
        strcpy(buffer, "world");
        send(newSocket, buffer, strlen(buffer), 0);

}
