#include QMK_KEYBOARD_H
#include "version.h"
#include "sm_td.h"
#include "secret.h"

#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#    define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum layers {
    BASE,
    NAV_LAYER,
    MOUSE_LAYER,
    SYMBOL_LAYER,
    NUMBER_LAYER,
    FUNCTION_LAYER,
    MAGIC_LAYER,
    QWERTY_LAYER,
};

enum custom_keycodes {
    RGB_SLD = ZSA_SAFE_RANGE,
    HSV_0_245_245,
    HSV_74_255_206,
    HSV_152_255_255,
    TYP_SECRT_1,
    TYP_SECRT_2,
    MAGIC_TG,   // tap = toggle Dvorak/QWERTY, hold = Magic layer
};

#define A_HRM LSFT_T(KC_A)
#define O_HRM LCTL_T(KC_O)
#define E_HRM LGUI_T(KC_E)
#define U_HRM LALT_T(KC_U)
#define H_HRM RALT_T(KC_H)
#define T_HRM RGUI_T(KC_T)
#define N_HRM RCTL_T(KC_N)
#define S_HRM RSFT_T(KC_S)

#define MEH_LSFT(kc) LSFT(LALT(kc))
#define HYPER(kc) HYPR(kc)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_moonlander(
        KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,           KC_NO, KC_F6,   KC_F7,                 KC_F8,                 KC_F9,                 KC_F10,                KC_EQL,
        KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_NO,           KC_NO, KC_F,    KC_G,                  KC_C,                  KC_R,                  KC_L,                  KC_PLUS,
        KC_GRV,  A_HRM,   O_HRM,   E_HRM,   U_HRM,   KC_I,    KC_NO,           KC_NO, KC_D,    H_HRM,                 T_HRM,                 N_HRM,                 S_HRM,                 KC_MINS,
        MAGIC_TG, KC_SCLN, KC_Q,     KC_J,    KC_K,    KC_X,                              KC_B,    KC_M,                  KC_W,                  KC_V,                  KC_Z,                  KC_UNDS,
        KC_NO,   KC_NO,   KC_NO,   TO(BASE), KC_DOWN, KC_UP,                    LT(SYMBOL_LAYER, KC_END), LT(NAV_LAYER, KC_ENT), KC_BSPC, KC_NO, KC_NO, KC_NO,
                                            LT(NUMBER_LAYER, KC_SPC), LT(MOUSE_LAYER, KC_HOME), LGUI(KC_SPC),   KC_NO, KC_NO, KC_NO
    ),

    [NAV_LAYER] = LAYOUT_moonlander(
        MEH_LSFT(KC_MINS), MEH_LSFT(KC_B), MEH_LSFT(KC_F), MEH_LSFT(KC_SLSH), MEH_LSFT(KC_EQL), KC_NO, KC_NO,           KC_NO, LALT(KC_BSPC), KC_NO,          KC_NO,          MEH_LSFT(KC_G), MEH_LSFT(KC_C), KC_NO,
        KC_NO,             MS_WHLL,        MS_WHLD,        MS_WHLU,           MS_WHLR,         KC_NO, KC_NO,           KC_NO, MEH_LSFT(KC_M), LCTL(LSFT(KC_TAB)), KC_UP,     LCTL(KC_TAB),  MEH_LSFT(KC_L), MEH_LSFT(KC_R),
        KC_APP,            LALT(KC_LEFT),  LALT(KC_DOWN),  LALT(KC_UP),       LALT(KC_RGHT),   LALT(KC_I), KC_NO,      KC_NO, KC_NO,          KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_NO,          KC_APP,
        KC_NO,             KC_NO,          KC_NO,          KC_NO,             KC_NO,           KC_NO,                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,             KC_NO,          KC_NO,          TO(BASE),          KC_PGDN,         KC_PGUP,                 KC_TRNS,        KC_TAB,         KC_DEL,         KC_NO,          KC_NO,          KC_NO,
                                                                                        KC_LSFT, KC_NO, KC_NO,       KC_NO, KC_NO, KC_NO
    ),

    [MOUSE_LAYER] = LAYOUT_moonlander(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO, KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        QK_BOOT,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO, LGUI(LSFT(KC_Z)), LGUI(KC_V), LGUI(KC_C), LGUI(KC_X), LGUI(KC_Z),    KC_NO,
        KC_NO,   KC_LGUI, KC_LALT, KC_MS_BTN2, KC_MS_BTN1, KC_MS_BTN3, KC_NO,     KC_NO, KC_MS_BTN1,   KC_MS_BTN1,   KC_MS_BTN3,   KC_MS_BTN2,   KC_NO,        KC_NO,
        KC_NO,   KC_NO,   MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,                                   MS_WHLR,      MS_WHLU,      MS_WHLD,      MS_WHLL,      KC_NO,        KC_NO,
        KC_NO,   KC_NO,   KC_NO,   TO(BASE),KC_NO,   KC_NO,                    KC_TRNS,       KC_NO,        KC_TRNS,       KC_NO,        KC_NO,        KC_NO,
                                            KC_NO,   KC_NO,   KC_NO,           KC_NO, KC_NO, KC_NO
    ),

    [SYMBOL_LAYER] = LAYOUT_moonlander(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NO,           KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_RALT, KC_NO,   KC_NO,
        KC_NO,   KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, KC_NO,           KC_NO, KC_NO,   KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT, KC_NO,
        KC_NO,   KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   TO(BASE),KC_NO,   KC_NO,                    KC_NO,   KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO,
                                            KC_LPRN, KC_RPRN, KC_UNDS,         KC_NO, KC_NO, KC_NO
    ),

    [NUMBER_LAYER] = LAYOUT_moonlander(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU,
        KC_NO,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_NO,           KC_NO, KC_DOT,  KC_7,    KC_8,    KC_9,    KC_PLUS, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO, KC_0,    KC_4,    KC_5,    KC_6,    KC_MINS, KC_NO,
        KC_NO,   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,                                  KC_DOT,  KC_1,    KC_2,    KC_3,    KC_UNDS, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   TO(BASE),KC_NO,   KC_NO,                    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                            KC_TRNS, KC_NO,   KC_NO,           KC_NO, KC_NO, KC_NO
    ),

    [FUNCTION_LAYER] = LAYOUT_moonlander(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,           KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, KC_NO,           KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_RALT, KC_NO,   KC_NO,
        KC_NO,   KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, KC_NO,           KC_NO, KC_NO,   KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT, KC_NO,
        KC_NO,   KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_MPLY,                                  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   TO(BASE),KC_NO,   KC_NO,                    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                            KC_APP,  KC_BSPC, KC_DEL,          KC_NO, KC_NO, KC_NO
    ),

    [MAGIC_LAYER] = LAYOUT_moonlander(
        QK_BOOT, KC_BRID, KC_BRIU, KC_MPRV, KC_MNXT, KC_MPLY, KC_NO,           KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,   KC_NO,   QK_BOOT,
        QK_BOOT, RGB_SPI, RGB_SAI, RGB_HUI, RGB_VAI, RGB_TOG, KC_NO,           KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
        EE_CLR,  RGB_SPD, RGB_SAD, RGB_HUD, RGB_VAD, RGB_MOD, KC_NO,           KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EE_CLR,
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   TO(QWERTY_LAYER),
        KC_NO,   KC_NO,   KC_NO,   TO(BASE),KC_NO,   KC_NO,                    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                            HSV_0_245_245, HSV_74_255_206, HSV_152_255_255, KC_NO, KC_NO, KC_NO
    ),

    [QWERTY_LAYER] = LAYOUT_moonlander(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,           KC_NO, KC_TRNS, KC_TRNS,              KC_TRNS,              KC_TRNS,              KC_TRNS,              KC_EQL,
        KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,           KC_NO, KC_Y,    KC_U,                 KC_I,                 KC_O,                 KC_P,                 KC_PLUS,
        KC_TRNS, A_HRM,   LCTL_T(KC_S), LGUI_T(KC_D), LALT_T(KC_F), KC_G, KC_NO, KC_NO, KC_H, RALT_T(KC_J), RGUI_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN), KC_MINS,
        KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                      KC_N,    KC_M,                 KC_COMM,              KC_DOT,               KC_SLSH,              KC_UNDS,
        KC_NO,   KC_NO,   KC_NO,   TO(BASE),KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO,
                                            KC_TRNS, KC_TRNS, KC_TRNS,         KC_NO, KC_NO, KC_NO
    ),
};
// clang-format on

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
    JK_LCBR,
    MW_RCBR,
};

const uint16_t PROGMEM eu_combo[]   = {E_HRM, U_HRM, COMBO_END};
const uint16_t PROGMEM ht_combo[]   = {H_HRM, T_HRM, COMBO_END};
const uint16_t PROGMEM hc_combo[]   = {H_HRM, KC_C, COMBO_END};
const uint16_t PROGMEM dotu_combo[] = {KC_DOT, U_HRM, COMBO_END};
const uint16_t PROGMEM dotp_combo[] = {KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM gc_combo[]   = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM ui_combo[]   = {U_HRM, KC_I, COMBO_END};
const uint16_t PROGMEM dh_combo[]   = {KC_D, H_HRM, COMBO_END};
const uint16_t PROGMEM jk_combo[]   = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM mw_combo[]   = {KC_M, KC_W, COMBO_END};

combo_t key_combos[] = {
    [EU_ESC]     = COMBO(eu_combo, KC_ESC),
    [HT_BSPC]    = COMBO(ht_combo, KC_BSPC),
    [HC_SLASH]   = COMBO(hc_combo, KC_SLSH),
    [DOTU_BSLASH]= COMBO(dotu_combo, KC_BSLS),
    [DOTP_LBRC]  = COMBO(dotp_combo, KC_LBRC),
    [GC_RBRC]    = COMBO(gc_combo, KC_RBRC),
    [UI_LPRN]    = COMBO(ui_combo, KC_LPRN),
    [DH_RPRN]    = COMBO(dh_combo, KC_RPRN),
    [JK_LCBR]    = COMBO(jk_combo, KC_LCBR),
    [MW_RCBR]    = COMBO(mw_combo, KC_RCBR),
};
#endif

smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    return SMTD_RESOLUTION_UNHANDLED;
}

static uint16_t magic_tg_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAGIC_TG:
            if (record->event.pressed) {
                magic_tg_timer = timer_read();
                layer_on(MAGIC_LAYER);
            } else {
                layer_off(MAGIC_LAYER);
                if (timer_elapsed(magic_tg_timer) < TAPPING_TERM) {
                    // Tap: toggle between Dvorak (BASE) and QWERTY
                    if (layer_state_is(QWERTY_LAYER)) {
                        layer_move(BASE);
                    } else {
                        layer_move(QWERTY_LAYER);
                    }
                }
            }
            return false;
        case QK_MODS ... QK_MODS_MAX:
            // Mouse keys with modifiers work inconsistently across operating systems; make sure modifiers are applied first.
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
                rgblight_sethsv(0, 245, 245);
            }
            return false;
        case HSV_74_255_206:
            if (rawhid_state.rgb_control) {
                return false;
            }
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(74, 255, 206);
            }
            return false;
        case HSV_152_255_255:
            if (rawhid_state.rgb_control) {
                return false;
            }
            if (record->event.pressed) {
                rgblight_mode(1);
                rgblight_sethsv(152, 255, 255);
            }
            return false;
        case TYP_SECRT_1:
            if (record->event.pressed) {
                SEND_STRING(SECRET_STRING_1);
            }
            return false;
        case TYP_SECRT_2:
            if (record->event.pressed) {
                SEND_STRING(SECRET_STRING_2);
            }
            return false;
    }
    return true;
}

bool rgb_matrix_indicators_user(void) {
    if (rawhid_state.rgb_control) {
        return true;
    }
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case QWERTY_LAYER:
            // Distinct solid color for QWERTY (orange)
            rgb_matrix_set_color_all(0xFF, 0x55, 0x00);
            break;
        default:
            break;
    }
    return true;
}
