#pragma once
#include "../task_queue/TaskQueue.h"
#include "../task_queue/Task.h"

/*
gRPC Server
*/
class NetworkClient {
public:
    NetworkClient(TaskQueue* queue);

    void startServer(int port);
    void stopServer();

private:
    TaskQueue* taskQueue_;
    std::string loadBalancerAddress_;

    void handleWriteRequest(const std::string& key, const std::vector<uint8_t>& data, TierHint tier);
    void handleReadRequest(const std::string& key, std::function<void(std::vector<uint8_t>)> callback);
    void registerWithLoadBalancer();
};
