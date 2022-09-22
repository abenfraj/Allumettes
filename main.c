#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_CHAR_PLAYER_NAME 16

void save_history(char player_name[], int result)
{
    FILE *fp;
    fp = fopen("history.txt", "a");
    switch (result)
    {
    case 0:
        fprintf(fp, "%s a gagne (Joueur contre Joueur)\n", player_name);
        fclose(fp);
        break;
    case 1:
        fprintf(fp, "%s a gagne (Joueur contre IA - Facile)\n", player_name);
        fclose(fp);
        break;
    case 2:
        fprintf(fp, "%s a perdu (Joueur contre IA - Facile)\n", player_name);
        fclose(fp);
        break;
    case 3:
        fprintf(fp, "%s a gagne (Joueur contre IA - Difficile\n", player_name);
        fclose(fp);
        break;
    case 4:
        fprintf(fp, "%s a perdu (Joueur contre IA - Difficile\n", player_name);
        fclose(fp);
        break;
    default:
        break;
    }
}

int check_player_name_input(char player_name[])
{
    if (strlen(player_name) > MAX_CHAR_PLAYER_NAME)
    {
        printf("Veuillez respecter la limite de caracteres (%d caracteres max)\n\n", MAX_CHAR_PLAYER_NAME);
        return 0;
    }
    return 1;
}

void printmatches(int matches)
{
    for (int i = 0; i < matches; ++i)
    {
        printf("| ");
    }
}

void pvp_mode(char player_name1[], char player_name2[])
{
    int matches = 30;
    char p1Matches = 0;
    char p2Matches = 0;
    srand(time(NULL));

    printf("Jeu contre un humain en local avec %d allumettes au depart.\n\n", matches);
    do
    {
        printmatches(matches);
        printf("\t- Il reste %d allumettes\n\n", matches);
        printf("Votre tour - Nombre d'allummettes a enlever (entre 1 et 3) : ");
        scanf(" %s", &p1Matches);
        while (p1Matches < 49 || p1Matches > 51 || strlen(&p1Matches) > 1)
        {
            printf("On ne peut pas faire ca... :/\n");
            printf("Votre tour - Nombre d'allummettes a enlever (entre 1 et 3) : ");
            scanf(" %s", &p1Matches);
        }

        int nbMatches = p1Matches - 48;
        matches -= nbMatches;

        if (matches <= 0)
        {
            printf("\nBravo %s (J2), tu as gagne contre %s (J1) !\n", player_name2, player_name1);
            save_history(player_name2, 0);
            break;
        }
        else
        {
            printmatches(matches);
            printf("\t- Il reste %d allumettes\n\n", matches);
            printf("Votre tour - Nombre d'allummettes a enlever (entre 1 et 3) : ");
            scanf(" %s", &p1Matches);

            while (p1Matches < 49 || p1Matches > 51 || strlen(&p1Matches) > 1)
            {
                printf("On ne peut pas faire ca... :/\n");
                printf("Votre tour - Nombre d'allummettes a enlever (entre 1 et 3) : ");
                scanf(" %s", &p1Matches);
            }

            int nbMatches = p1Matches - 48;
            matches -= nbMatches;

            if (matches <= 0)
            {
                printf("\nBravo %s (J1), tu as gagne contre %s (J2) !\n", player_name1, player_name2);
                save_history(player_name1, 0);
                break;
            }
        }
    } while (matches > 0);
    return;
}

void pvp_mode_menu()
{
    char player_name1[MAX_CHAR_PLAYER_NAME] = {};
    char player_name2[MAX_CHAR_PLAYER_NAME] = {};

    printf("\n\nVous avez rejoint le mode Joueur contre Joueur !\n");
    do
    {
        printf("Nom joueur 1 : ");
        scanf("%s", player_name1);
    } while (check_player_name_input(player_name1) != 1);
    do
    {
        printf("Nom joueur 2 : ");
        scanf("%s", player_name2);
    } while (check_player_name_input(player_name2) != 1);

    pvp_mode(player_name1, player_name2);
}

void easy_ia_mode()
{
    int matches = 30;
    char p1Matches = 0;
    int iaMatches = 0;
    srand(time(NULL));

    printf("Jeu contre l'ordinateur, niveau facile avec %d allumettes au depart.\n\n", matches);
    do
    {
        printmatches(matches);
        printf("\t- Il reste %d allumettes\n\n", matches);
        printf("Votre tour - Nombre d'allummettes a enlever (entre 1 et 3) : ");
        scanf(" %s", &p1Matches);
        while (p1Matches < 49 || p1Matches > 51 || strlen(&p1Matches) > 1)
        {
            printf("On ne peut pas faire ca... :/\n");
            printf("Votre tour - Nombre d'allummettes a enlever (entre 1 et 3) : ");
            scanf(" %s", &p1Matches);
        }
        int nbMatches = p1Matches - 48;
        matches -= nbMatches;
        if (matches <= 0)
        {
            printf("\nPerdu ! L'important c'est de participer, tu sais ? :(\n");
            save_history("Un utilisateur", 2);
            return;
        }
        else
        {
            printmatches(matches);
            printf("\t- Il reste %d allumettes\n\n", matches);
            iaMatches = rand() % 3 + 1;
            printf("L'ordinateur retire aleatoirement %d allumettes\n", iaMatches);
            matches -= iaMatches;
        }
    } while (matches > 0);
    printf("\nBien joue tu as remporte la partie !\n");
    save_history("Un utilisateur", 1);
}

void hard_ia_mode()
{
    int matches = 30;
    char p1Matches = 0;
    int iaMatches = 0;
    srand(time(NULL));

    printf("Jeu contre l'ordinateur, niveau facile avec %d allumettes au depart.\n\n", matches);

    do
    {
        printmatches(matches);
        printf("\t- Il reste %d allumettes\n\n", matches);
        printf("Votre tour - Nombre d'allummettes a enlever (entre 1 et 3) : ");
        scanf(" %s", &p1Matches);
        while (p1Matches < 49 || p1Matches > 51 || strlen(&p1Matches) > 1)
        {
            printf("On ne peut pas faire ca... :/\n");
            printf("Votre tour - Nombre d'allummettes a enlever (entre 1 et 3) : ");
            scanf(" %s", &p1Matches);
        }

        int nbMatches = p1Matches - 48;
        matches -= nbMatches;

        if (matches <= 0)
        {
            printf("\nPerdu ! L'important c'est de participer, tu sais ? :(\n\n");
            save_history("Un utilisateur", 4);

            return;
        }
        else
        {
            printmatches(matches);
            printf("\t- Il reste %d allumettes\n\n", matches);
            iaMatches = (matches % 4) - 1;
            if (iaMatches == 0)
            {
                iaMatches = 1;
            }
            if (iaMatches < 0)
            {
                iaMatches = 3;
            }
            printf("L'ordinateur retire %d allumettes\n", iaMatches);
            matches -= iaMatches;
        }
    } while (matches > 0);
    printf("\nBien joue vous avez remporte la partie !");
    save_history("Un utilisateur", 3);
}

void pvia_mode_menu()
{
    int difficulty_choice = 0;

    printf("\nChoisis le niveau de difficulte\n");
    printf("1. Facile\n2. Difficile\n");
    scanf("%d", &difficulty_choice);
    switch (difficulty_choice)
    {
    case 1:
        easy_ia_mode();
        break;
    case 2:
        hard_ia_mode();
        break;
    default:
        printf("Cette entree n'est pas reconnue, veuillez reessayer");
        break;
    }
}

void game_mode_choice()
{
    int game_mode_choice = 0;

    printf("\nA quel mode de jeu tu veux jouer ?\n");
    printf("1. Mode Humain\n2. Mode Ordinateur\n");
    scanf("%d", &game_mode_choice);
    switch (game_mode_choice)
    {
    case 1:
        pvp_mode_menu();
        break;
    case 2:
        pvia_mode_menu();
        break;
    default:
        printf("Cette entree n'est pas reconnue, veuillez reessayer");
        break;
    }
}

void show_rules()
{
    printf("\n\n*****REGLES*****\n\n");
    printf("Le but du jeu est simple:\n");
    printf("Ce jeu se joue a deux. Vous avez un nombre n d'allumettes.\n");
    printf("A tour de role, chacun des deux joueurs enleve entre 1 et 3 allumet tes selon ce qu'il souhaite.\n");
    printf("Le perdant est celui qui doit enlever la derniere allumette.\n");
    printf("Attention, il existe 3 niveaux de difficulte en version humain vs_ordi.\n");
    printf("Le ler est plutot simple a battre, donc pour les debut ants. Mais le dernier...\n");
    printf("Contactez-moi si vous avez reussi (screenshot evidemment ^^), mon e-mail est dans les credits.\n\n");
    printf("*****************\n\n");
}

void show_credits()
{
    printf("\n\n*****CREDITS*****\n\n");
    printf("COPYRIGHT © 2022\n");
    printf("Ayoub & Simeon\n\n");
    printf("Ayoub: ayoub.ben-fraj@efrei.net\n");
    printf("Simeon: simeon.deiva@efrei.net\n");
    printf("******************\n\n");
    printf("**  HISTORIQUE  **\n\n");

    char buffer[500];
    FILE *file_ = fopen("history.txt", "r");
    while (!feof(file_))
    {
        fread(buffer, sizeof(buffer), 1, file_);
        printf("%s", buffer);
    }
    fclose(file_);
    printf("\n******************\n\n");
}

int main()
{
    int menu_choice = 0;
    printf("\t\t\t\t**********************\n");
    printf("\t\t\t\t* Jeu des allumettes *\n");
    printf("\t\t\t\t**********************\n\n\n");
    printf("\tBonjour et bienvenue dans le jeu des allumettes\n\n");
    printf("Vous allez avoir 3 menus.\nVous choisirez d'abord si vous voulez voir les regles du jeu ou non, puis le nombre d'allumettes a utiliser, et enfin le nombre de joueurs.\n");

    while (1)
    {
        printf("1 - Jouer\n");
        printf("2 - Voir les regles du jeu\n");
        printf("3 - Voir les credits\n");
        printf("4 - Quitter\n\n");
        printf("Votre choix : ");
        scanf("%d", &menu_choice);
        switch (menu_choice)
        {
        case 1:
            game_mode_choice();
            break;
        case 2:
            show_rules();
            break;
        case 3:
            show_credits();
            break;
        case 4:
            return 0;
        default:
            printf("Cette entree n'est pas reconnue, veuillez reessayer");
            break;
        }
    }

    return 0;
}
