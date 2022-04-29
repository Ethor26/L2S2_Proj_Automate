#include "reconnaissance_de_mots.h"

int lire_mot(char mot[]){

    printf("\nEcrire * pour saisir le mot vide et ecrire la chaine 'fin' pour quitter\n\n");

    printf("Entrez une chaine de caracteres : ");
    scanf("%s", mot);

    if (strcmp(mot, "fin") == 0){

        return 1;

    }

    else{

        printf("Chaine de caracteres saisie : %s\n", mot);

    }

    return 0;

}

void reconnaitre_mot(char mot[], Automate *AF){

    int etat_courant = 0;
    int etat_courant1 = 0;
    char symbole_courant;
    int longueur_mot = strlen(mot);
    int tmp = 0;
    int tmp1 = 0;
    int tmp2 = 0;
    int i = 0;
    int j = 0;
    int k = 0;

    etat_courant = AF->numeros_etats_initiaux[0];
    etat_courant1 = AF->numeros_etats_initiaux[1];

    // Cas du mot vide
    if (mot[0] == '*')
    {

        if (AF->nb_etats_initiaux != 0)
        {

            printf("\nOui : l'automate reconnait le mot vide\n");

        }

        else
        {

            printf("\nNon : l'automate ne reconnait pas le mot vide\n");

        }

    }

    // Cas de l'automate 01
    else if (AF->nb_transitions == 0)
    {

        printf("\nNon : l'automate ne reconnait pas le mot %s\n", mot);

    }

    else if (AF->nb_transitions == 1 && longueur_mot > 1 && AF->nb_etats > 1)
    {

        printf("\nNon : l'automate ne reconnait pas le mot %s\n", mot);

    }

    else if (AF->nb_transitions >= 1 && longueur_mot > 1 && AF->nb_etats > 1)
    {

        printf("\nNon : l'automate ne reconnait pas le mot %s\n", mot);

    }

    else

    {

        for (j = 0; j < longueur_mot; j++)
        {

            symbole_courant = mot[j];

            for (k = 0; k < AF->nb_transitions; k++)
            {

                if ((AF->etats_depart[k] == etat_courant) && (AF->symboles[k] == symbole_courant))
                {

                    tmp = AF->etats_arrivee[k];

                    etat_courant = tmp;

                }

                else if ((AF->etats_depart[k] == etat_courant1) && (AF->symboles[k] == symbole_courant))
                {

                    tmp1 = AF->etats_arrivee[k];

                    etat_courant = tmp;

                }
            }

        }


        for (k = 0; k < AF->nb_etats_terminaux; k++)
        {

            if (tmp == AF->numeros_etats_terminaux[k] || tmp1 == AF->numeros_etats_terminaux[k])
            {
                if (mot[longueur_mot-1] == AF->symboles[k])
                {

                    tmp2 = 1;

                }

            }


        }


        if ((tmp2 == 1))
        {

            printf("\nOui : l'automate reconnait le mot %s\n", mot);

        }

        else
        {

            printf("\nNon : l'automate ne reconnait pas le mot %s\n", mot);

        }

    }

}
