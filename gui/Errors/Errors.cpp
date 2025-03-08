/*
** EPITECH PROJECT, 2023
** zappy
** File description:
** Error
*/

#include "Errors.hpp"

Errors::ErrorOpen::ErrorOpen(std::string m_what)
{
    name = m_what;
}

const char *Errors::ErrorOpen::what() const noexcept
{
    return name.c_str();
}

Errors::ErrorFile::ErrorFile(std::string m_what)
{
    name = m_what;
}

const char *Errors::ErrorFile::what() const noexcept
{
    return name.c_str();
}

Errors::ErrorUsage::ErrorUsage(std::string m_what)
{
    name = m_what;
}

const char *Errors::ErrorUsage::what() const noexcept
{
    return name.c_str();
}

Errors::ErrorEnv::ErrorEnv(std::string m_what)
{
    name = m_what;
}

const char *Errors::ErrorEnv::what() const noexcept
{
    return name.c_str();
}

Errors::ErrorFont::ErrorFont(std::string m_what)
{
    name = m_what;
}

const char *Errors::ErrorFont::what() const noexcept
{
    return name.c_str();
}

Errors::ErrorTexture::ErrorTexture(std::string m_what)
{
    name = m_what;
}

const char *Errors::ErrorTexture::what() const noexcept
{
    return name.c_str();
}

Errors::ErrorTeam::ErrorTeam(std::string m_what)
{
    name = m_what;
}

const char *Errors::ErrorTeam::what() const noexcept
{
    return name.c_str();
}

Errors::ErrorCharacter::ErrorCharacter(std::string m_what)
{
    name = m_what;
}

const char *Errors::ErrorCharacter::what() const noexcept
{
    return name.c_str();
}

Errors::ErrorSocket::ErrorSocket(std::string m_what)
{
    name = m_what;
}

const char *Errors::ErrorSocket::what() const noexcept
{
    return name.c_str();
}

const char *Errors::ErrorBroadcast::what() const noexcept
{
    return name.c_str();
}

Errors::ErrorElevate::ErrorElevate(std::string m_what)
{
    name = m_what;
}

const char *Errors::ErrorElevate::what() const noexcept
{
    return name.c_str();
}

Errors::ErrorInventory::ErrorInventory(std::string m_what)
{
    name = m_what;
}

const char *Errors::ErrorInventory::what() const noexcept
{
    return name.c_str();
}

Errors::ErrorColor::ErrorColor(std::string m_what)
{
    name = m_what;
}

const char *Errors::ErrorColor::what() const noexcept
{
    return name.c_str();
}

Errors::ErrorButton::ErrorButton(std::string m_what)
{
    name = m_what;
}

const char *Errors::ErrorButton::what() const noexcept
{
    return name.c_str();
}
