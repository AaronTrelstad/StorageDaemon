#pragma once
#include "../device/DeviceInfo.h"
#include <unordered_map>
#include <string>
#include <mutex>

struct KVMeta {
    DeviceInfo* device;
    uint64_t blockIndex;
    size_t numBlocks;
    size_t size;
    TierHint tier;
};

/*
This maps a key to the where it is being stored
*/
class KVStore {
public:
    void put(const std::string& key, const KVMeta& meta);
    bool get(const std::string& key, KVMeta& meta);

private:
    std::unordered_map<std::string, KVMeta> store_;

    // We need to lock the map
    std::mutex mutex_; 
};

