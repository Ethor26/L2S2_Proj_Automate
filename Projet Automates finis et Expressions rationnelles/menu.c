#include "menu.h"
#include "test_automates.h"

void menu(){

    int numero = 0;
    int continuer = 1;

    printf("\t-----------------------------\n");
    printf("\t Traitement d'automate fini\n");
    printf("\t   Reconnaissance de mots\n");
    printf("\t-----------------------------\n");

    while (continuer){

        printf("\nChoix de l'automate\n\n");

        printf("\nQuel automate voulez-vous utiliser ? (saisir un n%c entre 1 et 44 ou saisir 45 pour quitter le programme) ", 248);
        scanf("%d", &numero);

        // Quitter le programme
        if(numero == 45){

            break;

        }

        else if (numero > 45 || numero == 0){

            printf("\nChoix incorrect.\n\n");
            break;

        }

        printf("\n--------------------------------------------\n");

        switch(numero)
        {

        case 1:

            test_function_automate01(numero);
            break;

        case 2:

            test_function_automate02(numero);
            break;

        case 3:

            test_function_automate03(numero);
            break;

        case 4:

            test_function_automate04(numero);
            break;

        case 5:

            test_function_automate05(numero);
            break;

        case 6:

            test_function_automate06(numero);
            break;

        case 7:

            test_function_automate07(numero);
            break;

        case 8:

            test_function_automate08(numero);
            break;

        case 9:

            test_function_automate09(numero);
            break;

        case 10:

            test_function_automate10(numero);
            break;

        case 11:

            test_function_automate11(numero);
            break;

        case 12:

            test_function_automate12(numero);
            break;

        case 13:

            test_function_automate13(numero);
            break;

        case 14:

            test_function_automate14(numero);
            break;

        case 15:

            test_function_automate15(numero);
            break;

        case 16:

            test_function_automate16(numero);
            break;

        case 17:

            test_function_automate17(numero);
            break;

        case 18:

            test_function_automate18(numero);
            break;

        case 19:

            test_function_automate19(numero);
            break;


        case 20:

            test_function_automate20(numero);
            break;

        case 21:

            test_function_automate21(numero);
            break;

        case 22:

            test_function_automate22(numero);
            break;

        case 23:

            test_function_automate23(numero);
            break;

        case 24:

            test_function_automate24(numero);
            break;

        case 25:

            test_function_automate25(numero);
            break;

        case 26:

            test_function_automate26(numero);
            break;

        case 27:

            test_function_automate27(numero);
            break;

        case 28:

            test_function_automate28(numero);
            break;

        case 29:

            test_function_automate29(numero);
            break;

        case 30:

            test_function_automate30(numero);
            break;

        case 31:

            test_function_automate31(numero);
            break;

        case 32:

            test_function_automate32(numero);
            break;

        case 33:

            test_function_automate33(numero);
            break;

        case 34:

            test_function_automate34(numero);
            break;

        case 35:

            test_function_automate35(numero);
            break;

        case 36:

            test_function_automate36(numero);
            break;

        case 37:

            test_function_automate37(numero);
            break;

        case 38:

            test_function_automate38(numero);
            break;

        case 39:

            test_function_automate39(numero);
            break;

        case 40:

            test_function_automate40(numero);
            break;

        case 41:

            test_function_automate41(numero);
            break;

        case 42:

            test_function_automate42(numero);
            break;

        case 43:

            test_function_automate43(numero);
            break;

        case 44:

            test_function_automate44(numero);
            break;

        case 45:
            // Quitter le programme
            continuer = 0;
            break;

        default:
            printf("\nChoix incorrect.\n\n");
            exit(EXIT_FAILURE);
            break;


        }
    }
}
