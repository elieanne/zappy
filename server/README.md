# Zappy server

## Description
This part is the server. It allows to manage the game and the communication between the clients.
There is two type of client, the AI and the graphic client.
For each type of client there is a specific protocol with his set of command to implement.

## Goal of the game
The first team with 6 players to reach the maximum level wins the game.

## The rules

---

- **Resources**
    - First spawn of resources in the start of the game and then every 20 time units
    - On the planet there is at least 1 occurrence of each resource
    - To calculate the quantity of each resource use the **map_width * map_height * density** formula

  | Resources | Density |
  |-----------|---------|
  | food      | 0.5     |
  | linemate  | 0.3     |
  | deraumere | 0.15    |
  | sibur     | 0.1     |
  | mendiane  | 0.1     |
  | phiras    | 0.08    |
  | thystame  | 0.05    |


---

- **Elevation ritual**
    - The verification for the prerequisites is done at the start and at the end of the ritual
    - All the players participating in the ritual must be on the same tile and can be from different teams
    - To count required resources for the ritual use the following table

  | Elevation | Number of players | Linemate | Deraumere | Sibur | Mendiane | Phiras | Thystame |
  |-----------|-------------------|----------|-----------|-------|----------|--------|----------|
  | 1 ⇒ 2     | 1                 | 1        | 0         | 0     | 0        | 0      | 0        |
  | 2 ⇒ 3     | 2                 | 1        | 1         | 1     | 0        | 0      | 0        |
  | 3 ⇒ 4     | 2                 | 2        | 0         | 1     | 0        | 2      | 0        |
  | 4 ⇒ 5     | 4                 | 1        | 1         | 2     | 0        | 1      | 0        |
  | 5 ⇒ 6     | 4                 | 1        | 2         | 1     | 3        | 0      | 0        |
  | 6 ⇒ 7     | 6                 | 1        | 2         | 3     | 0        | 1      | 0        |
  | 7 ⇒ 8     | 6                 | 2        | 2         | 2     | 2        | 2      | 1        |

---

- **Vision**

  - The “*look”* command response is formatted as follow:
  *[ player, object-on-tile1, ... , object-on-tileP, ...]*
  - For each new level the player can see further


---

- **Sound Transmission**
    - The sound is propagated in a straight line
    - All the player can hear the sound, but they can’t know the origin
    - The sound direction is materialized by numbers from 1 to 8. 1 is in front of the player view and the numbers are incremented in reverse clockwise all around the player
    - The shortest path is used to transmit the sound and calculate the direction


---

- **Teams**
    - At the start of the game each team as **n** slots available waiting for a player to connect
    - At the start of the game each player have **10** food units that correspond to **1260** time units of life expectancy

---

- **Commands**
    - L’ensemble des commandes sont transmises par une string avec un “*\n”* à la fin
    - Si one commande n’est pas reconnue le server doit répondre par un “****ko”****
    - The execution time block the player during the action

  | Action                      | Command        | Time limit | Response                               |
  |-----------------------------|----------------|------------|----------------------------------------|
  | Move up one tile            | Forward        | 7/f        | ok                                     |
  | Turn 90° right              | Right          | 7/f        | ok                                     |
  | Turn 90° left               | Left           | 7/f        | ok                                     |
  | Look around                 | Look           | 7/f        | [tile1, tile2,.. .]                    |
  | Inventory                   | Inventory      | 1/f        | [linemate n, sibur n,. .. ]            |
  | Broadcast text              | Broadcast text | 7/f        | ok                                     |
  | Number of team unused slots | Connect_nbr    | -          | value                                  |
  | Fork a player               | Fork           | 42/f       | ok                                     |
  | Eject player from his tile  | Eject          | 7/f        | ok/ko                                  |
  | Death of a player           | -              | -          | dead                                   |
  | Take object                 | Take object    | 7/f        | ok/ko                                  |
  | Set object down             | Set object     | 7/f        | ok/ko                                  |
  | Start incantation           | Incantation    | 300/f      | Elevation underway Current level: k/ko |

---

- **Client/Server communication**
    - The request treatment is done in the order of arrival
      - Connection protocol <br>
        → Server: WELCOME\n <br>
        ← Client : TEAM-NAME\n <br>
        → Server: CLIENT-NUM\n <br>
        →Server: X Y\n <br><br>
**X** and **Y** are the map dimensions
  **CLIENT-NUM** is the number of slot available for the team
    - The server can send an event to the client at any time
---

- **Player reproduction**
    - The *Fork* command allow to create a new connection slot for the team materialized by an egg
    - This egg is dropped on the tile of the player and will constitute a new spawn point for the next player to join the team

---

- **Binary**
```bash
USAGE: ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
    port        is the port number
    width       is the width of the world
    height      is the height of the world
    nameX       is the name of the team X
    clientsNb   is the number of authorized clients per team
    freq        is the reciprocal of time unit for execution of actions
```
