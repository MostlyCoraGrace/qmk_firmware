 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */


#include "layernames.h"

//Sets up what the OLED screens display.

#ifdef OLED_ENABLE

static void render_logo(void) {
    oled_write(get_u16_str((uint16_t)get_matrix_scan_rate(), ' '), false);
}

static void print_status_narrow(void) {
    //print aesthetic bar
    oled_write_P(PSTR("     "), TRUE);
    oled_write_P(PSTR("\n"), false);

    // Print current mode
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _QW:
            oled_write_P(PSTR("QWRTY"), false);
            break;
        case _QL:
            oled_write_P(PSTR("QWRTY"), false);
            break;
        case _QR:
            oled_write_P(PSTR("QWRTY"), false);
            break;
        case _GA:
            oled_write_P(PSTR("GAME\n"), false);
            break;
        case _GL:
            oled_write_P(PSTR("GAME\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
            break;
    }

    // Print current layer
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _QW:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _QL:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _QR:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _GA:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _GL:
            oled_write_P(PSTR("Lower"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

    //print aesthetic bar
    oled_write_P(PSTR("\n"), false);
    oled_write_P(PSTR("     "), TRUE);
    oled_write_P(PSTR("\n"), false);

    //print current caps state, etc
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("NUMLK"), led_usb_state.num_lock);
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
    oled_write_ln_P(PSTR("SCRLK"), led_usb_state.scroll_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif
