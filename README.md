# ZAPPY
# français
Objectifs
Vous devez créer Zappy, un jeu entièrement automatique où certaines IA jouent entre elles. Il s'agit de créer des familles/équipes, de survivre en mangeant et en collectant des pierres pour progresser. Chaque niveau requiert un rituel différent, ce qui rend l'aventure de plus en plus difficile pour les joueurs IA, qui jouent seuls, sans l'aide de leur créateur. La partie se termine lorsque six membres d'une même famille/équipe atteignent le niveau maximum (8).

Présentation du jeu
Les pièces du jeu
Voici les différentes parties du jeu :

Le servercontient le terrain, les ressources et gère la logique et le timing du jeu.

Un ou plusieurs joueurs clientsse connecteront au serveur et piloteront chacun un joueur. Les joueurs seront répartis en équipes.

Un graphic clientqui se connecte au serveur et affiche le champ et ce qui s'y passe.

Géographie
Le jeu consiste à gérer un monde entier et sa population. Ce monde, « Minerth », est géographiquement constitué de plaines ; il ne comporte aucun obstacle.

Le monde est sphérique et le plateau de jeu est représenté par une carte. Ainsi, si un joueur quitte le plateau par la droite, il y entrera à nouveau par la gauche.

Ressources
L'endroit où nous nous trouvons contient de nombreuses ressources utiles à votre survie. Il vous suffit de les chercher et de les récupérer avant les autres joueurs. Vous y trouverez des pierres et de la nourriture nécessaires à votre survie et à votre évolution.

Ces pierres sont de 6 types différents :

jade
péridot
ambre
améthyste
grenat
ammolite
Ces ressources doivent être générées aléatoirement par le serveur, bien qu'elles soient aléatoires, la génération doit avoir certaines règles logiques, par exemple :

On ne peut pas mettre toutes les pierres dans un seul carré.

Vous ne pouvez pas mettre plus d'un aliment par carré.

Une seule pierre de chaque type dans une case. Vous pouvez placer jusqu'à trois pierres de types différents dans une même case.

Ce ne sont là que quelques exemples de règles. C'est à vous de les définir, mais soyez prêt à les expliquer aux auditeurs.

Règles générales
Chaque joueur commence avec 10 aliments et 0 pierres.
Chaque joueur commence au niveau 1.
Au fur et à mesure que vous progressez, votre vue de joueur s'améliore.
Vous devez manger pour survivre et non pas mourir de faim.
Vous devez collecter des pierres pour monter de niveau.
Pour gagner la partie, vous devez avoir au moins 6 joueurs de votre famille/équipe au niveau 8.
Joueur
Le local se contente de chercher des pierres et de se nourrir en chemin, mais ne vous laissez pas tromper par lui, il peut devenir gourmand et vous chasser de son chemin !

Il rencontre, sans difficulté, d'autres personnes au même endroit et voit aussi loin que l'œil peut porter.

Il est impossible de deviner l'orientation minerthienne en le croisant.

La nourriture que le Minerthien ramasse est la seule ressource dont il a besoin pour vivre.

Une unité de nourriture lui permet de survivre 126 unités de temps, soit 126 secondes. Plus il en ramasse, plus il vit.

Rituel d'évolution
L'objectif de chacun est d'atteindre le sommet de la hiérarchie minerthienne.

Le rituel qui permet d'augmenter les capacités physiques et mentales minerthiennes doit être réalisé comme suit :

Vous devez vous rassembler dans la même unité de terrain (carré) :

Un ensemble spécifique de pierres.
Un nombre spécifique de joueurs du même niveau.
Le joueur lancera l'enchantement et l'évolution commencera.

Il n’est pas nécessaire que tous les joueurs soient dans la même équipe, mais ils doivent avoir les mêmes niveaux.

Tous les joueurs participant à l'enchantement atteindront un niveau supérieur.

Un seul joueur commence l'enchantement et les autres vont vers lui et le rejoignent.

Ce n'est qu'une fois que deux joueurs ou plus se trouvent sur la même case qu'ils peuvent commencer l'enchantement.

Si l'un des membres meurt, les autres continueront l'enchantement, à moins que le joueur ne soit laissé seul, si cela se produit, il doit recommencer le processus d'enchantement.

Voici les combinaisons de ressources et de joueurs dont vous avez besoin pour l'enchantement et l'évolution :

Niveau	Nombre de joueurs	jade	péridot	ambre	améthyste	grenat	ammolite
1-2	1	1	0	0	0	0	0
2-3	2	1	1	1	0	0	0
3-4	2	2	0	1	0	2	0
4-5	4	1	1	2	0	1	0
5-6	4	1	2	1	3	0	0
6-7	6	1	2	3	0	1	0
7-8	6	2	2	2	2	2	1
Vision
La vue du joueur sur le terrain est limitée ! Pour améliorer votre vision, vous devrez progresser.
À chaque évolution, votre vision monte d'une unité de mesure en avant et d'une de chaque côté d'une nouvelle ligne.

Voici l'exemple pour les 3 premiers niveaux (notre joueur est à 0) :


              ---- ---- ----
             | 1  | 2  | 3  |
              ---- ---- ----
                  | 0  |
                   ----
                  Level 1

         ---- ---- ---- ---- ----
        | 4  |  5 |  6 |  7 |  8 |
         ---- ---- ---- ---- ----
             | 1  | 2  | 3  |
              ---- ---- ----
                  | 0  |
                   ----
                  Level 2

 ----- ----- ----- ----- ----- ----- -----
|  9  | 10  | 11  | 12  | 13  | 14  | 15  |
 ----- ----- ----- ----- ----- ----- -----
      |  4  |  5  |  6  |  7  |  8  |
       ----- ----- ----- ----- -----
             | 1  | 2  | 3  |
              ---- ---- ----
                  | 0  |
                   ----
                  Level 3

Pour que le joueur sache ce qui l'entoure, il clientenvoie la commande SEEet le serveur répond la chaîne de caractères suivante (pour le niveau 1) :

{content-square-0, content-square-1, content-square-2, content-square-3}
Notre joueur ne peut pas se voir et s'il y a plus d'un objet dans un carré, ils sont tous indiqués et séparés par un espace :

              -------- -------- --------
             | amber  | garnet |        |
             | player | garnet |        |
              -------- -------- --------
                      |        |
                      |  food  |
                       --------
                        Level 1

{food, player amber, garnet garnet, }
Le temps et la vitesse du jeu
La vitesse du jeu est définie par une unité de temps. Chaque action du jeu a une durée proportionnelle à cette unité de temps.

L'unité de temps est définie par la fonction 1/t :

t est passé en paramètre au démarrage du serveur.
Une unité de temps dure 1/t seconde.
Les Minerthiens ont la seconde comme unité de temps absolue.
La formule pour l’exécution d’une action est action/t.
test un entier. Si t=1« avance » prend 7 secondes (choisie par défaut), t=100« avance » prendra alors 7/100 secondes.
Gestion des objets
Il est impossible de distinguer deux objets de la même classe. Seule la classe d'un objet est identifiable. Autrement dit, deux « ambres » auront la même dénomination, car ils appartiennent à la même classe, tandis que le « grenat » aura une classe différente de celle des « ambres », ce qui permet d'identifier les ressources.

Équipes/Familles
Le but du jeu est de créer un groupe team/familyde six joueurs et de les amener au niveau 8 !

Au début du jeu, votre famille n'a qu'un seul membre, vous devez donc terminer l'action callingpour obtenir plus de membres de la famille.

Chaque joueur commence avec 10 aliments et est contrôlé par un client. Ils clientsne peuvent en aucun cas communiquer ni échanger de données entre eux en dehors du jeu.

Appel
L'exécution de la forkcommande déclenche l' shipappel d'un membre de sa famille. Votre joueur appellera alors un autre membre de sa famille.

Une fois l'appel lancé, le joueur peut poursuivre sa vie en attendant l'arrivée du « vaisseau ». À son shiparrivée, un nouveau joueur apparaîtra et recevra une instruction aléatoire. Cette opération permet à un nouveau joueur de rejoindre le groupe.

La connect_nbrcommande renvoie le nombre de connexions en cours et autorisées pour cette famille. Vous saurez ainsi combien de places sont libres dans votre équipe/famille.

Temps d'appel du navire : 48/t

Il est temps que le navire arrive 600/t

Inventaire
Cette inventorycommande permet de voir les objets dont dispose le joueur et le temps qu'il lui reste. Le serveur renvoie, par exemple, la ligne suivante :

{food 300, amber 4, garnet 7, ..., peridot 2}
Coup
Un joueur peut expulser tous les joueurs partageant la même case. Il les pousse dans la direction de son regard. Lorsqu'il clientenvoie la kickcommande au serveur, tous les joueurs clientsde cette case reçoivent la ligne suivante :

moving <K>\n
K indique la direction vers laquelle le joueur regarde, c'est-à-dire vers laquelle les autres joueurs seront expulsés. L'expulsion ne fonctionne que pour les joueurs ; vous ne pouvez pas expulser de nourriture ou d'autres ressources, et vous ne pouvez pas expulser pendant le rituel d'évolution.

Les commandes
Voici les actions auxquelles un joueur répondra et leur syntaxe. N'oubliez pas que la syntaxe doit être la suivante :

Action	Commande	Retard/temps	Réponse
avancer d'une case	avance	7/t	d'accord
tourner à droite à 90 degrés	droite	7/t	d'accord
tourner à gauche à 90 degrés	gauche	7/t	d'accord
voir	voir	7/t	{carré1, carré2, ...}
inventaire	inventaire	1/t	{grenat n, ambre n, ...}
choisir un objet	choisir <objet>	7/t	ok/ko
laisser tomber un objet	déposer <objet>	7/t	ok/ko
expulser un joueur du carré	coup	7/t	ok/ko
diffuser	diffusion <texte>	7/t	d'accord
commencer l'enchantement	enchantement	300/t	évolution en cours
niveau actuel : K
bifurquer un joueur	fourchette	48/t	d'accord
connaître le nombre de connexions inutilisées par l'équipe	connect_nbr	0/t	valeur
décès d'un joueur	-	-	la mort
Toutes les commandes sont transmises sous forme de chaîne de caractères se terminant par un saut de ligne. En cas de commande inconnue ou incorrecte, le serveur doit répondre par « ko ».

Diffuser
Pour envoyer un message, la commande suivante doit être envoyée au serveur par le client :

broadcast <text>
Le serveur enverra cette ligne à tous ses clients :

message <K>,<text>
Avec K indiquant la direction d'où vient le son.

Transmission du son
Tous les joueurs écoutent les émissions sans savoir qui les diffuse, ce qu'ils en comprennent, c'est seulement la direction d'où vient le son et le message.

Le nombre de cases parcourues par le son avant d'atteindre le joueur indique sa direction. Cette numérotation s'effectue en attribuant « 1 » à la case devant le joueur, puis en comptant les cases autour de lui dans le sens trigonométrique (sens inverse des aiguilles d'une montre). N'oubliez pas que le son est une onde se déplaçant linéairement et que la Terre est ronde ; nous choisirons donc le chemin le plus court pour le son entre l'émetteur et le joueur pour lequel nous avons calculé le trajet.

L'exemple suivant indique la trajectoire du son à choisir, ainsi que le nombre de cases autour du lecteur. Le lecteur « A » est la source qui envoie le signal via la case 4 et « B » est le récepteur qui reçoit le signal via la case 2.

Exemple

Si la diffusion est envoyée depuis la même case que le joueur récepteur, il recevra le message depuis la case 0.

Le serveur
Le serveur est le moteur principal qui interfère entre l'IA et l'interface graphique. Il échange toutes les données avec l'IA et exécute les instructions. Il envoie simultanément les informations à l'interface graphique. Il peut être écrit dans l'un des langages suivants : C, C++, Rust.

Pour cette partie, vous devez créer un serveur TCP pour établir une connexion entre les clients et gérer le monde entier. Il n'est pas nécessaire d'héberger le serveur, car le jeu ne fonctionnera que sur une seule machine ; un serveur local suffira pour l'instant.

Instructions du serveur
Votre serveur doit générer toutes les ressources de manière aléatoire en suivant les règles mentionnées ci-dessus dans la section ressources.
Aucune requête adressée à votre serveur ne doit être bloquée indéfiniment. Elle ne doit jamais être bloquée et clientpeut être renvoyée si nécessaire.
Le serveur exécute les clientrequêtes dans l’ordre dans lequel elles sont reçues.
Les requêtes sont mises en mémoire tampon et le temps d'exécution de la commande ne bloquera que le joueur concerné.
Il est interdit d'utiliser des execfonctions pour exécuter un autre serveur.
Il doit rester disponible à tout prix.
Utilisez des connexions multiplexées sur votre serveur.

$ ./server
	Usage: ./server -p <port> -x <width> -y <height> n <team> [<team>] [<team>] ... -c <nb> [-t <t>]
    -p  is the port number
    -x  is the width of the world
    -y  is the height of the world
    -n  is the name of the teams
    -c  is the number of authorized clients per team
    -t  is the time unit divider (the greater t is, the faster the game will go)
Conseil

Vous pouvez implémenter une architecture non bloquante avec un tampon circulaire pour chaque action du joueur, permettant ainsi le stockage des données pendant l'exécution des actions. L'approche à adopter vous appartient.
Le client
Le Client peut être rédigé dans la langue de votre choix.

$./client
Usage: ./client -n <team> -p <port> [-h <hostname>]
  -n is the name of the team
  -p is the port number
  -h is the name of the host, the default is localhost
Le client est autonome, il doit envoyer l'ordre de commande au serveur sans aucune intervention humaine.

Communication client/serveur
La communication entre le client et le serveur s'effectue via des sockets et TCP. Le port utilisé doit être indiqué dans les paramètres du programme.

Le client enverra ses requêtes sans attendre leur exécution, et le serveur renvoie un message confirmant l'exécution réussie des requêtes.

Cela clientouvrira un socket sur le port du serveur et la connexion clientse serverfera comme suit :

Message du client	Commande
BIENVENUE\n
nom-de-l'équipe\n	
nb-client\n
xy\n
Indique nb-clientle nombre de clients que le serveur peut encore accepter pour l'équipe team-name. Si ce nombre est supérieur à 1, un nouveau client se connecte. Indique Xégalement Yles dimensions du monde.

Si le nom de l'équipe transmis par le client n'existe pas, le serveur doit l'imprimer"Error: the team <name of team> doesn't exist"

Le client peut envoyer jusqu'à 10 requêtes réussies sans réponse du serveur. Au-delà, le serveur ne les prend plus en compte.

Il n'y a pas de chat ni de partage de données entre les joueurs. Cependant, le joueur peut diffuser un message via une ligne de commande envoyée au serveur, qui sera diffusé à tous les joueurs. Tous les détails sont disponibles dans la section « Transmission audio ».

Interface graphique
Pour une meilleure vision du jeu, simple, claire et ergonomique, le projet devra disposer d'un client de visualisation graphique. Ce client proposera une représentation en temps réel du monde tel qu'il est sur le serveur.

L'utilisation de tout moteur de jeu est interdite !
L'interface doit être au moins en 2D avec l'utilisation d'icônes permettant une représentation du monde.
Vous devez vous assurer que vous pouvez voir les objets du jeu.
Vous devez implémenter la fonctionnalité permettant de cliquer sur un carré pour en afficher les détails, comme le nombre d'éléments de chaque élément. Cela devrait ressembler à une fenêtre flottante, une info-bulle ou autre.
Vous devez vous assurer que la visualisation des sons est incluse.
La partie graphique peut être développée dans le langage de votre choix [Javascript, Python, C, C++, PHP, Perl, etc.]. Elle communiquera au sein du réseau avec le serverpour récupérer le contenu du map, teams, inventories, etc, tout ce qui est nécessaire pour visualiser l'activité du jeu.

PRIME
Créer une interface 3D ou tout autre type de représentation.
Ajoutez un indicateur pour un mode journal lors de l'exécution du serveur.
Ajoutez un indicateur pour le nombre de ressources et la densité de nourriture (il peut s'agir de niveaux différents par exemple).
Implémentez une graine dans le serveur et le client afin que des scénarios spécifiques puissent être reproduits.
Attention : siegecet outil est stressant. Utilisez-le UNIQUEMENT pour tester votre propre serveur. Ne l'utilisez JAMAIS sur un serveur/site web sans l'autorisation du propriétaire. Vous pourriez alors commettre une attaque DDoS illégale et vous exposer à de graves problèmes.

# anglais
Objectives
You have to create Zappy, which is an entirely automatic game where some AIs play amongst themselves. It is about creating families/teams, surviving by eating food and collecting stones in order to level up. Each level has different requirements for a ritual, which makes the adventure more and more difficult for the AI players, which play on their own, without any help form their creator. The game is over once six members of one family/team reach the highest possible level (8).

Game presentation
The Game Parts
Here are the different parts of the game:

The server contains the field, the resources, and manages the logic and timing of the game.

One or many clients will connect to the server and each will “pilot” one player. The players are spread over teams.

A graphic client that connects to the server and displays the field and what happens there.

Geography
The game consists in managing an entire world and its population. That world, "Minerth" is geographically made of plains, there won't be any obstacles on it.

The world is spherical and the game board is represented as a map. So if a player leaves the board from the right, he will enter again from the left.

Resources
The place where we are contains many resources that can be used for your survival, what you have to do is just look for them and get them before other players do. Here you will find some stones and food that you will need if you want to survive and evolve.

These stones are of 6 different types:

jade
peridot
amber
amethyst
garnet
ammolite
These resources must be randomly generated by the server, despite being random, the generation must have some logical rules, for example:

You can't put all the stones in one square.

You can't put more than one food per square.

Only one stone of each type in a square. You can have up to 3 stones of different types in the same square.

These are just some examples of some rules. It's up to you to decide them, but be prepared to explain them to the auditors.

General Rules
Each player starts with 10 food and 0 stones.
Each player starts on level 1.
As you level up, your player sight improves.
You must eat to survive and not starve and die.
You must collect stones to level up.
To win the game you must have at least 6 players of your family/team at level 8.
Player
The local is happy just looking for stones and feeding on the way, but don't be fooled by him, he can get greedy and kick you out of his way!

He meets, without issues, other people on the same location and sees as far as the eye can see.

It is impossible to guess the Minerthian orientation when crossing him.

The food that the Minerthian picks up is the only resource he needs to live.

One food unit allows him to survive 126 time units, so 126/t seconds. The more he picks up the more he lives.

Evolution ritual
The goal for everyone is to reach the top of the Minerthian hierarchy.

The ritual that allows you to increase the Minerthian physical and mental capacities must be performed as follows:

You need to gather in the same field unit (square):

A specific set of stones.
A specific number of players of the same level.
The player will start the enchantment and the evolution will start.

It is not necessary that all the players are on the same team, but they need to have the same levels.

All players participating in the enchantment will reach a higher level.

Only one player starts the enchantment and the others go to him and join.

Only after two or more players are on the same square, they can start the enchantment.

If one of the members dies, the others will continue the enchantment, unless the player is left alone, if that happens he has to start the process of enchantment again.

Here are the combinations of resources and players you need for the enchantment and evolution:

Level	Number of Players	jade	peridot	amber	amethyst	garnet	ammolite
1-2	1	1	0	0	0	0	0
2-3	2	1	1	1	0	0	0
3-4	2	2	0	1	0	2	0
4-5	4	1	1	2	0	1	0
5-6	4	1	2	1	3	0	0
6-7	6	1	2	3	0	1	0
7-8	6	2	2	2	2	2	1
Vision
The player's view of the field is limited! In order to improve your vision you will have to level up.
With each evolution, your vision goes up one unit of measurement ahead and one on either side of a new line.

Here is the example for the first 3 levels (our player is at 0):


              ---- ---- ----
             | 1  | 2  | 3  |
              ---- ---- ----
                  | 0  |
                   ----
                  Level 1

         ---- ---- ---- ---- ----
        | 4  |  5 |  6 |  7 |  8 |
         ---- ---- ---- ---- ----
             | 1  | 2  | 3  |
              ---- ---- ----
                  | 0  |
                   ----
                  Level 2

 ----- ----- ----- ----- ----- ----- -----
|  9  | 10  | 11  | 12  | 13  | 14  | 15  |
 ----- ----- ----- ----- ----- ----- -----
      |  4  |  5  |  6  |  7  |  8  |
       ----- ----- ----- ----- -----
             | 1  | 2  | 3  |
              ---- ---- ----
                  | 0  |
                   ----
                  Level 3

For the player to know what's around him, the client sends the command SEE and the server responds the following chain of characters (for level 1):

{content-square-0, content-square-1, content-square-2, content-square-3}
Our player cannot see himself and if there is more than 1 object in a square, they are all indicated and separated by a space:

              -------- -------- --------
             | amber  | garnet |        |
             | player | garnet |        |
              -------- -------- --------
                      |        |
                      |  food  |
                       --------
                        Level 1

{food, player amber, garnet garnet, }
The Time and Game Speed
The game speed is defined by a time unit. Each action in the game has a duration proportionate to this time unit.

The time unit is defined by the function 1/t :

t is passed as parameter at the start of the server.
A time unit lasts 1/t seconds.
The Minerthians have second as an absolute time unit.
The formula for the execution of an action is action/t.
t is an integer. If t=1 "advance" takes 7 seconds. We choose by default, t=100 then "advance" will take 7/100 seconds.
Objects Management
It is impossible to distinguish two objects of the same class. Only the class of an object can be identifiable, that is, two 'ambers' will have the same denomination, as they belong to the same class, but 'garnet' will have a different class than 'ambers', that way you are able to identify the resources.

Teams/Families
The goal of the game is to create a team/family of six players and get them to level 8!

At the beginning of the game your family only has one member, so you have to complete the action of calling in order to get more family members.

Each player starts with 10 food and is controlled by a client. The clients cannot communicate or exchange amongst each other data outside of the game, in any way.

Calling
The execution of the fork command results in a ship being called. Your player will call another member of his family.

Once the call has been made, the player can proceed with his life while waiting for the "ship" to arrive. When the ship arrives, a new player will appear and will receive a random direction. This operation allows a new player to join.

The connect_nbr command sends back the number of connections that are underway and authorized for this family. This way you will also know how many spots you have free on you team/family.

Time to call the ship: 48/t

Time for the ship to arrive 600/t

Inventory
The inventory command allows you to see what objects the player has and how much time he has left. The server will send back, for example, the following line:

{food 300, amber 4, garnet 7, ..., peridot 2}
Kick
A player can kick all the players sharing the same square. It pushes them in the direction he is looking at. When a client sends the kick command to the server, all the clients in that square receive the following line:

moving <K>\n
With K indicating the direction the player is looking to, which is where the other players will be kicked. The kick only works for players, you can't kick food or other resources and you can't kick during the evolution ritual.

The commands
Here are the actions that a player will respond to and their syntax. Remember that the syntax must be the same as the following:

Action	Command	Delay/time	Response
advance one square	advance	7/t	ok
turn right 90 degrees	right	7/t	ok
turn left 90 degrees	left	7/t	ok
see	see	7/t	{square1, square2, ...}
inventory	inventory	1/t	{garnet n, amber n, ...}
pick an object	pick <object>	7/t	ok/ko
drop an object	drop <object>	7/t	ok/ko
kick a player from the square	kick	7/t	ok/ko
broadcast	broadcast <text>	7/t	ok
begin the enchantment	enchantment	300/t	evolution in progress
current level : K
fork a player	fork	48/t	ok
know the number of unused connections by the team	connect_nbr	0/t	value
death of a player	-	-	death
All commands are passed as a character string that ends with a newline. In case of any unknown or incorrect command, the server must respond with "ko".

Broadcast
To send a message, the following command must be sent to the server by the client:

broadcast <text>
The server will send this line to all its clients:

message <K>,<text>
With K indicating the direction from where the sound comes.

Sound Transmission
All the players listen to the broadcasts without knowing who broadcasts them, what they understand from it, is only the direction from which the sound comes and the message.

The number of squares traversed by the sound before reaching the player indicates its direction. This numbering is done by assigning '1' to the square in front of the player, then counting down the squares around the player in a trigonometric (counterclockwise) direction. Remember, sound is a wave that moves in a linear manner and the world is round, so we'll choose the shortest path for sound between the transmitter and the player we calculated for.

The following example indicates the sound trajectory that we must choose, as well as the numbers of the squares around the player. The player "A" is the source that sends the broadcast through the square 4 and "B" is the receptor witch receives the broadcast through square 2.

Example

If the broadcast is sent from the same box as the receiving player, he will receive the message from square 0.

The Server
The server is the main engine that will interfere between the AI and the GUI. It will exchange all data with the AI and execute these instructions. At the same time, it send the information to the GUI. It can be written in one of these languages [C, C++, Rust].

For this part, you must create a TCP server to make a connection between clients and manage the entire world. There is no need to host the server as the game will run in one machine only, a localhost will be enough for now.

Server Instructions
Your server must generate all the resources in a random way following the rules mentioned above in the resources section.
Any request to your server must never hang forever. It must never block, and the client can be appropriately bounced if necessary.
The server executes the client requests in the order they are received.
The requests are buffered and the execution time of the command will only block the player concerned.
It's forbidden to use any exec functions to run another server.
It must stay available at all costs.
Use multiplexing connections on your server.

$ ./server
	Usage: ./server -p <port> -x <width> -y <height> n <team> [<team>] [<team>] ... -c <nb> [-t <t>]
    -p  is the port number
    -x  is the width of the world
    -y  is the height of the world
    -n  is the name of the teams
    -c  is the number of authorized clients per team
    -t  is the time unit divider (the greater t is, the faster the game will go)
Tip

You can implement a non-blocking architecture with a circular buffer for every player action, allowing the data to be stored while performing the actions. The approach you take is up to you to decide.
The Client
The Client can be written in a language of your choice.

$./client
Usage: ./client -n <team> -p <port> [-h <hostname>]
  -n is the name of the team
  -p is the port number
  -h is the name of the host, the default is localhost
The client is autonomous, he must send the command order to the server without any intervention from humans.

Client/server communication
The communication between client and server will happen via sockets and TCP. The port used must be indicated in the programs parameters.

The client will send its requests without waiting for their execution, and the server sends back a message confirming the successful execution of the requests.

The client will open a socket on the server's port and the connection client to server will happen as such:

Client's message	Command
WELCOME\n
team-name\n	
nb-client\n
x y\n
The nb-client indicates the number of clients that can still be accepted by the server for the team team-name. If that number is greater than 1 a new client connects. X and Y indicate the world’s dimensions.

If the team name passed by the client doesn't exist the server must print "Error: the team <name of team> doesn't exist"

The client can send up to 10 successful requests without a response from the server. More than 10, the server will no longer take them into account.

There is no chat room or sharing of data between players. Still, the Player can broadcast a message through a command-line sent to the server, which will be broadcasted to all players; All details are in the sound transmission part.

Graphic interface
To have a better vision of the game, which is simple, clear and ergonomic, the project will need to have a graphic visualization client. That client will propose a real-time representation of the world as it is on the server.

Using any game Engine is forbidden!
The interface must be at least in 2D with the use of icons allowing a representation of the world.
You need to make sure you can see the in-game items.
You need to implement the ability to click on a square to see its details, such as how many items of each are inside the square. It should look like a floating window, tooltip or something else.
You need to make sure that the visualization of sounds is included.
The graphic part can be developed in a language of your choice [Javascript, Python, C, C++, PHP, Perl, etc]. This will communicate within the network with the server to retrieve the contents of the map, teams, inventories, etc, everything that is needed to see what is happening in the game.

BONUS
Create a 3D interface or any other type of representation.
Add a flag to for a log mode when running the server.
Add a flag for the number of resources and food density (could be different levels for example).
Implement a seed in the server and client so that specific scenarios could be reproduced.
Attention: siege is a stressing tool, use it ONLY to test your own server. Do NEVER use it on any server/website without the owner's permission. If you do so you would have illegally DDoSed a server and could face serious troubles.



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
