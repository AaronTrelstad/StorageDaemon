#pragma once
#include "BlockStore.h"
#include <cstdint>
#include <stdio.h>
#include <vector>
#include <string>
#include <unordered_map>

class TieredBlockStore {
public:
    TieredBlockStore(const std::vector<DeviceInfo*>& devices);

    std::vector<uint8_t> get(const std::string& key);
    bool put(const std::string& key, const std::vector<uint8_t>& data, TierHint tier);

private:
    std::vector<BlockStore*> fast_;
    std::vector<BlockStore*> slow_;
};
