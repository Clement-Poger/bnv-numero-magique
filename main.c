#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int nb_to_guess;
    int guess;
    int try = 1;

    srand(time(NULL));
    nb_to_guess = rand() % 100 + 1;

    printf("Je viens de choisir un nombre entier entre 1 et 100.\n");
    printf("A toi de le deviner. Bon Courage.\n");
    printf("Indiquez un nombre : ");
    scanf("%d", &guess);

    while (nb_to_guess != guess) {
        if (guess >= 1 && guess <= 100) {
            if (nb_to_guess > guess) {
                printf("Plus !\n");
            } else {
                printf("Moins\n");
            }
        } else {
            printf("La valeur n'est pas comprise entre 1 et 100.\n");
        }

        printf("Indiquez un nouveau nombre : ");
        scanf("%d", &guess);
        try++;
    }

    printf("Félicitation ! Vous avez trouvé %d en %d essai(s).\n",
           nb_to_guess, try);
    return 0;
}
