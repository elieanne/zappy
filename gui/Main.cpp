/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** main
*/

#include "Map.hpp"
#include "SceneManager.hpp"
#include "Arguments.hpp"
#include "Network.hpp"
#include <memory>
#include "Errors.hpp"

int launch(gui::Network &client, Arguments &args)
{
    gui::Data data;
    gui::SceneManager sceneManager;
    gui::Window window;

    sf::Font font;
    sf::Clock timer;
    timer.restart();
    font.loadFromFile("gui/Resources/RationalInteger.ttf");
    srand(time(nullptr));
    window.createWindow("Zappy", 1920, 1080, args.getPort(), args.getHostname());
    sceneManager.setState(std::make_unique<SceneMenu>());
    sceneManager.loadScene(sceneManager, window, data);
    data.getTextBox().initTextBox(font, 20, sf::Vector2f(140, 42), sf::Vector2f(400, 750));
    while (window.isOpenWindow()) {
        client.run(data);
        if (!client.isConnected())
            return 0;
        sceneManager.update(window, data);
        sceneManager.display(window, data);
        if (data.getTextBox().isFinished()) {
            client.sendCommand("sst " + data.getTextBox().getString() + "\n");
            data.getTextBox().clear();
        }
        if (timer.getElapsedTime().asSeconds() > 2 * (static_cast<float>(1) / static_cast<float>(data.getFrequency()))) {
            client.sendCommand("mct\n");
            timer.restart();
        }
    }
    return 0;
}

int main(const int argc, char *const argv[])
{
    Arguments args;
    gui::Window window;

    try {
        args.checkArgs(argc, argv);
        gui::Network client(args.getPort(), args.getHostname());
        return launch(client, args);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
