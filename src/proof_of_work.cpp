/*
** EPITECH PROJECT, 2022
** cppBlockChain
** File description:
** proof_of_work.cpp
*/

#include "proof_of_work.hpp"
#include "sha256.hpp"

ProofOfWork::ProofOfWork(Block block, int difficulty) {
    this->block = block;
    this->difficulty = difficulty;

    this->target = "";
    for (int i = 0; i < difficulty; i++) {
        this->target += "0";
    }

    this->nonce = 0;
}

std::string ProofOfWork::run() {
    while (!checkNonce()) {
        this->nonce++;
    }

    return std::to_string(this->nonce);
}

bool ProofOfWork::checkNonce() {
    std::string header = this->block.getData() + this->block.getPrevHash() + std::to_string(this->block.getTime()) + std::to_string(this->nonce);
    std::string hash = sha256(header);
    return hash.substr(0, this->difficulty) == this->target;
}
