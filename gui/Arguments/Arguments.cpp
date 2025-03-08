/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Arguments
*/

#include "Arguments.hpp"
#include "Errors.hpp"

Arguments::Arguments()
{
    resources.push_back("./gui/Resources/parallax/background.png");
    resources.push_back("./gui/Resources/parallax/foreground.png");
    resources.push_back("./gui/Resources/parallax/middle.png");
    resources.push_back("./gui/Resources/parallax/ground.png");
    resources.push_back("./gui/Resources/parallax/sky.png");
    resources.push_back("./gui/Resources/parallax/planet.png");
    resources.push_back("./gui/Resources/settingsBackground.png");
    resources.push_back("./gui/Resources/loseBackground.png");
    resources.push_back("./gui/Resources/winBackground.png");
    resources.push_back("./gui/Resources/spritesheet.png");
    resources.push_back("./gui/Resources/golem_spritesheet.png");
    resources.push_back("./gui/Resources/inventory.png");
    resources.push_back("./gui/Resources/mainMenuLogo.png");
    resources.push_back("./gui/Resources/tiles.png");
    resources.push_back("./gui/Resources/mapFrame.png");
    resources.push_back("./gui/Resources/help.txt");
    resources.push_back("./gui/Resources/Musics/journey.ogg");
    resources.push_back("./gui/Resources/Musics/skyStation.ogg");
    resources.push_back("./gui/Resources/Musics/bowserGenerator.ogg");
    resources.push_back("./gui/Resources/Musics/rosalinaLullaby.ogg");
    resources.push_back("./gui/Resources/Sounds/button.wav");
    resources.push_back("./gui/Resources/Sounds/elevate.ogg");
    resources.push_back("./gui/Resources/Sounds/death.wav");
    resources.push_back("./gui/Resources/Sounds/tile.ogg");
    resources.push_back("./gui/Resources/Sounds/broadcast.wav");
    resources.push_back("./gui/Resources/Sounds/spawn.wav");
    resources.push_back("./gui/Resources/Sounds/bowling.wav");
    resources.push_back("./gui/Resources/Sounds/strike.wav");
    resources.push_back("./gui/Resources/Sounds/happybowler.wav");
    resources.push_back("./gui/Resources/Sounds/hihihou.wav");
    resources.push_back("./gui/Resources/RationalInteger.ttf");
}

void Arguments::checkRessources()
{
    for (auto &ressource : resources) {
        if (!std::filesystem::exists(ressource))
            throw Errors::ErrorFile("zappy: " + ressource + " not found");
    }
}

void Arguments::displayHelp()
{
    std::fstream helpFile("./gui/Resources/help.txt");
    std::string line;

    if (!helpFile.is_open())
        throw Errors::ErrorOpen("zappy: Failed to open help file");
    while (std::getline(helpFile, line))
        std::cout << line << std::endl;
    std::cout << std::endl;
    helpFile.close();
    exit(EXIT_SUCCESS);
}

void Arguments::processArguments(const int argc, char *const argv[])
{
    int option;

    this->hostname = "127.0.0.1";
    while ((option = getopt(argc, argv, "p:h:")) != -1) {
        switch (option) {
        case 'p':
            this->port = atoi(optarg);
            break;
        case 'h':
            this->hostname = optarg;
            break;
        default:
            throw Errors::ErrorUsage("Usage: ./zappy -p port -h hostname (localhost by default))");
        }
    }
    if (this->port == 0)
        throw Errors::ErrorUsage("Option -p is required");
}

int Arguments::checkArgs(const int argc, char *const argv[])
{
    if (!argv || !argv[1])
        throw Errors::ErrorUsage("Usage: ./zappy -p port -h hostname");
    if (strcmp(argv[1], "--help") == 0)
        displayHelp();
    if (!getenv("DISPLAY"))
        throw Errors::ErrorEnv("zappy: DISPLAY environment variable not set");
    checkRessources();
    processArguments(argc, argv);
    return 0;
}

unsigned int Arguments::getPort() const
{
    return this->port;
}

const char *Arguments::getHostname() const
{
    return this->hostname;
}
