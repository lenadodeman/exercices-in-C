#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ajoutClient2(char*prenom,char*nom,char*naissance,char*mail)
{
	FILE*fd=fopen("baseClient.txt","a+");
	if(fd==NULL)
	{
		perror("Problème dans le fichier.\n"); 
		exit(1);
	}
	
	//Si le '?' est ailleurs que pour le mail ou la date de naissance.
	char none[]= "?";
	char noneClient[]="NONE";
	if(strcmp(prenom,none)==0)
	{
		printf("Le prénom doit être fourni.\n");
		exit(1);
	}
	else if(strcmp(nom,none)==0)
	{
		printf("Le nom doit être fourni.\n");
		exit(1);
	}
	
	//Remplacement du '?' du terminal par NONE dans la ligne client du fichier.
	if(strcmp(naissance,none)==0)
	{
		fprintf(fd,"%s ;%s ;%s ;%s ;",prenom,nom,noneClient,mail);
	}
	
	if(strcmp(mail,none)==0)
	{
		fprintf(fd,"%s ;%s ;%s ;%s ;",prenom,nom,naissance,noneClient);
	}
	else if(strcmp(naissance,none)!=0 && strcmp(mail,none)!=0)
	{
		fprintf(fd,"%s ;%s ;%s ;%s ;",prenom,nom,naissance,mail);
	}
	int nbAchats=0;
	fprintf(fd,"%d\n",nbAchats);
	fclose(fd);
}


int main(int argc, char * argv[])
{
	if (argc<5)
	{
		printf("Nombre d'éléments insuffisant pour un client.\n");
		exit(1);
	}
	
	char * prenomClient = argv[1];
	char * nomClient = argv[2];
	char * dateNaissanceClient = argv[3];
	char * mailClient = argv[4];
	ajoutClient2(prenomClient,nomClient,dateNaissanceClient,mailClient);


return 0;
}
