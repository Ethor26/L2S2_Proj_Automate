#include "standardisation.h"

void standardisation(Automate* AF, const char* nom_fichier_trace_execution)
{

    FILE* fichier = NULL;

    // Ouverture du fichier en mode "a" mode (ajout à la fin du fichier)
    fichier = fopen(nom_fichier_trace_execution, "a");

    if (fichier != NULL)
    {

        printf("\nStandardisation de l'automate\n\n");
        fprintf(fichier, "\nStandardisation de l'automate\n\n");

        // 105 correspond au code ascii de 'i'

        char new_i;
        new_i='i';
        AF->nb_etats++;
        int tampon = AF->nb_transitions; // tampon nous permet de ne pas perdre le nombre de transition
        int i, j;
        int compteur; // permet de connaitre le nombre de nouevlle fonction cree
        compteur=0;

        //On regarde les transition pour chaque etats initiaux
        for(j=0; j<AF->nb_etats_initiaux; j++)
        {
            for(i=0; i<AF->nb_transitions; i++)
            {
                if(AF->etats_depart[i] == AF->numeros_etats_initiaux[j])
                {
                    //Creer une nouvelle transition entre le nouvel etat i(=105 en ascii) et l'etat d'arrivee qui faisait une transition avec notre ancien etat initial
                    AF->etats_depart[AF->nb_transitions] = new_i;
                    AF->symboles[AF->nb_transitions]= AF->symboles[i];
                    AF->etats_arrivee[AF->nb_transitions] = AF->etats_arrivee[i];
                    printf("Transition : %c%c%d\n",AF->etats_depart[AF->nb_transitions],AF->symboles[AF->nb_transitions], AF->etats_arrivee[AF->nb_transitions]);
                    fprintf(fichier, "Transition : %c%c%d\n",AF->etats_depart[AF->nb_transitions],AF->symboles[AF->nb_transitions], AF->etats_arrivee[AF->nb_transitions]);
                    AF->nb_transitions++;
                    compteur++;
                }
            }
        }
        //Standardisation entraine un unique état initial new_i
        AF->nb_etats_initiaux = 1;
        AF->numeros_etats_initiaux[0]=new_i;
        //Actualiser le nombre de transition
        AF->nb_transitions = tampon + compteur;

        // Fermeture du fichier
        fclose(fichier);

    }

    else
    {

        printf("Impossible d'ouvrir le fichier %s\n", nom_fichier_trace_execution);
        exit(EXIT_FAILURE);

    }
}
