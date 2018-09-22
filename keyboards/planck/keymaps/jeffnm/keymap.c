#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _COLEMAK,
  _FN,
  _LOWER,
  _RAISE,
  _HOTKEYS,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  FN,
  LOWER = LT(_LOWER,KC_SPC),
  RAISE = LT(_RAISE,KC_SPC),
  HBSPC = LT(_HOTKEYS,KC_BSPC),
  HENT  = LT(_HOTKEYS,KC_ENT),
  ADJUST,
};

//Tap Dance Declarations
// enum {
//   TD_SHIFT_CAPS = 0
// };

//Tap Dance Definitions
// qk_tap_dance_action_t tap_dance_actions[] = {
//   //Tap once for Shift, twice for Caps Lock
//   [TD_SHIFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
// // Other declarations would go here, separated by commas, if you have them
// };

// MacOS Lock
#define OSLOCK LCTL(LSFT(KC_SYSTEM_SLEEP))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |ShftEn|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  FN  | Ctrl | Alt  | GUI  |L/Spc |H/Bksp|H/Entr|R/Spc | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT },
  {FN,      KC_LCTL, KC_LALT, KC_LGUI, LOWER,   HBSPC,   HENT,    RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* Colemak Mod-DH
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   R  |   S  |   T  |   G  |   K  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   M  |   H  |   ,  |   .  |   /  |ShftEn|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  FN  | Ctrl | Alt  | GUI  |L/Spc |H/Bksp|H/Entr|R/Spc | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
  {KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC},
  {KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT },
  {FN,      KC_LCTL, KC_LALT, KC_LGUI, LOWER,   HBSPC,   HENT,    RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

/* FN
 * ,-----------------------------------------------------------------------------------.
 * |OSLOCK|  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LEDs |  F11 |  F12 |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CAPSLK|      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] =  {
  {OSLOCK,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL},
  {BL_STEP, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},


/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   -  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   0  |   .  |   =  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8, KC_9,   KC_0,    KC_BSPC},
  {_______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5, KC_6,   KC_MINS, KC_DEL},
  {_______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2, KC_3,   KC_PLUS, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_0, KC_DOT, KC_EQL,  XXXXXXX}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   "  |   /  |   {  |  [   |   ]  |   }  |   \  |   -  |   =  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   |  |ISO | |   _  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Del  |      |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC},
  {_______, _______, KC_QUOT, KC_SLSH, KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_BSLS,    KC_MINS, KC_EQL,  KC_DEL},
  {_______, _______, _______, _______, _______, _______, _______, KC_PIPE, S(KC_NUBS), KC_UNDS, KC_PLUS, _______},
  {_______, _______, _______, _______, _______, KC_DEL,  _______, _______, KC_HOME,    KC_PGDN, KC_PGUP, KC_END}
},
/* Hotkeys
 * ,-----------------------------------------------------------------------------------.
 * |      |      |  Up  |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Left | Down |Right |      |      |      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Prev | Play | Next |      |      |      |      | Mute | VoUp | VoDn |      |
 * `-----------------------------------------------------------------------------------'
 */
[_HOTKEYS] = {
  {_______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______}
  {_______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |Qwerty|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |Debug |      |      |Aud on|Audoff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |Colemk|      |      |      |Mus on|Musoff|MIDIon|MIDIof|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |XXXXXX|      |Voice-|Voice+|      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {RESET,   QWERTY,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {DEBUG,   _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______},
  {_______, _______, _______, COLEMAK, _______, _______, _______, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, MUV_DE,  MUV_IN,  _______}
}
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        // print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case FN:
      if (record->event.pressed){
        layer_on(_FN);
      } else {
        layer_off(_FN);
      }
      break;
    case LOWER:
      if (record->event.pressed) {
        // print("lowered\n");
        layer_on(_LOWER);
         update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      // return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        // print("raised\n");
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      // return false;
      break;

    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
