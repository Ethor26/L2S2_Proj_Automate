#include "automates.h"

Automate* lire_automate_sur_fichier(const char* nom_du_fichier){

    /* Declaration et initialisation de trois tableaux
    de taille BUFSIZ pour stocker les numeros des
    etats initiaux, les numeros des etats terminaux
    et les numeros des etats */
    int numero_etat_initial[BUFSIZ] = {0};
    int numero_etat_terminal[BUFSIZ] = {0};
    int numero_etat[BUFSIZ] = {0};

    /* Declaration et initialisation de trois tableaux
    de taille BUFSIZ pour stocker les etats de departs,
    les symboles et les etats d'arrivee des transitions */
    int etat_depart[BUFSIZ] = {0};
    char symbole[BUFSIZ] = {0};
    int etat_arrivee[BUFSIZ] = {0};

    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;

    // Declaration et allocation de l'automate
    Automate* AF;
    AF = malloc(1 * sizeof(Automate));

    if (AF == NULL){

        printf("Allocation dynamique impossible : erreur malloc().\n");

    }

    FILE* fichier = NULL;

    // Ouverture du fichier en mode "r" (lecture seule)
    fichier = fopen(nom_du_fichier, "r");

    if (fichier != NULL){

        // Lecture de la ligne 1
        fscanf(fichier, "%d", &AF->nb_symboles);

        // Lecture de la ligne 2

        /* Stockage du nombre d'états et des
        numeros des etats */

        fscanf(fichier, "%d", &AF->nb_etats);

        for (i = 0; i < AF->nb_etats; i++){

            fscanf(fichier, "%d\n", &numero_etat[i]);
            AF->numeros_etats[i] = numero_etat[i];

        }

        // Lecture de la ligne 3

        /* Stockage du nombre d'états initiaux
        et des numeros des etats initiaux */

        fscanf(fichier, "%d", &AF->nb_etats_initiaux);

        for (j = 0; j < AF->nb_etats_initiaux; j++){

            fscanf(fichier, "%d\n", &numero_etat_initial[j]);
            AF->numeros_etats_initiaux[j] = numero_etat_initial[j];

        }

        // Lecture de la ligne 4

        /* Stockage du nombre d'états terminaux
        et des numeros des etats terminaux */

        fscanf(fichier, "%d", &AF->nb_etats_terminaux);

        for (k = 0; k < AF->nb_etats_terminaux; k++){

            fscanf(fichier, "%d\n", &numero_etat_terminal[k]);
            AF->numeros_etats_terminaux[k] = numero_etat_terminal[k];
        }

        // Lecture de la ligne 5

        fscanf(fichier, "%d", &AF->nb_transitions);

        // Lecture des lignes 6 et suivantes

        /* Stockage des etats de departs, des symboles
        et des etats d'arrivee des transitions */

        for (m = 0; m < AF->nb_transitions; m++){

            fscanf(fichier, "%d %c %d\n", &etat_depart[m], &symbole[m], &etat_arrivee[m]);
            AF->etats_depart[m] = etat_depart[m];
            AF->symboles[m] = symbole[m];
            AF->etats_arrivee[m] = etat_arrivee[m];
        }

        // Fermeture du fichier
        fclose(fichier);

    }

    else{

        printf("Impossible d'ouvrir le fichier %s\n", nom_du_fichier);
        exit(EXIT_FAILURE);

    }

    return AF;

}

void afficher_automate(Automate* AF, const char* nom_fichier_trace_execution, int numero){

    FILE* fichier = NULL;

     // Ouverture du fichier en mode "w" (écriture seule)
    fichier = fopen(nom_fichier_trace_execution, "w");

    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;

    if (fichier != NULL){

        printf("Affichage de l'automate %d\n\n", numero);
        fprintf(fichier, "Affichage de l'automate %d\n\n", numero);

        printf("Nombre de symboles dans l'alphabet de l'automate : %d\n\n", AF->nb_symboles);
        fprintf(fichier, "Nombre de symboles dans l'alphabet de l'automate : %d\n\n", AF->nb_symboles);

        printf("Nombre d'etats : %d\n\n", AF->nb_etats);
        fprintf(fichier, "Nombre d'etats : %d\n\n", AF->nb_etats);

        for (i = 0; i < AF->nb_etats; i++){

            printf("Numeros des etats : %d\n", AF->numeros_etats[i]);
            fprintf(fichier, "Numeros des etats : %d\n", AF->numeros_etats[i]);

        }

        printf("\nNombre d'etats initiaux : %d\n\n", AF->nb_etats_initiaux);
        fprintf(fichier, "\nNombre d'etats initiaux : %d\n\n", AF->nb_etats_initiaux);

        for (j = 0; j < AF->nb_etats_initiaux; j++){

            printf("Numeros des etats initiaux : %d\n", AF->numeros_etats_initiaux[j]);
            fprintf(fichier, "Numeros des etats initiaux : %d\n", AF->numeros_etats_initiaux[j]);

        }

        printf("\nNombre d'etats terminaux : %d\n\n", AF->nb_etats_terminaux);
        fprintf(fichier, "\nNombre d'etats terminaux : %d\n\n", AF->nb_etats_terminaux);

        for (k = 0; k < AF->nb_etats_terminaux; k++){

            printf("Numeros des etats terminaux : %d\n", AF->numeros_etats_terminaux[k]);
            fprintf(fichier, "Numeros des etats terminaux : %d\n", AF->numeros_etats_terminaux[k]);

        }

        printf("\nNombre de transitions : %d\n\n", AF->nb_transitions);
        fprintf(fichier, "\nNombre de transitions : %d\n\n", AF->nb_transitions);

        for (m = 0; m < AF->nb_transitions; m++){

            printf("Transition : %d%c%d\n", AF->etats_depart[m], AF->symboles[m], AF->etats_arrivee[m]);
            fprintf(fichier, "Transition : %d%c%d\n", AF->etats_depart[m], AF->symboles[m], AF->etats_arrivee[m]);
        }

        // Fermeture du fichier
        fclose(fichier);

    }

    else{

        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier_trace_execution);
        exit(EXIT_FAILURE);

    }
}

void afficher_automate_complementaire(Automate* AF, const char* nom_fichier_trace_execution, int numero){

    FILE* fichier = NULL;

     // Ouverture du fichier en mode "a" (ajout à la fin )
    fichier = fopen(nom_fichier_trace_execution, "a");

    int i = 0;
    int j = 0;
    int k = 0;
    int m = 0;

    if (fichier != NULL){

        fprintf(fichier, "\nAutomate complementaire\n\n");

        printf("Nombre de symboles dans l'alphabet de l'automate : %d\n\n", AF->nb_symboles);
        fprintf(fichier, "Nombre de symboles dans l'alphabet de l'automate : %d\n\n", AF->nb_symboles);

        printf("Nombre d'etats : %d\n\n", AF->nb_etats);
        fprintf(fichier, "Nombre d'etats : %d\n\n", AF->nb_etats);

        for (i = 0; i < AF->nb_etats; i++){

            printf("Numeros des etats : %d\n", AF->numeros_etats[i]);
            fprintf(fichier, "Numeros des etats : %d\n", AF->numeros_etats[i]);

        }

        printf("\nNombre d'etats initiaux : %d\n\n", AF->nb_etats_initiaux);
        fprintf(fichier, "\nNombre d'etats initiaux : %d\n\n", AF->nb_etats_initiaux);

        for (j = 0; j < AF->nb_etats_initiaux; j++){

            printf("Numeros des etats initiaux : %d\n", AF->numeros_etats_initiaux[j]);
            fprintf(fichier, "Numeros des etats initiaux : %d\n", AF->numeros_etats_initiaux[j]);

        }

        printf("\nNombre d'etats terminaux : %d\n\n", AF->nb_etats_terminaux);
        fprintf(fichier, "\nNombre d'etats terminaux : %d\n\n", AF->nb_etats_terminaux);

        for (k = 0; k < AF->nb_etats_terminaux; k++){

            printf("Numeros des etats terminaux : %d\n", AF->numeros_etats_terminaux[k]);
            fprintf(fichier, "Numeros des etats terminaux : %d\n", AF->numeros_etats_terminaux[k]);

        }

        printf("\nNombre de transitions : %d\n\n", AF->nb_transitions);
        fprintf(fichier, "\nNombre de transitions : %d\n\n", AF->nb_transitions);

        for (m = 0; m < AF->nb_transitions; m++){

            printf("Transition : %d%c%d\n", AF->etats_depart[m], AF->symboles[m], AF->etats_arrivee[m]);
            fprintf(fichier, "Transition : %d%c%d\n", AF->etats_depart[m], AF->symboles[m], AF->etats_arrivee[m]);
        }

        // Fermeture du fichier
        fclose(fichier);

    }

    else{

        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier_trace_execution);
        exit(EXIT_FAILURE);

    }
}

