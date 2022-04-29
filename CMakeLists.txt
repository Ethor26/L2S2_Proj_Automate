cmake_minimum_required(VERSION 3.21)
project(L2S2_Proj_Automate C)

set(CMAKE_C_STANDARD 99)

add_executable(L2S2_Proj_Automate main.c
        "Projet Automates finis et Expressions rationnelles/main_Rekia.c" "Projet Automates finis et Expressions rationnelles/main_Rekia.h"
        "Projet Automates finis et Expressions rationnelles/menu.c" "Projet Automates finis et Expressions rationnelles/menu.h"
        "Projet Automates finis et Expressions rationnelles/langage_complementaire.c" "Projet Automates finis et Expressions rationnelles/langage_complementaire.h"
        "Projet Automates finis et Expressions rationnelles/determinisation_completion.c" "Projet Automates finis et Expressions rationnelles/determinisation_completion.h"
        "Projet Automates finis et Expressions rationnelles/reconnaissance_de_mots.c" "Projet Automates finis et Expressions rationnelles/reconnaissance_de_mots.h"
        "Projet Automates finis et Expressions rationnelles/standardisation.c" "Projet Automates finis et Expressions rationnelles/standardisation.h"
        "Projet Automates finis et Expressions rationnelles/status.h"
        "Projet Automates finis et Expressions rationnelles/test_automates.c" "Projet Automates finis et Expressions rationnelles/test_automates.h"
        "Projet Automates finis et Expressions rationnelles/automates.c" "Projet Automates finis et Expressions rationnelles/automates.h")
