#pragma once
#include <string>
#include <functional>
#include "iSpiSlave.h"


#ifdef _WINDOWS
    #define DLL_EXPORT extern "C" __declspec(dllexport)
#else
    #define DLL_EXPORT extern "C"
#endif

int GetPinNumber(const std::string &pin_name);
iSpiSlave* CreateSpiSlave(SpiSlaveConfig &spi_config);

bool GetPinLevel(int pin_number);
bool GetPinLevel(const std::string &pin_name);
void SetPinLevel(int pin_number, bool pin_level);
void SetPinLevel(const std::string &pin_name, bool pin_level);

/* Peripheral Timed Callback */
typedef std::function<void ()> callback_t;
int AddTimedCallback(uint64_t ns, const callback_t &callback, bool run_once = false);
void CancelTimedCallback(int id);
void UpdateTimedCallback(int id, uint64_t ns);

int32_t GetNextInt32FromDataGenerator(std::string name);
double GetNextDoubleFromDataGenerator(std::string name);
int16_t GetNextInt16FromDataGenerator(std::string name);
uint8_t GetNextUInt8FromDataGenerator(std::string name);
double GetCachedValueFromDataGenerator(std::string name);

class ExternalPeripheral {
  public:
    virtual void Main() = 0;
    virtual void Stop() = 0;
};

typedef ExternalPeripheral* peripheral_factory_t();