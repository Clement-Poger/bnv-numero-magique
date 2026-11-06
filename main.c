#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int nb_to_guess;
    int guess;

    srand(time(NULL));
    nb_to_guess = rand() % 100 + 1;

    printf("Je viens de choisir un nombre entier entre 1 et 100.\n");
    printf("Indiquez un nombre : ");
    scanf("%d", &guess);

    if (guess == nb_to_guess) {
        printf("Félicitation ! Vous avez trouvé %d.\n", nb_to_guess);
    } else {
        printf("Dommage ! Il fallait trouver %d.\n", nb_to_guess);
    }

    return 0;
}
