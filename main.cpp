#include <cstdlib>
#include<string> 
#include <iostream>
#include<string.h> 
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h> 
#include<unistd.h>
#include "json.hpp"

using namespace std;

int main(int argc, char** argv)
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
    //const char* message = "{" + '"' + "method" + '"' + ": " + '"' + "guide" + '"' + ", " + '"' + "params" + '"' + ": [{" + '"' + "pixels" + '"' + ": 1.5, " + '"' + "time" +  '"' + ": 8, " +  '"' + "timeout" + '"' + ": 40}, false], " + '"' + "id" + '"' +  ": 42}";
    //json_object *jstring = json_object_new_string("Joys of Programming");
    //"{method: guide, params: [{pixels: 1.5, time: 8, timeout: 40}, false], id: 42}"
    json j2 = {
        {"method": "guide"},
        {"params", {
            {"pixels": 1.5},
            {"time": 8},
            {"timeout": 40}
        }},
        {"id": 42},                                        
    };

    //send(socket_desc ,  j2 , sizeof(j2), NULL); 
    close(socket_desc);
    return 0;
}