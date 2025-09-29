#include <stdio.h>
#include <math.h>   // باش نستعمل pow 

int main() {
    int x;
    double resultat ;
     printf("enter x : %d, ");
     scanf ("%d,&x");

        resultat = 3*pow(x,5)+2*pow(x,4)-5*pow(x,3)-pow(x,2)+7*x-6 ;
     printf ("la valeur de x est : %.2f",resultat);

    return 0;
}
