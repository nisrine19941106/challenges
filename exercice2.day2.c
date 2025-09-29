#include <stdio.h>
                 // affiche ce nombre avec ses chiffres inversés.28(n % 10 , n / 10)
int main(void){
    int n=28;
    int unite;
    int dizaines;
    int inverse;
    printf("entrer n");
    scanf("%d",&n);
    unite = n % 10;
    dizaines = n / 10;
    inverse = unite * 10 + dizaines;
    printf("le nombre inverse est : %d",inverse);
    return 0;}
