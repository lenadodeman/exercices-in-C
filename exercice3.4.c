#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectClient(char * typeCritere, char * critere) 
{

    FILE * fd = fopen("baseClient.txt", "r+");
    if(fd==NULL){ 
        perror("Problème d’ouverture de fichier");
        exit(-1) ;
    }

	char prenomCritere[]="prenom";
	char nomCritere[]="nom";
	char mailCritere[]="mail";
	char dateCritere[]="dateNaissance";
    char prenom[30];
    char nom[30];
    char mail[100];
    int nombreAchat = 0;
    char dateNaissance[20];
    int comptePrenom=0;
	int compteNom=0;
	int compteDate=0;
	int compteMail=0;
	
    while(fscanf(fd, "%s ;%s ;%s ;%s ;%d ", prenom, nom, dateNaissance, mail, &nombreAchat) != EOF)
    {
        if(strcmp(prenomCritere, typeCritere) == 0 && strcmp(prenom, critere) == 0)
        {
           	comptePrenom++;  
           	if(comptePrenom>=1)
       		{
       			printf("%s ;%s ;%s ;%s ;%d\n", prenom, nom, dateNaissance, mail, nombreAchat);
       		}
		
        }

        if((strcmp(nomCritere, typeCritere)) == 0 && (strcmp(nom, critere)) == 0)
        {
        	compteNom++; 
           	if(compteNom>=1)
       		{
       			printf("%s ;%s ;%s ;%s ;%d\n", prenom, nom, dateNaissance, mail, nombreAchat);
       		}
       		exit(1);
        }
        
        if((strcmp(dateCritere, typeCritere)) == 0 && (strcmp(dateNaissance, critere)) == 0)
        {
        	compteDate++;
        	if(compteDate>=1)
       		{
       			printf("%s ;%s ;%s ;%s ;%d\n", prenom, nom, dateNaissance, mail, nombreAchat);
       		}
			exit(1);
        }
        
        if((strcmp(mailCritere, typeCritere)) == 0 && (strcmp(mail, critere)) == 0)
        {
        	compteMail++;
        	if(compteMail>=1)
       		{
       			printf("%s ;%s ;%s ;%s ;%d\n", prenom, nom, dateNaissance, mail, nombreAchat);
       		}
			exit(1);
        }
        

        //Nous n'avons pas réussis à le faire pour le nombre d'achats.
        
        /*else if((strcmp("nbAchats", critere)) == 0)
        {
        	printf("%s ;%s ;%s ;%s ;%d \n", prenom, nom, dateNaissance, mail, nombreAchat);
        	exit(1);
        }*/
            
    }
    if(comptePrenom==0 && compteNom==0 && compteDate==0 && compteMail==0)
    {
    	printf("Client not Found\n");
    }
    
    fclose(fd);
}

int main(int argc, char * argv[])
{
    if (argc < 3)
    {
        printf("Le nombre d'arguments pour la selection de client est insuffisant.\n");
        exit(-1);
    }
    char * typeCritere = argv[1];
    char * critere = argv[2];

    selectClient(typeCritere,critere);
    
    
    return 0;
}
