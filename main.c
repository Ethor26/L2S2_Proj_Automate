// Déclaration bibliothèques (toutes ne sont pas utilisées)
# include <stdio.h> // Pour fonctions basiques.
# include<stdlib.h> // Pour pointeurs.
# include<string.h> // Pour Chaine de caractères.
# include <conio.h> // Plus on est de fous, plus on rit (pour couleur mais incomplet).
#include "Projet Automates finis et Expressions rationnelles/main_Rekia.h"
#include "Tools.h"
#include "minimisation.h"

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
            printf("Debut du test: ouverture de fichier\n ");
            FILE * File_1 = fopen("BN6-01.txt", "r");
            printf("passe fopen\n");
            fclose(File_1);
            Automate * AF = lire_automate_sur_fichier("BN6-40.txt"); //Projet Automates finis et Expressions rationnelles/
            printf("passe lire\n");
        }

        case 2 : {
            printf("Debut du test: minimisation\n ");
            //minimisation_automate();
        }

        default : printf("\nAu revoir");

    }
    return 0 ; }

