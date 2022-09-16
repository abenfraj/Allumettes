#include <stdio.h>
#define MAX_CHAR_PLAYER_NAME 16

void pvp_mode_menu(){
    char player_name1[MAX_CHAR_PLAYER_NAME] = { };
    char player_name2[MAX_CHAR_PLAYER_NAME] = { };
    printf("\n\nVous avez rejoins le mode Joueur contre Joueur !\nNom joueur 1 : ");
    scanf("%s", player_name1);
    printf("Nom joueur 2 : ");
    scanf("%s", player_name2);
    
    
}

void pvia_mode() {
    int difficulty_choice = 0;
    printf("\n1. Mode Facile\n2. Mode Difficile");
    scanf("%d", &difficulty_choice);
    switch (difficulty_choice)
    {
    case 1:
        printf("easyia_mode()");
        break;
    case 2:
        printf("hardia_mode()");
        break;
    default:
        printf("Cette entree n'est pas reconnue, veuillez reessayer");
        printf("pvia_mode_menu()");
        break;
    }
}

void game_mode_choice()
{
    int game_mode_choice = 0;
    printf("\n\n1.Mode Humain\nMode Ordinateur");
    scanf("%d", &game_mode_choice);
    switch (game_mode_choice)
    {
    case 1:
        pvp_mode_menu();
        break;
    case 2:
        pvia_mode();
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
    printf("Contactez-moi si vous avez reussi (screenshot evidemment** ), mon e-mail est dans les credits.");
}

void show_credits() {
    printf("\n\n*****CREDITS*****\n\n");
    printf("COPYRIGHT © 2022\n");
    printf("Ayoub & Siméon");
}

int main()
{
    int menu_choice = 0;
    printf("\t\t\t\t**********************\n");
    printf("\t\t\t\t* Jeu des allumettes *\n");
    printf("\t\t\t\t**********************\n\n\n");
    printf("\tBonjour et bienvenue dans le jeu des allumettes\n\n");
    printf("Vous allez avoir 3 menus.\nVous choisirez d'abord si vous voulez voir les regles du jeu ou non, puis le nombre d'allumettes a utiliser, et enfin le nombre de joueurs.\n");

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
        break;
    default:
        printf("Cette entree n'est pas reconnue, veuillez reessayer");
        break;
    }

    return 0;
}
