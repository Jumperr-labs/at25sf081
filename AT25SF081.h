#pragma once
#include "ModelingFramework.h"

#define MEMORY_SIZE (0x100000)

class AT25SF081 : public ExternalPeripheral {
  public:
    AT25SF081();
    void Main() override;
    void Stop() override;

  private:
    enum BlockSize {
        BLOCK_SIZE_4KB,
        BLOCK_SIZE_32KB,
        BLOCK_SIZE_64KB
    };

    enum StatusRegisterByte {
        STATUS_REGISTER_BYTE_1,
        STATUS_REGISTER_BYTE_2
    };

    void ReadArray(bool with_dummy_byte);
    void ByteOrPageProgram();
    int ReadAddress();
    size_t ReadDummyBytes(size_t num);
    bool WelStatus();
    void SetWel(bool enable);
    void BlockErase(size_t block_size);
    void ChipErase();
    void MemReset();
    void WriteEnable();
    void WriteDisable();
    void IgnoreUntilSsInactive();
    void ReadStatusRegister(StatusRegisterByte byte);
    void ReadManufacturerAndDeviceId();
    void ReadDeviceId();

    iSpiSlaveV1* spi_slave_ {};
    uint8_t memory_[MEMORY_SIZE] {};
    int wp_pin_number_ {};
    int hold_pin_number_ {};
    bool should_stop_;
    uint8_t status_register1_ {};
    uint8_t status_register2_ {};
};

extern "C" ExternalPeripheral *PeripheralFactory() {
    return new AT25SF081();
}
