#include <stdio.h>
#include <string.h>
    typedef struct
    {char CNE [20];
     char NOM [40];
     char PRENOM [10];
     float note [4];    // 4 notes fixe
     float moyenne;}Etudiant;
Etudiant classe [30];  // max 30 etudiant
int nbetudiant=0 ;
void affichercadre(){   // afficher menu principale
    printf("1* ajouter une étudint \n :");
    printf("2* saisir les notes d'un étudiant \n :");
    printf("3* afficher tous les étudiants \n :");
    printf("4* afficher bulletin \n");
    printf("5* calculet la moyenne \n");
    printf("0* quitter \n");}
void ajouteretudiant (){     // ajouter un étudiant
  if (nbetudiant>=30){
                       printf("impossible d'ajouter plus de 30 d'étudiant \n :");return}
    printf("ajouter un etudiant\n");
    printf("enter CNE \n :");
    scanf("%s",classe[nbetudiant].CNE);
    printf("enter Nom \n :");
    scanf("%s",classe[nbetudiant].NOM);
    printf("entrer PRENOM \n :");
    scanf("%s",classe[nbetudiant].PRENOM);

for(int j=0;j<4;j++){
    printf("enter la note \n :");
    scanf("%f",classe[nbetudiant].note[j]);}
nbetudiant++;} 

void afficheretudiant(){       // afficher les tous les étudiants
  if(nbetudiant==0){
printf("aucun etudiant trouver\n");
return;}
  for (int i=0; i<= nbetudiant;i++){ 
    printf("CNE :%s | nom:%s | prenom : %s \n",classe[i].CNE,classe[i].NOM,classe[i].PRENOM);
  }}