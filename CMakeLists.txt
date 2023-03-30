cmake_minimum_required(VERSION 3.16)
project(basic-blockchain)

set(CMAKE_CXX_STANDARD 17)

# Add source files
add_executable(basic-blockchain
    src/main.cpp
    src/blockchain.cpp
    src/block.cpp
    src/sha256.cpp
    src/proof_of_work.cpp
)

# Add include directories
target_include_directories(basic-blockchain PRIVATE include)

# Add OpenSSL library for SHA-256 hashing
find_package(OpenSSL REQUIRED)
target_link_libraries(basic-blockchain PRIVATE OpenSSL::Crypto)
