# Gestionnaire-de-notes-d-tudiants-.
Description
Ce programme permet de gérer les informations des étudiants dans une classe, telles que leur âge, nom, matières, coefficients, et notes. Il permet également de calculer la moyenne de chaque étudiant et d'afficher les informations d'un étudiant ou d'une classe en particulier.
Les fonctionnalités disponibles incluent :
1.Ajouter des informations pour un étudiant (nom, âge, matières, notes).
2.Afficher la liste des étudiants avec leurs moyennes.
3.Afficher la moyenne d'un étudiant spécifique.
4.Afficher les informations de tous les étudiants.
5.Afficher les informations d'un étudiant particulier.
Les données sont stockées dans des fichiers texte, un pour chaque classe et un autre pour les moyennes des étudiants.
Fonctionnalités
1. Ajouter les informations  d’un étudiant
Saisie de l'âge, du nom, des matières suivies, de leurs coefficients et des notes.
Enregistrement des informations dans le fichier classeX et des moyennes dans le fichier moyenne_classeX.
2. Liste des étudiants et leurs moyennes
Affiche tous les étudiants d'une classe ainsi que leurs moyennes, extraites du fichier moyenne_classeX.
3. Afficher la moyenne d'un étudiant
Permet de rechercher un étudiant par son nom et d'afficher sa moyenne à partir du fichier moyenne_classeX.
4. Afficher les informations d'un étudiant
Permet de rechercher un étudiant par son nom et d'afficher ses informations complètes (âge, nom, identifiant).
5. Afficher les informations de tous les étudiants
Affiche toutes les informations enregistrées dans le fichier classeX pour la classe sélectionnée.
Structures des fichiers
Le programme utilise deux fichiers par classe :
classeX : Contient les informations des étudiants (âge, nom, identifiant).
moyenne_classeX : Contient les moyennes des étudiants et leurs informations (ID, nom, moyenne).
Les fichiers sont créés au besoin lorsqu'un utilisateur choisit une classe.
Fonctionnement du programme
1.Menu principal : Lors du lancement, un menu permet de choisir la classe (classe1a, classe2a, ou classe3a).
2.Gestion des informations des étudiants : Le programme vous invite à entrer des informations sur les étudiants. Vous pouvez ajouter plusieurs étudiants si nécessaire.
3.Choix des actions : Un sous-menu permet de choisir différentes actions comme ajouter un étudiant, afficher les informations d'une classe ou rechercher un étudiant par son nom.

Le programme utilise des bibliothèques standard de C :
stdio.h pour les entrées/sorties.
string.h pour manipuler des chaînes de caractères.
stdlib.h pour la gestion de la mémoire et des conversions.
math.h pour les calculs mathématiques (comme l'arrondi des valeurs).
