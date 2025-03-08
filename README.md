
- [Server Documentation](server/README.md)
- [AI Documentation](ai/README.md)
- [GUI Documentation](gui/README.md)

# Zappy

## Prérequis
Pour utiliser ce projet, vous aurez besoin d’un compilateur compatible avec C++ 20.

Le client graphique a été développé en C++20 à l’aide de la bibliothèque SFML pour l’interface graphique.
L’intelligence artificielle a été réalisée avec Python (version 3.10+).
Le client serveur a été développé en C avec le compilateur GNU GCC.

## Description
Zappy est un jeu entièrement automatisé où des intelligences artificielles (IA) s’affrontent dans un monde virtuel pour survivre,
 collecter des ressources et atteindre le plus haut niveau de leur évolution. Le jeu met en scène des équipes d’IA autonomes qui 
 doivent collaborer au sein de leurs familles ou groupes tout en rivalisant avec les autres pour remporter la partie.

 ## Objectifs du jeu
Le but ultime est qu'une équipe parvienne à faire évoluer six de ses membres au niveau maximum (8). Pour atteindre cet objectif, les IA doivent :

Survivre en trouvant et consommant de la nourriture.
Explorer le monde pour collecter des ressources spécifiques.
Effectuer des rituels d’évolution en réunissant les membres nécessaires et les ressources requises pour chaque niveau.
Chaque niveau d'évolution impose des exigences de plus en plus complexes, rendant la progression plus difficile à mesure que le jeu avance.

## Utilisation
### Compilation du programme

Vous pouvez compiler les binaires comme suit :
**make** ou **make re** pour recompiler tous les fichiers.

Une fois le projet compilé, vous trouverez 3 binaires :

Un serveur, qui génère le monde des habitants.
Un client graphique, qui permet d’observer ce qui se passe dans le monde.
Un client, qui pilote un habitant à travers les ordres envoyés au serveur.
will never initiate an elevation to the next level (except to level 2). This one will never fork either.

### Exécution

After building project, here is the help output for the 3 binaries:

```bash
USAGE: ./zappy_gui -p port -h machine

DESCRIPTION:
        port is the port number
        machine is the name of the machine; localhost by default
```

```bash
usage: zappy_ai -p port -n name [-h machine] [-c file]

options:
  -p port     is the port number
  -n name     is the name of the team
  -h machine  is the name of the machine; localhost by default
  -c file     is the configuration file
```

```bash
USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
    port        is the port number
    width       is the width of the world
    height      is the height of the world
    nameX       is the name of the team X
    clientsNb   is the number of authorized clients per team
    freq        is the reciprocal of time unit for execution of actions
```

  # Pour jouer le jeux exécutez ces commandes dans le terminal
  ``
./zappy_server -p 8080 -x 10 -y 10 -n team1 team2 -c 10 -f 50

./zappy_gui -p 8080 -h 127.0.0.1
``

## Authors

**bahouara**
**komaudey**
**omarlene**
**rocoulibaly**