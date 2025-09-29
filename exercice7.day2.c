#include <stdio.h>
//                                Écrivez un programme qui demande à l'utilisateur d'entrer un nombre n, puis
//                                 affiche tous les carrés pairs compris entre 1 et n.
int main(void)
{
    int n;
    int i;
    int carre;
    printf("entrer n :");
    scanf("%d", &n);

    for (i = 1; i * i <= n; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d", i);
        }
    }

    return 0;
}