#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void incAchat(char * nomClient, char * prenomClient) {

    FILE * fd = fopen("baseClient.txt", "r+");
    if(fd==NULL){ 
        perror("Problème d’ouverture de fichier");
        exit(-1) ;
    }

    char prenom[30];
    char nom[30];
    char dateClient[20];
    char mail[100];
    int nbAchats = 0;
    char date[20];
    int compte = 0;

    while(fscanf(fd, "%s ;%s ;%s ;%s ;%d ", prenom, nom, date, mail, &nbAchats) != EOF)
    {
        if((strcmp(prenom, prenomClient)) == 0 && (strcmp(nom, nomClient) == 0))
        {
            compte++;
        }
    }

    if(compte == 0) 
    {
        printf("Ce client n'existe pas dans la base de donnees.\n");
    }
    else if (compte > 1)
    {
        printf("Veuillez entrer la date de naissance du client: ");
        scanf("%s", date);
    }
    

    fseek (fd, 0, SEEK_SET);

    int position = 0;
    
    while(fscanf(fd, "%s ;%s ;%s ;%s ;%d ", prenom, nom, dateClient, mail, &nbAchats) != EOF)
    {   
        if((strcmp(prenom, prenomClient)) == 0 && (strcmp(nom, nomClient) == 0)) 
        {
            if(compte == 1) 
            {
                nbAchats++;
                fseek(fd, position, SEEK_SET);
                fprintf(fd, "%s ;%s ;%s ;%s ;%d\n", prenom, nom, dateClient, mail, nbAchats);
                fflush(fd);

            }
            else if(compte > 1)
            {
                if(strcmp(dateClient, date) == 0) 
                {
                    nbAchats++;
                    fseek(fd, position, SEEK_SET);
                    fprintf(fd, "%s ;%s ;%s ;%s ;%d\n", prenom, nom, dateClient, mail, nbAchats);
                    fflush(fd);
                }
            }
        }
        
        position = ftell(fd);
    }
    
    fclose(fd);
}

int main(int argc, char * argv[])
{
    if (argc < 3)
    {
        printf("Le nombre d'arguments pour une incrementation d'achats est insuffisant.\n");
        exit(-1);
    }
    char * prenomClient = argv[1];
    char * nomClient = argv[2];

    incAchat(nomClient, prenomClient);
    
    return 0;
}
