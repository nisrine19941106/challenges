#include <stdio.h>

int main(void) {
    int GS1, IDG, CDE, NA, CC;

    printf("Entrez l'ISBN : ");
    scanf("%d-%d-%d-%d-%d",&GS1, &IDG, &CDE, &NA, &CC);
    
    printf("préfixe GS1 :%d\n",GS1);
    printf("identifiant de groupe :%d\n",IDG);
    printf("code de l'editeur :%d\n",CDE);
    printf("numero d'article :%d\n",NA);
    printf("chiffre de controle :%d\n",CC); 
     return 0;
}