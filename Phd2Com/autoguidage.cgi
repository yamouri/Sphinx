//******************************************************************************
//******************************************************************************
//**************Programme de AMOURI Yanis pour le projet Sphinx*****************
//**************Derniere mise à jour : 01/03/2017 à 15h22***********************
//******************************************************************************
//**************Le programme va via une socket se connecter au port 4400********
//**************pour ensuite envoyer une trame (écrite en dur dans le***********
//**************programme). La trame est en Json et communique avec*************
//**************le logiciel phd2 sur la machine*********************************
//******************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <iostream>
  
  
int main(int argv, char * argc [])
{
    std::cout << "Content-type:text/html\r\n\r\n";
            
    //Declaration des variables.
    struct addrinfo hints, * res;
    int status;
    int socket_id;
      
    //Definition hints.
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    
    //Ici, nous pouvons mettre l'adresse et le port. Phd2 utilise le port 4400.
    status = getaddrinfo("127.0.0.1","4400", &hints, &res);
    if(status != 0)
    {
        fprintf(stderr, "Erreur info adresse\n"); //Retour en cas d'erreur sur l'adresse ou le port.
        exit(1);
    }       
      
    socket_id = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if(socket_id < 0)
    {
        fprintf(stderr, "Erreur création socket \n"); //Retour en cas d'erreur sur la création du socket.
        exit(2);
    }
      
    status = connect(socket_id, res->ai_addr, res->ai_addrlen);
    if(status < 0)
    {
        fprintf(stderr, "Erreur de connexion \n"); //Retour en cas d'un problème de connexion
        exit(3);
    }
    const char* buf;
    //Voici la trame Json : {"method": "guide", "params": [{"pixels": 1.5, "time": 8, "timeout": 40}, false], "id": 42}
    buf = "{\"method\": \"guide\", \"params\": [{\"pixels\": 1.5, \"time\": 8, \"timeout\": 40}, false], \"id\": 42}\n";
    int numbytes = 0; 
    numbytes = send(socket_id, buf , 93, 0);
      
    if(numbytes == -1)
    {
        fprintf(stderr, "Erreur de l'envoi de la trame \n"); //Retour en cas d'erreur du send
        exit(4);
    }
    close(socket_id);   
    return 0;
}