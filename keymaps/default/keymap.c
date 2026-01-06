#include QMK_KEYBOARD_H
#include "version.h"
#include "sm_td.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  HSV_0_245_245,
  HSV_74_255_206,
  HSV_152_255_255,
};

#define SYMBOL_LAYER 1
#define MOUSE_LAYER 2
#define NUMBER_LAYER 3




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE, HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_4), HYPR(KC_5), KC_LEFT,
    KC_RIGHT, HYPR(KC_6), HYPR(KC_7), HYPR(KC_8), HYPR(KC_9), HYPR(KC_0), KC_DEL,

    KC_TAB, KC_QUOTE, KC_COMMA, KC_DOT, KC_P, KC_Y, KC_MS_BTN2,
    TG(SYMBOL_LAYER), KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC,

    KC_LCTL, KC_A, KC_O, KC_E, KC_U, KC_I, KC_MS_BTN1,
    KC_MEH, KC_D, KC_H, KC_T, KC_N, LT(MOUSE_LAYER, KC_S), KC_ENTER,

    KC_LEFT_SHIFT, MT(MOD_LALT, KC_SCLN), MT(MOD_LGUI, KC_Q), KC_J, KC_K, KC_X,
    KC_B, KC_M, KC_W, MT(MOD_RGUI, KC_V), MT(MOD_RALT, KC_Z), KC_RIGHT_SHIFT,

    LT(SYMBOL_LAYER, KC_GRAVE), MO(SYMBOL_LAYER), KC_TRANSPARENT, KC_MEH, MO(NUMBER_LAYER), LGUI(KC_SPACE),
    MT(MOD_LCTL, KC_ESCAPE), MO(MOUSE_LAYER), KC_DOWN, KC_UP, KC_RIGHT, MO(SYMBOL_LAYER),

    KC_SPACE, KC_HYPR, MO(SYMBOL_LAYER),
    KC_LEFT_ALT, KC_TAB, KC_ENTER
  ),
  [SYMBOL_LAYER] = LAYOUT_moonlander(
    KC_ESCAPE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11,

    KC_TRANSPARENT, KC_EXLM, LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_PIPE, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_UP, KC_7, KC_8, KC_9, KC_ASTR, KC_F12,

    KC_TRANSPARENT, KC_HASH, MS_WHLR, KC_MS_BTN2, KC_MS_BTN1, MS_WHLL, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_DOWN, KC_4, KC_5, KC_6, KC_KP_PLUS, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC, MS_WHLU, MS_WHLD, KC_TILD,
    KC_AMPR, KC_1, KC_2, KC_3, KC_BSLS, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_COMMA, HSV_0_245_245, HSV_74_255_206, HSV_152_255_255, RGB_MODE_FORWARD,
    RGB_TOG, KC_TRANSPARENT, KC_DOT, KC_0, KC_EQUAL, KC_TRANSPARENT,

    RGB_VAD, RGB_VAI, TOGGLE_LAYER_COLOR,
    RGB_SLD, RGB_HUD, RGB_HUI
  ),
  [MOUSE_LAYER] = LAYOUT_moonlander(
    AU_TOGG, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,

    MU_TOGG, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    MU_NEXT, KC_TRANSPARENT, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_HOME, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_END, KC_MEDIA_PLAY_PAUSE,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1, KC_MS_BTN2, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
  ),
  [NUMBER_LAYER] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_CIRC, KC_7, KC_8, KC_9, KC_GRAVE, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_PLUS, KC_MINUS, KC_EQUAL, KC_UNDERSCORE, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_0, KC_4, KC_5, KC_6, KC_TILDE, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_QUESTION, KC_PIPE, KC_ASTERISK, KC_AMPERSAND,
    KC_DOT, KC_1, KC_2, KC_3, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

#ifdef COMBO_ENABLE
enum combo_events {
  EU_ESC,
  HT_BSPC,
  HC_SLASH,
  DOTU_BSLASH,
  DOTP_LBRC,
  GC_RBRC,
  UI_LPRN,
  DH_RPRN,
  KX_LCBR,
  BM_RCBR,
};

const uint16_t PROGMEM eu_combo[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM ht_combo[] = {KC_H, KC_T, COMBO_END};
const uint16_t PROGMEM hc_combo[] = {KC_H, KC_C, COMBO_END};
const uint16_t PROGMEM dotu_combo[] = {KC_DOT, KC_U, COMBO_END};
const uint16_t PROGMEM dotp_combo[] = {KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM gc_combo[] = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM dh_combo[] = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM kx_combo[] = {KC_K, KC_X, COMBO_END};
const uint16_t PROGMEM bm_combo[] = {KC_B, KC_M, COMBO_END};

combo_t key_combos[] = {
  [EU_ESC] = COMBO(eu_combo, KC_ESCAPE),
  [HT_BSPC] = COMBO(ht_combo, KC_BSPC),
  [HC_SLASH] = COMBO(hc_combo, KC_SLASH),
  [DOTU_BSLASH] = COMBO(dotu_combo, KC_BSLS),
  [DOTP_LBRC] = COMBO(dotp_combo, KC_LBRC),
  [GC_RBRC] = COMBO(gc_combo, KC_RBRC),
  [UI_LPRN] = COMBO(ui_combo, KC_LPRN),
  [DH_RPRN] = COMBO(dh_combo, KC_RPRN),
  [KX_LCBR] = COMBO(kx_combo, KC_LCBR),
  [BM_RCBR] = COMBO(bm_combo, KC_RCBR),
};
#endif

smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
  switch (keycode) {
    SMTD_MT(KC_Q, KC_LEFT_GUI)
    SMTD_MT(KC_SCLN, KC_LEFT_ALT)
    SMTD_MT(KC_V, KC_RIGHT_GUI)
    SMTD_MT(KC_Z, KC_RIGHT_ALT)
  }

  return SMTD_RESOLUTION_UNHANDLED;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (!process_smtd(keycode, record)) {
    //     return false;
    // }

    switch (keycode) {
  case QK_MODS ... QK_MODS_MAX:
    // Mouse keys with modifiers work inconsistently across operating systems, this makes sure that modifiers are always
    // applied to the mouse key that was pressed.
    if (IS_MOUSE_KEYCODE(QK_MODS_GET_BASIC_KEYCODE(keycode))) {
    if (record->event.pressed) {
        add_mods(QK_MODS_GET_MODS(keycode));
        send_keyboard_report();
        wait_ms(2);
        register_code(QK_MODS_GET_BASIC_KEYCODE(keycode));
        return false;
      } else {
        wait_ms(2);
        del_mods(QK_MODS_GET_MODS(keycode));
      }
    }
    break;

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
    case HSV_0_245_245:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(0,245,245);
        }
        return false;
    case HSV_74_255_206:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(74,255,206);
        }
        return false;
    case HSV_152_255_255:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(152,255,255);
        }
        return false;
  }
  return true;
}
