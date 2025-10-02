#include <stdio.h> 
int main(void) 
{ 
  float mont;
  float r=0.05;
  printf("afficher le montant");
  scanf("%f",&mont);
  float total=mont*r+mont;
  printf("Avec taxe ajoutée : $%f",total);
return 0; 
}