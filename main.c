#include <stdio.h>

int main()
{
    char choice[] = { };
    printf("\t\t\t\t**********************\n");
    printf("\t\t\t\t* Jeu des allumettes *\n");
    printf("\t\t\t\t**********************\n\n\n");
    printf("\tBonjour et bienvenue dans le jeu des allumettes\n\n");
    printf("Vous allez avoir 3 menus.\nVous choisirez d'abord si vous voulez voir les regles du jeu ou non, puis le nombre d'allumettes a utiliser, et enfin le nombre de joueurs.");

    printf("1 - Jouer\n");
    printf("2 - Voir les regles du jeu\n");
    printf("3 - Voir les credits\n");
    printf("4 - Quitter\n");
    printf("Votre choix : ");
    scanf("%s", choice);

    return 0;
}