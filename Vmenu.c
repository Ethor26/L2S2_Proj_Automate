#include "Vmenu.h"
#include "Vtest_automates.h"

void menu_auto(){

    int numero = 0;
    int continuer = 1;
    char * fichier;
    char * fichiertrace;
    printf("\t-----------------------------\n");
    printf("\t Traitement d'automate fini\n");
    printf("\t   Reconnaissance de mots\n");
    printf("\t-----------------------------\n");

    while (continuer){

        printf("\nChoix de l'automate\n\n");

        printf("\nQuel automate voulez-vous utiliser ? (saisir un n%c entre 1 et 44 ou saisir un autre nombre pour quitter le programme) ", 248);
        scanf("%d", &numero);


        if (numero > 45 || numero <= 0){

            printf("\nAu revoir.\n\n");
            continuer = 0;

        }

        else{
            char * file_automate = creation_file_BN(numero, "-", ".txt");
            char * file_trace_auto = creation_file_BN(numero, "-trace", ".txt");
            printf("\n--------------------------------------------\n");
            test_function_automate(numero, file_automate, file_trace_auto);
        }
    }
}

// --------------------------------------------
// Pour créer un nom de fichier absolu et adaptatif
char* creation_file_BN(int numero, char* type, char * format){
    char* Current_Path = Return_Current_Path();
    char numero_str[20];
    itoa(numero, numero_str, 10); // sprintf(text, "%d", number); // Pour conversion de string en int
    char * nom_file_general = strcat(Current_Path, "\\BN6"); // strcat("\\BN6", type)
    strcat(nom_file_general, type);
    printf("nom_fichier gen %s\n", nom_file_general);

    if (numero >= -9 && numero <= 9) {
        strcat(nom_file_general, "0");
    }
    char * nom_file_automate = strcat(nom_file_general, strcat(numero_str, format));
    printf("nom_fichier %s", nom_file_automate);
    return nom_file_automate;
}
