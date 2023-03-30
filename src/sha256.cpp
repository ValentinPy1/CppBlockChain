/*
** EPITECH PROJECT, 2022
** cppBlockChain
** File description:
** sha256.cpp
*/

#include "sha256.hpp"

std::string sha256(const std::string str) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.length());
    SHA256_Final(hash, &sha256);

    std::string result;
    char buffer[2];
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(buffer, "%02x", hash[i]);
        result += buffer;
    }

    return result;
}
