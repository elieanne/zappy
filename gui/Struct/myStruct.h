/*
** EPITECH PROJECT, 2023
** gui
** File description:
** myStruct
*/

#ifndef MYSTRUCT_H_
#define MYSTRUCT_H_

#include <array>
#include <string>
#include <vector>

/**
* @brief Orientation enum
* @enum class Orientation
*/
enum class Orientation {
    West,
    East,
    South,
    North
};

/**
* @brief Msz Command
* @struct MszCommand
*/
struct MszCommand {
    int x, y;
};

/**
* @brief Bct Command
* @struct BctCommand
*/
struct BctCommand {
    int x, y;
    std::array<int, 7> resources{};
};

/**
* @brief Tna Command
* @struct TnaCommand
*/
struct TnaCommand {
    std::string teamName;
};

/**
* @brief Pnw Command
* @struct PnwCommand
*/
struct PnwCommand {
    int number, x, y, level;
    std::string teamName;
    Orientation orientation;
};

/**
* @brief Ppo Command
* @struct PpoCommand
*/
struct PpoCommand {
    int number, x, y;
    Orientation orientation;
};

/**
* @brief Plv Command
* @struct PlvCommand
*/
struct PlvCommand {
    int number, level;
};

/**
* @brief Pin Command
* @struct PinCommand
*/
struct PinCommand {
    int number, x, y;
    std::array<int, 7> resources{};
};

/**
* @brief Pex Command
* @struct PexCommand
*/
struct PexCommand {
    int number;
};

/**
* @brief Pbc Command
* @struct PbcCommand
*/
struct PbcCommand {
    int number;
    std::string message;
};

/**
* @brief Pic Command
* @struct PicCommand
*/
struct PicCommand {
    int x, y, level;
    std::vector<int> numbers;
};

/**
* @brief Pie Command
* @struct PieCommand
*/
struct PieCommand {
    int x, y, result;
};

/**
* @brief Pfk Command
* @struct PfkCommand
*/
struct PfkCommand {
    int number;
};

/**
* @brief Pdr Command
* @struct PdrCommand
*/
struct PdrCommand {
    int number, resource;
};

/**
* @brief Pgt Command
* @struct PgtCommand
*/
struct PgtCommand {
    int number, resource;
};

/**
* @brief Pdi Command
* @struct PdiCommand
*/
struct PdiCommand {
    int number;
};

/**
* @brief Enw Command
* @struct EnwCommand
*/
struct EnwCommand {
    int eggId, number, x, y;
};

/**
* @brief Ebob Command
* @struct EboCommand
*/
struct EboCommand {
    int eggId;
};

/**
* @brief Edi Command
* @struct EdiCommand
*/
struct EdiCommand {
    int eggId;
};

/**
* @brief Sgt Command
* @struct SgtCommand
*/
struct SgtCommand {
    int freq;
};

/**
* @brief Sst Command
* @struct SstCommand
*/
struct SstCommand {
    int freq;
};

/**
* @brief Seg Command
* @struct SegCommand
*/
struct SegCommand {
    std::string teamName;
};

/**
* @brief Smg Command
* @struct SmgCommand
*/
struct SmgCommand {
    std::string message;
};

#endif /* !MYSTRUCT_H_ */
