// Déclaration bibliothèques (toutes ne sont pas utilisées)
# include <stdio.h> // Pour fonctions basiques.
# include<stdlib.h> // Pour pointeurs.
# include<string.h> // Pour Chaine de caractères.
#include "Projet Automates finis et Expressions rationnelles/main_Rekia.h"
#include "Tools.h"
#include "minimisation.h"
#include "Vmenu.h"
#include "minimisation_V2.h"

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
            break;
        }
        case 1 : {
            printf("Debut de l'algo principal\n ");
            menu_auto();
            break;
        }

        case 2 : {
            printf("Debut du test 2: ouverture de fichier\n ");
            char* Current_Path = Return_Current_Path();
            //delnword(Current_Path, "\\cmake-build-debug", -1); // Traitement des chemins en trop
            // printf("%s", Current_Path);
            FILE * File_2 = fopen(strcat(Current_Path, "\\TestOuv.txt"), "r+");
            // FILE * File_2 = fopen("TestOuv.txt", "r+");
            //printf("%p", File_2);
            fprintf(File_2, "d/d/d");
            break;
        }

        case 3 : {
            printf("Debut du test: ouverture de fichier\n ");
            FILE * File_1 = fopen("Projet Automates finis et Expressions rationnelles\\BN6-01.txt", "r");
            printf("%s", (const char *) File_1);
            fscanf(File_1, "Bonjour");
            printf("passe fopen\n");
            fclose(File_1);
            char* Current_Path = Return_Current_Path();
            strcat(Current_Path, "\\Projet Automates finis et Expressions rationnelles");
            Automate * AF = lire_automate_sur_fichier(strcat(Current_Path, "\\BN6-35.txt")); //Projet Automates finis et Expressions rationnelles/

            afficher_automate(AF, "BN6-trace40.txt", 40);
            printf("passe lire\n");
            break;
        }

        case 4:{
            printf("Debut du test: minimisation\n ");
            char* Current_Path = Return_Current_Path();
            char* Path_Lecture = Return_Current_Path();
            strcat(Path_Lecture, "\\Projet Automates finis et Expressions rationnelles");
            Automate * AF = lire_automate_sur_fichier(strcat(Path_Lecture, "\\BN6-30.txt"));
            Minim_princ(AF, strcat(Current_Path, "\\BN6-TraceTest"), 30);
            break;
        }

        default : printf("\nAu revoir");

    }
    return 0 ; }

