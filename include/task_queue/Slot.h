#pragma once
#include "Task.h"
#include <atomic>

struct Slot {
    // This is to address ABA problem, so we mark if a slot is ready to be pushed/popped
    std::atomic<size_t> sequence;
    Task task;
};
