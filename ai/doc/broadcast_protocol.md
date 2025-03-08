# Broadcast protocol
## Synopsys
`message K, [TEXT]...`

## Description
The broadcast protocol is used to send messages to all players in the game.

<br />

`K` is the tile where the message is sent. It is a number between 1 and 8.
### Text
`TEXT` is the text of the message.<br />
It can be composed with multiple parameters:
- `Identifier of the broadcast`: Number of the broadcast
- `Identifier of his team`: Name of the team
- `Level`: Current level
- `What for?`: { Connection | Elevation | Response (to a previous broadcast) | Confirmation (OK or KO) | Update | Join | End }
### Connection
The connection will send to inform that a player has just connected to the game.<br /><br />
### Response
The response is sent to reply to a previous broadcast.<br /><br />
For `Elevation`:<br />
A player will not send a response if he is not able to elevate.
- `0 name1 Response` + `OK`<br /><br />

### Update
The update will send to reset the position of the player on the map.<br />
It permits to other player(s) to know where he is on the map.<br /><br />
### Join
The join will send to inform another player that he cans join his broadcast<br /><br />
### End
The end will send to inform that the broadcast is finished.<br /><br />
### Examples
For an identifier of the broadcast equal to `5`, a team name equal to `Team1` and a level equal to `2`:<br />
```
<<< 5 Team1 2 Elevation
>>> 5 Team1 2 Response OK
<<< 5 Team1 2 Confirmation OK
<<< 5 Team1 2 Update
<<< 5 Team1 2 Update
```
A complete example of a broadcast protocol to elevate two players to level 3:
```
<<< 5 Team1 3 Incantation
>>> 5 Team1 3 Response OK
<<< 5 Team1 3 Confirmation OK
<<< 5 Team1 3 Update
<<< 5 Team1 3 Update
<<< 5 Team1 3 End
```
An example to join a broadcast:
```
<<< 5 Team1 2 Elevation
>>> 10 Team1 2 Elevation
<<< 5 Team1 2 Join 10
>>> 5 Team1 2 Response OK
>>> 10 Team1 2 End
<<< 5 Team1 2 Confirmation OK
<<< 5 Team1 2 Update
<<< 5 Team1 2 Update
<<< 5 Team1 2 End
```
