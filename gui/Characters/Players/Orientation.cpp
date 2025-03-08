/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Orientation
*/

#include "Players.hpp"
#include <functional>

int redRectFunc(Orientation orientation)
{
    std::vector<int> redRect = { 20, 287, 555, 828};
    return redRect[static_cast<int>(orientation)];
}

int yellowRectFunc(Orientation orientation)
{
    std::vector<int> yellowRect = { 1102, 1368, 1634, 1908 };
    return yellowRect[static_cast<int>(orientation)];
}

int greenRectFunc(Orientation orientation)
{
    std::vector<int> greenRect = { 2180, 2447, 2715, 2981 };
    return greenRect[static_cast<int>(orientation)];
}

int blueRectFunc(Orientation orientation)
{
    std::vector<int> blueRect = { 3260, 3526, 3794, 4060 };
    return blueRect[static_cast<int>(orientation)];
}

int darkBlueRectFunc(Orientation orientation)
{
    std::vector<int> darkBlueRect = { 4341, 4607, 4874, 5141};
    return darkBlueRect[static_cast<int>(orientation)];
}

int purpleRectFunc(Orientation orientation)
{
    std::vector<int> purpleRect = { 5421, 5688, 5960, 6220 };
    return purpleRect[static_cast<int>(orientation)];
}

int getRightRect(const std::string &colorParams, Orientation orientation)
{
    struct RectData {
        std::string color;
        std::function<int(Orientation)> rectFunc;
    };

    std::vector<RectData> rectData = {
        { "red", redRectFunc },
        { "blue", blueRectFunc },
        { "yellow", yellowRectFunc },
        { "green", greenRectFunc },
        { "darkBlue", darkBlueRectFunc },
        { "purple", purpleRectFunc },
    };
    for (const auto& data : rectData) {
        if (data.color == colorParams) {
            return data.rectFunc(orientation);
        }
    }
    return 0;
}

int getFacingRectByColor(const std::string &colorParams)
{
    struct RectData {
        std::string color;
        int rect;
    };

    std::vector<RectData> rectData = {
        { "red", 555 },
        { "yellow", 1634 },
        { "green", 2715 },
        { "blue", 3794 },
        { "darkBlue", 4874 },
        { "purple", 5960 }
    };
    for (const auto& data : rectData) {
        if (data.color == colorParams) {
            return data.rect;
        }
    }
    return 0;
}
