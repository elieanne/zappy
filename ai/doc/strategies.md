# Strategies

## Introduction
The strategies are an important part of the projet. They are the way to win the game.

## How to use them?
To use strategies, you have to add the flag `-c` to the command line of the AI:
```bash
./zappy_ai -n TEAM_NAME -p PORT [-c FILE_NAME]
```
FILE_NAME is the name of the file which contains the strategies.
By default, a file is provided. It is called `ai/ai.conf`.

## How to set them?
Strategies can be set in the file `ai/ai.conf` (by default).
It must be set like this:
```
[STRATEGY_NAME] [STRATEGY_VALUE]
```

`STRATEGY_NAME` is the name of the strategy you want to set.
`STRATEGY_VALUE` is the value of the strategy you want to set.<br />
True: the strategy is set.<br />
False: the strategy is not set.

## Strategies
All strategies available are listed below:

- `Default`: The default strategy. It is the strategy used if no strategy is set.
- `Eject`: The player will try to eject the other players when a broadcast is sent.
- `Materialist`: By default, the player will stop at the number of stones needed to finish the game. The materialist, on the other hand, will constantly collect these stones. Beware: his love for his stones means that he will never initiate an elevation to the next level (except to level 2). This one will never fork either.
- `Thrifty`: The player will save his stones and use them only to reach levels 2, 7 and 8. Attention: This one will never fork.
- `Oppotunist`: The player will collect stones only to rise to level 2. He will take advantage of the others to level up afterward. Attention: This one will never fork.
- `Fool`: Sometimes, the player will spin on himself...
- `Greedy`: The player will focus the food. The stones are not really important for him.

## Questions
`What happens if there is no strategy to set?`

- The default strategy is used.

`What happens if several strategies are set?`

- Probabilities are assigned to each strategy. Randomization is then performed on the parameterized strategies.
