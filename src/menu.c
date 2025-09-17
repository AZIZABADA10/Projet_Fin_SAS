#include <stdio.h>
#include "../include/menu.h"

int Menu()
{
    int choix;

    printf("\n============================Systeme de gestion d'equipe de footbool==========================\n");
    printf("============================================== Menu =========================================\n\n");
    printf("                                    1. Ajouter un joueur \n");
    printf("                                    2. Afficher la liste des joueurs \n");
    printf("                                    3. Modifier un joueur \n");
    printf("                                    4. Supprimer un joueur \n");
    printf("                                    5. Rechercher un joueur \n");
    printf("                                    6. Statistiques \n");
    printf("                                    7. Quitter le programme \n\n");
    printf("============================================= Fin Menu ========================================\n");
    printf("Donner voitre Choix:-> ");
    scanf("%d", &choix);
    getchar();

    return choix;
}

int MenuAjouter()
{
    int choixAjouter;
    printf("\n");
    printf("                                    1. Ajouter un nouveau joueur \n");
    printf("                                    2. Ajouter plusieur joueurs \n");
    printf("                                    0. Rotour au menu principal \n\n");
    printf("Donner voitre Choix:-> ");
    scanf("%d", &choixAjouter);
    getchar();

    return choixAjouter;
}

int MenuAfficher()
{
    int choixAfficher;
    printf("\n");
    printf("                                    1. Affichier les joueurs par ordre alphabetique \n");
    printf("                                    2. Affichier  les joueurs par age. \n");
    printf("                                    3. Affichier les joueurs par poste. \n");
    printf("                                    0. Rotour au menu principal \n\n");
    printf("Donner voitre Choix:-> ");
    scanf("%d", &choixAfficher);
    getchar();

    return choixAfficher;
}

int MenuRecherche()
{
    int choixRecherche;
    printf("\n");
    printf("                                    1. Rechercher un joueur par Identifiant \n");
    printf("                                    2. Rechercher un joueur par Nom \n");
    printf("                                    0. Rotour au menu principal \n");
    printf("Donner voitre Choix:-> ");
    scanf("%d", &choixRecherche);
    getchar();

    return choixRecherche;
}

int MenuModifier()
{
    int choixModifier;
    printf("                                    1. Modifier le poste d'un joueur. \n");
    printf("                                    2. Modifier l'age d'un joueur. \n");
    printf("                                    3. Modifier le nombre de buts marques par un joueur. \n");
    printf("                                    4. Modifier le statut du joueur. \n");
    printf("                                    0. Rotour au menu principal \n\n");
    printf("Donner voitre Choix:-> ");
    scanf("%d", &choixModifier);
    getchar();

    return choixModifier;
}

int MenuStatistiques()
{
    int choixStatistiques;
    printf("\n");
    printf("                                    1. Afficher le nombre total de joueurs dans l'equipe \n");
    printf("                                    2. Afficher l'age moyen des joueurs \n");
    printf("                                    3. Afficher les joueurs ayant marque plus de X buts \n");
    printf("                                    4. Afficher le meilleur buteur \n");
    printf("                                    5. Afficher le joueur le plus jeune et le plus age \n");
    printf("                                    0. Rotour au menu principal \n\n");
    printf("Donner voitre Choix:-> ");
    scanf("%d", &choixStatistiques);
    getchar();

    return choixStatistiques;
}

int MenuSupp()
{
    int choixSupp;
    printf("\n");
    printf("                                    1. Supprimer par id \n");
    printf("                                    0. Rotour au menu principal \n");
    printf("Donner voitre Choix:-> ");
    scanf("%d", &choixSupp);
    getchar();

    return choixSupp;
}
