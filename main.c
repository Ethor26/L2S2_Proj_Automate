// Déclaration bibliothèques (toutes ne sont pas utilisées)
# include <stdio.h> // Pour fonctions basiques.
# include<stdlib.h> // Pour pointeurs.
# include<string.h> // Pour Chaine de caractères.
# include <conio.h> // Plus on est de fous, plus on rit (pour couleur mais incomplet).
#include "Projet Automates finis et Expressions rationnelles/main_Rekia.h"
#include "Tools.h"

/* Fichier qui active les autres */
int main(void) {
// Déclaration variables //
    int RefFich, RefFich2; char NameOldFile, NameNewFile;

/*Algorithme */
    printf("Entrez la référence du projet à lancer ");
    LireInt(&RefFich);
/* Attention : RefFich ne peut être qu'un caractère (pas une chaine) ou un entier */
    switch(RefFich){

// II. Pour les exos de cour
        case 0 : {
            printf("Debut de l'algo d'archive:\n ");
            main_Rekia();
        }
        case 1 : {
            printf("Debut du test:\n ");
            fopen("BN6-01", "r");
            printf("passé");
        }
        default : printf("Au revoir");

    }
    return 0 ; }