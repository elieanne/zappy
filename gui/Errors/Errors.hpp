/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Error
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <exception>
#include <string>
#include <iostream>

/**
 * @class ErrorT
 * @brief A class to handle errors.
 ** This class provides a way to throw errors.
*/
class Errors : public std::exception {
    public:
        /**
         * @brief Default Constructor a new Error T object
         */
        Errors() = default;
        /**
         * @brief Default Destructor a new Error T object
         */
        ~Errors() = default;
        /**
        * @brief Construct a new Errors object by copy
        * @param other
        */
        Errors(const Errors& other) = delete;
        /**
        * @brief Assign a Errors object by copy
        */
        Errors& operator=(const Errors& other) = delete;
        /**
        * @brief Construct a new Errors object by move
        * @param other
        */
        Errors(Errors&& other) = default;
        /**
        * @brief Assign a Errors object by move
        * @param other
        * @return Errors&
        */
        Errors& operator=(Errors&& other) = default;
        /**
         * @class ErrorTeam
         * @brief A class for Team Error
         */
        class ErrorTeam : public std::exception {
            public:
                /**
                 * @brief Constructor a new Error Team object
                 * @param m_what The error message
                 */
                explicit ErrorTeam(std::string m_what);
                /**
                 * @brief Destructor a new Error Team object
                 */
                ~ErrorTeam() noexcept override = default;
                /**
                * @brief Construct a new Error Team object by copy
                * @param other
                */
                ErrorTeam(const ErrorTeam& other) = delete;
                /**
                 * @brief Assign a ErrorTeam object by copy
                 * @param other
                 * @return ErrorTeam&
                 */
                ErrorTeam& operator=(const ErrorTeam& other) = delete;
                /**
                 * @brief Construct a new ErrorTeam object by move
                 * @param other
                 */
                ErrorTeam(ErrorTeam&& other) = default;
                /**
                 * @brief Assign a ErrorTeam object by move
                 * @param other
                 * @return ErrorTeam&
                 */
                ErrorTeam& operator=(ErrorTeam&& other) = default;
                /**
                 * @brief Get the What object
                 * @return const char* The error message
                 */
                [[nodiscard]] const char *what() const noexcept override;
            private:
                /**
                 * @private @var name The error message
                 */
                std::string name;
        };
        /**
         * @class ErrorTexture
         * @brief A class for Texture Error
         */
        class ErrorTexture : public std::exception {
            public:
                /**
                 * @brief Constructor a new Error Texture object
                 * @param m_what The error message
                 */
                explicit ErrorTexture(std::string m_what);
                /**
                 * @brief Destructor a new Error Texture object
                 */
                ~ErrorTexture() noexcept override = default;
                /**
                * @brief Construct a new Error Texture object by copy
                * @param other
                */
                ErrorTexture(const ErrorTexture& other) = delete;
                /**
                 * @brief Assign a ErrorTexture object by copy
                 * @param other
                 * @return ErrorTexture&
                 */
                ErrorTexture& operator=(const ErrorTexture& other) = delete;
                /**
                 * @brief Construct a new ErrorTexture object by move
                 * @param other
                 */
                ErrorTexture(ErrorTexture&& other) = default;
                /**
                 * @brief Assign a ErrorTexture object by move
                 * @param other
                 * @return ErrorTexture&
                 */
                ErrorTexture& operator=(ErrorTexture&& other) = default;
                /**
                 * @brief Get the What object
                 * @return const char* The error message
                 */
                [[nodiscard]] const char *what() const noexcept override;
            private:
                /**
                 * @private @var name The error message
                 */
                std::string name;
        };
        /**
         * @class ErrorUsage
         * @brief A class for Usage Error
         */
        class ErrorUsage : public std::exception {
            public:
                /**
                 * @brief Constructor a new Error Usage object
                 * @param m_what The error message
                 */
                explicit ErrorUsage(std::string m_what);
                /**
                 * @brief Destructor a new Error Usage object
                 */
                ~ErrorUsage() noexcept override = default;
                /**
                * @brief Construct a new Error Usage object by copy
                * @param other
                */
                ErrorUsage(const ErrorUsage& other) = delete;
                /**
                 * @brief Assign a ErrorUsage object by copy
                 * @param other
                 * @return ErrorUsage&
                 */
                ErrorUsage& operator=(const ErrorUsage& other) = delete;
                /**
                 * @brief Construct a new ErrorUsage object by move
                 * @param other
                 */
                ErrorUsage(ErrorUsage&& other) = default;
                /**
                 * @brief Assign a ErrorUsage object by move
                 * @param other
                 * @return ErrorUsage&
                 */
                ErrorUsage& operator=(ErrorUsage&& other) = default;
                /**
                 * @brief Get the What object
                 * @return const char* The error message
                 */
                [[nodiscard]] const char *what() const noexcept override;
            private:
                /**
                 * @private @var name The error message
                 */
                std::string name;
        };
        /**
         * @class ErrorFile
         * @brief A class for file Error
         */
        class ErrorFile : public std::exception {
            public:
                /**
                 * @brief Constructor a new Error File object
                 * @param m_what The error message
                 */
                explicit ErrorFile(std::string m_what);
                /**
                 * @brief Destructor a new Error File object
                 */
                ~ErrorFile() noexcept override = default;
                /**
                * @brief Construct a new Error File object by copy
                * @param other
                */
                ErrorFile(const ErrorFile& other) = delete;
                /**
                 * @brief Assign a ErrorFile object by copy
                 * @param other
                 * @return ErrorFile&
                 */
                ErrorFile& operator=(const ErrorFile& other) = delete;
                /**
                 * @brief Construct a new ErrorFile object by move
                 * @param other
                 */
                ErrorFile(ErrorFile&& other) = default;
                /**
                 * @brief Assign a ErrorFile object by move
                 * @param other
                 * @return ErrorFile&
                 */
                ErrorFile& operator=(ErrorFile&& other) = default;
                /**
                 * @brief Get the What object
                 * @return const char* The error message
                 */
                [[nodiscard]] const char *what() const noexcept override;
            private:
                /**
                 * @private @var name The error message
                 */
                std::string name;
        };
        /**
         * @class ErrorOpen
         * @brief A class for open Error
         */
        class ErrorOpen : public std::exception {
            public:
                /**
                 * @brief Constructor a new Error Open object
                 * @param m_what The error message
                 */
                explicit ErrorOpen(std::string m_what);
                /**
                 * @brief Destructor a new Error Open object
                 */
                ~ErrorOpen() noexcept override = default;
                /**
                * @brief Construct a new Error Open object by copy
                * @param other
                */
                ErrorOpen(const ErrorOpen& other) = delete;
                /**
                 * @brief Assign a ErrorOpen object by copy
                 * @param other
                 * @return ErrorOpen&
                 */
                ErrorOpen& operator=(const ErrorOpen& other) = delete;
                /**
                 * @brief Construct a new ErrorOpen object by move
                 * @param other
                 */
                ErrorOpen(ErrorOpen&& other) = default;
                /**
                 * @brief Assign a ErrorOpen object by move
                 * @param other
                 * @return ErrorOpen&
                 */
                ErrorOpen& operator=(ErrorOpen&& other) = default;
                /**
                 * @brief Get the What object
                 * @return const char* The error message
                 */
                [[nodiscard]] const char *what() const noexcept override;
            private:
                /**
                 * @private @var name The error message
                 */
                std::string name;
        };
        /**
         * @class ErrorCharacter
         * @brief A class for Character Error
         */
        class ErrorCharacter : public std::exception {
            public:
                /**
                 * @brief Constructor a new Error Character object
                 * @param m_what The error message
                 */
                explicit ErrorCharacter(std::string m_what);
                /**
                 * @brief Destructor a new Error Character object
                 */
                ~ErrorCharacter() noexcept override = default;
                /**
                * @brief Construct a new Error Character object by copy
                * @param other
                */
                ErrorCharacter(const ErrorCharacter& other) = delete;
                /**
                 * @brief Assign a ErrorCharacter object by copy
                 * @param other
                 * @return ErrorCharacter&
                 */
                ErrorCharacter& operator=(const ErrorCharacter& other) = delete;
                /**
                 * @brief Construct a new ErrorCharacter object by move
                 * @param other
                 */
                ErrorCharacter(ErrorCharacter&& other) = default;
                /**
                 * @brief Assign a ErrorCharacter object by move
                 * @param other
                 * @return ErrorCharacter&
                 */
                ErrorCharacter& operator=(ErrorCharacter&& other) = default;
                /**
                 * @brief Get the What object
                 * @return const char* The error message
                 */
                [[nodiscard]] const char *what() const noexcept override;
            private:
                /**
                 * @private @var name The error message
                 */
                std::string name;
        };
        /**
        * @brief A class for env Error
        * @class ErrorEnv
        */
        class ErrorEnv : public std::exception {
            public:
                /**
                 * @brief Constructor a new Error Env object
                 * @param m_what The error message
                 */
                explicit ErrorEnv(std::string m_what);
                /**
                 * @brief Destructor a new Error Env object
                 */
                ~ErrorEnv() noexcept override = default;
                /**
                * @brief Construct a new Error Env object by copy
                * @param other
                */
                ErrorEnv(const ErrorEnv& other) = delete;
                /**
                 * @brief Assign a ErrorEnv object by copy
                 * @param other
                 * @return ErrorEnv&
                 */
                ErrorEnv& operator=(const ErrorEnv& other) = delete;
                /**
                 * @brief Construct a new ErrorEnv object by move
                 * @param other
                 */
                ErrorEnv(ErrorEnv&& other) = default;
                /**
                 * @brief Assign a ErrorEnv object by move
                 * @param other
                 * @return ErrorEnv&
                 */
                ErrorEnv& operator=(ErrorEnv&& other) = default;
                /**
                 * @brief Get the What object
                 * @return const char* The error message
                 */
                [[nodiscard]] const char *what() const noexcept override;
            private:
                /**
                 * @private @var name The error message
                 */
                std::string name;
        };
        /**
        * @brief A class for font Error
        * @class ErrorFont
        */
        class ErrorFont : public std::exception {
            public:
                /**
                 * @brief Constructor a new Error Font object
                 * @param m_what The error message
                 */
                explicit ErrorFont(std::string m_what);
                /**
                 * @brief Destructor a new Error Font object
                 */
                ~ErrorFont() noexcept override = default;
                /**
                * @brief Construct a new Error Font object by copy
                * @param other
                */
                ErrorFont(const ErrorFont& other) = delete;
                /**
                 * @brief Assign a ErrorFont object by copy
                 * @param other
                 * @return ErrorFont&
                 */
                ErrorFont& operator=(const ErrorFont& other) = delete;
                /**
                 * @brief Construct a new ErrorFont object by move
                 * @param other
                 */
                ErrorFont(ErrorFont&& other) = default;
                /**
                 * @brief Assign a ErrorFont object by move
                 * @param other
                 * @return ErrorFont&
                 */
                ErrorFont& operator=(ErrorFont&& other) = default;
                /**
                 * @brief Get the What object
                 * @return const char* The error message
                 */
                [[nodiscard]] const char *what() const noexcept override;
            private:
                /**
                 * @private @var name The error message
                 */
                std::string name;
        };
        /**
        * @brief A class for socket Error
        * @class ErrorSocket
        */
        class ErrorSocket : public std::exception {
            public:
                /**
                 * @brief Constructor a new Error Socket object
                 * @param m_what The error message
                 */
                explicit ErrorSocket(std::string m_what);
                /**
                 * @brief Destructor a new Error Socket object
                 */
                ~ErrorSocket() noexcept override = default;
                /**
                * @brief Construct a new Error Socket object by copy
                * @param other
                */
                ErrorSocket(const ErrorSocket& other) = delete;
                /**
                 * @brief Assign a ErrorSocket object by copy
                 * @param other
                 * @return ErrorSocket&
                 */
                ErrorSocket& operator=(const ErrorSocket& other) = delete;
                /**
                 * @brief Construct a new ErrorSocket object by move
                 * @param other
                 */
                ErrorSocket(ErrorSocket&& other) = default;
                /**
                 * @brief Assign a ErrorSocket object by move
                 * @param other
                 * @return ErrorSocket&
                 */
                ErrorSocket& operator=(ErrorSocket&& other) = default;
                /**
                 * @brief Get the What object
                 * @return const char* The error message
                 */
                [[nodiscard]] const char *what() const noexcept override;
            private:
                /**
                 * @private @var name The error message
                 */
                std::string name;
        };
        /**
        * @brief A class for broadcast Error
        * @class ErrorBroadcast
        */
        class ErrorBroadcast : public std::exception {
            public:
                /**
                 * @brief Destructor a new Error Broadcast object
                 */
                ~ErrorBroadcast() noexcept override = default;
                /**
                * @brief Construct a new Error Broadcast object by copy
                * @param other
                */
                ErrorBroadcast(const ErrorBroadcast& other) = delete;
                /**
                 * @brief Assign a ErrorBroadcast object by copy
                 * @param other
                 * @return ErrorBroadcast&
                 */
                ErrorBroadcast& operator=(const ErrorBroadcast& other) = delete;
                /**
                 * @brief Construct a new ErrorBroadcast object by move
                 * @param other
                 */
                ErrorBroadcast(ErrorBroadcast&& other) = default;
                /**
                 * @brief Assign a ErrorBroadcast object by move
                 * @param other
                 * @return ErrorBroadcast&
                 */
                ErrorBroadcast& operator=(ErrorBroadcast&& other) = default;
                /**
                 * @brief Get the What object
                 * @return const char* The error message
                 */
                [[nodiscard]] const char *what() const noexcept override;
            private:
                /**
                 * @private @var name The error message
                 */
                std::string name;
        };
       /**
        * @brief A class for Elevate Error
        * @class ErrorElevate
        */
        class ErrorElevate : public std::exception {
            public:
                /**
                 * @brief Constructor a new Error Elevate object
                 * @param m_what The error message
                 */
                explicit ErrorElevate(std::string m_what);
                /**
                 * @brief Destructor a new Error Elevate object
                 */
                ~ErrorElevate() noexcept override = default;
                /**
                * @brief Construct a new Error Elevate object by copy
                * @param other
                */
                ErrorElevate(const ErrorElevate& other) = delete;
                /**
                 * @brief Assign a ErrorElevate object by copy
                 * @param other
                 * @return ErrorElevate&
                 */
                ErrorElevate& operator=(const ErrorElevate& other) = delete;
                /**
                 * @brief Construct a new ErrorElevate object by move
                 * @param other
                 */
                ErrorElevate(ErrorElevate&& other) = default;
                /**
                 * @brief Assign a ErrorElevate object by move
                 * @param other
                 * @return ErrorElevate&
                 */
                ErrorElevate& operator=(ErrorElevate&& other) = default;
                /**
                 * @brief Get the What object
                 * @return const char* The error message
                 */
                [[nodiscard]] const char *what() const noexcept override;
            private:
                /**
                 * @private @var name The error message
                 */
                std::string name;
        };
       class ErrorColor : public std::exception {
            public:
                /**
                 * @brief Constructor a new Error Color object
                 * @param m_what The error message
                 */
                explicit ErrorColor(std::string m_what);
                /**
                 * @brief Destructor a new Error Color object
                 */
                ~ErrorColor() noexcept override = default;
                /**
                * @brief Construct a new Error Color object by copy
                * @param other
                */
                ErrorColor(const ErrorColor& other) = delete;
                /**
                 * @brief Assign a ErrorColor object by copy
                 * @param other
                 * @return ErrorColor&
                 */
                ErrorColor& operator=(const ErrorColor& other) = delete;
                /**
                 * @brief Construct a new ErrorColor object by move
                 * @param other
                 */
                ErrorColor(ErrorColor&& other) = default;
                /**
                 * @brief Assign a ErrorColor object by move
                 * @param other
                 * @return ErrorColor&
                 */
                ErrorColor& operator=(ErrorColor&& other) = default;
                /**
                 * @brief Get the What object
                 * @return const char* The error message
                 */
                [[nodiscard]] const char *what() const noexcept override;
            private:
                /**
                 * @private @var name The error message
                 */
                std::string name;
        };
        /**
        * @brief A class for Inventory Error
        * @class ErrorInventory
        */
        class ErrorInventory : public std::exception {
            public:
                /**
                 * @brief Constructor a new Error Inventory object
                 * @param m_what The error message
                 */
                explicit ErrorInventory(std::string m_what);
                /**
                 * @brief Destructor a new Error Inventory object
                 */
                ~ErrorInventory() noexcept override = default;
                /**
                * @brief Construct a new Error Inventory object by copy
                * @param other
                */
                ErrorInventory(const ErrorInventory& other) = delete;
                /**
                 * @brief Assign a ErrorInventory object by copy
                 * @param other
                 * @return ErrorInventory&
                 */
                ErrorInventory& operator=(const ErrorInventory& other) = delete;
                /**
                 * @brief Construct a new ErrorInventory object by move
                 * @param other
                 */
                ErrorInventory(ErrorInventory&& other) = default;
                /**
                 * @brief Assign a ErrorInventory object by move
                 * @param other
                 * @return ErrorInventory&
                 */
                ErrorInventory& operator=(ErrorInventory&& other) = default;
                /**
                 * @brief Get the What object
                 * @return const char* The error message
                 */
                [[nodiscard]] const char *what() const noexcept override;
            private:
                /**
                 * @private @var name The error message
                 */
                std::string name;
        };
        /**
        * @brief A class for Button Error
        * @class ErrorButton
        */
        class ErrorButton : public std::exception {
            public:
                /**
                 * @brief Constructor a new Error Button object
                 * @param m_what The error message
                 */
                explicit ErrorButton(std::string m_what);
                /**
                 * @brief Destructor a new Error Button object
                 */
                ~ErrorButton() noexcept override = default;
                /**
                * @brief Construct a new Error Button object by copy
                * @param other
                */
                ErrorButton(const ErrorButton& other) = delete;
                /**
                 * @brief Assign a ErrorButton object by copy
                 * @param other
                 * @return ErrorButton&
                 */
                ErrorButton& operator=(const ErrorButton& other) = delete;
                /**
                 * @brief Construct a new ErrorButton object by move
                 * @param other
                 */
                ErrorButton(ErrorButton&& other) = default;
                /**
                 * @brief Assign a ErrorButton object by move
                 * @param other
                 * @return ErrorButton&
                 */
                ErrorButton& operator=(ErrorButton&& other) = default;
                /**
                 * @brief Get the What object
                 * @return const char* The error message
                 */
                [[nodiscard]] const char *what() const noexcept override;
            private:
                /**
                 * @private @var name The error message
                 */
                std::string name;
        };
};

#endif /* !ERRORS_HPP_ */
