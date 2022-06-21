#include <arpa/inet.h>
  
#include <netinet/in.h>
  
#include <stdio.h>
  
#include <string.h>
  
#include <sys/socket.h>
  
#include <sys/stat.h>
  
#include <sys/types.h>

/*
•   #include <arpa/inet.h> librăria care definește structura in_addr;
•   #include <netinet/in.h> librăria necesară pentru adresa domeniului de internet;
•   #include <stdio.h> librăria standard pentru input și output;
•   #include <sys/socket.h> librăria necesară pentru crearea de sockets;
•   #include <string.h> librăria care conține funcțiile string;
•   #include <sys/stat.h> librăria necesară pentru a obține informații despre atributele fișierelor;
*/

  
main()
{
    /*  Cream un client si un server utilizând Internet domain specificat prin socketaddr_in */
    struct sockaddr_in client, server;
    int socketNou, n, sock, verificator;
    char animal[20];
  
    /*Cream un socket nou, specificand domeniul, tipul si protocolul */
    socketNou = socket(AF_INET, SOCK_STREAM, 0);
  
    /*Familia AF_INET pentru Internet domain */
    server.sin_family = AF_INET;
  
    /* Portul 8924 si adresa IP pentru sys.ase.ro */
    server.sin_port = htons(8924);
    server.sin_addr.s_addr = inet_addr("37.120.249.45");
  
    /* Legam un nume de un socket prin bind(). dupa care asteptam o conexiune cu un numar maxim de o cerere */
    bind(socketNou, (struct sockaddr*)&server, sizeof server);
    listen(socketNou, 1);
    n = sizeof client;
  
    /* Acceptam o conexiune la un socket si cream unul nou */
    sock = accept(socketNou, (struct sockaddr*)&client, &n);
printf("Socket creat și pregatit pentru a primi mesaje");    
for (;;) {
    /* Receptionam mesajul de la client */
        recv(sock, animal, sizeof(animal), 0);
  

        /*Verificam dimensiunea mesajulul, pentru a putea serta verificatorul cu 0,1 sau2 */
        printf("\nAnimalul dumneavoastră preferat este:%s\n", animal);
        if (strlen(animal) > 5)
            verificator = 1;
        else if(strlen(animal)<5){
            verificator = 2;
        }else{
verificator=0;
}
/*La final, intoarcem valoarea verificatorului catre client, pentru a putea prelucra mesajul */
        send(sock, &verificator, sizeof(int), 0);
printf("Socketul stream a trimis mesajul\n");
