#include<string> 
#include <iostream>
#include<string.h> 
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h> 
#include<unistd.h>
 
int main()
{
    int socket_desc;
    struct sockaddr_in server;
     
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Echec création socket");
    }
         
    server.sin_addr.s_addr = inet_addr("localhost");
    server.sin_family = AF_INET;
    server.sin_port = htons( 4400 );
 
    connect(socket_desc , (struct sockaddr *)&server , sizeof(server));    
    std::string message = std::string("{") + '"' + "method" + '"' + ": " + '"' + "guide" + '"' + ", " + '"' + "params" + '"' + ": [{" + '"' + "pixels" + '"' + ": 1.5, " + '"' + "time" +  '"' + ": 8, " +  '"' + "timeout" + '"' + ": 40}, false], " + '"' + "id" + '"' +  ": 42}";
    send(socket_desc ,  message , sizeof(message), NULL); 
    close(socket_desc);
    return 0;
}
