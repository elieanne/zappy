/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>

namespace gui {
    /**
    * @brief Camera class
    * @class Camera
    */
    class Camera {
        public:
            /**
            * @brief Construct a new Camera object
            * @param width
            * @param height
            */
            Camera(unsigned int width, unsigned int height);
            /**
            * @brief Destroy the Camera object
            */
            ~Camera() noexcept = default;
            /**
            * @brief Construct a new Camera object by copy
            * @param cpy
            */
            Camera(const Camera &cpy) = delete;
            /**
            * @brief Assign a Camera object by copy
            * @param src
            * @return Camera&
            */
            Camera &operator=(const Camera &src) = delete;
            /**
            * @brief Construct a new Camera object by move
            * @param cpy
            */
            Camera(Camera &&cpy) = default;
            /**
            * @brief Assign a Camera object by move
            * @param src
            * @return Camera&
            */
            Camera &operator=(Camera &&src) = default;
            /**
            * @brief Set the Center of the camera Object
            * @param pos
            */
            void setCenter(sf::Vector2f pos);
            /**
            * @brief Get the Center of the camera Object
            * @return sf::Vector2f
            */
            sf::Vector2f getCenter();
            /**
            * @brief Set the Zoom of the camera Object
            * @param zoom
            */
            void setZoom(float zoom);
            /**
             * @brief Set the View of the camera Object
             * @param window
             */
            void setView(sf::RenderWindow &window);
            /**
             * @brief Get the View of the camera Object
             * @return sf::View&
             */
            [[nodiscard]] sf::View &getView();
        private:
            /**
            * @private @var sf::View view
            */
            sf::View view;
            /**
             * @private @var The zoom factor of the camera
             */
            float zoomFactor;
    };
}

#endif /* !CAMERA_HPP_ */
