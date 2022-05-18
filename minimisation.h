//
// Created by ethan on 02/05/2022.
//

#ifndef L2S2_PROJ_AUTOMATE_MINIMISATION_H
#define L2S2_PROJ_AUTOMATE_MINIMISATION_H


#include "Projet Automates finis et Expressions rationnelles/automates.h"
#include "Tools.h"
// #include "Vautomates.h"

typedef struct Etat_automate{
    char* num_etat_depart;
    char symboles_trans[BUFSIZ];
    char* etats_arrivee[BUFSIZ];
    int nb_etats_arrivee;
}etat_AF;

typedef struct Groupe_minimisation{
    char* name_Gr;
    char* etats_Gr[BUFSIZ];
    int nb_etats_Gr;
}Gr_minim;

typedef struct Etat_automate_minimisation{
    etat_AF* Etat_AF;
    Gr_minim* list_gr_minim[BUFSIZ];
}etat_AF_minim;

void minimisation_automate(Automate* AF, const char* nom_fichier_trace_execution, int numero);

#endif //L2S2_PROJ_AUTOMATE_MINIMISATION_H




