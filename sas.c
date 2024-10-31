#include <stdio.h>
#include <string.h>

#define MAX_TACHES 100

typedef struct {
    char titre[50];
    char description[200];
    char date_echeance[11]; 
    char priorite[5]; 
} Tache;

Tache liste_taches[MAX_TACHES];
int nombre_taches = 0;