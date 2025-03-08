/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Arguments
*/

#ifndef ARGUMENTS_HPP_
#define ARGUMENTS_HPP_

#include <getopt.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <memory>
#include <cstring>

/**
* @brief Class for the arguments
* @class Arguments
*/
class Arguments {
    public:
        /**
        * @brief Construct a new Arguments object
        */
        Arguments();
        /**
        * @brief Destroy the Arguments object
        */
        ~Arguments() = default;
        /**
        * @brief Construct a new Arguments object by copy deleted
        */
        Arguments(const Arguments &) = delete;
        /**
        * @brief Assign a Arguments object by copy deleted
        * @return Arguments&
        */
        Arguments &operator=(const Arguments &) = delete;
        /**
        * @brief Construct a new Arguments object by move
        */
        Arguments(Arguments &&) = default;
        /**
        * @brief Assign a Arguments object by move
        * @return Arguments&
        */
        Arguments &operator=(Arguments &&) = default;
        /**
        * @brief Display the help
        */
        void displayHelp();
        /**
        * @brief Process the arguments
        * @param argc The number of arguments
        * @param argv The arguments
        */
        void processArguments(const int argc, char *const argv[]);
        /**
        * @brief Check if the resources exist
        */
        void checkRessources();
        /**
        * @brief Check the arguments
        * @param argc The number of arguments
        * @param argv The arguments
        * @return 0 if no error, 84 otherwise
        */
        int checkArgs(const int argc, char *const argv[]);
        /**
        * @brief Get the port
        * @return The port
        */
        unsigned int getPort() const;
        /**
        * @brief Get the hostname
        * @return The hostname
        */
        const char *getHostname() const;

    private:
        /**
        * @private @var unsigned int port
        */
        unsigned int port;
        /**
        * @private @var const char *hostname
        */
        const char *hostname;
        /**
        * @private @var std::vector<std::string> resources
        */
        std::vector<std::string> resources;
};


#endif /* !ARGUMENTS_HPP_ */
