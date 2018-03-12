#pragma once

#define SPI_MODE_0 (1U)
#define SPI_MODE_1 (1U << 1)
#define SPI_MODE_2 (1U << 2)
#define SPI_MODE_3 (1U << 3)

#define SPI_MODE_CPOL0_CPHA0 SPI_MODE_0
#define SPI_MODE_CPOL0_CPHA1 SPI_MODE_1
#define SPI_MODE_CPOL1_CPHA0 SPI_MODE_2
#define SPI_MODE_CPOL1_CPHA1 SPI_MODE_3

typedef int SpiPacketHeader;

const SpiPacketHeader kSpiPacketHeaderFrequecy = 0;
const SpiPacketHeader kSpiPacketHeaderMode = 1;
const SpiPacketHeader kSpiPacketHeaderDataReadyOnMosi = 2;
const SpiPacketHeader kSpiPacketHeaderBitOrder = 3;

struct SpiFrequencyPacket {
    explicit SpiFrequencyPacket(int spi_frequency) : header(kSpiPacketHeaderFrequecy), frequency(spi_frequency) {};
    SpiPacketHeader header;
    int frequency;
};

struct SpiModePacket {
    explicit SpiModePacket(int spi_mode) : header(kSpiPacketHeaderMode), mode(spi_mode) {};
    SpiPacketHeader header;
    int mode;
};

struct SpiDataReadyOnMosiPacket {
    explicit SpiDataReadyOnMosiPacket(int mosi_data_length) : header(kSpiPacketHeaderDataReadyOnMosi), data_length(mosi_data_length) {};
    SpiPacketHeader header;
    int data_length;
};

enum BitOrder {
    BIT_ORDER_UNDEFINED = -1,
    MSB_FIRST,
    LSB_FIRST
};

struct SpiBitOrderPacket {
    explicit SpiBitOrderPacket(BitOrder spi_bit_order) : header(kSpiPacketHeaderBitOrder), bit_order(spi_bit_order) {};
    SpiPacketHeader header;
    BitOrder bit_order;
};
