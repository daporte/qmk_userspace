/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

#include QMK_KEYBOARD_H
#include "num_word.h"
/* Key positions
  ╭─────────────────────╮ ╭─────────────────────╮
  │ LT4 LT3 LT2 LT1 LT0 │ │ RT0 RT1 RT2 RT3 RT4 │
  │ LM4 LM3 LM2 LM1 LM0 │ │ RM0 RM1 RM2 RM3 RM4 │
  │ LB4 LB3 LB2 LB1 LB0 │ │ RB0 RB1 RB2 RB3 RB4 │
  ╰───────╮ LH2 LH1 LH0 │ │ RH0 RH1 RH2 ╭───────╯
          ╰─────────────╯ ╰─────────────╯ */

/*#define COMBO_TERM_FAST 18*/
/*#define COMBO_TERM_SLOW 30*/
/*#define COMBO_TERM 18*/


enum combos {
    COMBO_QMARK,
    COMBO_EXCL,
    COMBO_LBKT,
    COMBO_RBKT,
    COMBO_LPAR,
    COMBO_RPAR,
    COMBO_LBRC,
    COMBO_RBRC,
    COMBO_AT,
    COMBO_HASH,
    COMBO_DLLR,
    COMBO_PRCNT,
    COMBO_GRAVE,
    COMBO_BSLH,
    COMBO_MINUS,
    COMBO_TILDE,
    COMBO_CARET,
    COMBO_EQUAL,
    COMBO_STAR,
    COMBO_AMPS,
    COMBO_PLUS,
    COMBO_UNDER,
    COMBO_FSLH,
    COMBO_PIPE,
};

const uint16_t PROGMEM combo_qmark[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM combo_excl[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_lbkt[] = {KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM combo_rbkt[] = {KC_C, KC_R, COMBO_END};
const uint16_t PROGMEM combo_lpar[] = {KC_H, KC_T, COMBO_END};
const uint16_t PROGMEM combo_rpar[] = {KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM combo_lbrc[] = {KC_M, KC_W, COMBO_END};
const uint16_t PROGMEM combo_rbrc[] = {KC_W, KC_V, COMBO_END};



/*// Vertical combos - left hand*/
const uint16_t PROGMEM combo_at[] = {KC_COMM, KC_O, COMBO_END};
const uint16_t PROGMEM combo_hash[] = {KC_DOT, KC_E, COMBO_END};
const uint16_t PROGMEM combo_dllr[] = {KC_P, KC_U, COMBO_END};
const uint16_t PROGMEM combo_prcnt[] = {KC_Y, KC_I, COMBO_END};

const uint16_t PROGMEM combo_grave[] = {KC_O, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_bslh[] = {KC_E, KC_J, COMBO_END};
const uint16_t PROGMEM combo_minus[] = {KC_U, KC_K, COMBO_END};
const uint16_t PROGMEM combo_tilde[] = {KC_I, KC_X, COMBO_END};

// Vertical combos - right hand
const uint16_t PROGMEM combo_caret[] = {KC_F, KC_D, COMBO_END};
const uint16_t PROGMEM combo_equal[] = {KC_G, KC_H, COMBO_END};
const uint16_t PROGMEM combo_star[] = {KC_C, KC_T, COMBO_END};
const uint16_t PROGMEM combo_amps[] = {KC_R, KC_N, COMBO_END};

const uint16_t PROGMEM combo_plus[] = {KC_D, KC_B, COMBO_END};
const uint16_t PROGMEM combo_under[] = {KC_H, KC_M, COMBO_END};
const uint16_t PROGMEM combo_fslh[] = {KC_T, KC_W, COMBO_END};
const uint16_t PROGMEM combo_pipe[] = {KC_N, KC_V, COMBO_END};

/*const uint16_t PROGMEM combo_lalt[] = {KC_P0, KC_P12, COMBO_END};*/

combo_t key_combos[] = {
    [COMBO_QMARK] = COMBO(combo_qmark, KC_QUES),
    [COMBO_EXCL] = COMBO(combo_excl, KC_EXLM),
    [COMBO_LBKT] = COMBO(combo_lbkt, KC_LBRC),
    [COMBO_RBKT] = COMBO(combo_rbkt, KC_RBRC),
    [COMBO_LPAR] = COMBO(combo_lpar, KC_LPRN),
    [COMBO_RPAR] = COMBO(combo_rpar, KC_RPRN),
    [COMBO_LBRC] = COMBO(combo_lbrc, KC_LCBR),
    [COMBO_RBRC] = COMBO(combo_rbrc, KC_RCBR),
    [COMBO_AT] = COMBO(combo_at, KC_AT),
    [COMBO_HASH] = COMBO(combo_hash, KC_HASH),
    [COMBO_DLLR] = COMBO(combo_dllr, KC_DLR),
    [COMBO_PRCNT] = COMBO(combo_prcnt, KC_PERC),
    [COMBO_GRAVE] = COMBO(combo_grave, KC_GRV),
    [COMBO_BSLH] = COMBO(combo_bslh, KC_BSLS),
    [COMBO_MINUS] = COMBO(combo_minus, KC_MINS),
    [COMBO_TILDE] = COMBO(combo_tilde, KC_TILD),
    [COMBO_CARET] = COMBO(combo_caret, KC_CIRC),
    [COMBO_EQUAL] = COMBO(combo_equal, KC_EQL),
    [COMBO_STAR] = COMBO(combo_star, KC_ASTR),
    [COMBO_AMPS] = COMBO(combo_amps, KC_AMPR),
    [COMBO_PLUS] = COMBO(combo_plus, KC_PLUS),
    [COMBO_UNDER] = COMBO(combo_under, KC_UNDS),
    [COMBO_FSLH] = COMBO(combo_fslh, KC_SLSH),
    [COMBO_PIPE] = COMBO(combo_pipe, KC_PIPE),
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [L_BASE] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, KC_QUOTE, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_DEL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_ESC, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_SLSH,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, NUMWORD,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        LSFT_T(KC_BSPC), LCTL_T(KC_TAB), MO(L_NUMBERS), QK_UNDERGLOW_VALUE_UP, KC_SPC, RALT_T(KC_ENT)
        //`--------------------------'  `--------------------------'

        ),

    [L_NUMBERS] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TAB, XXXXXXX, XXXXXXX, KC_K, KC_J, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_ESC, KC_6, KC_4, KC_0, KC_2, XXXXXXX, XXXXXXX, KC_3, KC_1, KC_5, KC_7, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_LSFT, XXXXXXX, XXXXXXX, KC_G, KC_8, XXXXXXX, XXXXXXX, KC_9, XXXXXXX, XXXXXXX, XXXXXXX, NUMWORD,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_BSPC, KC_TAB, KC_LCTL, MO(L_NUMBERS), KC_SPC, KC_ENT
        //`--------------------------'  `--------------------------'
    /*    ),*/
    /**/
    /*[2] = LAYOUT_split_3x6_3(*/
    /*    //,-----------------------------------------------------.                    ,-----------------------------------------------------.*/
    /*    KC_TAB, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,*/
    /*    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|*/
    /*    KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,*/
    /*    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|*/
    /*    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,*/
    /*    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|*/
    /*    KC_LGUI, KC_SPC, MO(3), _______, KC_ENT, KC_RALT*/
    /*    //`--------------------------'  `--------------------------'*/
    /*    ),*/
    /**/
    /*[3] = LAYOUT_split_3x6_3(*/
    /*    //,-----------------------------------------------------.                    ,-----------------------------------------------------.*/
    /*    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/
    /*    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|*/
    /*    RM_TOGG, RM_HUEU, RM_SATU, RM_VALU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/
    /*    //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|*/
    /*    RM_NEXT, RM_HUED, RM_SATD, RM_VALD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/
    /*    //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|*/
    /*    KC_LGUI, KC_SPC, _______, _______, KC_ENT, KC_RALT*/
    /*    //`--------------------------'  `--------------------------'*/
        )};

