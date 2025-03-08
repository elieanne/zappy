/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** TextBox
*/

#ifndef TEXTBOX_HPP_
#define TEXTBOX_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>

/**
* @brief TextBox class
* @class TextBox
*/
class TextBox {
    public:
        /**
        * @brief Construct a new Text Box object
        */
        TextBox() = default;
        /**
        * @brief Destroy the Text Box object
        */
        ~TextBox() noexcept = default;
        /**
        * @brief Construct a new Text Box object by copy
        * @param other
        */
        TextBox(const TextBox& other) = delete;
        /**
        * @brief Assign a Text Box object by copy
        * @param other
        * @return TextBox&
        */
        TextBox& operator=(const TextBox& other) = delete;
        /**
        * @brief Construct a new Text Box object by move
        * @param other
        */
        TextBox(TextBox&& other) = default;
        /**
        * @brief Assign a Text Box object by move
        * @param other
        * @return TextBox&
        */
        TextBox& operator=(TextBox&& other) = default;
        /**
        * @brief Handle the text event
        * @param event
        * @return int
        */
        int textEvent(sf::Event event);
        /**
        * @brief Check if the mouse is pressed
        * @param mousePos
        * @return true
        * @return false
        */
        bool isPressed(sf::Vector2f mousePos);
        /**
        * @brief Draw the text box
        * @param window
        * @param sprite
        */
        void draw(sf::RenderWindow &window, sf::Sprite &sprite);
        /**
        * @brief Get the String
        * @return const sf::String&
        */
        const sf::String& getString();
        /**
        * @brief Set the String
        * @param str
        */
        void setString(const sf::String &str);
        /**
        * @brief Init the text box
        * @param font
        * @param characterSize
        * @param size
        * @param position
        */
        void initTextBox(const sf::Font& font, unsigned int characterSize, sf::Vector2f size, sf::Vector2f position);
        /**
        * @brief Activate the text box
        * @param mode
        */
        void activate(bool mode);
        /**
        * @brief Clear the text box
        */
        void clear();
        /**
        * @brief Get the Position
        * @return sf::Vector2f
        */
        sf::Vector2f getPosition();
        /**
        * @brief Check if the text box is finished
        * @return true
        * @return false
        */
        const bool &isFinished();
        /**
        * @brief Check if the text box is in input mode
        * @return true
        * @return false
        */
        const bool &isInputMode();
    private:
        /**
        * @private @var sf::Text descriptionText
        */
        sf::Text descriptionText;
        /**
        * @private @var sf::Text text
        */
        sf::Text text;
        /**
        * @private @var sf::String inputText
        */
        sf::String inputText;
        /**
        * @private @var sf::RectangleShape box
        */
        sf::RectangleShape box;
        /**
        * @private @var bool inputMode
        */
        bool inputMode;
        /**
        * @private @var bool finished
        */
        bool finished;
        /**
        * @private @var sf::IntRect rect
        */
        sf::IntRect rect;
};

#endif /* !TEXTBOX_HPP_ */
