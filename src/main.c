#include <stdio.h>
#include "../include/menu.h"
#include "../include/joueur.h"


int main()
{
    int choix;
    int nbrJoueur = 7;

    //struct Joueur Equipe[MAX_N_J];
    //  int nbrJoueur = MAX_N_J;

    struct Joueur Equipe[MAX_N_J] = {
        {1, 1, 26, 0, "Bounou", "Yassine", "Gardien", "Titulaire", {01, 07, 2024}},
        {2, 6, 29, 3, "Amrabat", "Sofyan", "Milieu", "Titulaire", {01, 07, 2024}},
        {3, 7, 25, 12, "Ziyech", "Hakim", "Ailier", "Titulaire", {01, 07, 2024}},
        {4, 5, 24, 2, "Aguerd", "Nayef", "Defenseur", "Titulaire", {01, 07, 2024}},
        {5, 2, 21, 1, "Hakimi", "Achraf", "Arriere Droit", "Titulaire", {01, 07, 2024}},
        {6, 9, 27, 8, "En-Nesyri", "Youssef", "Attaquant", "Titulaire", {01, 07, 2024}},
        {7, 8, 28, 4, "Ounahi", "Azzedine", "Milieu", "Remplacant", {01, 07, 2024}}

    };

    do
    {
        choix = Menu();
        int choixAjouter;
        int choixAfficher;
        int choixRecherche;
        int position;
        int choixAModier;
        int choixStatistiques;
        int choixSupp;

        switch (choix)
        {
        case 1:
            do
            {
                choixAjouter = MenuAjouter();

                switch (choixAjouter)
                {
                case 1:
                    nbrJoueur = ajouterJoueur(Equipe, nbrJoueur);
                    break;
                case 2:
                    nbrJoueur = ajouterPlusieursJoueur(Equipe, nbrJoueur);
                    break;
                case 0:
                    break;
                default:
                    printf("-----------------------Donner soit 1 soit 2 !!-----------------------\n");
                    break;
                }
            } while (choixAjouter != 0);
            break;
        case 2:
            do
            {
                choixAfficher = MenuAfficher();

                switch (choixAfficher)
                {
                case 1:
                    printf("-->La liste des joueur trie par nom: \n");
                    afficherListeJoueur(triParNom(Equipe, nbrJoueur), nbrJoueur);
                    break;
                case 2:
                    printf("-->La liste des joueur trie par Age: \n");
                    afficherListeJoueur(triParAge(Equipe, nbrJoueur), nbrJoueur);
                    break;
                case 3:
                    printf("-->La liste des joueur trie par poste: \n");
                    afficherListeJoueur(triParPoste(Equipe, nbrJoueur), nbrJoueur);
                    break;
                case 0:
                    break;
                default:
                    printf("-------------------Donner un choix entre 1 et 3 !!----------------------------- \n");
                    break;
                }
            } while (choixAfficher != 0);
            break;
        case 3:
            position = rechercherParId(Equipe, nbrJoueur);
            if (position >= 0)
            {
                afficherJoueurRecherche(Equipe, position, nbrJoueur);

                do
                {
                    choixAModier = MenuModifier();

                    switch (choixAModier)
                    {
                    case 1:
                        modifierPost(Equipe, position);
                        break;
                    case 2:
                        modifierAge(Equipe, position);
                        break;
                    case 3:
                        modifierNbrBut(Equipe, position);
                        break;
                    case 4:
                        modifierStatut(Equipe, position);
                        break;
                    case 0:
                        break;
                    default:
                        printf("----------------------Donner un choix entre 0 et 3 !-------------------");
                        break;
                    }
                } while (choixAModier != 0);
            }
            else
            {
                printf("-------------------------------Aucun joueur avce ce id !-------------------------------------");
            }
            break;
        case 4:
            do
            {
                choixSupp = MenuSupp();

                switch (choixSupp)
                {
                case 1:
                    position = rechercherParId(Equipe, nbrJoueur);
                    if (position >= 0)
                    {
                        nbrJoueur = supprimerJoueur(position, Equipe, nbrJoueur);
                        printf("----------------------%s a ete supprime avec succes.-----------------\n", Equipe[position].nom);
                    }
                    else
                    {
                        printf("---------------Aucun joueur avec cet ID:%d trouve ! --------------\n", position);
                    }
                    break;
                case 0:
                    break;
                default:
                    printf("---------------Il faut donner donner soit 1 soit 2! --------------\n", position);
                    break;
                }

            } while (choixSupp != 0);
            break;
        case 5:
            do
            {
                choixRecherche = MenuRecherche();
                switch (choixRecherche)
                {
                case 1:
                    position = rechercherParId(Equipe, nbrJoueur);
                    afficherJoueurRecherche(Equipe, position, nbrJoueur);
                    break;
                case 2:
                    position = rechercherParNom(Equipe, nbrJoueur);
                    afficherJoueurRecherche(Equipe, position, nbrJoueur);
                    break;
                case 0:
                    break;
                default:
                    printf("----------------Donner un choix entre 1 et 2 ou 0!!-------------- \n");
                    break;
                }

            } while (choixRecherche != 0);
            break;
        case 6:
            do
            {
                choixStatistiques = MenuStatistiques();

                switch (choixStatistiques)
                {
                case 1:
                    printf("\n-->Le nombre total des joueur sur l'equipe est: %d \n", nbrJoueur);
                    break;
                case 2:
                    ageMoyenne(Equipe, nbrJoueur);
                    break;
                case 3:
                    joueurMaxButs(Equipe, nbrJoueur);
                    break;
                case 4:
                    maxButeur(Equipe, nbrJoueur);
                    break;
                case 5:
                    plusAgePlusJeune(Equipe, nbrJoueur);
                    break;
                case 0:
                    break;
                default:
                    printf("\n--------------------Donner un choi entre 0 et 5 !-----------------\n");
                    break;
                }

            } while (choixStatistiques != 0);
            break;
        case 7:
            printf("=========================================== Au revoir! ========================================");
            break;
        default:
            printf("------------------------------Il faut donner un choix entre 1 et 7 !!!-------------------------------\n");
            break;
        }

    } while (choix != 7);

    return 0;
}
