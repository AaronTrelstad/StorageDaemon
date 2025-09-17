#pragma once
#include <string>

enum class DeviceType { SSD, HDD };
enum class TierHint { HOT, COLD };

struct DeviceInfo {
    std::string path;
    DeviceType type;
    uint64_t blockSize;
    uint64_t totalBlocks;
    uint64_t capacity;
};
