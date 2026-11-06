#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRN "\033[0;32m"
#define RED "\033[0;31m"
#define BLU "\033[0;34m"
#define CYN "\033[0;36m"
#define BGRN "\033[1;32m"
#define BBLU "\033[1;34m"
#define BCYN "\033[1;36m"
#define CRESET "\033[0m"

int main(void)
{
    int option;
    int nb_to_guess;
    int guess;
    int try;

    srand(time(NULL));
    printf(BBLU " ┏━  Numero Magique  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(BBLU " ┃       "BCYN"Lancer le Jeu"BBLU"                                      ┃\n");
    printf(BBLU " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

    nouvelle_partie:
    nb_to_guess = rand() % 100 + 1;
    try = 1;
    printf(CYN "  - Indiquez un nombre : " CRESET);
    scanf("%d", &guess);

    while (nb_to_guess != guess) {
        if (guess >= 1 && guess <= 100) {
            printf(BLU " ┏━━━━━━━  "BCYN"C'est %s!"BLU"  ━━━━━━━━━┓\n",
                   nb_to_guess > guess ? "Plus" : "Moins");
            printf(BLU " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" CRESET);
        } else {
            printf(RED "La valeur n'est pas comprise entre 1 et 100.\n" CRESET);
        }
        printf(CYN "  - Indiquez un nouveau nombre : " CRESET);
        scanf("%d", &guess);
        try++;
    }

    printf(GRN " ┏━  Numero Magique  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(GRN " ┃ "BGRN"Félicitation ! Vous avez trouvé %d en %d essai(s)."GRN" ┃\n",
           nb_to_guess, try);
    printf(GRN " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" CRESET);
    printf("1. Rejouer  2. Arrêter : ");
    scanf("%d", &option);
    if (option == 1) {
        goto nouvelle_partie;
    }

    return 0;
}
