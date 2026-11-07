// Appel des libraires nécessaires
#include <stdio.h>
#include <stdlib.h>
#include <time.h>      // Pour le Nombre Aléatoire
#include <math.h>      // Pour pouvoir utiliser des logarithmes
#include <string.h>    // Pour pouvoir répéter des caractères
#include <stdbool.h>   // Pour pouvoir utiliser des booleens


// Table de couleur provenant de https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
// Couleurs Basiques
#define GRN "\033[0;32m"
#define RED "\033[0;31m"
#define BLU "\033[0;34m"
#define CYN "\033[0;36m"

// Couleurs en Gras
#define BGRN "\033[1;32m"
#define BRED "\e[1;31m"
#define BBLU "\033[1;34m"
#define BCYN "\033[1;36m"

// Reset les Couleurs
#define CRESET "\033[0m"


int main() {
    // Répitition de caractère n fois [Plus d'info dans AIDE_EXTERIEURE.md]
    #define REPEAT_STRING(name, count, character)             \
        int name##_length = (count);                          \
        if (name##_length < 0) {                              \
            name##_length = 0;                                \
        }                                                     \
        char *name = malloc((size_t)name##_length + 1);       \
        if (name != NULL) {                                   \
            memset(name, (character), (size_t)name##_length); \
            name[name##_length] = '\0';                       \
        }

    // Initialisation du Menu Principal et de ses options
    int option;
    bool try_limit = false;
    bool show_plage = false;
    bool sarcastique_mode = false;

    // Menu Principal ou d'Accueil permettant de naviguer entre la config ou lancer des jeux
    menu_principal:
    system("clear");
    printf(BBLU " ┏━  Numero Magique  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf(BBLU " ┃  "BLU"Bonjour. Avant de lancer une partie, vous pouvez "BBLU"         ┃\n");
    printf(BBLU " ┃  "BLU"activer ou non des options pour vous aider... ou "BBLU"         ┃\n");
    printf(BBLU " ┃  "BLU"vous handicaper. "BBLU"                                         ┃\n");
    printf(BBLU " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf(BBLU " ┏━━━━━━━━━━━  "BLU"1"BBLU"  ━━━━━━━━━━━┓    ┏━━━━━━━━━━━  "BLU"2"BBLU"  ━━━━━━━━━━━┓\n");
    printf(BBLU " ┃       "BCYN"Lancer le Jeu"BBLU"       ┃    ┃     "BCYN"Configurer le Jeu"BBLU"     ┃\n");
    printf(BBLU " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛    ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf(CYN "  - Indiquez l'option (1-2): " CRESET);
    scanf("%d", &option);
    
    // Cas d'Erreur quand option ne vaut pas 1 ou 2
    if ((1 > option) || (option > 2)) {
        printf(RED " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf(RED " ┃         "BRED"La valeur n'est pas comprise entre 1 et 2. "RED"        ┃\n");
        printf(RED " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" CRESET);
        goto menu_principal;
    
    // Cas où le joueur choisi 2 et donc le menu de config
    } else if (option == 2) {
        // Reset de la variable option
        option = 0;

        // Boucle d'affichage du menu évoluant en fonction des choix du joueur
        while (option != 4) {
            system("clear");
            printf(BBLU " ┏━  Liste des Options  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf(BBLU " ┃  "BLU"Vous pouvez switch une option en ecrivant son numéro.     "BBLU"┃\n");
            printf(BBLU " ┃  "CYN"Retour au menu "BLU"n'est évidement pas une option. :).        "BBLU"┃\n");
            printf(BBLU " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
            printf(BBLU " %s┏━━━━━━━━━━━  1.  ━━━━━━━━━━━┓  %s┏━━━━━━━━━━━  2.  ━━━━━━━━━━━┓\n", try_limit ? "\e[1;32m" : "\033[1;31m", show_plage ? "\e[1;32m" : "\033[1;31m");
            printf(BBLU " %s┃   Limiter les essais à 6   ┃  %s┃ Afficher la plage restante ┃\n", try_limit ? "\e[1;32m" : "\033[1;31m", show_plage ? "\e[1;32m" : "\033[1;31m");
            printf(BBLU " %s┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛  %s┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n", try_limit ? "\e[1;32m" : "\033[1;31m", show_plage ? "\e[1;32m" : "\033[1;31m");
            printf(BBLU " %s┏━━━━━━━━━━━  3.  ━━━━━━━━━━━┓  "BLU"┏━━━━━━━━━━━  4.  ━━━━━━━━━━━┓\n", sarcastique_mode ? "\e[1;32m" : "\033[1;31m");
            printf(BBLU " %s┃      Sarcastique Mode      ┃  "BLU"┃       Retour au menu       ┃\n", sarcastique_mode ? "\e[1;32m" : "\033[1;31m");
            printf(BBLU " %s┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛  "BLU"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n", sarcastique_mode ? "\e[1;32m" : "\033[1;31m");
            printf(CYN "  - Indiquez l'option (1-4): " CRESET);
            scanf("%d", &option);
            if (option == 1) {
                try_limit = !try_limit;
            } else if (option == 2) {
                show_plage = !show_plage;
            } else if (option == 3) {
                sarcastique_mode = !sarcastique_mode;
            }
        }
        goto menu_principal;        
    } else {
        // Debut d'une partie
        nouvelle_partie:
        // On utilise le bloc donné dans l'énnoncé pour le nombre random
        srand(time(NULL));
        int nb_to_guess = rand() % 100 + 1;

        // Creation de `guess` (l'essai du joueur), de `try` (le nombre d'essai)
        // de `min` (l'essai du joueur) et de `max` (l'essai du joueur). 
        int guess;
        int try = 1;
        int min = 1;
        int max = 100;

        // Texte du lancement de la partie avec les options validés par l'utilisateur
        system("clear");
        printf(BBLU " ┏━  Numero Magique  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf(BBLU " ┃  "BLU"Je viens de choisir un nombre entier entre 1 et 100."BBLU"      ┃\n");
        printf(BBLU " ┃  "BLU"A toi de le deviner. Bon Courage."BBLU"                         ┃\n");
        printf(BBLU " ┃                                                            ┃\n");
        printf(BBLU " ┃  "BLU"Options:                                                  ┃\n");
        printf(BBLU " ┃     - %sLimiter les essais à 6"BBLU"                               ┃\n", try_limit ? "\e[1;32m" : "\033[1;31m");
        printf(BBLU " ┃     - %sAfficher la plage restante"BBLU"                           ┃\n", show_plage ? "\e[1;32m" : "\033[1;31m");
        printf(BBLU " ┃     - %sSarcastique Mode"BBLU"                                     ┃\n", sarcastique_mode ? "\e[1;32m" : "\033[1;31m");
        printf(BBLU " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" CRESET);
        printf(CYN "  - Indiquez un nombre: " CRESET);
        scanf("%d", &guess);

        // Boucle de Jeu :
        //         - On check le nombre du joueur
        //         - On affiche la "box" avec les options de la partie
        while (nb_to_guess != guess && (!try_limit || try < 6)) {
            system("clear");
            
            // Cas où le joueur indique un nombre valide
            if (guess >= 1 && guess <= 100) {
                
                // Calcul de la position du nombre à trouver
                int guess_is_too_low = nb_to_guess > guess;
                const char *keyword;

                // Variation du texte en fonction du mode Sarcastique
                if (sarcastique_mode) {
                    keyword = guess_is_too_low
                        ? "Plus, essaie de réfléchir un peu "
                        : "Moins, tu peux faire mieux (non) ";
                } else {
                    keyword = guess_is_too_low ? "Plus " : "Moins";
                }

                // Cas où le joueur a choisi d'afficher la plage restante
                if (show_plage) {

                    // Chaque indice resserre la plage possible du nombre secret.
                    if (guess_is_too_low) {
                        min = (guess > min) ? guess : min;
                    } else {
                        max = (guess < max) ? guess : max;
                    }

                    // Calcul du nombre de caractère à placer pour chaque bout de barre.
                    // left  : entre 0 et le nombre le plus proche inférieur au nombre à trouver.
                    // right : entre 100 et le nombre le plus proche supérieur au nombre à trouver.
                    // mid   : entre le nombre le plus proche inférieur au nombre à trouver et
                    //         le nombre le plus proche supérieur au nombre à trouver.
                    int left_bar_prog = ((min - 1) * 50) / 100;
                    int right_bar_prog = ((100 - max) * 50) / 100;
                    int mid_bar_prog = 50 - (left_bar_prog + right_bar_prog);

                    // Répétition des caractères d'après la macro au début du main.
                    REPEAT_STRING(left_bar, left_bar_prog, '-');
                    REPEAT_STRING(right_bar, right_bar_prog, '-');
                    REPEAT_STRING(mid_bar, mid_bar_prog, '=');
                    
                    // Ajustation des espaces à la taille des nombres
                    int min_length = (try == 0) ? 1 : (int)log10(min) + 1;
                    int max_length = (try == 0) ? 1 : (int)log10(max) + 1;
                    REPEAT_STRING(min_sp_needed, 4 - min_length, ' ');
                    REPEAT_STRING(max_sp_needed, 4 - max_length, ' ');

                    // Box affichant la plage restantes
                    printf(BLU " ┏━━━━━━━  "BCYN"C'est %s!"BLU"  ━━━━━━━━━┓\n", keyword);
                    printf(BLU " ┃%s"BCYN"%d "RED"%s"BGRN"%s"RED"%s "BCYN"%d"BLU"%s┃\n",
                           min_sp_needed, min, left_bar, mid_bar, right_bar, max, max_sp_needed);
                    printf(BLU " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" CRESET);
                } else {
                    // Cas où le joueur n'a pas l'option "Afficher la plage restante"
                    // Box affichant juste la réaction au nombre de l'utilisateur
                    printf(BLU " ┏━━━━━━━  "BCYN"C'est %s!"BLU"  ━━━━━━━━━┓\n", keyword);
                    printf(BLU " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" CRESET);
                }

            } else {
                // Cas où le joueur n'indique pas un nombre entre 1 et 100.
                printf(RED " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
                printf(RED " ┃        "BRED"%s"RED"        ┃\n",
                    sarcastique_mode
                        ? "Entre 1 et 100, ce n'est pas clair pour toi!"
                        : "La valeur n'est pas comprise entre 1 et 100.");
                printf(RED " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" CRESET);
            }
            // Nouvelle proposition d'input
            printf(CYN "  - Indiquez un nouveau nombre: " CRESET);
            scanf("%d", &guess);
            try++;
        }

        system("clear");
        if (guess != nb_to_guess && try_limit) {
            // Cas où le joueur perd
            int nb_to_guess_length =
                (nb_to_guess == 0) ? 1 : (int)log10(nb_to_guess) + 1;

            // Calcul des Espaces pour centrer l'affichage
            REPEAT_STRING(spaces_needed,
                          (31 - nb_to_guess_length) / 2, ' ');
            REPEAT_STRING(middle_space_needed,
                          (31 - nb_to_guess_length) % 2, ' ');
            
            // Affichage de la "box" de défaite
            printf(RED " ┏━  Numero Magique  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf(RED " ┃%s"BRED"%s%s! Il fallait trouver %d."RED"%s┃\n"
                    , spaces_needed,
                    sarcastique_mode ? "Fail x6" : "Dommage",
                    middle_space_needed, nb_to_guess, spaces_needed);
            printf(RED " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" CRESET);
        } else {
            // Cas où le joueur gagne
            int nb_to_guess_length =
                (nb_to_guess == 0) ? 1 : (int)log10(nb_to_guess) + 1;
            int try_length = (try == 0) ? 1 : (int)log10(try) + 1;

            // Calcul des Espaces pour centrer l'affichage
            REPEAT_STRING(spaces_needed,
                          (15 - nb_to_guess_length - try_length) / 2, ' ');
            REPEAT_STRING(middle_space_needed,
                          (15 - nb_to_guess_length - try_length) % 2, ' ');
            
            // Affichage de la "box" de victoire
            printf(GRN " ┏━  Numero Magique  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            printf(GRN " ┃%s"BGRN"%s%s! Vous avez trouvé %d en %d essai(s).%s"GRN"┃\n",
                spaces_needed,
                sarcastique_mode ? "Et bah enfin" : "Félicitation",
                middle_space_needed, nb_to_guess, try, spaces_needed);
            printf(GRN " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" CRESET);
        }
    }
    // Menu de fin avec la possibilité de relancer une partie
    menu_de_fin:
    option = 0;
    printf(BBLU " "GRN"┏━━━━━━  "BGRN"1"GRN"  ━━━━━━┓  "CYN"┏━━━━━━  "BCYN"2."CYN"  ━━━━━━┓  "RED"┏━━━━━━  "BRED"3"RED"  ━━━━━━┓\n");
    printf(BBLU " "GRN"┃     "BGRN"Rejouer"GRN"     ┃  "CYN"┃  "BCYN"Retour au Menu"CYN"  ┃  "RED"┃     "BRED"Arrêter"RED"     ┃\n");
    printf(BBLU " "GRN"┗━━━━━━━━━━━━━━━━━┛  "CYN"┗━━━━━━━━━━━━━━━━━━┛  "RED"┗━━━━━━━━━━━━━━━━━┛\n");
    printf(CYN "  - Indiquez l'option (1-3): " CRESET);
    scanf("%d", &option);
    
    if ((1 > option) || (option > 3)) {
        // Cas où la valeur n'est pas égal à 1, 2 ou 3
        system("clear");
        printf(RED " ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf(RED " ┃         "BRED"La valeur n'est pas comprise entre 1 et 3. "RED"        ┃\n");
        printf(RED " ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" CRESET);
        goto menu_de_fin;
    } else if (option == 3) {
        // Cas où le joueur quitte
        exit(0);
    } else if (option == 2) {
        // Cas où le joueur retourne au menu
        goto menu_principal;
    } else {
        // Cas où le joueur relance une partie
        goto nouvelle_partie;
    }
    
    
}