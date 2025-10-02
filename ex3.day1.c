#include <stdio.h> 
{
    float r;
    float pi=3.14;
    float volume;
    printf("entrer le rayon");
    scanf("%f",&r);
    volume =(4.0f/3.0f)*pi*(r*r*r);
    printf("%f",volume);
   
    return 0;
}