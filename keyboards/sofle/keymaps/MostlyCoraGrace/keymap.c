#include QMK_KEYBOARD_H
#include "oled.c"
#include "layernames.h"


#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QW] = { ENCODER_CCW_CW(  DF(_GA), XXXXXXX),           ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_QL] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______) },
    [_QR] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______)},
    [_GA] = { ENCODER_CCW_CW(XXXXXXX,   DF(_QW)),           ENCODER_CCW_CW(_______, _______)},
    [_GL] = { ENCODER_CCW_CW(_______, _______),           ENCODER_CCW_CW(_______, _______)}
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BKSP |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  '   |  ;   |
 * |------+------+------+------+------+------|RGB OFF|    | MUTE  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   /  |   ,  |   .  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Enter | / LOWER /       \RAISE \  |SPACE | RCTR | RAlt | MENU |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QW] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,     KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_EQUAL,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,     KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_MINUS,
  KC_BSPC,  KC_A,   KC_S,    KC_D,    KC_F,     KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,   KC_SCLN,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,     KC_B,  RGB_TOG,  KC_MUTE,     KC_N,    KC_M, KC_SLSH, KC_COMM,  KC_DOT,   KC_RSFT,
                 KC_LGUI, KC_LALT, KC_LCTL,   KC_ENT,  MO(_QL),  MO(_QR),   KC_SPC, KC_RCTL, KC_RALT,  KC_APP
),
/* QWERTY LOWER
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |   `  |NUMLK |   /  |   *  |   -  |      |                    |      |      |      |  (   |   )  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   7  |   8  |   9  |   +  |      |                    |      |      |      |  {   |   }  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | DEL  |   4  |   5  |   6  |   .  |      |-------.    ,-------|      |      |      |  [   |   ]  |      |
 * |------+------+------+------+------+------|RGB OFF|    | MUTE  |------+------+------+------+------+------|
 * | CAPS |   1  |   2  |   3  | ENTER|      |-------|    |-------| SCRLK|      |   \  |  <   |   >  | CAPS |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |  0   | LAlt | LCTR |Enter | / LOWER /       \RAISE \  |SPACE | RCTR | RAlt | MENU |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_QL] = LAYOUT(
   KC_GRV,  KC_NUM, KC_PSLS, KC_PAST, KC_PMNS, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX,    S(KC_9),    S(KC_0), XXXXXXX,
  _______,   KC_P7,   KC_P8,   KC_P9, KC_PPLS, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, S(KC_LBRC), S(KC_RBRC), XXXXXXX,
   KC_DEL,   KC_P4,   KC_P5,   KC_P6, KC_PDOT, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX,    KC_LBRC,    KC_RBRC, XXXXXXX,
  KC_CAPS,   KC_P1,   KC_P2,   KC_P3, KC_PENT, XXXXXXX, _______,       _______, KC_SCRL, XXXXXXX, KC_BSLS, S(KC_COMM),  S(KC_DOT), KC_CAPS,
                      KC_P0, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

 /* QWERTYRAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | F21  | F22  | F23  | F24  |      |                    | PAUSE| HOME |  Up  |  END | PGUP | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | DEL  | F17  | F18  | F19  | F20  |      |-------.    ,-------| PRTSC| Left | Down | Right| PGDN | INS  |
 * |------+------+------+------+------+------|RGB OFF|    | MUTE  |------+------+------+------+------+------|
 * | CAPS | F13  | F14  | F15  | F16  |      |-------|    |-------| SCRLK|      |      |      |      | CAPS |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | / Enter /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_QR] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,  KC_F20,  KC_F22,  KC_F23,  KC_F24, XXXXXXX,                         KC_PAUS, KC_HOME,   KC_UP,  KC_END, KC_PGUP,  KC_F12,
  _______,  KC_F17,  KC_F18,  KC_F19,  KC_F20, XXXXXXX,                         KC_PSCR, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,  KC_INS,
  KC_CAPS,  KC_F13,  KC_F14,  KC_F15,  KC_F16, XXXXXXX, _______,       _______, KC_SCRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,
                    _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),

 /* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   6  |   Q  |   W  |   E  |   R  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LOWER| SHIFT|   A  |   S  |   D  |   F  |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|RGB OFF|    |       |------+------+------+------+------+------|
 * |   Z  | CTRL |   G  |   M  |   P  |   T  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |   X  |   C  |   V  | SPACE| /  ALT  /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_GA] = LAYOUT(
   KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   KC_TAB,    KC_6,    KC_Q,    KC_W,    KC_E,    KC_R,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  MO(_GL), KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     KC_Z, KC_LCTL,    KC_G,    KC_M,    KC_P,    KC_T, _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       KC_X,    KC_C,    KC_V,  KC_SPC, KC_LALT,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

 /* GAME LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   7  |   8  |   9  |   0  |  F1  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Y  |   U  |   W  |   I  |   O  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LOWER| SHIFT|   A  |   S  |   D  |   L  |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|RGB OFF|    |       |------+------+------+------+------+------|
 * |   J  | CTRL |   G  |   H  |   B  |   N  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |   K  |   C  |   V  | SPACE| /  ALT  /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_GL] = LAYOUT(
   KC_GRV,    KC_7,    KC_8,    KC_9,    KC_0,   KC_F1,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______,    KC_Y,    KC_U, _______,    KC_I,    KC_O,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______, _______,    KC_L,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
     KC_J, _______,    KC_G,    KC_H,    KC_B,    KC_N, _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                       KC_K, _______, _______, _______, _______,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)
};

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_PURPLE);
}

/*
void keyboard_post_init_user(void) {
    rgb_matrix_set_color(0, HSV_WHITE);
}
*/
