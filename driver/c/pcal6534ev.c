/*
 *
 * PCAL6534EV driver - C example
 *
 * Full datasheet at https://www.nxp.com/docs/en/data-sheet/PCAL6534.pdf
 *
 */

// magic defines that will alter how the PCAL6534EV driver behaves

// Is this a PCAL6534EV breakout board? This disables P1_0 and P3_1
#define PCAL6534EV_BREAKOUT

// Other pins to disable
#define PCAL6534EV_PORT_0_DISABLE_PINS 0b00000000
#define PCAL6534EV_PORT_1_DISABLE_PINS 0b00000000
#define PCAL6534EV_PORT_2_DISABLE_PINS 0b00000000
#define PCAL6534EV_PORT_3_DISABLE_PINS 0b00000000
#define PCAL6534EV_PORT_4_DISABLE_PINS 0b00000000

// Include must come after the defines
#include <pcal6534ev.h>

pcal6534ev_status pcal6534ev_reset_software(pcal6534ev_i2c_write_cb *pcal6534ev_i2c_write_cb) {
}

pcal6534ev_status pcal6534ev_init(
    pcal6534ev *device,
    pcal6534ev_i2c_address i2c_address,
    uint8_t debounce_count,
    pcal6534ev_i2c_read_cb *pcal6534ev_i2c_read_cb,
    pcal6534ev_i2c_write_cb *pcal6534ev_i2c_write_cb,
    pcal6534ev_i2c_read_reg_cb *pcal6534ev_i2c_read_reg_cb,
    pcal6534ev_reset_gpio_cb *pcal6534ev_reset_gpio_cb) {
}
