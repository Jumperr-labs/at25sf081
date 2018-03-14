#pragma once
#include <string>
#include "SpiSlave.h"

int GetPinNumber(const std::string &pin_name);

iSpiSlaveV1* CreateSpiSlave(SpiSlaveConfig &spi_config);

bool GetPinLevel(int pin_number);

void SetPinLevel(int pin_number, bool pin_level);

class ExternalPeripheral {
  public:
    virtual void Main() = 0;
    virtual void Stop() = 0;
};

typedef ExternalPeripheral* peripheral_factory_t();
