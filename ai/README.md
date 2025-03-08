# Zappy AI

## Description

This is the AI for the Zappy project. It is written in Python 3.10.
The AI is a client that connects to the server and controls a player.

## Usage

```bash
make zappy_ai
```

```
./zappy_ai -help
usage: zappy_ai -p port -n name [-h machine] [-c file]

options:
  -p port     is the port number
  -n name     is the name of the team
  -h machine  is the name of the machine; localhost by default
  -c file     is the configuration file
```
```bash
./zappy_ai -p 4242 -n Team1
```

## Documentation

All the code is documented using the [Google Python Style Guide](https://google.github.io/styleguide/pyguide.html#38-comments-and-docstrings).

Documentation for all [strategies](doc/strategies.md).

Documentation for the [broadcast protocol](doc/broadcast_protocol.md) used.
