/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_
#include "SceneMenu.hpp"
#include "SceneSettings.hpp"
#include "SceneGame.hpp"
#include "SceneSkins.hpp"
#include "SceneWin.hpp"
#include <unordered_map>
#include "SoundBox.hpp"

namespace gui {
    /**
    * @brief SceneManager class
    * @class SceneManager
    */
    class SceneManager {
    public:
        /**
        * @brief Construct a new Scene Manager object
        * @throw Errors::ErrorTexture
        */
        SceneManager();
        /**
        * @brief Destroy the Scene Manager object
        */
        ~SceneManager() noexcept = default;
        /**
        * @brief Construct a new Scene Manager object by copy
        * @param other
        */
        SceneManager(const SceneManager &other) = delete;
        /**
        * @brief Assign a Scene Manager object by copy
        * @param other
        * @return SceneManager&
        */
        SceneManager &operator=(const SceneManager &other) = delete;
        /**
        * @brief Construct a new Scene Manager object by move
        * @param other
        */
        SceneManager(SceneManager &&other) = default;
        /**
        * @brief Assign a Scene Manager object by move
        * @param other
        * @return SceneManager&
        */
        SceneManager &operator=(SceneManager &&other) = default;
        /**
        * @brief Set the state of the scene
        * @param state The state of the scene
        */
        void setState(std::unique_ptr<IScene> state);
        /*
         * @brief Load the scene
         */
        void loadScene(gui::SceneManager &manager, gui::Window &window, gui::Data &data);
        /*
         * @brief Display the scene
         * @param window The window where the scene will be displayed
         */
        void display(gui::Window &window, gui::Data &data);
        /**
        * @brief Check the events of the scene
        * @param window The window where the events will be checked
        * @param data The data of the game
        */
        void update(gui::Window &window, gui::Data &data);
        /**
        * @brief Create a Buttons object
        */
        void createButtons();
        /**
        * @brief Create a Sounds object
        */
        void createSounds();
        /**
        * @brief Get the Buttons object
        * @return std::vector<std::unique_ptr<gui::Button>>&
        */
        std::vector<std::unique_ptr<gui::Button>> &getButtons();
        /**
        * @brief Get the Button
        * @param name
        * @return gui::Button&
        */
        gui::Button &getButton(std::string name);
        /**
        * @brief Get the Sprite
        * @return sf::Sprite&
        */
        sf::Sprite &getSprite();
        /**
        * @brief Get the Vol Sprite
        * @return sf::Sprite&
        */
        sf::Sprite &getVolSprite();
        /**
        * @brief Set the Map Frame Sprite
        * @param rect
        */
        void setMapFrameSprite(int rect);
        /**
        * @brief Get the Map Frame Sprite
        * @return sf::Sprite&
        */
        sf::Sprite &getMapFrameSprite();
        /**
        * @brief Set the Tile Sprite
        * @param rect
        */
        void setTileSprite(int rect);
        /**
        * @brief Get the Tile Sprite
        * @return sf::Sprite&
        */
        [[nodiscard]] const sf::Sprite &getTileSprite();
        /**
        * @brief Set the Volume
        * @param volume
        */
        void setVolume(float volume);
        /**
        * @brief Get the Volume
        * @return const int&
        */
        [[nodiscard]] int getVolume();
        /**
        * @brief Get the Sound Box
        * @return SoundBox&
        */
        [[nodiscard]] SoundBox &getSoundBox();

    private:
        /**
        * @private @var std::unique_ptr<IScene> currentState
        */
        std::unique_ptr<IScene> currentState;
        /**
        * @private @var std::vector<std::unique_ptr<gui::Button>> buttons
        */
        std::vector<std::unique_ptr<gui::Button>> buttons;
        /**
        * @private @var sf::Sprite sprite
        */
        sf::Sprite sprite;
        /**
        * @private @var sf::Sprite volSprite
        */
        sf::Sprite volSprite;
        /**
        * @private @var sf::Texture texture
        */
        sf::Texture texture;
        /**
        * @private @var sf::Texture mapFrameTexture
        */
        sf::Texture mapFrameTexture;
        /**
        * @private @var sf::Sprite mapFrameSprite
        */
        sf::Sprite mapFrameSprite;
        /**
        * @private @var sf::Texture tileTexture
        */
        sf::Texture tileTexture;
        /**
        * @private @var sf::Sprite tilesprite
        */
        sf::Sprite tileSprite;
        /**
        * @private @var SoundBox soundbox
        */
        SoundBox soundbox;
    };
}

#endif /* !SCENEMANAGER_HPP_ */
