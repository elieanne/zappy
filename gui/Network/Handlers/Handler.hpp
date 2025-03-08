/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Handler
*/

#ifndef HANDLER_HPP_
#define HANDLER_HPP_
    #include <vector>
    #include <functional>
    #include <sstream>
    #include <iostream>
    #include "Data.hpp"

namespace gui {
    class Data;
}

/**
* @brief Command struct
* @struct Command
*/
struct Command {
    std::string keyword;
    std::function<void(std::istringstream&, gui::Data &)> handler;
};

namespace gui {
    /**
    * @brief Handler class
    * @class Handler
    */
    class Handler {
        public:
            /**
            * @brief Construct a new Handler object
            */
            Handler() = default;
            /**
            * @brief Destroy the Handler object
            */
            ~Handler() = default;
            /**
            * @brief Construct a new Handler object by copy
            */
            Handler(const Handler &) = delete;
            /**
            * @brief Construct a new Handler object by move
            */
            Handler(Handler &&) = default;
            /**
            * @brief Assign a Handler object by copy
            * @return Handler&
            */
            Handler &operator=(const Handler &) = delete;
            /**
            * @brief Assign a Handler object by move
            * @return Handler&
            */
            Handler &operator=(Handler &&) = default;
            /**
            * @brief handle the command
            * @param keyword
            * @param game
            * @param iss
            */
            void handle(const std::string &keyword, gui::Data &game, std::istringstream &iss);
        private:
            /**
            * @brief msz command
            * @param iss
            * @param game
            */
            static void mszCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief bct command
            * @param iss
            * @param game
            */
            static void bctCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief tna command
            * @param iss
            * @param game
            */
            static void tnaCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief pnw command
            * @param iss
            * @param game
            */
            static void pnwCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief ppo command
            * @param iss
            * @param game
            */
            static void ppoCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief plv command
            * @param iss
            * @param game
            */
            static void plvCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief pin command
            * @param iss
            * @param game
            */
            static void pinCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief pex command
            * @param iss
            * @param game
            */
            static void pexCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief pbc command
            * @param iss
            * @param game
            */
            static void pbcCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief pic command
            * @param iss
            * @param game
            */
            static void picCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief pie command
            * @param iss
            * @param game
            */
            static void pieCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief pfk command
            * @param iss
            * @param game
            */
            static void pfkCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief pdr command
            * @param iss
            * @param game
            */
            static void pdrCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief pgt command
            * @param iss
            * @param game
            */
            static void pgtCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief pdi command
            * @param iss
            * @param game
            */
            static void pdiCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief enw command
            * @param iss
            * @param game
            */
            static void enwCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief ebo command
            * @param iss
            * @param game
            */
            static void eboCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief edi command
            * @param iss
            * @param game
            */
            static void ediCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief sgt command
            * @param iss
            * @param game
            */
            static void sgtCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief sst command
            * @param iss
            * @param game
            */
            static void sstCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief seg command
            * @param iss
            * @param game
            */
            static void segCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief smg command
            * @param iss
            * @param game
            */
            static void smgCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief suc command
            * @param iss
            * @param game
            */
            static void sucCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @brief sbp command
            * @param iss
            * @param game
            */
            static void sbpCommand(std::istringstream& iss, gui::Data& game);
            /**
            * @private @var std::vector<Command> commands
            */
            std::vector<Command> commands = {
                    {"msz", mszCommand},
                    {"bct", bctCommand},
                    {"tna", tnaCommand},
                    {"pnw", pnwCommand},
                    {"ppo", ppoCommand},
                    {"plv", plvCommand},
                    {"pin", pinCommand},
                    {"pex", pexCommand},
                    {"pbc", pbcCommand},
                    {"pic", picCommand},
                    {"pie", pieCommand},
                    {"pfk", pfkCommand},
                    {"pdr", pdrCommand},
                    {"pgt", pgtCommand},
                    {"pdi", pdiCommand},
                    {"enw", enwCommand},
                    {"ebo", eboCommand},
                    {"edi", ediCommand},
                    {"sgt", sgtCommand},
                    {"sst", sstCommand},
                    {"seg", segCommand},
                    {"smg", smgCommand},
                    {"suc", sucCommand},
                    {"sbp", sbpCommand},
            };
    };
}

/**
* @brief operator<< overload for Orientation
* @param is
* @param orientation
* @return std::istream&
*/
std::istream &operator>>(std::istream &is, Orientation &orientation);


#endif /* !HANDLER_HPP_ */
