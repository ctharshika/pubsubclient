# Let's Toggle

### Introduction
Ce projet a pour objectif de vous aider à prendre en main le framework Arduino puis ESP-IDF pour le SoC WIFI ESP32 d'Espressif.

### Prérequis
1. Avoir un binôme
2. Créer un compte Gitlab
3. Installer Git ([Windows](https://gitforwindows.org/), [Ubuntu](https://help.ubuntu.com/lts/serverguide/git.html), ou [OSX](https://git-scm.com/download/mac))
4. Installer [VS Code](https://code.visualstudio.com/)
5. Ajouter l'extension [PlatformIO IDE](https://platformio.org/) à VS Code
6. Etudier la documentation de la carte [WiFi kit 32 de Heltec](https://heltec.org/project/wifi-kit-32/) et notamment son [Schéma de câblage](https://github.com/Heltec-Aaron-Lee/WiFi_Kit_series/blob/master/SchematicDiagram/WIFI_Kit_32_Schematic_diagram.PDF)

### Objectif
Votre objectif lors de ce TP est de manipuler et de vous familiariser avec le développement d'un firmware communiquant pour un objet connecté.

Afin de vérifier votre compréhension du fonctionnement de l'environnement de développement, **vous devrez mettre à jour votre "git repository" sur gitlab**.
Vous devrez donc "commit" vos modifications régulièrements. Chaque exercice, devra faire l'objet d'une "branch" distincte sur votre "repository". Pour indiquer qu'un exercice est terminé, vous devrez tagguer le "commit" corrrespondant avec le formalisme suivant : **ex-N** ou N correspond au numéro de l'exercice.

**Chaque exercice contient une consigne bonus ! Avant de l'implémenter, terminez tous les exercices :)**

***Posez toutes vos questions sur [gitter](https://gitter.im/PP-ECE/community) !***

### Evaluation
L'évaluation de votre travail sera réalisée sur les critères suivants :
- Exercices terminées
- Respect des consignes
- Contenu et description des "commit"
- Qualité du code (structure, lisibilité, commentaires utiles si et seulement si nécessaire...)
- Temps nécessaire pour réaliser les exercices

# Exercice 1 - Ardui... quoi ?

### Objectif
Prendre en main la carte [WiFi kit 32 de Heltec](https://heltec.org/project/wifi-kit-32/) dans un environnement simple : le framework Arduino.

Vous devrez controler la LED et l'écran OLED avec le bouton poussoir PRG.

Votre code devra :
- Lorsque l'application démarre, la LED s'allume
- Lorsqu'un utilisateur appui sur le bouton PRG :
  - L'état de la LED (allumé ou éteint) doit-être inversé
  - L'écran OLED doit afficher en toute lettre l'état de la LED

**Bonus** : Utiliser une interruption pour detecter l'appui sur le bouton

### Instructions
1. Ajouter un clé SSH à votre compte Gitlab => [Aide disponible ici](https://gitlab.com/help/ssh/README#generating-a-new-ssh-key-pair)
   
2. Cloner le projet `git clone git@gitlab.com:OCRES_PP/2019_2020/b<N>/toggle.git` (remplacer `<N>` par votre numéro de binôme)
   
3. Ouvrir votre projet avec PlatformIO

4. **Build** le projet avec PlatformIO pour vérifier que votre environnement de développement fonctionne

5. Modifier le code pour compléter l'exercice
   
6. "Commit" de l'exercice sur une "branch" :
   - Créez une "branch" local et placez vous dessus `git checkout -b Exercice-1`
   - Vérifier vos changement réalisé depuis le clonage du repo `git status`
   - Regardez en détails vos changements sur le fichier main.cpp `git diff main.cpp`
   - Ajouter les fichiers que vous souhaitez conserver pour votre "commit" `git add <filename>`
   - Lorsque vous avez ajouté tous les fichers nécessaire à votre "commit" créez-le `git commit -m "Description de votre commit"`
   - Maintenant que vous avez mis à jour votre "repository" local vous devez mettre à jour le "repository" distant `git push -u origin Exercice-1`
   - Tagguer votre "commit" `git tag Ex-1` puis mettre à jour le "repository" distant `git push origin --tags`

# Exercice 2 - Espressif ESP-IDF Framework :

### Objectif
Prendre en main la carte dans un environnement plus complet et moins abstrait : ESP-IDF

Vous devrez controler la LED et l'écran OLED avec le bouton poussoir PRG.

Votre code devra :
- Lorsque l'application démarre, la LED s'allume
- Lorsqu'un utilisateur appui sur le bouton PRG :
  - L'état de la LED (allumé ou éteint) doit-être inversé
  - L'écran OLED doit afficher en toute lettre l'état de la LED
 
**Bonus** : Utiliser une interruption pour detecter l'appui sur le bouton

### Instructions
1. Ouvrir la "branch" Exercice-2 `git checkout Exercice-2`

2. **Build** le projet avec PlatformIO pour vérifier que votre environnement de développement fonctionne

3. Modifier le code pour compléter l'exercice et "commit" à convenance

4. Tagguer le "commit" à corriger
