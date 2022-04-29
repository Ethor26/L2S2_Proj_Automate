#ifndef DETERMINISATION_COMPLETION_H_INCLUDED
#define DETERMINISATION_COMPLETION_H_INCLUDED

#include <stdbool.h>
#include <ctype.h>

#include "automates.h"

bool est_un_automate_asynchrone(Automate* AF, const char* nom_fichier_trace_execution);

extern void elimination_epsilon(Automate* AF, const char* nom_fichier_trace_execution, int numero);
extern void AND_synchrone_31(Automate* AF, FILE* fichier, int etat_initial_transition_epsilon[], int etat_final_transition_epsilon[], int numero_etat[], int compteur1);
extern void AND_synchrone_32(Automate* AF, FILE* fichier, int etat_initial_transition_epsilon[], int etat_final_transition_epsilon[], int numero_etat[], int compteur1);
extern void AND_synchrone_33(Automate* AF, FILE* fichier, int etat_initial_transition_epsilon[], int etat_final_transition_epsilon[], int numero_etat[], int compteur1);
extern void AND_synchrone_34(Automate* AF, FILE* fichier, int etat_initial_transition_epsilon[], int etat_final_transition_epsilon[], int numero_etat[], int compteur1);
extern void AND_synchrone_35(Automate* AF, FILE* fichier, int etat_initial_transition_epsilon[], int etat_final_transition_epsilon[], int numero_etat[], int compteur1);

bool est_un_automate_deterministe(Automate* AF, const char* nom_fichier_trace_execution);

bool est_un_automate_complet(Automate* AF, const char* nom_fichier_trace_execution);

extern int nb_de_symbole_different(char tab[]);

extern void completion(Automate* AF, const char* nom_fichier_trace_execution);

//extern int presence_etat(Automate* AF, char* arrivee);
//extern void remplissage_initial(Automate* AF);
//Automate* determinisation(Automate* AF,char* symb_pos

// extern void afficher_automate_deterministe_complet(Automate* AF);

#endif // DETERMINISATION_COMPLETION_H_INCLUDED
