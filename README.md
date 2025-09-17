# ⚽ Projet Fin SAS – Gestion d’une Équipe de Football

##  Description

Ce projet est une application en langage C permettant de gérer une équipe de football.  
Elle offre un ensemble complet de fonctionnalités : ajout, suppression, recherche, modification, tri et statistiques des joueurs.  
Le programme fonctionne en mode console et utilise des menus interactifs.

---

## Fonctionnalités principales

- **Gestion des joueurs**
  - Ajouter un joueur
  - Ajouter plusieurs joueurs
  - Supprimer un joueur
  - Modifier les informations d’un joueur (poste, statut, âge, nombre de buts)

- **Affichage et tri**
  - Afficher tous les joueurs
  - Trier les joueurs par nom
  - Trier les joueurs par âge
  - Trier les joueurs par poste

- **Recherche**
  - Rechercher un joueur par ID
  - Rechercher un joueur par nom

- **Statistiques**
  - Calculer l’âge moyen des joueurs
  - Afficher le joueur ayant le plus de buts
  - Afficher les buteurs par poste
  - Afficher le joueur le plus âgé et le plus jeune

---

##  Structure du projet

```

Projet\_Fin\_SAS/
│
├── include/
│   ├── joueur.h     # Déclarations des structures et fonctions des joueurs
│   └── menu.h       # Déclarations des fonctions d’affichage des menus
│
├── src/
│   ├── main.c       # Point d’entrée du programme
│   ├── joueur.c     # Implémentation des fonctions de gestion des joueurs
│   └── menu.c       # Implémentation des fonctions des menus
│
└── Makefile         # Fichier de compilation

````

---

## Compilation et exécution

### 1. Avec **gcc** directement

Dans le dossier `src` :

```bash
gcc main.c menu.c joueur.c -I../include -o foot
./foot
````

## Utilisation

Au lancement du programme, un menu principal s’affiche.
Vous pouvez naviguer en tapant le chiffre correspondant à l’action souhaitée :

```
1. Ajouter des joueurs
2. Afficher les joueurs
3. Rechercher un joueur
4. Modifier un joueur
5. Supprimer un joueur
6. Statistiques
7. Quitter
```

Suivez les instructions à l’écran pour effectuer les opérations.

---

## Technologies utilisées

* **Langage :** C (standard C99)
* **Compilation :** GCC
* **Organisation :** Architecture modulaire avec headers `.h` et sources `.c`

---

##  Auteurs

* **Abada aziz* – Développeur
* **Encadrant / Binôme** – Encadrement / Collaboration

