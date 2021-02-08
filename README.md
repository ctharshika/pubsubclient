# Plateforme de Prototypage
## Partie 1 : L'application embarquée

### Besoin d'aide ?
**Posez toutes vos questions sur la conversation de groupe Teams**

### Prérequis
1. Avoir un binôme
2. Créer un compte Gitlab
3. Installer Git ([Windows](https://gitforwindows.org/), [Ubuntu](https://help.ubuntu.com/lts/serverguide/git.html), ou [OSX](https://git-scm.com/download/mac))
4. Installer [VS Code](https://code.visualstudio.com/)
5. Ajouter l'extension [PlatformIO IDE](https://platformio.org/) à VS Code

### Objectif
Votre objectif lors de ce TP est de créer et structurer l'application embarqué d'un objet avant de le rendre connecté.

Afin de vérifier votre compréhension du fonctionnement de l'environnement de développement, **vous devrez mettre à jour votre `git repository` sur gitlab**.
Vous devrez donc `commit` vos modifications régulièrements. Chaque exercice, devra faire l'objet d'une `branch` distincte sur votre `repository`. Pour indiquer qu'un exercice est terminé, vous devrez tagguer le `commit` corrrespondant avec le formalisme suivant : **Ex-N** ou N correspond au numéro de l'exercice.

### Evaluation
L'évaluation de votre travail sera réalisée sur les critères suivants :
- Exercices terminées
- Respect des consignes de nommage des `branch` et `tag` git
- Contenu et description des `commit`
- Qualité du code (structure, lisibilité, commentaires utiles si et seulement si nécessaire...)
- Temps nécessaire pour réaliser les exercices

### Quelques resources
- [Documentation Heltec](https://heltec.org/project/wifi-kit-32/)
- [Reference framework Arduino](https://www.arduino.cc/reference/en/)
- [Reference framework ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/index.html)
- [Reference librairie u8g2](https://github.com/olikraus/u8g2/wiki/u8g2reference) : librairie utilisé pour l'ecran OLED
- [Librairies framework Arduino ESP32](https://github.com/espressif/arduino-esp32/tree/master/libraries) : liste des librairies disponible dans le framework Arduino accompagnée nombreux exemples d'utilisation
- [Diagramme en Markdown](https://docs.gitlab.com/ee/user/markdown.html#diagrams-and-flowcharts) : une solution simple pour faire une machine à état

# Exercice 1 - Structurer une application embarquée :

### Objectif
Lors du 1er TP, vous avez découvert l'environnement de développement et la carte Heltec Wifi kit 32. Nous vous proposons maintenant d'approffondir vos connaissances sur la structuration d'une application embarquée.

Pour ce faire, nous vous fournisson une nouvelle structure de projet composée de 4 grand blocs fonctionnels. Chaque bloc fonctionnel se compose d'un fichier `.h` et `.cpp` regroupé dans un dossié du même nom. Voici une rapide description de chaque bloc fonctionnel :
1. **App** : Regroupe l'ensemble du code relatif au fonctionnement de l'application. **Vous devrez travailler principalement sur ce bloc**
2. **Button** : Regroupe le code relatif au fonctionnement du bouton
3. **Led** : Regroupe le code relatif au fonctionnement de la led
4. **Oled** : Regroupe le code relatif au fonctionnement de l'ecran OLED

Votre code devra :
1. Lorsque l'application démarre, la LED s'allume
2. Lorsqu'un utilisateur appuie sur le bouton :
    - Si le bouton est resté appuyé plus de 5 secondes : faire clignoter la led 10 fois à 300ms d'interval
    - Si le bouton a été appuyé puis relaché 1 fois (simple clic) : inverser l'état de la led
    - Si le bouton a été appuyé puis relaché 2 fois (double clic) : incrémenter une variable et l'afficher sur l'écran OLED et faire clignoter la led à 1s d'interval à l'infini.
 

### Instructions
1. Cloner le projet
2. Ouvrir le projet avec PlatformIO
2. **Build** le projet avec PlatformIO
3. **Upload & Monitor** le projet sur la carte Heltec Wifi kit 32
4. Etudier le fonctionnement du code fourni
5. Dessiner le diagramme de la machine à état correspondant à l'application demandé.
6. Créer une `branch` Exercice-1 avec `git checkout -b Exercice-1`
7. Sauvegarder le diagramme au format png, jpg ou [md](https://docs.gitlab.com/ee/user/markdown.html) sous le nom `state_machine` à la racine de votre repository
8. Modifier le code pour compléter l'exercice et `commit` régulièrement
9. Tagguer le `commit` à corriger avec `Ex-1`
10. Publier vos `commit` avec `git push` et vos tags avec `git push origin --tags`

# Exercice 2 - Poke A Mole, votre futur jeu connecté :

### Objectif
Implémenter une version simplifiée du jeu d'arcade Poke A Mole.

Votre code devra :
1. Lorsque l'application démarre, la LED s'allume et le message `Attrappe Moi !` et `appuyer pour démarrer` s'affiche sur l'écran OLED
2. Lorsqu'un utilisateur appuie sur le bouton PRG, le jeu demarre :
   - Durant 5 secondes Le message `Prêt ?` s'affiche sur l'écran OLED et la LED clignote à 500ms d'interval
   - La LED s'éteint
   - Attendre pour une durée aléatoire entre 1 et 10 secondes
   - La LED s'allume et un chronomètre démarre (unité ms)
   - Lorsqu'un utilisateur appuie sur le bouton, la LED s'éteint, le chronomètre s'arrête et le temps de réactivité de l'utilisateur est mesuré et affiché sur l'ecran OLED avec le message `Temps de réaction xxxx ms` avec xxxx le temps de réaction.
   - Lorsqu'un utilisateur appuie sur le bouton PRG durant 5 secondes (long press), retourner à l'étape 1

### Instructions
1. Dessiner le diagramme de la machine à état correspondant à l'application demandé.
2. Créer une `branch` Exercice-2 à partir de la `branch` master
3. Sauvegarder le diagramme au format png, jpg ou [md](https://docs.gitlab.com/ee/user/markdown.html) sous le nom `state_machine` à la racine de votre repository
3. Modifier le code pour compléter l'exercice et `commit` à convenance
4. Tagguer le `commit` à corriger avec `Ex-2`
5. Publier vos `commit` avec `git push` et vos tags avec `git push origin --tags`