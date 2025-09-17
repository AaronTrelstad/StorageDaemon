#pragma once
#include "DeviceInfo.h"
#include <string>
#include <vector>

class DeviceManager {
public:
    DeviceManager();

    void detectDevices();
    
private:
    std::vector<DeviceInfo*> devices_;
};
