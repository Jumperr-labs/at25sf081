#pragma once
#include <cstdint>
#include "SpiCommon.h"

struct SpiSlaveConfig {
    int mosi_pin_number;
    int miso_pin_number;
    int ss_pin_number;
    int sclk_pin_number;
    int supported_spi_modes;
    unsigned int max_frequency;
    BitOrder bit_order;
};

class iSpiSlaveV1 {
  public:
    virtual size_t Read(uint8_t* buffer, size_t num_bytes_to_read) = 0;
    virtual size_t Write(const uint8_t* buffer, size_t num_bytes_to_write) = 0;
    virtual bool IsSsActive() = 0;
};

//class iSpiSlaveV2 : public iSpiSlaveV1 {
//    virtual void SetConfig(SpiSlaveConfig spi_config) = 0;
//    virtual void SetSupportedSpiModes(int spi_mode) = 0;
//    virtual void SetSsPin(int pin_number) = 0;
//    virtual void SetSclkPin(int pin_number) = 0;
//    virtual void SetMosiPin(int pin_number) = 0;
//    virtual void SetMisoPin(int pin_number) = 0;
//    virtual void SetBitOrder(BitOrder bit_order) = 0;
//    virtual void SetMaxFrequency(unsigned int max_frequency) = 0;
//};

