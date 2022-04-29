#include "langage_complementaire.h"

void automate_complementaire(Automate* AF)
{
    int i,j,k,l;
    l=0;
    int tampon = AF->nb_etats_terminaux;

    for(i=0; i < AF->nb_etats; i++)
    {
        for(j=0; j <= AF->nb_etats_terminaux;j++)
        {

            if(i == AF->numeros_etats_terminaux[j])
            {
                for(k=j; k < AF->nb_etats_terminaux;k++)
                {
                    AF->numeros_etats_terminaux[k] = AF->numeros_etats_terminaux[k+1];
                }
                k--;
                AF->nb_etats_terminaux--;
            }
            else if ( i!= AF->numeros_etats_terminaux[j])
            {

                    AF->numeros_etats_terminaux[l] = i;
                    l++;
            }
        }
    }

     AF->nb_etats_terminaux = AF->nb_etats - tampon;
}
