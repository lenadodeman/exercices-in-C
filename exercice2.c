#include <stdio.h>


void affiche1 ( int t[], int n){
    int i;
    for(i=0;i<n;i+=2){
        printf("T[%d]= %d\n",i,t[i]);
    }
    for(i=1;i<n;i+=2){
        printf("T[%d]= %d\n",i,t[i]);      
    }
}

void affiche2 ( int t[], int n){
    int i;
    for(i=0;i<n/2;i++){
        printf("T[%d]= %d, T[%d]= %d\n",i,t[i],n-1-i,t[n-1-i]);    
    }
    if(n%2!=0){
        printf("T[%d]= %d\n",(n-1)/2,t[(n-1)/2]);
    }
}

void afficheTab( int t[], int n, void (*fonct)(int *,int)){
    if(fonct==NULL){
        int i;
        for(i=n;i>0;i--){
             printf("T[%d]= %d\n",i-1,t[i-1]);      
        }       
    }
    else{
        fonct(t,n);
    }
}

int main (){
    int M[5]={1,2,3,4,5};
    affiche1(M,5);
    affiche2(M,5);
    afficheTab(M,5,NULL);
    return 0;
}
