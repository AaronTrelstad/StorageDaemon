#pragma once
#include <string>

struct MerkleNode {
    std::string hash;
    MerkleNode* left;
    MerkleNode* right;
    MerkleNode* parent;

    MerkleNode(const std::string& h) : hash(h), left(nullptr), right(nullptr) {}
};
