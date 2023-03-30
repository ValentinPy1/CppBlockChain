/*
** EPITECH PROJECT, 2022
** cppBlockChain
** File description:
** blockchain.cpp
*/

#include "blockchain.hpp"

Blockchain::Blockchain() {
    this->difficulty = 4;
    this->chain.push_back(createGenesisBlock());
}

void Blockchain::addBlock(std::string data) {
    Block lastBlock = getLastBlock();
    Block newBlock(data, lastBlock.getHash());

    ProofOfWork pow(newBlock, this->difficulty);
    std::string nonce = pow.run();
    newBlock.setNonce(nonce);

    this->chain.push_back(newBlock);
}

Block Blockchain::getLastBlock() const {
    return this->chain.back();
}

bool Blockchain::isChainValid() const {
    for (int i = 1; i < this->chain.size(); i++) {
        Block currentBlock = this->chain[i];
        Block previousBlock = this->chain[i - 1];

        if (currentBlock.getPrevHash() != previousBlock.getHash()) {
            return false;
        }

        ProofOfWork pow(currentBlock, this->difficulty);
        if (!pow.checkNonce()) {
            return false;
        }
    }

    return true;
}

Block Blockchain::createGenesisBlock() const {
    return Block("Genesis Block", "0");
}
