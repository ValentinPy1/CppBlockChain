/*
** EPITECH PROJECT, 2022
** cppBlockChain
** File description:
** proof_of_work.hpp
*/

#pragma once

#include <string>
#include "block.hpp"

class ProofOfWork {
public:
    ProofOfWork(Block block, int difficulty);
    std::string run();
    bool checkNonce();

private:
    Block block;
    int difficulty;
    std::string target;
    int nonce;
};
