#pragma once
#include <functional>

enum class TaskType { READ, WRITE };

// Hot written to SSD, Cold to HDD
enum class TierHint { HOT, COLD };

struct Task {
    TaskType type;
    TierHint tier;
    std::string key;
    std::vector<uint8_t> data;

    // This is for reading data
    std::function<void(std::vector<uint8_t>)> callback;
};
