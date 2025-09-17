#ifndef JOUEUR_H
#define JOUEUR_H

#include <stdio.h>
#include <string.h>

#define MAX_N_J 100
#define MAX_CH 50

extern const char poste[4][MAX_CH];
extern const char statut[2][MAX_CH];

struct DateInscription {
    int jour;
    int mois;
    int annee;
};

struct Joueur {
    int id, numeroMaillot, age, buts;
    char nom[MAX_CH], prenom[MAX_CH];
    char poste[MAX_CH];
    char statut[MAX_CH];
    struct DateInscription dateInscription;
};

int ajouterJoueur(struct Joueur J[], int nbrJoueur);

int ajouterPlusieursJoueur(struct Joueur J[], int nbrJoueur);

void afficherListeJoueur(struct Joueur J[], int nbrJoueur);

void afficherJoueurRecherche(struct Joueur J[], int position, int nbrJoueur);

struct Joueur *triParNom(struct Joueur J[], int nbrJoueur);

struct Joueur *triParAge(struct Joueur J[], int nbrJoueur);

struct Joueur *triParPoste(struct Joueur J[], int nbrJoueur);

int rechercherParId(struct Joueur J[], int nbrJoueur);

int rechercherParNom(struct Joueur J[], int nbrJoueur);

void modifierPost(struct Joueur J[], int position);

void modifierStatut(struct Joueur J[], int position);

void modifierAge(struct Joueur J[], int position);

void modifierNbrBut(struct Joueur J[], int position);

int supprimerJoueur(int position, struct Joueur Equipe[], int nbrJoueur);

void ageMoyenne(struct Joueur J[], int nbrJoueur);

void joueurMaxButs(struct Joueur J[], int nbrJoueur);

void maxButeur(struct Joueur J[], int nbrJoueur);

void plusAgePlusJeune(struct Joueur J[], int nbrJoueur);

#endif
