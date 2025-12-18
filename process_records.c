/* Copyright 2021 Joshua T.
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
#include "process_records.h"
#include "num_word.h"
#include "custom_keycodes.h"

// Custom keycode for momentary Base layer with Ctrl held
//
extern MidiDevice midi_device;


uint8_t mod_state;


__attribute__ ((weak))
bool process_record_user_kb(uint16_t keycode, keyrecord_t *record) {
    return true;
}

// Runs for each key down or up event.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Returning true here will cause QMK to continue handling the key normally.
    // Returning false indicates that we've handled everything the keycode should do, and QMK
    // should not continue handling the keypress.
    //
    // NOTE: There is also a process_record_kb function that can be defined in the keyboard-
    // specific code. This allows the keyboard to have its own process_record function.
    // This is supposed to be "higher" than the user function, meaning the kb function
    // is shared for all keymaps for the keyboard.
    //
    // For this reason, I add my own function, called process_record_user_kb, and at the end
    // of this function, I defer to that one if it exists.
    // return process_record_user(keycode, record);


    // Custom keycode / function handling, based on the core function
    // process_record_quantum
    // https://github.com/qmk/qmk_firmware/blob/master/quantum/quantum.c

/*    if (!(*/
/*#ifdef USER_CAPS_WORD_ENABLE*/
/*        process_record_caps_word(keycode, record) &&*/
/*#endif*/
/*#ifdef USER_MOUSE_JIGGLE_ENABLE*/
/*        process_record_mouse_jiggle(keycode, record) &&*/
/*#endif*/
/*#ifdef USER_NUM_WORD_ENABLE*/
    /*process_record_num_word(keycode, record) &&*/
/*#endif*/
/*#ifdef USER_SECRETS_ENABLE*/
/*        process_record_secrets(keycode, record) &&*/
/*#endif*/
/*#ifdef USER_SUPER_ALT_TAB_ENABLE*/
/*        process_record_super_alt_tab(keycode, record) &&*/
/*#endif*/
/*        true)) {*/
/*        return false;*/
/*    }*/
/**/

    /*// Miscellaneous keycode handling*/
    /*mod_state = get_mods();*/
    /**/
    /*switch(keycode)*/
    /*{*/
    /*    case QK_MAKE: {*/
    /*        if (record->event.pressed)*/
    /*            SEND_STRING("qmk compile --keyboard " QMK_KEYBOARD " --keymap " QMK_KEYMAP);*/
    /*        return false;*/
    /*    }*/
    /*    case QK_FLSH: {*/
    /*        if (record->event.pressed) {*/
    /*            SEND_STRING("qmk flash --keyboard " QMK_KEYBOARD " --keymap " QMK_KEYMAP);*/
    /*        }*/
    /*        return false;*/
    /*    }*/
    /*    case QK_VERS: {*/
    /*        if (record->event.pressed) {*/
    /*            SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);*/
    /*        }*/
    /*        return false;*/
    /*    }*/
    /*    case PRG_EQ: {*/
    /*        if (record->event.pressed) {*/
    /*            SEND_STRING("==");*/
    /*        }*/
    /*        return false;*/
    /*    }*/
    /*    case PRG_NE: {*/
    /*        if (record->event.pressed) {*/
    /*            SEND_STRING("!=");*/
    /*        }*/
    /*        return false;*/
    /*    }*/
    /*    case PRG_GEQ: {*/
    /*        if (record->event.pressed) {*/
    /*            SEND_STRING(">=");*/
    /*        }*/
    /*        return false;*/
    /*    }*/
    /*    case PRG_LEQ: {*/
    /*        if (record->event.pressed) {*/
    /*            SEND_STRING("<=");*/
    /*        }*/
    /*        return false;*/
    /*    }*/
    /*    case PRG_ARR: {*/
    /*        if (record->event.pressed) {*/
    /*            SEND_STRING("=>");*/
    /*        }*/
    /*        return false;*/
    /*    }*/
    /**/
    /*    case PS_ITEM: {*/
    /*        if (record->event.pressed) {*/
    /*            SEND_STRING("$_");*/
    /*        }*/
    /*        return false;*/
    /*    }*/
    /*    case FS_PIPE: {*/
    /*        if (record->event.pressed) {*/
    /*            SEND_STRING("|>");*/
    /*        }*/
    /*        return false;*/
    /*    }*/
    /*    case FS_ARR: {*/
    /*        if (record->event.pressed) {*/
    /*            SEND_STRING("->");*/
    /*        }*/
    /*        return false;*/
    /*    }*/
    /*    case SHEBANG: {*/
    /*        if (record->event.pressed) {*/
    /*            SEND_STRING("#!");*/
    /*        }*/
    /*        return false;*/
    /*    }*/
    /*}*/
    // BASE_CTRL_HOLD: Debug - just switch layer while holding, with LED indication
    // Tap for letter, hold for momentary layer + modifier
    if (keycode == LT(0, KC_F22)) {
        if (record->event.pressed) {
             if (record->tap.count && record->event.pressed) {
                //tap_code(MI_C3); // Intercept tap function to send Ctrl-C
                // midi_send_cc(&midi_device, midi_config.channel, 60, 127);
                midi_send_noteon(&midi_device, midi_config.channel, 61, midi_config.velocity);
            } else if (record->event.pressed) {
                //tap_code16(KC_V); // Intercept hold function to send Ctrl-V
                layer_on(L_BASE_TOGGLE);
                register_code(KC_LSFT);
            }
            return false;
        } else {
            if (!(record->tap.count && !record->tap.interrupted)) {
                layer_off(L_BASE_TOGGLE);
                unregister_code(KC_LSFT);
            }
            midi_send_noteoff(&midi_device, midi_config.channel, 61, 0);
        }
        return false;
    }

    if (keycode == LT(0, KC_F23)) {
        if (record->event.pressed) {
             if (record->tap.count && record->event.pressed) {
                //tap_code(MI_C3); // Intercept tap function to send Ctrl-C
                // midi_send_cc(&midi_device, midi_config.channel, 60, 127);
                midi_send_noteon(&midi_device, midi_config.channel, 62, midi_config.velocity);
            } else if (record->event.pressed) {
                //tap_code16(KC_V); // Intercept hold function to send Ctrl-V
                layer_on(L_BASE_TOGGLE);
                register_code(KC_LCTL);
            }
            return false;
        } else {
            if (!(record->tap.count && !record->tap.interrupted)) {
                layer_off(L_BASE_TOGGLE);
                unregister_code(KC_LCTL);
            }
            midi_send_noteoff(&midi_device, midi_config.channel, 62, 0);
        }
        return false;

    }

    if (keycode == LT(0, KC_NO)) {
        if (record->event.pressed) {
             if (record->tap.count && record->event.pressed) {
                //tap_code(MI_C3); // Intercept tap function to send Ctrl-C
                // midi_send_cc(&midi_device, midi_config.channel, 60, 127);
                midi_send_noteon(&midi_device, midi_config.channel, 60, midi_config.velocity);
            } else if (record->event.pressed) {
                //tap_code16(KC_V); // Intercept hold function to send Ctrl-V
                layer_on(L_BASE_TOGGLE);
                register_code(KC_LALT);
            }
            return false;
        } else {
            if (!(record->tap.count && !record->tap.interrupted)) {
                layer_off(L_BASE_TOGGLE);
                unregister_code(KC_LALT);
            }
            midi_send_noteoff(&midi_device, midi_config.channel, 60, 0);
        }
        return false;
    }


    if (!process_record_num_word(keycode, record)) {
        return false;
    }




    // Check for G, J, K in the numbers layer
    if (record->event.pressed && (keycode == KC_G || keycode == KC_J || keycode == KC_K)) {
        tap_code(keycode);  // Manually type the key
        disable_num_word(); // Disable num word
        return false;       // Stop further processing
    }

    if (keycode == COMBO_LAYER_TOGGLE && record->event.pressed) {
        // Toggle combos first
        /*tap_code16(QK_COMBO_TOGGLE);*/
        combo_toggle();

        // Small delay to ensure combo toggle is processed
        wait_ms(10);

        // Then toggle layer
        layer_invert(L_BASE_NOMODS);

        return false;
    }
    if (keycode == HWNZ) {
        if (record->event.pressed) {
            // Press all keys simultaneously
            register_code(KC_H);
            register_code(KC_W);
            register_code(KC_N);
            register_code(KC_Z);
            register_code(KC_SLASH);  // if you want the slash too

            // Optional: small delay if needed
            wait_ms(10);

            // Release all keys
            unregister_code(KC_H);
            unregister_code(KC_W);
            unregister_code(KC_N);
            unregister_code(KC_Z);
            unregister_code(KC_SLASH);
        }
    return false;  // Skip further processing
}


    return process_record_user_kb(keycode, record);
}
