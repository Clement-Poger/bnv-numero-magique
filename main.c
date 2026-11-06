#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRN "\033[0;32m"
#define RED "\033[0;31m"
#define BLU "\033[0;34m"
#define CYN "\033[0;36m"
#define BGRN "\033[1;32m"
#define BRED "\033[1;31m"
#define BBLU "\033[1;34m"
#define BCYN "\033[1;36m"
#define CRESET "\033[0m"

int main(void)
{
    int option;
    bool try_limit = false;
    bool sarcastique_mode = false;
    int nb_to_guess;
    int guess;
    int try;

    srand(time(NULL));

    menu_principal:
    printf(BBLU " ┏━  Numero Magique  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(BBLU " ┏━━━━━━━━━━━  "BLU"1"BBLU"  ━━━━━━━━━━━┓    ┏━━━━━━━━━━━  "BLU"2"BBLU"  ━━━━━━━━━━━┓\n");
    printf(BBLU " ┃       "BCYN"Lancer le Jeu"BBLU"       ┃    ┃     "BCYN"Configurer le Jeu"BBLU"     ┃\n");
    printf(BBLU " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛    ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    scanf("%d", &option);

    if (option == 2) {
        option = 0;
        while (option != 3) {
            printf(BBLU " ┏━  Liste des Options  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf("%s1. Limiter les essais à 6\n",
                   try_limit ? "\033[1;32m" : "\033[1;31m");
            printf("%s2. Sarcastique Mode\n",
                   sarcastique_mode ? "\033[1;32m" : "\033[1;31m");
            printf("3. Retour au menu\n");
            scanf("%d", &option);
            if (option == 1) {
                try_limit = !try_limit;
            } else if (option == 2) {
                sarcastique_mode = !sarcastique_mode;
            }
        }
        goto menu_principal;
    }

    nouvelle_partie:
    nb_to_guess = rand() % 100 + 1;
    try = 1;
    printf(CYN "  - Indiquez un nombre : " CRESET);
    scanf("%d", &guess);

    while (nb_to_guess != guess && (!try_limit || try < 6)) {
        if (guess >= 1 && guess <= 100) {
            int guess_is_too_low = nb_to_guess > guess;
            const char *keyword;
            if (sarcastique_mode) {
                keyword = guess_is_too_low
                    ? "Plus, essaie de réfléchir un peu "
                    : "Moins, tu peux faire mieux (non) ";
            } else {
                keyword = guess_is_too_low ? "Plus " : "Moins";
            }
            printf(BLU " ┏━━━━━━━  "BCYN"C'est %s!"BLU"  ━━━━━━━━━┓\n", keyword);
            printf(BLU " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" CRESET);
        } else {
            printf(RED "La valeur n'est pas comprise entre 1 et 100.\n" CRESET);
        }
        printf(CYN "  - Indiquez un nouveau nombre : " CRESET);
        scanf("%d", &guess);
        try++;
    }

    if (guess != nb_to_guess && try_limit) {
        printf(RED "Dommage ! Il fallait trouver %d.\n" CRESET, nb_to_guess);
    } else {
        printf(GRN "Félicitation ! Vous avez trouvé %d en %d essai(s).\n" CRESET,
               nb_to_guess, try);
    }

    printf("1. Rejouer  2. Retour au Menu  3. Arrêter : ");
    scanf("%d", &option);
    if (option == 1) {
        goto nouvelle_partie;
    } else if (option == 2) {
        goto menu_principal;
    }

    return 0;
}
