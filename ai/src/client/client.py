from typing import TypeVar, List, Dict
from socket import socket, AF_INET, SOCK_STREAM
from ai.src.command.command import Command, TCommand

TClient = TypeVar("TClient", bound="Client")


class Client:
    """Client class.

    Contains methods to:
        - connect to a server.
        - send a message to the server.
        - receive a message from the server.
        - disconnect from the server.

    Similar to an encapsulation of the Socket class.

    Attributes:
        command (TCommand): Class Command (handle the commands to send to the server).
        port (int): the port to connect to the server.
        name (str): the name of the team.
        host (str): the host to connect to the server.
        connected (Dict[str, bool]): the status of the connection with the server.
        socket: the Socket class to connect to the server.
        x (int) : map size x
        y (int) : map size y
        line (int) : define a "fake" y position for the player
        connect_nbr (int) : number to allow connection

    """

    def __init__(self: TClient, port: int, name: str, host: str) -> None:
        """Init Client Class.

        :param int port: the port to connect to the server.
        :param str name: the name of the team.
        :param str host: the host to connect to the server.
        """
        self.command: TCommand = Command()
        self.port: int = port
        self.name: str = name
        self.host: str = host
        self.connected: Dict[str, bool] = {
            "Welcome": False,
            "Connected": False,
            "Food": True,
        }
        self.socket = socket(AF_INET, SOCK_STREAM)
        self.x: int = 0
        self.y: int = 0
        self.line: int = self.y
        self.connect_nbr: int = -1
        self.connect_to_server()

    def send_message(self: TClient, message: str, command: str, to_add: bool) -> None:
        """Connect to a server.

        :param str message: the message to send to the server.
        :param str command: the command to add in player's commands list.
        :param bool to_add: if the command must be added in player's commands list.
        """
        print(f"<--{message}")
        message += "\n"
        self.socket.sendall(message.encode())
        if to_add:
            self.command.commands.append(command)

    def verify_connection(self: TClient, message: str) -> None:
        """Handle first connection to the server.

        When a player first connect to the server, the discussion is:

        <--WELCOME\n
        -->TEAM-NAME\n
        <--CLIENT-NUM\n
        <--X Y\n

        This function allow to handle this discussion.

        :param str message: the message received from the server.

        :raises Exception: if the connection is refused.
        """
        if "ko" == message:
            raise Exception("Error: connection with server refused")
        if "WELCOME" == message and not self.connected["Welcome"]:
            print("-->WELCOME")
            self.send_message(self.name, "Welcome", True)
            self.connected["Welcome"] = True
        elif self.connected["Welcome"] and not self.connected["Connected"]:
            self.connect_nbr = int(message.split("\n")[0])
            self.x = int(message.split("\n")[1].split(" ")[0])
            self.y = int(message.split("\n")[1].split(" ")[0])
            self.line = self.y
            print(f"-->{self.connect_nbr}")
            print(f"-->{self.x} {self.y}")
            self.command.pop_command(0)
            self.connected["Connected"] = True
            print(message)

    def receive_message(self: TClient) -> List[str]:
        """Connect to a server.

        :return: Message(s) received from the server.
        """
        message_received: str = self.socket.recv(4096).decode().rstrip()
        if not self.connected["Welcome"] or not self.connected["Connected"]:
            self.verify_connection(message_received)
            return []
        parsed_message: List[str] = message_received.split("\n")
        return parsed_message

    def connect_to_server(self: TClient) -> None:
        """Connect to a server.

        :raises Exception: if the connection is refused.
        """
        print("Connect to server...")
        try:
            self.socket.connect((self.host, self.port))
        except ConnectionRefusedError:
            raise Exception("Error: connection refused")

    def __del__(self: TClient) -> None:
        """Close the socket."""
        self.socket.close()
