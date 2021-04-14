#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union nombre {char a[2];char b[2];char c[2];}nb;


int main (int argc, char* argv []){
    if((argc !=2)||(strlen(argv[1])!=6)){printf("ERREUR ARGUMENTS\n");exit(-1);}
    nb k;
    k.a[0]=argv[1][0]; k.a[1]=argv[1][1];
    int terme1= atoi(k.a);
    k.b[0]=argv[1][2]; k.b[1]=argv[1][3];
    int terme2= atoi(k.b);
    k.c[0]=argv[1][4]; k.c[1]=argv[1][5];
    int terme3= atoi(k.c);
    if(terme1<0||terme1>49||terme2<0||terme2>49||terme3<0||terme3>49){
        printf("PAS LES BONS NOMBRES\n");        
        exit(-1);    
    }
    int res= (terme1*50*50)+(terme2*50)+terme3;
    printf("%d\n",res); 
    return 0;   
}
