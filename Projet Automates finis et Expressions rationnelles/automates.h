#ifndef AUTOMATES_H_INCLUDED
#define AUTOMATES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct Automate{

    int nb_symboles;
    int nb_etats;
    int numeros_etats[BUFSIZ];
    int nb_etats_initiaux;
    int numeros_etats_initiaux[BUFSIZ];
    int nb_etats_terminaux;
    int numeros_etats_terminaux[BUFSIZ];
    int nb_transitions;
    int etats_depart[BUFSIZ];
    char symboles[BUFSIZ];
    int etats_arrivee[BUFSIZ];

}Automate;

extern Automate* lire_automate_sur_fichier(const char* nom_du_fichier);

extern void afficher_automate(Automate* AF, const char* nom_fichier_trace_execution, int numero);

extern void afficher_automate_complementaire(Automate* AF, const char* nom_fichier_trace_execution, int numero);

#endif // AUTOMATES_H_INCLUDED
