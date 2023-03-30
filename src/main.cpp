/*
** EPITECH PROJECT, 2022
** cppBlockChain
** File description:
** main.cpp
*/

#include <iostream>

#include "block.hpp"
#include "blockchain.hpp"
#include "proof_of_work.hpp"

int main() {
    Blockchain blockchain;
    blockchain.addBlock("First block");
    blockchain.addBlock("Second block");

    std::cout << "Is blockchain valid? " << blockchain.isChainValid() << std::endl;

    blockchain.getLastBlock().setNonce("00");
    std::cout << "Is blockchain valid? " << blockchain.isChainValid() << std::endl;

    return 0;
}