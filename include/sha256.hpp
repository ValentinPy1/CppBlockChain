/*
** EPITECH PROJECT, 2022
** cppBlockChain
** File description:
** sha256.hpp
*/

#pragma once

#include <openssl/sha.h>
#include <string>

std::string sha256(const std::string str);
