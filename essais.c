#include <stdio.h>
int main()
{
    int t[100], v, i,x, j, temp,r,f=0; 
    // nekhetar che7al men case f tableau
    printf("entrer v:");
    scanf("%d", &v);
    // n3emer tableau
    for (i = 0; i < v; i++)
    {
        printf("remplir le tableau:");
        scanf("%d", &t[i]);
    }
    // afficher tableau
    for (i = 0; i < v; i++)
    {
        printf("%d\n", t[i]);
    }
    // applique tri
    printf("------\n");
    for (i = 0; i < v; i++)
    {
        for (j = i + 1; j < v; j++)
        {
            if (t[i] > t[j])
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
   
 }
    // affichage de tableau
    for (i = 0; i < v; i++)
    {
        printf("%d\n", t[i]);
    }
    // (recherche 
    printf("entrer r : ");
    scanf("%d",&r);
    
    for(i=0;i<v;i++){
        if(r==t[i]){
            //printf("%d",t[i]);
           
            x = i;
            f=1;
        }
    }
        
    if(f==0){
        printf("n'exist pas");
    }
    else
    {
        printf("%d",t[x]);
    }


    return 0;
}
