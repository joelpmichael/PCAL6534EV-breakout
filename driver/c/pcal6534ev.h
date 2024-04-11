/*
 *
 * PCAL6534EV driver - C example
 *
 * Full datasheet at https://www.nxp.com/docs/en/data-sheet/PCAL6534.pdf
 *
 */

// required includes
#include <stddef.h>
#include <stdint.h>

// Common definitions

// Function return codes
typedef enum pcal6534ev_status_e {
    PCAL6534EV_STATUS_OK = 0,
    PCAL6534EV_STATUS_FAIL = 0,
} pcal6534ev_status;

// Register names
typedef enum pcal6534ev_register_e {
    PCAL6534EV_REG_INPUT_PORT_0 = 0x00,
    PCAL6534EV_REG_INPUT_PORT_1 = 0x01,
    PCAL6534EV_REG_INPUT_PORT_2 = 0x02,
    PCAL6534EV_REG_INPUT_PORT_3 = 0x03,
    PCAL6534EV_REG_INPUT_PORT_4 = 0x04,

    PCAL6534EV_REG_OUTPUT_PORT_0 = 0x05,
    PCAL6534EV_REG_OUTPUT_PORT_1 = 0x06,
    PCAL6534EV_REG_OUTPUT_PORT_2 = 0x07,
    PCAL6534EV_REG_OUTPUT_PORT_3 = 0x08,
    PCAL6534EV_REG_OUTPUT_PORT_4 = 0x09,

    PCAL6534EV_REG_POLINV_PORT_0 = 0x0A,
    PCAL6534EV_REG_POLINV_PORT_1 = 0x0B,
    PCAL6534EV_REG_POLINV_PORT_2 = 0x0C,
    PCAL6534EV_REG_POLINV_PORT_3 = 0x0D,
    PCAL6534EV_REG_POLINV_PORT_4 = 0x0E,

    PCAL6534EV_REG_CONFIG_PORT_0 = 0x0F,
    PCAL6534EV_REG_CONFIG_PORT_1 = 0x10,
    PCAL6534EV_REG_CONFIG_PORT_2 = 0x11,
    PCAL6534EV_REG_CONFIG_PORT_3 = 0x12,
    PCAL6534EV_REG_CONFIG_PORT_4 = 0x13,

    PCAL6534EV_REG_DRIVE_PORT_0A = 0x30,
    PCAL6534EV_REG_DRIVE_PORT_0B = 0x31,
    PCAL6534EV_REG_DRIVE_PORT_1A = 0x32,
    PCAL6534EV_REG_DRIVE_PORT_1B = 0x33,
    PCAL6534EV_REG_DRIVE_PORT_2A = 0x34,
    PCAL6534EV_REG_DRIVE_PORT_2B = 0x35,
    PCAL6534EV_REG_DRIVE_PORT_3A = 0x36,
    PCAL6534EV_REG_DRIVE_PORT_3B = 0x37,
    PCAL6534EV_REG_DRIVE_PORT_4A = 0x38,

    PCAL6534EV_REG_ILATCH_PORT_0 = 0x3A,
    PCAL6534EV_REG_ILATCH_PORT_1 = 0x3B,
    PCAL6534EV_REG_ILATCH_PORT_2 = 0x3C,
    PCAL6534EV_REG_ILATCH_PORT_3 = 0x3D,
    PCAL6534EV_REG_ILATCH_PORT_4 = 0x3E,

    PCAL6534EV_REG_PULLEN_PORT_0 = 0x3F,
    PCAL6534EV_REG_PULLEN_PORT_1 = 0x40,
    PCAL6534EV_REG_PULLEN_PORT_2 = 0x41,
    PCAL6534EV_REG_PULLEN_PORT_3 = 0x42,
    PCAL6534EV_REG_PULLEN_PORT_4 = 0x43,

    PCAL6534EV_REG_PULLDIR_PORT_0 = 0x44,
    PCAL6534EV_REG_PULLDIR_PORT_1 = 0x45,
    PCAL6534EV_REG_PULLDIR_PORT_2 = 0x46,
    PCAL6534EV_REG_PULLDIR_PORT_3 = 0x47,
    PCAL6534EV_REG_PULLDIR_PORT_4 = 0x48,

    PCAL6534EV_REG_IMASK_PORT_0 = 0x49,
    PCAL6534EV_REG_IMASK_PORT_1 = 0x4A,
    PCAL6534EV_REG_IMASK_PORT_2 = 0x4B,
    PCAL6534EV_REG_IMASK_PORT_3 = 0x4C,
    PCAL6534EV_REG_IMASK_PORT_4 = 0x4D,

    PCAL6534EV_REG_ISTAT_PORT_0 = 0x4E,
    PCAL6534EV_REG_ISTAT_PORT_1 = 0x4F,
    PCAL6534EV_REG_ISTAT_PORT_2 = 0x50,
    PCAL6534EV_REG_ISTAT_PORT_3 = 0x51,
    PCAL6534EV_REG_ISTAT_PORT_4 = 0x52,

    PCAL6534EV_REG_OUT_PORT_CFG = 0x53,

    PCAL6534EV_REG_IEDGE_PORT_0A = 0x54,
    PCAL6534EV_REG_IEDGE_PORT_0B = 0x55,
    PCAL6534EV_REG_IEDGE_PORT_1A = 0x56,
    PCAL6534EV_REG_IEDGE_PORT_1B = 0x57,
    PCAL6534EV_REG_IEDGE_PORT_2A = 0x58,
    PCAL6534EV_REG_IEDGE_PORT_2B = 0x59,
    PCAL6534EV_REG_IEDGE_PORT_3A = 0x5A,
    PCAL6534EV_REG_IEDGE_PORT_3B = 0x5B,
    PCAL6534EV_REG_IEDGE_PORT_4A = 0x5C,

    PCAL6534EV_REG_ICLR_PORT_0 = 0x5E,
    PCAL6534EV_REG_ICLR_PORT_1 = 0x5F,
    PCAL6534EV_REG_ICLR_PORT_2 = 0x60,
    PCAL6534EV_REG_ICLR_PORT_3 = 0x61,
    PCAL6534EV_REG_ICLR_PORT_4 = 0x62,

    PCAL6534EV_REG_INPUT_STAT_PORT_0 = 0x63,
    PCAL6534EV_REG_INPUT_STAT_PORT_1 = 0x64,
    PCAL6534EV_REG_INPUT_STAT_PORT_2 = 0x65,
    PCAL6534EV_REG_INPUT_STAT_PORT_3 = 0x66,
    PCAL6534EV_REG_INPUT_STAT_PORT_4 = 0x67,

    PCAL6534EV_REG_OUT_PIN_PORT_0_CFG = 0x68,
    PCAL6534EV_REG_OUT_PIN_PORT_1_CFG = 0x69,
    PCAL6534EV_REG_OUT_PIN_PORT_2_CFG = 0x6A,
    PCAL6534EV_REG_OUT_PIN_PORT_3_CFG = 0x6B,
    PCAL6534EV_REG_OUT_PIN_PORT_4_CFG = 0x6C,

    PCAL6534EV_REG_DEBOUNCE_ENABLE_PORT_0 = 0x6D,
    PCAL6534EV_REG_DEBOUNCE_ENABLE_PORT_1 = 0x6E,
    PCAL6534EV_REG_DEBOUNCE_COUNT = 0x6F,
} pcal6534ev_register;

// Port names
typedef enum pcal6534ev_port_e {
    PCAL6534EV_PORT_0 = 0,
    PCAL6534EV_PORT_1 = 1,
    PCAL6534EV_PORT_2 = 2,
    PCAL6534EV_PORT_3 = 3,
    PCAL6534EV_PORT_4 = 4,
} pcal6534ev_port;
#define PCAL6534EV_PORT_COUNT 5

// Pin names
typedef enum pcal6534ev_port_pin_e {
    PCAL6534EV_PORT_PIN_0 = 1 << 0,
    PCAL6534EV_PORT_PIN_1 = 1 << 1,
    PCAL6534EV_PORT_PIN_2 = 1 << 2,
    PCAL6534EV_PORT_PIN_3 = 1 << 3,
    PCAL6534EV_PORT_PIN_4 = 1 << 4,
    PCAL6534EV_PORT_PIN_5 = 1 << 5,
    PCAL6534EV_PORT_PIN_6 = 1 << 6,
    PCAL6534EV_PORT_PIN_7 = 1 << 7,
} pcal6534ev_port_pin;
#define PCAL6534EV_PORT_PIN_COUNT 8

// Pin levels
typedef enum pcal6534ev_pin_level_e {
    PCAL6534EV_PIN_LEVEL_LOW = 0,
    PCAL6534EV_PIN_LEVEL_HIGH = 1,
} pcal6534ev_pin_level;

// Pin mode configuration - input (hi-z) or output (push-pull/open-drain)
// All pins are configured as input (hi-z) by default
typedef enum pcal6534ev_pin_mode_e {
    PCAL6534EV_PIN_MODE_OUTPUT = 0,
    PCAL6534EV_PIN_MODE_INPUT = 1,
} pcal6534ev_pin_mode;

// Output pin configuration
typedef enum pcal6534ev_pin_output_mode_e {
    PCAL6534EV_PIN_OUTPUT_MODE_PUSHPULL_NOPULL = 0b00,
    PCAL6534EV_PIN_OUTPUT_MODE_OPENDRAIN = 0b01,
    PCAL6534EV_PIN_OUTPUT_MODE_PUSHPULL_PULLDOWN = 0b10,
    PCAL6534EV_PIN_OUTPUT_MODE_PUSHPULL_PULLUP = 0b11,
} pcal6534ev_pin_output_mode;

// Output pin drive strength
typedef enum pcal6534ev_pin_output_drive_e {
    PCAL6534EV_PIN_OUTPUT_DRIVE_25 = 0b00,
    PCAL6534EV_PIN_OUTPUT_DRIVE_50 = 0b01,
    PCAL6534EV_PIN_OUTPUT_DRIVE_75 = 0b10,
    PCAL6534EV_PIN_OUTPUT_DRIVE_100 = 0b11,
} pcal6534ev_pin_output_drive;

// Input pin configuration

typedef enum pcal6534ev_i2c_address_e {
    I2C_GENERAL_CALL = 0x00,

    // Device Addresses: lower 7 bits
    // Suitable for MCU SDKs that expect I2C device address in the lower 7 bits (eg MCP)
    I2C_DEVICE_ID_L = 0xFE >> 1,
    PCAL6534EV_ADDR_00_L = 0x40 >> 1,
    PCAL6534EV_ADDR_01_L = 0x42 >> 1,
    PCAL6534EV_ADDR_10_L = 0x44 >> 1,
    PCAL6534EV_ADDR_11_L = 0x46 >> 1,

    // Device Addresses: upper 7 bits
    // Suitable for MCU SDKs that expect I2C device address in the upper 7 bits (eg STM32)
    I2C_DEVICE_ID_H = 0xFE,
    PCAL6534EV_ADDR_00_H = 0x40,
    PCAL6534EV_ADDR_01_H = 0x42,
    PCAL6534EV_ADDR_10_H = 0x44,
    PCAL6534EV_ADDR_11_H = 0x46,
} pcal6534ev_i2c_address;

// Device address aliases

// For ease of use when the ADDR pin is connected to a known address-set pin
#define PCAL6534EV_ADDR_SCL_L PCAL6534EV_ADDR_00_L
#define PCAL6534EV_ADDR_SDA_L PCAL6534EV_ADDR_10_L
#define PCAL6534EV_ADDR_VSS_L PCAL6534EV_ADDR_01_L
#define PCAL6534EV_ADDR_VDD_L PCAL6534EV_ADDR_11_L
#define PCAL6534EV_ADDR_SCL_H PCAL6534EV_ADDR_00_H
#define PCAL6534EV_ADDR_SDA_H PCAL6534EV_ADDR_10_H
#define PCAL6534EV_ADDR_VSS_H PCAL6534EV_ADDR_01_H
#define PCAL6534EV_ADDR_VDD_H PCAL6534EV_ADDR_11_H

// with _7B or _8B suffix
#define I2C_DEVICE_ID_7B I2C_DEVICE_ID_L
#define PCAL6534EV_ADDR_00_7B PCAL6534EV_ADDR_00_L
#define PCAL6534EV_ADDR_01_7B PCAL6534EV_ADDR_01_L
#define PCAL6534EV_ADDR_10_7B PCAL6534EV_ADDR_10_L
#define PCAL6534EV_ADDR_11_7B PCAL6534EV_ADDR_11_L
#define I2C_DEVICE_ID_8B I2C_DEVICE_ID_H
#define PCAL6534EV_ADDR_00_8B PCAL6534EV_ADDR_00_H
#define PCAL6534EV_ADDR_01_8B PCAL6534EV_ADDR_01_H
#define PCAL6534EV_ADDR_10_8B PCAL6534EV_ADDR_10_H
#define PCAL6534EV_ADDR_11_8B PCAL6534EV_ADDR_11_H
#define PCAL6534EV_ADDR_SCL_7B PCAL6534EV_ADDR_SCL_L
#define PCAL6534EV_ADDR_SDA_7B PCAL6534EV_ADDR_SDA_L
#define PCAL6534EV_ADDR_VSS_7B PCAL6534EV_ADDR_VSS_L
#define PCAL6534EV_ADDR_VDD_7B PCAL6534EV_ADDR_VDD_L
#define PCAL6534EV_ADDR_SCL_8B PCAL6534EV_ADDR_SCL_H
#define PCAL6534EV_ADDR_SDA_8B PCAL6534EV_ADDR_SDA_H
#define PCAL6534EV_ADDR_VSS_8B PCAL6534EV_ADDR_VSS_H
#define PCAL6534EV_ADDR_VDD_8B PCAL6534EV_ADDR_VDD_H

// Internal'ish definitions
#ifndef PCAL6534EV_PORT_0_DISABLE_PINS
#define PCAL6534EV_PORT_0_DISABLE_PINS 0b00000000
#endif
#ifndef PCAL6534EV_PORT_1_DISABLE_PINS
#define PCAL6534EV_PORT_1_DISABLE_PINS 0b00000000
#endif
#ifndef PCAL6534EV_PORT_2_DISABLE_PINS
#define PCAL6534EV_PORT_2_DISABLE_PINS 0b00000000
#endif
#ifndef PCAL6534EV_PORT_3_DISABLE_PINS
#define PCAL6534EV_PORT_3_DISABLE_PINS 0b00000000
#endif
#ifndef PCAL6534EV_PORT_4_DISABLE_PINS
#define PCAL6534EV_PORT_4_DISABLE_PINS 0b00000000
#endif

#define PCAL6534EV_PORT_0_MASK 0b00000000 | PCAL6534EV_PORT_0_DISABLE_PINS
#ifdef PCAL6534EV_BREAKOUT
// disable P1_0 on PCAL6534EV breakout
#define PCAL6534EV_PORT_1_MASK 0b00000001 | PCAL6534EV_PORT_1_DISABLE_PINS
#else
#define PCAL6534EV_PORT_1_MASK 0b00000000 | PCAL6534EV_PORT_1_DISABLE_PINS
#endif
#define PCAL6534EV_PORT_2_MASK 0b00000000 | PCAL6534EV_PORT_2_DISABLE_PINS
#ifdef PCAL6534EV_BREAKOUT
// disable P3_1 on PCAL6534EV breakout
#define PCAL6534EV_PORT_3_MASK 0b00000010 | PCAL6534EV_PORT_3_DISABLE_PINS
#else
#define PCAL6534EV_PORT_3_MASK 0b00000000 | PCAL6534EV_PORT_3_DISABLE_PINS
#endif
// P4 only contains P4_0 and P4_1, mask off the rest
#define PCAL6534EV_PORT_4_MASK 0b11111100 | PCAL6534EV_PORT_4_DISABLE_PINS

// callback definitions
// basic i2c read and write routines
typedef pcal6534ev_status (*pcal6534ev_i2c_read_cb)(uint8_t i2c_addr, uint8_t *buf, uint8_t len);
typedef pcal6534ev_status (*pcal6534ev_i2c_write_cb)(uint8_t i2c_addr, uint8_t *buf, uint8_t len);
// advanced i2c read that sends an initial 1-byte write then a repeated start to perform a read
typedef pcal6534ev_status (*pcal6534ev_i2c_read_reg_cb)(uint8_t i2c_addr, uint8_t reg, uint8_t *buf, uint8_t len);
// function that toggles a GPIO connected to the reset line (optional)
typedef pcal6534ev_status (*pcal6534ev_reset_gpio_cb)();
typedef struct pcal6534ev_port_s {
} pcal6534ev_port;

typedef struct pcal6534ev_s {
    pcal6534ev_i2c_address i2c_address;
    pcal6534ev_port port[PCAL6534EV_PORT_COUNT];
    uint8_t debounce_count;
    pcal6534ev_i2c_read_cb *pcal6534ev_i2c_read_cb;
    pcal6534ev_i2c_write_cb *pcal6534ev_i2c_write_cb;
    pcal6534ev_i2c_read_reg_cb *pcal6534ev_i2c_read_reg_cb;
    pcal6534ev_reset_gpio_cb *pcal6534ev_reset_gpio_cb;
    uint8_t i2c_buf[10];
} pcal6534ev;

// function definitions
pcal6534ev_status pcal6534ev_init(
    pcal6534ev *device,
    pcal6534ev_i2c_address i2c_address,
    uint8_t debounce_count,
    pcal6534ev_i2c_read_cb *pcal6534ev_i2c_read_cb,
    pcal6534ev_i2c_write_cb *pcal6534ev_i2c_write_cb,
    pcal6534ev_i2c_read_reg_cb *pcal6534ev_i2c_read_reg_cb,
    pcal6534ev_reset_gpio_cb *pcal6534ev_reset_gpio_cb);

pcal6534ev_status pcal6534ev_reset_software(pcal6534ev_i2c_write_cb *pcal6534ev_i2c_write_cb);
