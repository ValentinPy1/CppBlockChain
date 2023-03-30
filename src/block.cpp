/*
** EPITECH PROJECT, 2022
** cppBlockChain
** File description:
** block.cpp
*/

#include "block.hpp"

Block::Block(std::string data, std::string prevHash) {
    this->data = data;
    this->prevHash = prevHash;
    calculateHash();
}

std::string Block::getHash() const {
    return this->hash;
}

std::string Block::getPrevHash() const {
    return this->prevHash;
}

std::string Block::getData() const {
    return this->data;
}

void Block::setNonce(std::string nonce) {
    this->nonce = nonce;
    calculateHash();
}

time_t Block::getTime() const {
    return this->time;
}

void Block::calculateHash() {
    std::string dataHash = sha256(this->data);
    std::string header = this->prevHash + dataHash + this->nonce;
    this->hash = sha256(header);
}
