#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_N_J 100
#define MAX_CH 50

const char poste[4][MAX_CH] = {"Gardien", "Defenseur", "Milieu", "Attaquant"};
const char statut[2][MAX_CH] = {"titulaire", "remplacant"};

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

struct DateInscription
{
    int jour;
    int mois;
    int annee;
};

struct Joueur
{
    int id, numeroMaillot, age, buts;
    char nom[MAX_CH], prenom[MAX_CH];
    char poste[MAX_CH];
    char statut[MAX_CH];
    struct DateInscription dateInscription;
};

int idJ = 8;

int ajouterJoueur(struct Joueur J[], int nbrJoueur)
{

    if (nbrJoueur == MAX_N_J)
    {
        printf("--------------------------------------L'equipe est complet !--------------------------------------\n");
        return nbrJoueur;
    }
    else
    {

        J[nbrJoueur].id = idJ++;
        int Nstatus = 0;
        int posPost;
        int posStatut;
        int NumMaillot;
        int unique;

        printf("Donner le nom:-> ");
        fgets(J[nbrJoueur].nom, MAX_CH, stdin);
        J[nbrJoueur].nom[strcspn(J[nbrJoueur].nom, "\n")] = '\0';

        printf("Donner le prenom:-> ");
        fgets(J[nbrJoueur].prenom, MAX_CH, stdin);
        J[nbrJoueur].prenom[strcspn(J[nbrJoueur].prenom, "\n")] = '\0';

        do
        {
            printf("Choise le poste: ");
            for (int i = 0; i < 4; i++)
            {
                printf("%d-%s ", i + 1, poste[i]);
            }
            printf("->:");
            scanf("%d", &posPost);
            getchar();
            if (posPost < 1 || posPost > 4)
            {
                printf("\n----------------------il faut donner un choix entre 1 et 4 !----------------------------\n");
            }
            else
            {
                strcpy(J[nbrJoueur].poste, poste[posPost - 1]);
            }
        } while (posPost < 1 || posPost > 4);

        do
        {
            printf("Choise le statut: ");
            for (int i = 0; i < 2; i++)
            {
                printf("%d-%s ", i + 1, statut[i]);
            }
            printf("->:");
            scanf("%d", &posStatut);
            getchar();

            if (posStatut < 1 || posStatut > 2)
            {
                printf("\n-----------------Il faut donner un choix entre 1 et 2!----------------------------\n");
            }
            else
            {

                strcpy(J[nbrJoueur].statut, statut[posStatut - 1]);
            }
        } while (posStatut < 1 || posStatut > 2);

        printf("Donner l'age:-> ");
        scanf("%d", &J[nbrJoueur].age);
        getchar();

        printf("Donner nombre buts:-> ");
        scanf("%d", &J[nbrJoueur].buts);
        getchar();

        do
        {
            unique = 1; 
            printf("Donner le numero Maillot:-> ");
            scanf("%d", &NumMaillot);
            getchar();

            for (int i = 0; i < nbrJoueur; i++)
            {
                if (NumMaillot == J[i].numeroMaillot)
                {
                    printf("----------Le num %d existe deja! Veuillez en choisir un autre.-------------\n", NumMaillot);
                    unique = 0; 
                    break;      
                }
            }
        } while (!unique);

        J[nbrJoueur].numeroMaillot = NumMaillot;

        printf("Donner la date d'inscription en format JJ/MM/AAAA:-> ");
        scanf("%d/%d/%d", &J[nbrJoueur].dateInscription.jour, &J[nbrJoueur].dateInscription.mois, &J[nbrJoueur].dateInscription.annee);
        getchar();

        printf("---------------------%s a ete ajouter avec succes avec Id:%d !--------------------\n ", J[nbrJoueur].nom, J[nbrJoueur].id);

        nbrJoueur += 1;
    }
    return nbrJoueur;
}

int ajouterPlusieursJoueur(struct Joueur J[], int nbrJoueur)
{

    int nbrJ;
    printf("Donner le nombre des joueur que vous voulez ajouter:-> ");
    scanf("%d", &nbrJ);
    getchar();

    if ((nbrJ+nbrJoueur) >= MAX_N_J)
    {
        printf("---------------------------L'equipe est complet !!----------------------- \n");
        return nbrJoueur;
    }
    else
    {
        for (int i = 0; i < nbrJ; i++)
        {
            nbrJoueur = ajouterJoueur(J, nbrJoueur);
        }
        return nbrJoueur;
    }
}

void afficherListeJoueur(struct Joueur J[], int nbrJoueur)
{
    printf("================================================================ Liste ============================================================================\n");
    if (nbrJoueur != 0)
    {
        for (int i = 0; i < nbrJoueur; i++)
        {
            printf("Joueur %d :Id:%d  -le nom: %s -le prenom: %s -le poste: %s -age: %d ans -Numero Maillot: %d -Buts: %d Date Inscription: %02d/%02d/%04d -statut: %s \n\n",
                   i + 1, J[i].id, J[i].nom, J[i].prenom, J[i].poste, J[i].age, J[i].numeroMaillot, J[i].buts, J[i].dateInscription.jour, J[i].dateInscription.mois, J[i].dateInscription.annee,
                   J[i].statut);
        }
    }
    else
    {
        printf("\n---------------------Aucun Joueur sur cette equipe----------------------- !!\n");
    }

    printf("============================================================ Fin Liste =============================================================================\n");
}

void afficherJoueurRecherche(struct Joueur J[], int position, int nbrJoueur)
{
    if (position >= 0 && position < nbrJoueur)
    {
        printf("Le Joueur rechercher est: \n");
        printf("Id:%d -le nom: %s -le prenom: %s -le poste: %s -age: %d ans -Numero Maillot: %d -Buts: %d Date Inscription: %02d/%02d/%04d -statut: %s\n\n",
               J[position].id, J[position].nom, J[position].prenom, J[position].poste, J[position].age, J[position].numeroMaillot, J[position].buts,
               J[position].dateInscription.jour, J[position].dateInscription.mois, J[position].dateInscription.annee, J[position].statut);
    }
    else
    {
        printf("--------------------- Aucun Joueur avce ce id!!------------------\n", position);
    }
}

// int comparerEnMjuscule(char mot1[], char mot2[])
//  {
//      int k = 0;
//      while (mot1[k] != 0 && mot2[k] != 0)
//      {
//          char c1 = tolower(mot1[k]);
//          char c2 = tolower(mot2[k]);
//          if (c1 != c2)
//          {
//              return c1 - c2;
//          }
//          k++;
//      }
//      return tolower((unsigned char)mot1[k]) - tolower((unsigned char)mot2[k]);
//  }

struct Joueur *triParNom(struct Joueur J[], int nbrJoueur)
{

    struct Joueur Vtemp;
    if (nbrJoueur == 0)
    {
        return J;
    }
    else
    {
        for (int i = 0; i < nbrJoueur - 1; i++)
        {
            for (int k = i + 1; k < nbrJoueur; k++)
            {
                if (strcasecmp(J[i].nom, J[k].nom) > 0) // 97 - 98 = -1
                {
                    Vtemp = J[k];
                    J[k] = J[i];
                    J[i] = Vtemp;
                }
            }
        }
    }
    return J;
}

struct Joueur *triParAge(struct Joueur J[], int nbrJoueur)
{

    struct Joueur Vtemp;
    if (nbrJoueur == 0)
    {
        return J;
    }
    else
    {
        for (int i = 0; i < nbrJoueur - 1; i++)
        {
            for (int k = i + 1; k < nbrJoueur; k++)
            {
                if (J[i].age > J[k].age) // j[0]=17 > j[1]=15
                {
                    Vtemp = J[k]; // 15
                    J[k] = J[i];  // 17
                    J[i] = Vtemp; // 15
                }
            }
        }
    }
    return J;
}

struct Joueur *triParPoste(struct Joueur J[], int nbrJoueur)
{

    struct Joueur Vtemp;

    if (nbrJoueur == 0)
    {
        printf("-------Aucune Joueur dans cette equipe !!---------");
        return J;
    }
    else
    {

        for (int i = 0; i < nbrJoueur - 1; i++)
        {
            for (int z = i + 1; z < nbrJoueur; z++)
            {
                if (strcasecmp(J[i].poste, J[z].poste) > 0) // 97 98
                {
                    Vtemp = J[z];
                    J[z] = J[i];
                    J[i] = Vtemp;
                }
            }
        }
    }
    return J;
}

int rechercherParId(struct Joueur J[], int nbrJoueur)
{
    int idR;
    int existe = 0;
    printf("Donner l'id de Joueur:-> ");
    scanf("%d", &idR);
    getchar();

    for (int i = 0; i < nbrJoueur; i++)
    {

        if (idR == J[i].id)
        {
            return i;
        }
    }
    return -1;
}

int rechercherParNom(struct Joueur J[], int nbrJoueur)
{
    char nomC[MAX_CH];
    int existe = 0;
    printf("Donner le nom du Joueur:-> ");
    scanf("%s", &nomC);
    getchar();

    for (int i = 0; i < nbrJoueur; i++)
    { // strcasecmp strcmp
        if (strcasecmp(nomC, J[i].nom) == 0)
        {
            return i;
        }
    }
    return -1;
}

void modifierPost(struct Joueur J[], int position)
{
    int posPostM;

    do
    {
        printf("Choise le nouveau poste:->: ");
        for (int i = 0; i < 4; i++)
        {
            printf("%d-%s ", i + 1, poste[i]);
        }
        printf("->:");
        scanf("%d", &posPostM);
        getchar();
        if (posPostM < 1 || posPostM > 4)
        {
            printf("\n----------------------il faut donner un choix entre 1 et 4 !----------------------------\n");
        }
        else
        {
            strcpy(J[position].poste, poste[posPostM - 1]);
        }
    } while (posPostM < 1 || posPostM > 4);

    printf("------La modification a fait avec succes !-------\n");
}

void modifierStatut(struct Joueur J[], int position)
{
    int positionStatus;

    do
    {
        printf("Choise le statut: ");
        for (int i = 0; i < 2; i++)
        {
            printf("%d-%s ", i + 1, statut[i]);
        }
        printf("->:");
        scanf("%d", &positionStatus);
        getchar();

        if (positionStatus < 1 || positionStatus > 2)
        {
            printf("\n-----------------il faut donner un choix entre 1 et 2!----------------------------\n");
        }
        else
        {

            strcpy(J[position].statut, statut[positionStatus - 1]);
        }
    } while (positionStatus < 1 || positionStatus > 2);
    printf("--------------La modification a fait avec succes !----------\n");
}

void modifierAge(struct Joueur J[], int position)
{
    int NouveauAge;

    printf("Donner le nouveau age:-> ");
    scanf("%d", &NouveauAge);
    J[position].age = NouveauAge;
    printf("---------------La modification a fait avec succes !-----------------\n");
}

void modifierNbrBut(struct Joueur J[], int position)
{
    int NouveauNbrBut;
    int MaxButStar = 10;
    

    printf("Donner le nouveau buts:-> ");
    scanf("%d", &NouveauNbrBut);


    if (NouveauNbrBut <=J[position].buts )
    {
        printf(" il faut donner un nombre suprieur strictement a %d",J[position].buts );
    }else
    {
        J[position].buts = NouveauNbrBut;
        printf("\n-------------------------------------------------------------\n");
        printf("--------------La modification a fait avec succes !-------------\n");
        printf("\n--------------------------------------------------------------\n");
    }
}

int supprimerJoueur(int position, struct Joueur Equipe[], int nbrJoueur)
{
    for (int i = position; i < nbrJoueur - 1; i++)
    {
        Equipe[i] = Equipe[i + 1];
    }
    nbrJoueur--;
    return nbrJoueur;
}

void ageMoyenne(struct Joueur J[], int nbrJoueur)
{
    float Moyenne;
    int Somme = 0;
    for (int i = 0; i < nbrJoueur; i++)
    {
        Somme += J[i].age;
    }

    if (nbrJoueur > 0)
    {
        Moyenne = Somme / nbrJoueur;
        printf("->L'age moyenne de equipe est: %.2f ans \n", Moyenne);
    }
    else
    {
        printf("\n----------------------------- Aucun joueur on ne peut pas calculer la moyenne !! ---------------------------\n");
    }
}

void joueurMaxButs(struct Joueur J[], int nbrJoueur)
{

    int nombreMax;
    int cmpJmax = 0;
    printf("Donner le nombre de buts minimum:--> ");
    scanf("%d", &nombreMax);
    getchar();

    for (int i = 0; i < nbrJoueur; i++)
    {
        if (nombreMax <= J[i].buts)
        {
            printf("->Id:%d -le nom: %s-le prenom: %s -le poste: %s-age: %d ans -Numero Maillot: %d -Buts: %d \n",
                   J[i].id, J[i].nom, J[i].prenom, J[i].poste, J[i].age, J[i].numeroMaillot, J[i].buts);
            cmpJmax++;
        }
    }
    if (cmpJmax == 0)
    {
        printf("\n--------------------------Aucun joueur a ete marquer %d buts----------------------------\n", nombreMax);
    }
}

void maxButeur(struct Joueur J[], int nbrJoueur)
{
    int max = J[0].buts;
    int pos;
    for (int i = 0; i < nbrJoueur; i++)
    {
        if (max < J[i].buts)
        {
            max = J[i].buts;
            pos = i;
        }
    }
    printf("-->Le buteur est:%s nombre de buts: %d \n", J[pos].nom, max);
}

void plusAgePlusJeune(struct Joueur J[], int nbrJoueur)
{
    int plusJeune = J[0].age;
    int posJeun;
    int plusAge = J[0].age;
    int posAge;
    for (int i = 0; i < nbrJoueur; i++)
    {
        if (plusJeune > J[i].age)
        {
            plusJeune = J[i].age;
            posJeun = i;
        }
        if (plusAge < J[i].age)
        {
            plusAge = J[i].age;
            posAge = i;
        }
    }
    printf("-->Le plus Jeune est: %s sont age: %d \n", J[posJeun].nom, plusJeune);
    printf("-->Le plus Age est: %s sont age: %d \n", J[posAge].nom, plusAge);
}

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
