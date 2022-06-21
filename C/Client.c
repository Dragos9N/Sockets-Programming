#include <arpa/inet.h>
  
#include <netinet/in.h>
  
#include <stdio.h>
  
#include <string.h>
  
#include <sys/socket.h>

#include <sys/stat.h>
  
#include <sys/types.h>

#include <ctype.h>

/* Acem librariile asemanatoare cu cele de pe partea de server  */
/* Folosim in plus, libraria ctype.h, pentru a putea transforma un string in uppercase, respectiv lowercase */
  
main()
{
    /*Structura client din Internet domain */
    struct sockaddr_in client;
    int socketNou, verificatorPrimit;
    char animal[20];
  
    /* Cream un nou socket, specificand domeniul, tipul si protocolul */
    socketNou = socket(AF_INET, SOCK_STREAM, 0);
  
    /*Familia AF_INET specifica Internet domain */
    client.sin_family = AF_INET;

    /*Portul 8924 si adresa ip pentru sys.ase.ro */
    client.sin_port = htons(8924);
    client.sin_addr.s_addr = inet_addr("37.120.249.45");

    /*Initializam o conexiune la socket, speficicand socketul, un pointer de adrese si lungimea acesteia */
    connect(socketNou, (struct sockaddr*)&client, sizeof client);
  printf("Socket creat de Petcu Nicusor Dragos si pregatit pentru a trimite mesaje");
    for (;;) {
        /*Citim un animal de la tastatura */
        printf("\nIntroduceti animalul dumneavoastră favorit: ");
        scanf("%s", animal);

        /* Il trimitem catre server */
        send(socketNou, animal, sizeof(animal), 0);

        /* Primim de la server, verificatorul care poate fi 0,1 sau 2, in functie de lungimea animalului */
        recv(socketNou, &verificatorPrimit, sizeof(int), 0);
  
        /* Daca verificatorul este 1, vom afisa animalul uppercase, cu functia toupper */
        if (verificatorPrimit == 1) {
            printf("\nServer: Animalul are peste 5 caractere: %s.\n", animal);
            printf("Categorie: UpperCase:-->");

int i=0;
char caracter;
while(animal[i]){
caracter=animal[i];
putchar(toupper(caracter));
i++;
} 
            break;
        }
         /* Daca verificatorul este 2, vom afisa animalul lowercase, cu functia tolower */
else if(verificatorPrimit==2){
  printf("\nServer: Animalul are sub 5 caractere: %s.\n", animal);
            printf("Categorie: LowerCase:-->");

int i=0;
char caracter;
while(animal[i]){
caracter=animal[i];
putchar(tolower(caracter));
i++;
} 
break;
}
/* Altfel, daca verificatorul este 0, vom afisa animalul invers, folosind o variabila temp in care retinem litera pentru a o inversa */
        else {
            printf("\nServer: Animalul are exact 5 caractere.\n");
printf("Categorie: Caractere inversate: --> ");
int i=0,j=0;
char temp;
j=strlen(animal)-1;
while(i<j){
temp=animal[j];
animal[j]=animal[i];
animal[i]=temp;
i++;
j--;
}
printf("%s",animal);
/* Iesim din structura alternativa */
            break;
        }
    }

printf("\nSocketul va fi inchis de Petcu Nicusor Dragos G1089");
/* Inchidem socketul */
    close(socketNou);
}

