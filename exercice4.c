#include <stdio.h>
#include <stdlib.h>

void afficheTab(int * tab, int n){
    int i;
    for (i=0;i<n;i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
}

void copieTab(int * t1,int * t2,int n){
    int i;
    for (i=0;i<n;i++){
        t2[i]=t1[i];
    }
}

int **creeMat(int n){
	int i;
	int **m = NULL;
	m =(int**)malloc(n*sizeof(int*));
	if (m==NULL){
        exit(-1);
    }
	for(i=0;i<n+1;i++){
		m[i]=(int*)malloc(n*sizeof(int));
		if (m==NULL){
            exit(-1);
        }
	}
	return m;
}

void afficheMatcarree(int **m,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}


int tDroite(int **M,int i,int j,int n){
    if (j>=n){
            return 0;
        }
    else if  ((M[i][j]==(M[i][j+1]+1) ) | (M[i][j]==(M[i][j+1]-1))){
            return 1;
        }
    return 0;
}

int tBas(int **M,int i,int j,int n){
    if (i>=n){
            return 0;
        }
    else if  ( (M[i][j]==(M[i+1][j]+1) )  | (M[i][j]==(M[i+1][j]-1))){
            return 1;
        }
    return 0;
}

int compteLongueur(int ** M,int i,int j,int n){
    int droite=tDroite(M,i,j,n);
    int bas=tBas(M,i,j,n);
    if (j>=n){
        droite=0;
    }
    if (i>=n){
        bas=0;
    }
    if ((i==n)&&(j==n)){
        return 1;
    }
    if ((droite==0)&&(bas==0)){
        return 0;
    }
    else if ((droite==1)&&(bas==0)){
        j+=1;
        return 1+compteLongueur(M,i,j,n);
    }
    else if ((bas==1)&&(droite==0)){
        i+=1;
        return 1+compteLongueur(M,i,j,n);
    }
    else if ((droite==1)&&(bas==1)){
        int pos_x1,pos_x2,pos_y1,pos_y2;
        pos_x1=i;
        pos_y1=j+1;
        pos_x2=i+1;
        pos_y2=j;
        int d=compteLongueur(M,pos_x1,pos_y1,n);
        int b=compteLongueur(M,pos_x2,pos_y2,n);
        if (d>b){
            return d;
        }
         else{
            return b;
         }
    }
    else{
        printf("ERREUR\n");
        exit(-1);
    }
}

int RechercheSuite(int **M, int n,int * chemin,int i,int j,int k){ //la fonction envoie le dernier terme de la suite
    int droite=tDroite(M,i,j,n);
    int bas=tBas(M,i,j,n);
    while(k<2*n){  // le chemin le plus long possible est de taille 2N-1
        if ((droite==0) && (bas==0)){
            break;
        }
        else if ((droite==1) && (bas==0)){
            j+=1;
            chemin[k]=M[i][j];
            k+=1;
        }
        else if ((bas==1) && (droite==0)){
            i+=1;
            chemin[k]=M[i][j];
            k+=1;
        }

        else if ((droite==1) && (bas==1)){
            int pos_x1,pos_x2,pos_y1,pos_y2;
            pos_x1=i;
            pos_y1=j+1;
            pos_x2=i+1;
            pos_y2=j;
            int a=compteLongueur(M,pos_x1,pos_y1,n);
            int b=compteLongueur(M,pos_x2,pos_y2,n);
            if (a>=b){
                j+=1;
                chemin[k]=M[i][j];
                k+=1;
            }
            else{
                i+=1;
                chemin[k]=M[i][j];
                k+=1;
            }
        }
        droite=tDroite(M,i,j,n);
        bas=tBas(M,i,j,n);
    }
    return k;
}

int renvoieIndiceMax(int **M,int n,int * cheminMax,int iMax){ //pour tester tous les chemins et renvoyer le plus long ainsi que son indice
    int t;
    int * cheminTmp = malloc(2*n*sizeof(int));
    for (t=1;t<n;t++){
        cheminTmp[0]=M[0][t];
        int iTmp = RechercheSuite(M,n,cheminTmp,0,t,1);
        if (iTmp>iMax){
            iMax=iTmp;
            copieTab(cheminTmp,cheminMax,iMax);
        }
    }
    return iMax;
}

int main(){
    int n,i,j,tmp;
    printf("Veuillez tapper la dimension de la matrice");
    scanf("%d",&n);
    int **M=creeMat(n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("tapper la valeur de M[%d][%d]\n",i,j);
            scanf("%d",&tmp);
            M[i][j]=tmp;
        }
    }
    afficheMatcarree(M,n);
    printf("\n");
    int * cheminMax=malloc(n*sizeof(int));
    cheminMax[0]=M[0][0];
    int indiceMax = RechercheSuite(M,n,cheminMax,0,0,1);//initialisation
    indiceMax = renvoieIndiceMax(M,n,cheminMax,indiceMax);
    printf("Le chemin le plus long est :\n");
    afficheTab(cheminMax,indiceMax);
    for(int y=0;y<n;y++){
        free(M[y]);
    }
    free(M);

    return 0;
}
