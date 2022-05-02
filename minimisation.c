//
// Created by ethan on 02/05/2022.
//

#include "minimisation.h"

void minimisation_automate(Automate* AF, const char* nom_fichier_trace_execution, int numero){
    // On suppose l'automate déterministe complet
    FILE * fichier = fopen(nom_fichier_trace_execution, "w");

    fprintf(fichier, "************** Debut de la minimisation ***************\n ------------------\n - - - - - Debut Partition 0: Séparation des états entre terminaux et non terminaux\n");
    printf("************** Debut de la minimisation ***************"
           "\n ------------------"
           "\n - - - - - Debut Partition 0: Séparation des états entre terminaux et non terminaux\n");

    int numeros_etats_groupe1[AF->nb_etats_initiaux];
    int numeros_etats_groupe2[AF->nb_etats_terminaux];

    for (int j = 0; j < AF->nb_etats_initiaux; j++){
        printf("Groupe 1 : Numeros des etats initiaux : %d\n", AF->numeros_etats_initiaux[j]);
        fprintf(fichier, "Groupe 1 :Numeros des etats initiaux : %d\n", AF->numeros_etats_initiaux[j]);
        numeros_etats_groupe1[j] = AF->numeros_etats_initiaux[j];
    }

    for (int k = 0; k < AF->nb_etats_terminaux; k++){
        printf("Groupe 2 : Numeros des etats terminaux : %d\n", AF->numeros_etats_terminaux[k]);
        fprintf(fichier, "Groupe 2 : Numeros des etats terminaux : %d\n", AF->numeros_etats_terminaux[k]);
        numeros_etats_groupe2[k] = AF->numeros_etats_terminaux[k];
    }

    fprintf(fichier, "- - - - - Fin Partition 0:\n ------------------\n - - - - - Debut Partition 1: Séparation des états en fonctions de leur types de transitions (T ou NT)\n");
    printf("- - - - - Fin Partition 0:"
           "\n ------------------"
           "\n - - - - - Debut Partition 1: Séparation des états en fonctions de leur types de transitions (T ou NT)\n");

}

