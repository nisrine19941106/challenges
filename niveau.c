#include<stdio.h>
int main(){
     int t[100],i,somme=0,moyenne,v ,r,max=0,min=0;

     // numero d case sur tableau
     printf("entrer v:");
    scanf("%d", &v); 
      
    // remplir
    for(i=0; i<v ; i++){
    printf("remplir le tableau :");
    scanf("%d",&t[i]);

    somme = somme + t[i];
    moyenne = somme / v;
    }
    //  resultat
    printf("La somme = %d\n", somme);
    printf("La moyenne = %d\n", moyenne);
    // max / min 
    for(i =0 ; i < v; i++) {
        if(t[i] > max) {
            max = t[i];
        }
    }
    min=t[0];
    for(int j =0 ; j < v; j++) {
       
        if(t[j] < min) {
            min = t[j];
        }
    }
  // affichge :
  
    printf("Le plus grand = %d\n", max);
    printf("Le plus petit = %d\n", min);

    
    

return 0 ;}
        

