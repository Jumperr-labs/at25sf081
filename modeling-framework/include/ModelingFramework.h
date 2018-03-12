#pragma once
#include <string>
#include "SpiSlave.h"
//#include "memory.h"

int GetPinNumber(std::string pin_name);
iSpiSlave* CreateSpiSlave(SpiSlaveConfig spi_config);

bool GetPinLevel(int pin_number);
//void SetPinLevel(int pin_number, bool pin_level);
//Memory CreateMemory(size_t size, uint8_t reset_value);

class ExternalPeripheral {
  public:
    virtual void Main() = 0;
    virtual void Stop() = 0;
};

typedef ExternalPeripheral* peripheral_maker(int peripheral_id);
