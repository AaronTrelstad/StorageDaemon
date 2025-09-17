#pragma once
#include <string>

struct MerkleNode {
    std::string hash;
    MerkleNode* left;
    MerkleNode* right;

    MerkleNode(const std::string& h) : hash(h), left(nullptr), right(nullptr) {}
};
