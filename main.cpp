// ********************************************
// Nom du code : ecoute_udp.cpp
// Auteur : _SebF AT frameIP.com
// date de création : 10 juin 2004
// version : 1.0
// Licence : Ce code est libre de toute utilisation.
// La seule condition existante est de faire référence au site http://www.frameip.com afin de respecter le travail d'autrui.
// ********************************************

// ********************************************************
// Les includes
// ********************************************************
#include <winsock2.h> // pour les fonctions socket
#include <cstdio> // Pour les Sprintf

// ********************************************************
// Les librairies
// ********************************************************
#pragma comment(lib,"ws2_32.lib")

// ********************************************************
// Définition des variables
// ********************************************************
WSADATA initialisation_win32; // Variable permettant de récupérer la structure d'information sur l'initialisation
int erreur; // Variable permettant de récupérer la valeur de retour des fonctions utilisées
int tempo; // Variable temporaire de type int
int nombre_de_caractere; // Indique le nombre de caractères qui a été reçu ou envoyé
char buffer[65535]; // Tampon contenant les données reçues ou envoyées
SOCKET id_de_la_socket; // Identifiant de la socket
SOCKADDR_IN information_sur_la_source; // Déclaration de la structure des informations lié à l'écoute

int main (int argc, char* argv[])
	{
	printf("\nBonjour, vous etes du cote serveur. www.frameip.com\n");

	// ********************************************************
	// Initialisation de Winsock
	// ********************************************************
	erreur=WSAStartup(MAKEWORD(2,2),&initialisation_win32);
	if (erreur!=0)
		printf("\nDesole, je ne peux pas initialiser Winsock du a l'erreur : %d %d",erreur,WSAGetLastError());
	else
		printf("\nWSAStartup  : OK");

	// ********************************************************
	// Ouverture d'une Socket
	// ********************************************************
	id_de_la_socket=socket(AF_INET,SOCK_DGRAM,0);
	if (id_de_la_socket==INVALID_SOCKET)
		printf("\nDesole, je ne peux pas creer la socket du a l'erreur : %d",WSAGetLastError());
	else
		printf("\nsocket      : OK");

	// ********************************************************
	// Lie la socket à une ip et un port d'écoute
	// ********************************************************
	information_sur_la_source.sin_family=AF_INET;
	information_sur_la_source.sin_addr.s_addr=INADDR_ANY; // Ecoute sur toutes les IP locales  
	information_sur_la_source.sin_port=htons(33333); // Ecoute sur le port 33333
	erreur=bind(id_de_la_socket,(struct sockaddr*)&information_sur_la_source,sizeof(information_sur_la_source));
	if (erreur!=0)
		printf("\nDesole, je ne peux pas ecouter ce port : %d %d",erreur,WSAGetLastError());
	else
		printf("\nbind        : OK");

	// ********************************************************
	// Reception des données
	// ********************************************************
	tempo=sizeof(information_sur_la_source); // Passe par une variable afin d'utiliser un pointeur
        for(;;){
	nombre_de_caractere=recvfrom(id_de_la_socket,buffer,1515,0,(struct sockaddr*)&information_sur_la_source,&tempo);
        
	buffer[nombre_de_caractere]=0; // Permet de fermer le tableau après le contenu des data, car la fonction recvfrom ne le fait pas
	printf("\nVoici les donnees : %s",buffer);
        }
	// ********************************************************
	// Fermeture de la socket correspondante à la commande socket()
	// ********************************************************
	erreur=closesocket(id_de_la_socket);
	if (erreur!=0)
		printf("\nDesole, je ne peux pas liberer la socket du a l'erreur : %d %d",erreur,WSAGetLastError());
	else
		printf("\nclosesocket : OK");

	// ********************************************************
	// Quitte proprement le winsock ouvert avec la commande WSAStartup
	// ********************************************************
	erreur=WSACleanup(); // A appeler autant de fois qu'il a été ouvert.
	if (erreur!=0)
		printf("\nDesole, je ne peux pas liberer winsock du a l'erreur : %d %d",erreur,WSAGetLastError());
	else
		printf("\nWSACleanup  : OK");
	}