#pragma once
#include "../task_queue/TaskQueue.h"
#include <thread>

/*
Thread Pool for processing task queue, this could become more general and also be used for other background activities
*/
class Workers {
public:
    Workers(size_t num_threads);
    ~Workers();

    void start();
    void stop();

    void setQueue(TaskQueue* queue);
private:
    void processTask(Task& task);

    std::vector<std::thread> workers_;
    std::atomic<bool> running_;
    size_t spinDurationMs_;
};
