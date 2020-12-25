//Common header files 
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
        int clientSocket;
        struct sockaddr_in serverAddr;
        char buffer[1024];
        
        //Socket discripter file
        //socket function required three arguments,PF_INET, SOCK_STREAM and 0.
        //It defines the TCP communication 
        clientSocket=socket(PF_INET, SOCK_STREAM, 0);
        memset(&serverAddr, '\0', sizeof(serverAddr));
        serverAddr.sin_family=AF_INET;
        serverAddr.sin_port=htons(PORT);
        //defining the address
        serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
        //connecting 
        connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
        
        recv(clientSocket, buffer, 1024, 0);
        printf("Data Received: %s", buffer);

}

