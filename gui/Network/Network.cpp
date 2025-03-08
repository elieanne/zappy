/*
** EPITECH PROJECT, 2023
** network
** File description:
** main
*/

#include "Network.hpp"
#include <iostream>
#include <sstream>
#include "Players.hpp"
#include "Errors.hpp"

void gui::Network::parseCommand(const std::string& command, gui::Data &game)
{
    std::istringstream iss(command);
    std::string keyword;
    iss >> keyword;

    handler.handle(keyword, game, iss);
}

void gui::Network::run(gui::Data &game)
{
    char buf[4096] = {0};
    std::string tmp;
    std::size_t size = 0;
    std::string cmd;
    memset(buf, 0, 4096);
    while (this->socket.receive(buf, 4095, size) == sf::Socket::Done) {
        cmd += std::string(buf);
        memset(buf, 0, 4096);
    }
    if (this->socket.getRemoteAddress() == sf::IpAddress::None || this->socket.getRemotePort() == 0) {
        this->connected = false;
        return;
    }
    if (cmd.empty())
        return;
    std::istringstream iss(cmd);
    while (std::getline(iss, tmp)) {
        parseCommand(tmp, game);
    }
}

int gui::Network::sendCommand(const std::string &command)
{
    if (connected == false)
        return 1;
    const char* dataPtr = command.c_str();
    std::size_t dataSize = command.size();
    std::size_t totalSent = 0;
    sf::Socket::Status sendStatus;
    while (totalSent < dataSize) {
        std::size_t sent = 0;
        sendStatus = socket.send(dataPtr + totalSent, dataSize - totalSent, sent);
        if (sendStatus == sf::Socket::Error) {
            std::cerr << "Failed to send data to the server" << std::endl;
            return 1;
        }
        totalSent += sent;
    }
    if (command != "mct\n")
        std::cout << command;
    return 0;
}

void gui::Network::connectToServer()
{
    char buf[4096] = {0};

    if ((socket.connect(serverIP, serverPort)) != sf::Socket::Done)
        throw Errors::ErrorSocket("Cannot connect to server");
    this->socket.setBlocking(true);
    this->connected = true;
    this->socket.receive(buf, maxBufferSize, this->receivedSize);
    std::string tmp(buf, this->receivedSize);
    if (tmp == "WELCOME\n") {
        std::cout << tmp;
    }
    this->socket.setBlocking(false);
    sendCommand("GRAPHIC\n");
}

gui::Network::Network(unsigned int port, const char *path)
{
    this->serverIP = path;
    this->serverPort = port;
    this->receivedSize = 0;
    this->connectToServer();
}

bool gui::Network::isConnected()
{
    return this->connected;
}

gui::Network::~Network()
{
    socket.disconnect();
}
