/*
** EPITECH PROJECT, 2022
** cppBlockChain
** File description:
** block.hpp
*/

#pragma once

#include <string>
#include <ctime>
#include "sha256.hpp"

class Block {
public:
    Block(std::string data, std::string prevHash);
    Block() = default;

    std::string getHash() const;
    std::string getPrevHash() const;
    std::string getData() const;
    void setNonce(std::string nonce);
    time_t getTime() const;

private:
    std::string data;
    std::string prevHash;
    std::string hash;
    std::string nonce;
    time_t time;

    void calculateHash();
};
