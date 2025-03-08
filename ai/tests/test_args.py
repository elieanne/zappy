import pytest
from unittest.mock import patch

from ai.src.utils.args import parse_args


# Basic args test (that works)
def test_parse_args():
    # Basic args test (port, team)
    with patch("sys.argv", ["./zappy_ai", "-p", "4242", "-n", "team1"]):
        args = parse_args()
        assert args[0] == 4242
        assert args[1] == "team1"
        assert args[2] == "localhost"

    # Basic args test (port, team, ip)
    with patch("sys.argv", ["./zappy_ai", "-p", "4242", "-n", "team1", "-h", "192.168.0.1"]):
        args = parse_args()
        assert args[0] == 4242
        assert args[1] == "team1"
        assert args[2] == "192.168.0.1"


# Basic args test (that fails)
def test_failed_parse_args():
    # Basic wrong port test
    with patch("sys.argv", ["./zappy_ai", "-p", "-12", "-n", "team1"]):
        args = parse_args()
        assert args == None

    # Basic wrong port test 2
    with patch("sys.argv", ["./zappy_ai", "-p", "test", "-n", "team1"]):
        args = parse_args()
        assert args == None

    # Basic no port test
    with patch("sys.argv", ["./zappy_ai", "-n", "team1"]):
        args = parse_args()
        assert args == None

    # Basic no name test
    with patch("sys.argv", ["./zappy_ai", "-p", "-12"]):
        args = parse_args()
        assert args == None
