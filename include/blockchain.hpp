/*
** EPITECH PROJECT, 2022
** cppBlockChain
** File description:
** blockchain.hpp
*/

#pragma once

#include <vector>
#include "block.hpp"
#include "proof_of_work.hpp"

class Blockchain {
public:
    Blockchain();

    void addBlock(std::string data);
    Block getLastBlock() const;
    bool isChainValid() const;

private:
    std::vector<Block> chain;
    int difficulty;

    Block createGenesisBlock() const;
};
