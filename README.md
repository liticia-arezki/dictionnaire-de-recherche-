# Projet de Gestion et Classement de Mots
# dictionnaire de recherche en anglais 

## Description

Ce projet permet de lire un fichier texte contenant des mots, de les classer et de les organiser dans des structures de données adaptées pour un traitement efficace. L’utilisateur peut insérer, supprimer, compter et afficher les mots ainsi que la taille des différentes listes créées. Le programme est interactif et propose un menu pour choisir les différentes fonctionnalités.

---

## Principe de la réalisation

1. **Lecture du fichier**  
   L’utilisateur saisit le nom du fichier à lire. Le programme parcourt le fichier et stocke tous les mots dans un tableau.

2. **Tri des mots**  
   Les mots sont triés selon :
   - Leur longueur.
   - L’ordre alphabétique pour les mots de même longueur.

3. **Création des structures de données**  
   - Un tableau de 26 têtes vers des listes doublement chaînées est créé, une pour chaque lettre de l’alphabet.  
   - Les mots sont insérés dans la liste correspondant à leur première lettre.  
   - Des listes de syllabes sont également générées en parallèle.

4. **Création des liens**  
   - Des liens sont établis entre les mots et les syllabes selon certaines caractéristiques.  
   - Ces liens permettent de calculer le nombre de sous-listes pour l’affichage.

5. **Insertion et suppression**  
   - Pour insérer un mot, un nouveau maillon est créé et placé à la bonne position dans la liste.  
   - Pour supprimer un mot, le programme cherche le maillon correspondant et le retire de la liste.

6. **Calcul et affichage**  
   - Calcul du nombre total de mots en parcourant toutes les listes.  
   - Possibilité d’afficher la taille de chaque liste.

7. **Menu interactif**  
   L’utilisateur peut choisir les différentes opérations : afficher les mots, insérer, supprimer, compter ou afficher les tailles.

8. **Libération des ressources**  
   À la fin de l’exécution, toutes les listes sont libérées et le fichier est fermé.

---

## Fonctionnalités principales

- Lecture d’un fichier texte et stockage des mots.  
- Tri des mots par longueur et ordre alphabétique.  
- Organisation en listes doublement chaînées pour chaque lettre.  
- Gestion des listes de syllabes.  
- Insertion et suppression dynamique des mots.  
- Calcul du nombre total de mots et de la taille des listes.  
- Menu interactif pour l’utilisateur.  
- Libération complète de la mémoire et fermeture du fichier.

---

## Technologies utilisées

- Langage : C .  
- Structures de données : tableau, listes doublement chaînées, maillons et liens entre listes.  
- Gestion dynamique de la mémoire.

---

## Utilisation

1. Compiler le programme selon le langage utilisé.  
2. Lancer l’exécutable ou la classe principale.  
3. Saisir le nom du fichier contenant les mots.  
4. Utiliser le menu pour choisir les opérations :  
   - Afficher les mots  
   - Insérer un mot  
   - Supprimer un mot  
   - Compter les mots  
   - Afficher la taille des listes  
5. Quitter le programme pour libérer la mémoire et fermer le fichier.

---

## AREZKI Liticia
  
