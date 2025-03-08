/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SceneGame
*/

#ifndef SCENEGAME_HPP_
#define SCENEGAME_HPP_
#include "IScene.hpp"
#include "PanelBar.hpp"
#include "Data.hpp"
#include "ItemDrawer.hpp"

/**
* @brief Game scene class
* @class SceneGame
*/
class SceneGame : public IScene {
    public:
        /**
        * @brief Construct a new Scene Game object
        */
        SceneGame() = default;
        /**
        * @brief Destroy the Scene Game object
        */
        ~SceneGame() noexcept override = default;
        /**
        * @brief Construct a new Scene Game object by copy
        * @param other
        */
        SceneGame(const SceneGame &other) = delete;
        /**
        * @brief Assign a Scene Game object by copy
        * @param other
        * @return SceneGame&
        */
        SceneGame &operator=(const SceneGame &other) = delete;
        /**
        * @brief Construct a new Scene Game object by move
        * @param other
        */
        SceneGame(SceneGame &&other) = default;
        /**
        * @brief Assign a Scene Game object by move
        * @param other
        * @return SceneGame&
        */
        SceneGame &operator=(SceneGame &&other) = default;
        /**
        * @brief Load the scene
        * @param window The window where the scene will be loaded
        * @param data The data of the game
        * @param manager The scene manager
        */
        void loadScene(gui::SceneManager &manager, gui::Window &window, gui::Data &data) override;
        /**
        * @brief Display the scene
        * @param window The window where the scene will be displayed
        * @param data The data of the game
        * @param manager The scene manager
        */
        void display(gui::SceneManager &manager, gui::Window &window, gui::Data &data) override;
        /**
        * @brief Check the events of the scene
        * @param window The window where the events will be checked
        * @param data The data of the game
        * @param manager The scene manager
        */
        void checkEvents(gui::SceneManager &manager, gui::Window &window, gui::Data &data) override;
        /**
        * @brief Create the objects of the scene
        * @param data The data of the game
        * @throw Errors::ErrorTexture
        */
        void createObject(gui::Data &data) override;
        /**
         * @brief Set the outline of the selected tile
         * @param tiles The tiles of the map
         * @param pos The position of the mouse
         */
        void selected(std::vector<std::vector<gui::Tile>> &tiles, sf::Vector2f pos);
        /**
        * @brief Move the map
        * @param window The window where the map will be moved
        * @param data The data of the game
        */
        void mapMove(gui::Window &window, gui::Data &data);
        /**
        * @brief Display tile of the Map
        * @param map
        * @param window
        * @param itemDrawer
        * @param data
        */
        void displayTileContent(std::vector<std::vector<gui::Tile>> &map, gui::Window &window,
                                gui::ItemDrawer &itemDrawer, gui::Data &data);
        /**
        * @brief Display the panel bar
        * @param manager
        * @param window
        * @param data
        */
        void displayPanel(gui::SceneManager &manager, gui::Window &window, gui::Data &data);
        /**
        * @brief Display the Character
        * @param window
        * @param data
        * @param manager
        */
        void displayCharacter(gui::Window &window, gui::Data &data, gui::SceneManager &manager);
        /**
        * @brief Display the selected tile
        * @param window
        * @param data
        * @param itemDrawer
        * @param tile
        */
        void displaySelected(gui::Window &window, gui::Data &data, gui::ItemDrawer &itemDrawer, gui::Tile &tile);
        /**
        * @brief Display the inventory
        * @param data
        * @param tile
        */
        void displayInventory(gui::Data &data, gui::Tile &tile);
        /**
        * @brief Remove the character
        * @param manager
        * @param data
        */
        void removeCharacter(gui::SceneManager &manager, gui::Data &data);
        /**
        * @brief Hover state and the buttons
        * @param manager
        * @param window
        */
        void buttonsHover(gui::SceneManager &manager, gui::Window &window);
        /**
        * @brief Handle close event
        * @param window
        * @param data
        */
        void closeEvent(gui::Window &window, gui::Data &data);
        /**
        * @brief Handle buttons pressed
        * @param manager
        * @param window
        * @param data
        */
        void buttonsPressed(gui::SceneManager &manager, gui::Window &window, gui::Data &data);
        /**
        * @brief Handle buttons released
        * @param map
        */
        void previousSelected(std::vector<std::vector<gui::Tile>> &map);
        /**
        * @brief Check if the name is valid
        * @param button
        * @param data
        */
        void checkName(const std::unique_ptr<gui::Button> &button, gui::Data &data);

    private:
        /**
        * @private @var gui::Camera camera
        */
        gui::Camera camera{0, 0};
        /**
        * @private @var gui::Camera mapFrame
        */
        gui::Camera mapFrame{0, 0};
        /**
        * @private @var std:vector<gui::PanelBar> panelBars
        */
        std::vector<gui::PanelBar> panelBars;
        /**
        * @private @var bool panelBarVisible
        */
        bool panelBarVisible{false};
        /**
        * @private @var bool showInventory
        */
        bool showInventory{false};
        /**
        * @private @var sf::Texture texture
        */
        sf::Texture texture;
        /**
        * @private @var sf::Sprite sprite
        */
        sf::Sprite sprite;
        /**
        * @private @var sf::Texture textureMap
        */
        sf::Texture texturePanel;
        /**
        * @private @var sf::Sprite spriteMap
        */
        sf::Sprite spritePanel;
        /**
        * @private @var sf::Texture textureCharacters
        */
        sf::Texture textureCharacters;
        /**
        * @private @var sf::Sprite spriteCharacters
        */
        sf::Sprite spriteCharacters;
        /**
        * @private @var gui::ItemDrawer itemDrawer
        */
        gui::ItemDrawer itemDrawer;
        /**
        * @private @var int currentSelectedX
        */
        int currentPlayerIndex;
};

#endif /* !SCENEGAME_HPP_ */
