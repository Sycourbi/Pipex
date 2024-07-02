# Pipex

## Description

Bienvenue sur le dépôt du projet Pipex de l'École 42. Ce projet consiste à recréer le comportement de deux appels système très courants dans le monde Unix : `pipe` et `redirection`. L'objectif est de comprendre comment fonctionnent ces deux appels système et comment ils peuvent être utilisés pour construire un pipeline simple entre deux commandes.

## Badge et Note Obtenu

<div align="center">
  <img src="https://github.com/ayogun/42-project-badges/blob/main/badges/pipexm.png?raw=true" alt="Badge du projet ft_printf">
</div>

## Fonctionnalités

  - Permet d'exécuter deux commandes ou plus (bonus) en utilisant pipe et redirection.
  - Gère les entrées et les sorties de fichiers correctement.
   - Bonus : Gestion des flags <, >, >> pour les redirections de fichier.

## Exigences du Projet

Ce projet doit respecter les normes de l'École 42, y compris la norme de codage et les règles spécifiques définies pour le projet.

## Installation et Utilisation

Pour installer le projet Pipex, suivez ces étapes :

1. Clonez le dépôt :

   ```bash
   git clone https://github.com/Sycourbi/Pipex.git
   cd Pipex
   make
   make bonus
   
2. Lancer le programme :
   
   ```bash
   ./pipex file1 "ls -l" "wc -l" file2
   

