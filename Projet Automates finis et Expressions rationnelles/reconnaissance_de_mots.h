#ifndef RECONNAISSANCE_DE_MOTS_H_INCLUDED
#define RECONNAISSANCE_DE_MOTS_H_INCLUDED

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "automates.h"

extern int lire_mot(char mot[]);

extern void reconnaitre_mot(char mot[], Automate *AF);

#endif // RECONNAISSANCE_DE_MOTS_H_INCLUDED
