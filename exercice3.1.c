#include <stdio.h>
#include <stdlib.h>

void ajoutClient(char*prenom,char*nom,char*naissance,char*mail)
{
	FILE*fd=fopen("baseClient.txt","a+");
	if(fd==NULL)
	{
		perror("Problème dans le fichier.\n"); 
		exit(1);
	}
	
	fprintf(fd,"%s ;%s ;%s ;%s ;",prenom,nom,naissance,mail);
	int nbAchats=0;
	fprintf(fd," %d\n",nbAchats);
	fclose(fd);
}

int main(int argc, char * argv[])
{
	if (argc<5)
	{
		printf("Nombre d'éléments insuffisant pour un client.\n");
		exit(-1);
	}
	
	char * prenomClient = argv[1];
	char * nomClient = argv[2];
	char * dateNaissanceClient = argv[3];
	char * mailClient = argv[4];
	ajoutClient(prenomClient,nomClient,dateNaissanceClient,mailClient);
	

return 0;
}
