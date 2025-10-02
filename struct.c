#include<stdio.h>
#include<string.h>
    typedef struct
    {int id;
    char nom[20];
    float moyenne;
    } etudiant ;
    etudiant e1;
    int main (){   
    e1.id = 111;
    strcpy(e1.nom,"nisrine");
    e1.moyenne = 20;
    printf("id : %d | nom : %s | moyenne : %.2f \n",e1.id,e1.nom,e1.moyenne);
    return 0;}
    
   
    
