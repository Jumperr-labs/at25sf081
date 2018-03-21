#pragma once
#include "ModelingFramework.h"

class iJemuV1 {
  public:
    virtual int GetPinNumber(const char *pin_name) = 0;
    virtual iSpiSlave* CreateSpiSlave(SpiSlaveConfig &spi_config) = 0;
    virtual bool GetPinLevel(int pin_number) = 0;
    virtual void SetPinLevel(int pin_number, bool pin_level) = 0;
    virtual int AddTimedCallback(uint64_t ns, const callback_t &callback, bool run_once) = 0;
    virtual void CancelTimedCallback(int id) = 0;
    virtual void UpdateTimedCallback(int id, uint64_t ns) = 0;
    virtual int32_t GetNextInt32FromDataGenerator(const char* name) = 0;
    virtual double GetNextDoubleFromDataGenerator(const char* name) = 0;
    virtual int16_t GetNextInt16FromDataGenerator(const char* name) = 0;
    virtual uint8_t GetNextUInt8FromDataGenerator(const char* name) = 0;
    virtual double GetCachedValueFromDataGenerator(const char* name) = 0;
};

typedef iJemuV1 iJemuInterface;
