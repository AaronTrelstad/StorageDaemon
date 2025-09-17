#pragma once
#include "Task.h"
#include "Slot.h"

/*
Initial Concept:
Lock Free Ring Buffer (there are some famous examples)

Spin-then-Sleep, to limit latency for high activity times threads will spin, waiting for 
tasks for X time, then if the queue is still empty they will slept until a new task comes (using condition variables).

Sleeping threads like a mutex can lead to high latencies since it involve context switch when sleeping or waking.
*/
class TaskQueue {
public:
    TaskQueue(size_t capacity);

    bool push(const Task& task);
    bool pop(Task& task);
private:
    std::vector<Slot> buffer_;
    std::atomic<size_t> head_;
    std::atomic<size_t> tail_;
};
