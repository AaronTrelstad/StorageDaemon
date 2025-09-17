#pragma once
#include <string>

class QuorumManager {
public:
    QuorumManager(int n, int r, int w) : N_(n), readQuorum_(r), writeQuorum_(n) {};

    bool writeQuorum(const std::string& key, const std::vector<std::string>& nodeResponses);
    bool readQuorum(const std::string& key, const std::vector<std::string>& nodeResponses);
    
private:
    int N_;
    int readQuorum_;
    int writeQuorum_;
};
