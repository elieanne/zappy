from argparse import ArgumentParser, ArgumentError, SUPPRESS


def port_verification(port: str) -> int:
    """Verify if the port is valid.

    :param str port: port number.

    :return int: the port number.

    :raises ArgumentError: if port is not between 0 and 65535 or if port is not a number.
    """
    try:
        port = int(port)
        if port < 0 or port > 65535:
            raise ArgumentError(None, "port: invalid port number")
        return port
    except ValueError:
        raise ArgumentError(None, "port: invalid port argument")


def parse_args() -> tuple[None, None, None, None] | None:
    """Parse arguments.

    :return Parsed arguments (port, name, host, [config_file]) | None: if an error occurred.
    """
    parser = ArgumentParser(exit_on_error=False, add_help=False)
    parser.add_argument("-help", action="help", help=SUPPRESS)
    parser.add_argument(
        "-p",
        metavar="port",
        type=port_verification,
        help="is the port number",
        required=True,
    )
    parser.add_argument("-n", metavar="name", type=str, help="is the name of the team", required=True)
    parser.add_argument(
        "-h",
        metavar="machine",
        default="localhost",
        type=str,
        help="is the name of the machine; localhost by default",
    )
    parser.add_argument(
        "-c",
        metavar="file",
        default="",
        type=str,
        help="is the configuration file",
    )
    try:
        args = parser.parse_args()
    except ArgumentError as error:
        print(error)
        return None
    except SystemExit as error:
        print(error)
        return None
    return args.p, args.n, args.h, args.c
