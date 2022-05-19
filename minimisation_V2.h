//
// Created by ethan on 15/05/2022.
//

#ifndef L2S2_PROJ_AUTOMATE_MINIMISATION_V2_H
#define L2S2_PROJ_AUTOMATE_MINIMISATION_V2_H

#include <stdio.h>
#include "minimisation.h"
// #include Automate

typedef struct etat_automate{
    char* num_etat_depart;
    char symboles_trans[BUFSIZ];
    char* etats_arrivee[BUFSIZ];
    int nb_etats_arrivee;
}Etat_AF;

typedef struct etat_automate_minimisation{
    Etat_AF* Etat_AF;
    char* list_gr_minim[BUFSIZ];
    int len_list_gr_minim;
}Etat_AF_minim;

typedef struct groupe_minimisation{
    char* name_Gr;
    Etat_AF_minim* etats_Gr[BUFSIZ]; // Les groupes contienne leurs etats et non l'inverse (les etats ne contienne que les noms)
    int nb_etats_Gr;
}gr_minim;

typedef struct Liste_element_AF{
    gr_minim* list_Gr[BUFSIZ];
    int len_list_gr_minim;
    Etat_AF_minim * list_EtAF[BUFSIZ];
    int len_list_EtAF;
}list_AF;

// *******************************************************
// PRINCIPALES

// --------------------------------------------------
// FONCTION Principale de miminisation
void Minim_princ(Automate* AF, char* nom_Fichier_trace, int numero);

// --------------------------------------------------
// FONCTION Réalisant une partition à partir d'une liste de groupes d'états
list_AF * Partition(list_AF* List_Gr, int num_part, int * Creation_gr);

#endif //L2S2_PROJ_AUTOMATE_MINIMISATION_V2_H

