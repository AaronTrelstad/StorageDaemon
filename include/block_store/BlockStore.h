#pragma once
#include "../device/DeviceInfo.h"
#include <vector>
#include <cstdint>

/*
SSD and HDD are block addressable unlike DRAM and PMem which are byte addressable
*/
class BlockStore {
public:
    BlockStore(DeviceInfo* device);

    uint64_t allocateBlocks(size_t numBlocks);
    void writeBlock(uint64_t blockIndex, const std::vector<uint8_t>& data);
    std::vector<uint8_t> readBlock(uint64_t blockIndex);

private:
    DeviceInfo* device_;

    // This tells us which blocks are available
    std::vector<uint64_t> bitmap;
};
