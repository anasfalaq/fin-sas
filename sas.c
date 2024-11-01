#include <stdio.h>
#include <string.h>

#define MAX_TACHES 100
 typedef struct {
    int jour;
    int mois;
    int annee;
} date;


typedef struct {
    char titre[50];
    char description[200];
  //  char date_echeance[11]; 
    date Date;
    int priorite; 
}Tache;



Tache liste_taches[MAX_TACHES];
int nombre_taches = 0;

// Fonction pour afficher le menu
void afficher_menu() {
    printf("\n=== Menu de Gestion des Taches ===\n");
    printf("1. Ajouter une Tache\n");
    printf("2. Afficher la Liste des Taches\n");
    printf("3. Modifier une Tache\n");
    printf("4. Supprimer une Tache\n");
    printf("5. Filtrer les Taches par Priorite\n");
    printf("0. Quitter\n");
    printf("Choisissez une option : ");
}

// Fonction pour ajouter une tache
void ajouter_tache() {
    if (nombre_taches >= MAX_TACHES) {
        printf("La liste des taches est pleine.\n");
        return;
    }
    
    printf("Titre : ");
    scanf(" %[^\n]", liste_taches[nombre_taches].titre);
    printf("Description : ");
    scanf(" %[^\n]", liste_taches[nombre_taches].description);
    

    // Validation de l'année
    do {
        printf("Date d'echeance (JJ MM AAAA) : ");
        scanf("%d %d %d", &liste_taches[nombre_taches].Date.jour,
          &liste_taches[nombre_taches].Date.mois,
          &liste_taches[nombre_taches].Date.annee);
          printf("year + %d\n", liste_taches[nombre_taches].Date.annee);

    } while(liste_taches[nombre_taches].Date.annee < 2024
        || liste_taches[nombre_taches].Date.mois > 12 ||
        liste_taches[nombre_taches].Date.jour > 31);

    // Vérification de la priorité
    while (1) {
        printf("Priorite (High/Low) : ");
        scanf(" %[^\n]", liste_taches[nombre_taches].priorite);
        
        // Vérification de la priorite
        if (strcmp(liste_taches[nombre_taches].priorite, "High") == 0 || 
            strcmp(liste_taches[nombre_taches].priorite, "Low") == 0) {
            break; // Sortir de la boucle si la priorite est valide
        } else {
            printf("Entrée invalide. Veuillez saisir 'High' ou 'Low'.\n");
        }
    }

    nombre_taches++;
    printf("Tache ajoutée avec succès !\n");
}

// Fonction pour afficher toutes les taches
void afficher_taches() {
    printf("\n=== Liste des Taches ===\n");
    for (int i = 0; i < nombre_taches; i++) {
        printf("Tache %d :\n", i + 1);
        printf("Titre : %s\n", liste_taches[i].titre);
        printf("Description : %s\n", liste_taches[i].description);
        printf("Date d'echeance : %d-%d-%d\n",
          liste_taches[i].Date.jour,
          liste_taches[i].Date.mois,
          liste_taches[i].Date.annee);
        printf("Priorite : %s\n", liste_taches[i].priorite);
        printf("----------------------\n");
    }
}

// Fonction pour modifier une tache
void modifier_tache() {
    int index;
    printf("Entrez le numero de la tache à modifier : ");
    scanf("%d", &index);
    index--; 

    if (index < 0 || index >= nombre_taches) {
        printf("Tache introuvable.\n");
        return;
    }

    printf("Nouvelle description : ");
    scanf(" %[^\n]", liste_taches[index].description);
   // Demander la date d'échéance
    printf("Date d'echeance (JJ MM AAAA) : ");
    scanf("%d %d %d", &liste_taches[nombre_taches].Date.jour,
          &liste_taches[nombre_taches].Date.mois,
          &liste_taches[nombre_taches].Date.annee);

    // Validation de l'année
    if (liste_taches[nombre_taches].Date.annee < 2024) {
        printf("Invalide : l'année %d est inférieure à 2024.\n", 
               liste_taches[nombre_taches].Date.annee);
        return; // Sortir de la fonction si l'année est invalide
    }

    printf("Nouvelle priorite (High/Low) : ");
    scanf(" %[^\n]", liste_taches[index].priorite);

    printf("Tache modifiee avec succès !\n");
}

// Fonction pour supprimer une tache
void supprimer_tache() {
    int index;
    printf("Entrez le numero de la tache à supprimer : ");
    scanf("%d", &index);
    index--; 

    if (index < 0 || index >= nombre_taches) {
        printf("Tache introuvable.\n");
        return;
    }

    for (int i = index; i < nombre_taches - 1; i++) {
        liste_taches[i] = liste_taches[i + 1];
    }
    nombre_taches--;
    printf("Tache supprimee avec succès !\n");
}

// Fonction pour filtrer les taches par priorite
void filtrer_par_priorite() {
    char priorite[5];
    printf("Entrez la priorite à filtrer (High/Low) : ");
    scanf(" %[^\n]", priorite);

    printf("\n=== Taches avec priorite %s ===\n", priorite);
    for (int i = 0; i < nombre_taches; i++) {
        if (strcmp(liste_taches[i].priorite, priorite) == 0) {
            printf("Tache %d : %s\n", i + 1, liste_taches[i].titre);
            printf("Description : %s\n", liste_taches[i].description);
            printf("Date d'echeance : %d-%d-%d\n", 
             liste_taches[nombre_taches].Date.jour,
     liste_taches[nombre_taches].Date.mois,
     liste_taches[nombre_taches].Date.annee
    );
            printf("----------------------\n");
        }
    }
}

