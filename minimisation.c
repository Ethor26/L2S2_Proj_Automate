//
// Created by ethan on 02/05/2022.
//

#include <string.h>
#include "minimisation.h"

// =======================================
// Fonction outils : initialisation des structures

etat_AF* Return_etat_AF(Automate* AF, int num_etat){
    int i = 0;
    etat_AF* AF_etat = (etat_AF*)malloc(sizeof(etat_AF));
    AF_etat->num_etat_depart = (char*)num_etat;
    while((char *) AF->numeros_etats_initiaux[i] == AF_etat->num_etat_depart){
        AF_etat->symboles_trans[i] = AF->symboles[i];
        AF_etat->etats_arrivee[i] = (char*)AF->etats_arrivee[i];
        i++;
    }
    AF_etat->nb_etats_arrivee = i;
    return AF_etat;
}

Gr_minim * Return_Gr_minim(char* Etats_Gr[BUFSIZ], int nb_etats_gr){
    Gr_minim* Groupe = malloc(sizeof(Gr_minim));
    Groupe->nb_etats_Gr = nb_etats_gr;
    Groupe->name_Gr = "";
    for(int i=0 ; i<Groupe->nb_etats_Gr ; i++){
        Groupe->etats_Gr[i] = Etats_Gr[i];

        // Vérification si etat existait déjà dans le nom, sinon ajout au nom
        for(int j = 0; j< strlen(Groupe->etats_Gr[i]) ; j++){
            if(find_char_in_tab(Groupe->etats_Gr[i][j], Groupe->name_Gr)){
                strcat(Groupe->name_Gr, &Groupe->etats_Gr[i][j]);
            }
        }
    }
    return Groupe;
}

etat_AF_minim* Return_etat_AF_minim(Automate* AF, int num_etat){
    etat_AF_minim* E_AF_M = malloc(sizeof(etat_AF_minim));
    E_AF_M->Etat_AF = Return_etat_AF(AF, num_etat);
    // Pas de Gr_minim car création après
    return E_AF_M;
}

// =======================================
// ALGO PRINCIPAL

void minimisation_automate(Automate* AF, const char* nom_fichier_trace_execution, int numero){
    // On suppose l'automate déterministe complet
    // FILE * fichier = fopen(nom_fichier_trace_execution, "w"); // Réactiver après test

    //fprintf(fichier, "************** Debut de la minimisation ***************\n ------------------\n - - - - - Debut Partition 0: Séparation des états entre terminaux et non terminaux\n");
    printf("************** Debut de la minimisation ***************"
           "\n ------------------"
           "\n - - - - - Debut Partition 0: Séparation des états entre terminaux et non terminaux\n");

    Gr_minim * Groupe1 = Return_Gr_minim((char**) AF->numeros_etats_initiaux,AF->nb_etats_initiaux);
    Gr_minim * Groupe2 = Return_Gr_minim((char**) AF->numeros_etats_terminaux,AF->nb_etats_terminaux);
    //char* numeros_etats_groupe1[AF->nb_etats_initiaux];
    // char* numeros_etats_groupe2[AF->nb_etats_terminaux];

    for (int j = 0; j < AF->nb_etats_initiaux; j++){
        printf("Groupe 1 : Numeros des etats initiaux : %d\n", AF->numeros_etats_initiaux[j]);
        //fprintf(fichier, "Groupe 1 :Numeros des etats initiaux : %d\n", AF->numeros_etats_initiaux[j]);
        //numeros_etats_groupe1[j] = (char*)AF->numeros_etats_initiaux[j];
    }

    for (int k = 0; k < AF->nb_etats_terminaux; k++){
        printf("Groupe 2 : Numeros des etats terminaux : %d\n", AF->numeros_etats_terminaux[k]);
        //fprintf(fichier, "Groupe 2 : Numeros des etats terminaux : %d\n", AF->numeros_etats_terminaux[k]);
        // numeros_etats_groupe2[k] = (char*)AF->numeros_etats_terminaux[k];
    }

    //fprintf(fichier, "- - - - - Fin Partition 0:\n ------------------\n - - - - - Debut Partition 1: Séparation des états en fonctions de leur types de transitions (T ou NT)\n");
    printf("- - - - - Fin Partition 0:"
           "\n ------------------"
           "\n - - - - - Debut Partition 1: Séparation des états en fonctions de leur types de transitions (T ou NT)\n");

    int i = 0;
    foreach(char **num_etat_gr1, Groupe1->etats_Gr){
        printf("Etat gr1 : %d", **num_etat_gr1);
        etat_AF_minim* E_AF_min = Return_etat_AF_minim(AF, **num_etat_gr1); // Creation d'un état fait pour la minimisation
        if (find_charEt_in_tab(E_AF_min->Etat_AF->etats_arrivee[i], (const char **) Groupe1->etats_Gr) != -1){
            E_AF_min->list_gr_minim[i] = Groupe1;
        }
        else if (find_charEt_in_tab(E_AF_min->Etat_AF->etats_arrivee[i], (const char **) Groupe2->etats_Gr) != -1){
            E_AF_min->list_gr_minim[i] = Groupe2;
        }
    }
}





