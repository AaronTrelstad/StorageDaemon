#pragma once
#include "MerkleNode.h"
#include <string>
#include <vector>

/*
Merkle Tree is used for versioning, lets say a storage node fails when it restarts it could be out of date
we don't want to have to send the full data of another node, instead we can compare the hashes in the tree.

We also need to add some form of locking to the tree on updates or we can batch updates together to limit the locks
*/
class MerkleTree {
public:
    MerkleTree(size_t capacity);

    void setLeaf(size_t index, const std::string& hash);
    void remooveLeaf(size_t index);
    std::string getRootHash() const;

    // Given a different tree we can find differences in O(logn)
    std::vector<size_t> diff(const MerkleTree& other) const;

private:
    // When we update the tree we need to update parent hashes
    void recomputeUp(size_t index);

    std::vector<MerkleNode> nodes_;
    std::mutex mutex_;
};
