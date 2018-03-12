#pragma once
#include "ModelingFramework.h"

class AT25SF081 : public ExternalPeripheral {
  public:
    explicit AT25SF081(int peripheral_id);
    AT25SF081() = default;
    void Main() override;
    void Stop() override {
        should_stop_ = true;
    };

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

    iSpiSlave* spi_slave_ {};
    uint8_t memory_[0x100000] {};
    int wp_pin_number_ {};
    int hold_pin_number_ {};
    bool should_stop_;
    uint8_t status_register1_ {};
    uint8_t status_register2_ {};

    const size_t kMemorySize_ {0x100000};
    const uint8_t kManufacturerId_ {0x1f};
    const uint8_t kDeviceIdPart1_ {0x85};
    const uint8_t kDeviceIdPart2_ {0x01};
    const uint8_t kDeviceCode_ {0x13};
    const uint8_t kStatusRegisterBitWelMask_ {1U << 1};
};

extern "C" ExternalPeripheral *PeripheralMaker(int peripheral_id) {
    return new AT25SF081(peripheral_id);
}
