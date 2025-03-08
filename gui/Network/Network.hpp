/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Network
*/

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <cstring>
#include <variant>
#include "Data.hpp"
#include <array>
#include "myStruct.h"
#include "Handler.hpp"

/**
* @brief max buffer size
* @const std::size_t maxBufferSize
*/
constexpr std::size_t maxBufferSize = 4092;

namespace gui {
    class Data;
    class Handler;
}

namespace gui {
    /**
    * @brief Network class
    * @class Network
    */
    class Network {
        public:
            /**
            * @brief Construct a new Network object
            * @param port
            * @param path
            */
            Network(unsigned int port, const char *path);
            /**
            * @brief Destroy the Network object
            */
            ~Network();
            /**
            * @brief Construct a new Network object by move
            */
            Network(Network &&) = default;
            /**
            * @brief Assign a Network object by move
            * @return Network&
            */
            Network &operator=(Network &&) = default;
            /**
            * @brief Construct a new Network object
            */
            Network(const Network &) = delete;
            /**
            * @brief Assign a Network object by copy
            * @return Network&
            */
            Network &operator=(const Network &) = delete;
            /**
            * @brief run the network
            * @param game
            */
            void run(gui::Data &game);
            /**
            * @brief send a command to the server
            * @param command
            * @return int
            */
            int sendCommand(const std::string &command);
            /**
            * @brief parse the command
            * @param command
            * @param game
            */
            void parseCommand(const std::string &command, gui::Data &game);
            /**
            * @brief connect to the server
            * @throw Errors::ErrorNetwork
            */
            void connectToServer();
            /**
            * @brief Check if socket is disconnect
            */
            bool isConnected();
        private:
            /**
            * @private @var sf::TcpSocket socket
            */
            sf::TcpSocket socket;
            /**
            * @private @var sf::IpAddress serverIP
            */
            sf::IpAddress serverIP;
            /**
            * @private @var unsigned int serverPort
            */
            unsigned int serverPort;
            /**
            * @private @var bool connected
            */
            bool connected = false;
            /**
             * @private @var char buffer
             */
            char buffer[maxBufferSize]{0};
            /**
            * @private @var std::size_t receivedSize
            */
            std::size_t receivedSize{0};
            /**
            * @private @var gui::Handler handler
            */
            gui::Handler handler;
    };
}

#endif /* !NETWORK_HPP_ */
