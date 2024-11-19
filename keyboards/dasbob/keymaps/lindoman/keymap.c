#include QMK_KEYBOARD_H
#include "keymap_uk.h"
#include "keymap_us_international.h"
//#include "features/layer_lock.h"

/* 
  This file is the keymap for the lindoman-dasbob layout
  First written 24th March 2023 for the ferris 32 key keyboard
  Adapted from the Ergodox-EZ configurator file
  Updated to DASBOB 34 key layout October 2023

*/ 

 enum custom_keycodes {
  // not using layer lock feature
  //LLOCK = SAFE_RANGE,
  SMTD_KEYCODES_BEGIN = SAFE_RANGE,
  //CKC_Z, // reads as C(ustom) + KC_A, but you may give any name here
  //CKC_X,
  //CKC_SLA,
  //CKC_DOT,
  SMTD_KEYCODES_END,
  ST_MACRO_ROUND_BRACKETS,
  ST_MACRO_SQUARE_BRACKETS,
  ST_MACRO_CURLY_BRACKETS,
  SWITCH_LAYER_COL,
  SWITCH_LAYER_QWERT,
};

// new feature to experiment with more stable home row mods.
// Need to include after custom_keycodes according to the documentation
// https://github.com/stasmarkin/sm_td
// #include "features/sm_td.h"

enum unicode_names {
    U_GER_SS,
    
    U_GER_O_UC,
    U_GER_O_LC,

    U_GER_A_UC,
    U_GER_A_LC,

    U_GER_U_UC,
    U_GER_U_LC
};

const uint32_t PROGMEM unicode_map[] = {
    [U_GER_SS]   = 0x00df, // ß

    [U_GER_O_UC] = 0x00d6, // Ö
    [U_GER_O_LC] = 0x00f6, // ö

    [U_GER_A_UC] = 0x00c4, // Ä
    [U_GER_A_LC] = 0x00e4, // ä

    [U_GER_U_UC] = 0x00dC, // Ü
    [U_GER_U_LC] = 0x00fC, // ü
};

enum tap_dance_codes {
  dance_lgui,
  dance_f5,
  dance_scrl,
  dance_pscr,
  dance_insert,
  dance_notkey,
  dance_numlock,
};

// tap dance constants for number of taps
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

enum lindoman_layers {
    qwert = 0,
    col,
    navig,
    symbl,
    calcu,
    media,
    wasd,
    ger
};

// define combos
enum combos {
  // capsword functionality turned on by hitting F and J on the home row 
  FJ_CAPSWORD, 
  // left hand save combo, tied to S and G keys
  SG_SAVE,
  // left hand cut combo, tied to F and X keys
  CV_CUT,
// german characters using unicode
// GER_LC_U,
// GER_UC_U,
// GER_LC_O,
// GER_UC_O,
// GER_LC_A,
// GER_UC_A,
// GER_SS,
  CMB_MAC_BRK_S,
  CMB_MAC_BRK_R,
  CMB_MAC_BRK_C,
  SWAP_Q2C,
  SWAP_C2Q,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH;

// FJ capsword combo declaration
const uint16_t PROGMEM fj_combo[] = {KC_F, KC_J, COMBO_END};
// handy left hand "Ctrl-S" combo
const uint16_t PROGMEM c_sg_save[] = {KC_S, KC_G, COMBO_END};
// handy left hand "Ctrl-X" combo
const uint16_t PROGMEM c_cv_cut[]  = {KC_C, KC_V, COMBO_END};
// German character combo declarations
// const uint16_t PROGMEM c_gerlc_u[] = {KC_U, KC_I, KC_O, COMBO_END};
// const uint16_t PROGMEM c_geruc_u[] = {KC_U, KC_I, KC_O, KC_F, COMBO_END};
// const uint16_t PROGMEM c_gerlc_o[] = {KC_I, KC_O, KC_P, COMBO_END};
// const uint16_t PROGMEM c_geruc_o[] = {KC_I, KC_O, KC_P, KC_F, COMBO_END};
// const uint16_t PROGMEM c_gerlc_a[] = {KC_A, KC_S, KC_D, COMBO_END};
// const uint16_t PROGMEM c_geruc_a[] = {KC_A, KC_S, KC_D, KC_J, COMBO_END};
// const uint16_t PROGMEM c_ger_ss[]  = {KC_S, KC_D, KC_F, COMBO_END};

// Bracket combos
const uint16_t PROGMEM c_mac_brk_s[] = {KC_LBRC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM c_mac_brk_r[] = {KC_LPRN, KC_RPRN, COMBO_END};
const uint16_t PROGMEM c_mac_brk_c[] = {KC_LCBR, KC_RCBR, COMBO_END};

// colemak training swap keys
const uint16_t PROGMEM c_qwert_2_col[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM c_col_2_qwert[] = {KC_Q, KC_W, KC_F, KC_P, COMBO_END};

combo_t key_combos[] = {
  [FJ_CAPSWORD] = COMBO(fj_combo, CW_TOGG),
  [SG_SAVE] = COMBO(c_sg_save, LCTL(KC_S)),
  [CV_CUT] = COMBO(c_cv_cut, LCTL(KC_X)),
//   German letter combos, if combos are required instead of layers
//   [GER_LC_U] = COMBO(c_gerlc_u, U_GER_U_LC),
//   [GER_UC_U] = COMBO(c_geruc_u, U_GER_U_UC),
//   [GER_LC_O] = COMBO(c_gerlc_o, U_GER_O_LC),
//   [GER_UC_O] = COMBO(c_geruc_o, U_GER_O_UC),
//   [GER_LC_A] = COMBO(c_gerlc_a, U_GER_A_LC),
//   [GER_UC_A] = COMBO(c_geruc_a, U_GER_A_UC),
//   [GER_SS]   = COMBO(c_ger_ss , U_GER_SS),
// Bracket combos for easy coding:
  [CMB_MAC_BRK_S] = COMBO(c_mac_brk_s, ST_MACRO_SQUARE_BRACKETS),
  [CMB_MAC_BRK_R] = COMBO(c_mac_brk_r, ST_MACRO_ROUND_BRACKETS),
  [CMB_MAC_BRK_C] = COMBO(c_mac_brk_c, ST_MACRO_CURLY_BRACKETS),
  [SWAP_Q2C] = COMBO(c_qwert_2_col, SWITCH_LAYER_COL),
  [SWAP_C2Q] = COMBO(c_col_2_qwert, SWITCH_LAYER_QWERT),

};

//definitions to save some space:
#define MY_Z MT(MOD_LSFT, KC_Z)
#define MY_X MT(MOD_LCTL, KC_X)
#define MY_COM MT(MOD_LALT, UK_COMM)
#define MY_DOT MT(MOD_RCTL, UK_DOT)
#define MY_SLA MT(MOD_RSFT, UK_SLSH)
#define MY_TAB MT(MOD_LSFT, KC_TAB)
#define MY_Q MT(MOD_LGUI, KC_Q)
#define C__LEFT LCTL(KC_LEFT)
#define C_RIGHT LCTL(KC_RIGHT)
#define C_A_DEL LCA(KC_DELETE)
#define CAL_LEFT MT(MOD_LCTL, KC_LEFT)
#define CAL_DOWN MT(MOD_LALT, KC_DOWN)
// unicode map characters:
#define UC_G_A UP(U_GER_A_LC, U_GER_A_UC)
#define UC_G_O UP(U_GER_O_LC, U_GER_O_UC)
#define UC_G_U UP(U_GER_U_LC, U_GER_U_UC)
#define UC_G_S UM(U_GER_SS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ENT│
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │___├───┐           ┌───┤___│
      *           └───┤CLC├───┐   ┌───┤SYM├───┘
      *               └───│NAV│   │SPC├───┘
      *                   └───┘   └───┘
      */


    [qwert] = LAYOUT_split_3x5_3
    (
        KC_Q,  KC_W,   KC_E,     KC_R,       KC_T,               KC_Y,       KC_U,       KC_I,    KC_O,   KC_P,
        KC_A,  KC_S,   KC_D,     KC_F,       KC_G,               KC_H,       KC_J,       KC_K,    KC_L,   KC_ENTER,
        MY_Z,  MY_X,  KC_C,     KC_V,       KC_B,               KC_N,       KC_M,       KC_COMM, MY_DOT,MY_SLA,
                       KC_NO,    TT(calcu),  TT(navig),          KC_SPACE ,  OSL(symbl), KC_NO
    ),
    [col] = LAYOUT_split_3x5_3
    (
        KC_Q,  KC_W,   KC_F,     KC_P,       KC_B,               KC_J,       KC_L,       KC_U,    KC_Y,   KC_ENTER,
        KC_A,  KC_R,   KC_S,     KC_T,       KC_G,               KC_M,       KC_N,       KC_E,    KC_I,   KC_O,
        MY_Z, MY_X,  KC_C,     KC_D,       KC_V,               KC_K,       KC_H,       KC_COMM, MY_DOT,MY_SLA,
                       KC_TRNS,  TT(calcu),  TT(navig),          KC_SPACE ,  OSL(symbl), KC_TRNS
    ),
    [navig] = LAYOUT_split_3x5_3
	(
		OSM(MOD_LGUI),LWIN(KC_L),LWIN(KC_E), LALT(KC_F4), TD(dance_f5),      KC_DELETE, C__LEFT  , KC_UP  , C_RIGHT , KC_BSPC ,  
		LCTL(KC_A)   ,LCTL(KC_S),KC_LSFT   , KC_LCTL    , C_A_DEL     ,      KC_HOME  , KC_LEFT  , KC_DOWN, KC_RIGHT, KC_END  ,		
		LCTL(KC_Z)   ,LCTL(KC_X),LCTL(KC_C), LCTL(KC_V) , TO(media)   ,      OSL(ger) , TO(wasd) , KC_RALT, KC_RCTL , KC_ENTER,  
		                         KC_TRNS   , TO(qwert)  , TO(qwert)   ,      KC_TRNS  , TO(qwert), KC_TRNS
	), 
	[symbl] = LAYOUT_split_3x5_3
	(
		UK_EXLM, UK_DQUO, UK_PERC    ,UK_DLR     ,UK_PND     ,      UK_CIRC    ,      UK_AMPR,UK_ASTR,KC_LPRN,KC_RPRN,
		UK_PIPE, UK_QUOT, KC_LCBR    ,KC_RCBR    ,UK_MINS    ,      TD(dance_notkey), KC_LBRC,KC_RBRC,UK_HASH,UK_SCLN,		
		UK_BSLS, UK_AT  , KC_NO      ,UK_EQL     ,UK_PLUS    ,      TD(dance_numlock),UK_UNDS,UK_SLSH,UK_TILD,UK_COLN,
		                  KC_TRNS,    TO(qwert)  ,TO(qwert)  ,      KC_TRNS    ,      TO(qwert), KC_TRNS
	), 
	[calcu] = LAYOUT_split_3x5_3
	(
		KC_ESCAPE,C__LEFT ,KC_UP   ,C_RIGHT ,KC_NO   ,      KC_DELETE, UK_7, UK_8, UK_9, KC_BSPC ,
		KC_TAB   ,CAL_LEFT,CAL_DOWN,KC_RIGHT,UK_MINS ,      UK_DOT   , UK_4, UK_5, UK_6, KC_ENTER,
		KC_LSFT  ,KC_LCTL ,KC_LALT ,UK_EQL  ,UK_PLUS ,      UK_ASTR  , UK_1, UK_2, UK_3, UK_SLSH ,
		                   KC_TRNS, TO(qwert) ,KC_SPACE,    TO(qwert), UK_0, KC_TRNS
	),
	[media] = LAYOUT_split_3x5_3
	(
		KC_ESCAPE, KC_NO     ,KC_MS_UP  ,KC_NO      , KC_NO    ,     KC_NO            ,KC_NO          ,KC_MS_WH_UP  , KC_NO     ,KC_NO,
		KC_NO    , KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT, KC_NO    ,     KC_MS_WH_LEFT    ,KC_MS_BTN1     ,KC_MS_BTN3   , KC_MS_BTN2,KC_MS_WH_RIGHT,  
		KC_NO    , KC_NO     ,KC_NO     ,KC_NO      , KC_NO    ,     KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MS_WH_DOWN, KC_NO     ,KC_AUDIO_MUTE,  		
		                      KC_TRNS,   TO(qwert)  , TO(qwert),     KC_TRNS          ,TO(qwert),      KC_TRNS
	), 

	[wasd] = LAYOUT_split_3x5_3
	(
		KC_ESCAPE, KC_Q , KC_W , KC_E , KC_R       ,      KC_TRNS  , KC_TRNS  , KC_TRNS, KC_TRNS, KC_TRNS,  
		KC_LSFT  , KC_A , KC_S , KC_D , KC_F       ,      KC_TRNS  , KC_TRNS  , KC_TRNS, KC_TRNS, KC_TRNS,  		
		KC_LCTL  , KC_Z , KC_X , KC_C , KC_V       ,      KC_TRNS  , KC_TRNS  , KC_TRNS, KC_TRNS, KC_TRNS,  
	                      KC_TRNS,TO(qwert),KC_SPACE,     TO(qwert), TO(qwert), KC_TRNS		
	),
    // layers used for german letters - alternative to combos
	[ger] = LAYOUT_split_3x5_3
	(
		KC_NO    , KC_NO      , KC_NO, KC_NO, KC_NO,             KC_NO, UC_G_U    , KC_NO, UC_G_O    , KC_NO    ,  
		UC_G_A   , UC_G_S     , KC_NO, KC_NO, KC_NO,             KC_NO, KC_NO     , KC_NO, KC_NO     , KC_NO    ,  	
		KC_LSFT  , KC_NO      , KC_NO, KC_NO, KC_NO,             KC_NO, KC_NO     , KC_NO, KC_NO     , KC_RSFT,  		
		                       TO(qwert),TO(qwert),TO(qwert),    TO(qwert),TO(qwert),TO(qwert)
	), 
    /*
	[geru] = LAYOUT_split_3x5_3
	(
		KC_NO     , KC_NO     , KC_NO     , KC_NO, KC_NO,       KC_NO,UG_U_UC   , KC_NO, UG_O_UC    , KC_NO    , 
		UG_A_UC   , UG_SS     , KC_NO     , KC_NO, KC_NO,       KC_NO,KC_NO     , KC_NO, KC_NO      , KC_NO    ,  		
		TO(qwert) , KC_NO     , KC_NO     , KC_NO, KC_NO,       KC_NO,KC_NO     , KC_NO, KC_NO      , TO(qwert),  		
		                        TO(qwert) ,TO(qwert),TO(qwert),       TO(qwert),TO(qwert), TO(qwert)
	),
    */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {  
  // layer lock feature
  //if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
  // smtd feature (home row mods)
  //if (!process_smtd(keycode, record)) { return false; }

  switch (keycode) {
    case SWITCH_LAYER_COL:
    if (record->event.pressed) {
        set_single_persistent_default_layer(col);
    }
    break;

    case SWITCH_LAYER_QWERT:
        if (record->event.pressed) {
        set_single_persistent_default_layer(qwert);
    }
    break;

    case ST_MACRO_ROUND_BRACKETS:
    if (record->event.pressed) {
      // round brackets with line feeds and space
      SEND_STRING(
                   SS_LSFT(SS_TAP(X_9)) SS_DELAY(50) 
                   SS_LSFT(SS_TAP(X_0)) SS_DELAY(50) 
                   SS_TAP(X_LEFT)       SS_DELAY(50) 
                   SS_TAP(X_ENTER)      SS_DELAY(50)
                   SS_TAP(X_ENTER)      SS_DELAY(50)
                   SS_TAP(X_LEFT)       SS_DELAY(50)
                   SS_TAP(X_SPACE)      SS_DELAY(50)
                   SS_TAP(X_SPACE)
                );
    }
    break;

    case ST_MACRO_SQUARE_BRACKETS:
    if (record->event.pressed) {
      // round brackets with line feeds and space
      SEND_STRING(
                   SS_TAP(X_LBRC) SS_DELAY(50) 
                   SS_TAP(X_RBRC) SS_DELAY(50) 
                   SS_TAP(X_LEFT)       SS_DELAY(50) 
                   SS_TAP(X_ENTER)      SS_DELAY(50)
                   SS_TAP(X_ENTER)      SS_DELAY(50)
                   SS_TAP(X_LEFT)       SS_DELAY(50)
                   SS_TAP(X_SPACE)      SS_DELAY(50)
                   SS_TAP(X_SPACE)
                );
    }
    break;
    
    case ST_MACRO_CURLY_BRACKETS:
    if (record->event.pressed) {
      // round brackets with line feeds and space
      SEND_STRING(
                   SS_LSFT(SS_TAP(X_LBRC)) SS_DELAY(50) 
                   SS_LSFT(SS_TAP(X_RBRC)) SS_DELAY(50) 
                   SS_TAP(X_LEFT)       SS_DELAY(50) 
                   SS_TAP(X_ENTER)      SS_DELAY(50)
                   SS_TAP(X_ENTER)      SS_DELAY(50)
                   SS_TAP(X_LEFT)       SS_DELAY(50)
                   SS_TAP(X_SPACE)      SS_DELAY(50)
                   SS_TAP(X_SPACE)
                );
    }
    break;
  }
  return true;
}

// --------------------------------------------------------------------------
// ------------------------------------------------ CAPS WORD SETTNGS -------
// --------------------------------------------------------------------------

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS: // this allows minus sign to be typed and not turned into a capital e.g. for 'YYYY-MM-DD' use in Oracle SQL
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}


// ------------------------------------------------------------------------
// -------------------------------------- TAP DANCES ----------------------
// ------------------------------------------------------------------------

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

static tap dance_state[7];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}

// --------------------------------------------------------------------------------------------
// TAP DANCE LGUI -----------------------------------------------------------------------------
// Windows key on hold, otherwise Q

void on_dance_lgui(tap_dance_state_t *state, void *user_data);
void dance_lgui_finished(tap_dance_state_t *state, void *user_data);
void dance_lgui_reset(tap_dance_state_t *state, void *user_data);

void on_dance_lgui(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Q);
        tap_code16(KC_Q);
        tap_code16(KC_Q);
    }
    if(state->count > 3) {
        tap_code16(KC_Q);
    }
}

void dance_lgui_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_Q); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(KC_Q); register_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Q); register_code16(KC_Q);
    }
}

void dance_lgui_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_Q); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Q); break;
    }
    dance_state[0].step = 0;
}

// --------------------------------------------------------------------------------------------
// TAP DANCE 1 --------------------------------------------------------------------------------
// Double tap F5 (for SSMS execute) - otherwise LCTL

void on_dance_f5(tap_dance_state_t *state, void *user_data);
void dance_f5_finished(tap_dance_state_t *state, void *user_data);
void dance_f5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_f5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LCTL);
        tap_code16(KC_LCTL);
        tap_code16(KC_LCTL);
    }
    if(state->count > 3) {
        tap_code16(KC_LCTL);
    }
}

void dance_f5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_LCTL); break;
        case DOUBLE_TAP: register_code16(KC_F5); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LCTL); register_code16(KC_LCTL);
    }
}

void dance_f5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_LCTL); break;
        case DOUBLE_TAP: unregister_code16(KC_F5); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LCTL); break;
    }
    dance_state[1].step = 0;
}

// --------------------------------------------------------------------------------------------
// TAP DANCE 2 --------------------------------------------------------------------------------
// scroll lock on hold (otherwise UK_PND)
void on_dance_scrl(tap_dance_state_t *state, void *user_data);
void dance_scrl_finished(tap_dance_state_t *state, void *user_data);
void dance_scrl_reset(tap_dance_state_t *state, void *user_data);

void on_dance_scrl(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_PND);
        tap_code16(UK_PND);
        tap_code16(UK_PND);
    }
    if(state->count > 3) {
        tap_code16(UK_PND);
    }
}

void dance_scrl_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(UK_PND); break;
        case SINGLE_HOLD: register_code16(KC_SCRL); break;
        case DOUBLE_TAP: register_code16(UK_PND); register_code16(UK_PND); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_PND); register_code16(UK_PND);
    }
}

void dance_scrl_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(UK_PND); break;
        case SINGLE_HOLD: unregister_code16(KC_SCRL); break;
        case DOUBLE_TAP: unregister_code16(UK_PND); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_PND); break;
    }
    dance_state[2].step = 0;
}

// --------------------------------------------------------------------------------------------
// TAP DANCE 3 --------------------------------------------------------------------------------
// print screen on hold, otherwise UK_DLR
void on_dance_pscr(tap_dance_state_t *state, void *user_data);
void dance_pscr_finished(tap_dance_state_t *state, void *user_data);
void dance_pscr_reset(tap_dance_state_t *state, void *user_data);

void on_dance_pscr(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_DLR);
        tap_code16(UK_DLR);
        tap_code16(UK_DLR);
    }
    if(state->count > 3) {
        tap_code16(UK_DLR);
    }
}

void dance_pscr_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(UK_DLR); break;
        case SINGLE_HOLD: register_code16(KC_PSCR); break;
        case DOUBLE_TAP: register_code16(UK_DLR); register_code16(UK_DLR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_DLR); register_code16(UK_DLR);
    }
}

void dance_pscr_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(UK_DLR); break;
        case SINGLE_HOLD: unregister_code16(KC_PSCR); break;
        case DOUBLE_TAP: unregister_code16(UK_DLR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_DLR); break;
    }
    dance_state[3].step = 0;
}

// --------------------------------------------------------------------------------------------
// TAP DANCE 4 --------------------------------------------------------------------------------
// insert on hold, otherwise UK_PERC
void on_dance_insert(tap_dance_state_t *state, void *user_data);
void dance_insert_finished(tap_dance_state_t *state, void *user_data);
void dance_insert_reset(tap_dance_state_t *state, void *user_data);

void on_dance_insert(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_PERC);
        tap_code16(UK_PERC);
        tap_code16(UK_PERC);
    }
    if(state->count > 3) {
        tap_code16(UK_PERC);
    }
}

void dance_insert_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(UK_PERC); break;
        case SINGLE_HOLD: register_code16(KC_INSERT); break;
        case DOUBLE_TAP: register_code16(UK_PERC); register_code16(UK_PERC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_PERC); register_code16(UK_PERC);
    }
}

void dance_insert_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(UK_PERC); break;
        case SINGLE_HOLD: unregister_code16(KC_INSERT); break;
        case DOUBLE_TAP: unregister_code16(UK_PERC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_PERC); break;
    }
    dance_state[4].step = 0;
}

// --------------------------------------------------------------------------------------------
// TAP DANCE 5 --------------------------------------------------------------------------------
// UK_NOT ¬ on hold, otherwise UK_GRV (backtick) `
void on_dance_notkey(tap_dance_state_t *state, void *user_data);
void dance_notkey_finished(tap_dance_state_t *state, void *user_data);
void dance_notkey_reset(tap_dance_state_t *state, void *user_data);

void on_dance_notkey(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_GRV);
        tap_code16(UK_GRV);
        tap_code16(UK_GRV);
    }
    if(state->count > 3) {
        tap_code16(UK_GRV);
    }
}

void dance_notkey_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(UK_GRV); break;
        case SINGLE_HOLD: register_code16(UK_NOT); break;
        case DOUBLE_TAP: register_code16(UK_GRV); register_code16(UK_GRV); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_GRV); register_code16(UK_GRV);
    }
}

void dance_notkey_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(UK_GRV); break;
        case SINGLE_HOLD: unregister_code16(UK_NOT); break;
        case DOUBLE_TAP: unregister_code16(UK_GRV); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_GRV); break;
    }
    dance_state[5].step = 0;
}
// --------------------------------------------------------------------------------------------
// TAP DANCE 6 --------------------------------------------------------------------------------
// numlock on hold, otherwise UK_SLASH
void on_dance_numlock(tap_dance_state_t *state, void *user_data);
void dance_numlock_finished(tap_dance_state_t *state, void *user_data);
void dance_numlock_reset(tap_dance_state_t *state, void *user_data);

void on_dance_numlock(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(UK_SLSH);
        tap_code16(UK_SLSH);
        tap_code16(UK_SLSH);
    }
    if(state->count > 3) {
        tap_code16(UK_SLSH);
    }
}

void dance_numlock_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(UK_SLSH); break;
        case SINGLE_HOLD: register_code16(KC_NUM); break;
        case DOUBLE_TAP: register_code16(UK_SLSH); register_code16(UK_SLSH); break;
        case DOUBLE_SINGLE_TAP: tap_code16(UK_SLSH); register_code16(UK_SLSH);
    }
}

void dance_numlock_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(UK_SLSH); break;
        case SINGLE_HOLD: unregister_code16(KC_NUM); break;
        case DOUBLE_TAP: unregister_code16(UK_SLSH); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(UK_SLSH); break;
    }
    dance_state[6].step = 0;
}




tap_dance_action_t tap_dance_actions[] = {
        [dance_lgui] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_lgui, dance_lgui_finished, dance_lgui_reset),
        [dance_f5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_f5, dance_f5_finished, dance_f5_reset),
        [dance_scrl] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_scrl, dance_scrl_finished, dance_scrl_reset),
        [dance_pscr] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_pscr, dance_pscr_finished, dance_pscr_reset),
        [dance_insert] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_insert, dance_insert_finished, dance_insert_reset),
        [dance_notkey] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_notkey, dance_notkey_finished, dance_notkey_reset),
        [dance_numlock] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_numlock, dance_numlock_finished, dance_numlock_reset),
};




// smtd for home row mods:
/*
  
  CKC_Z,
  CKC_X,
  CKC_SLA,
  CKC_DOT,


void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_Z, KC_Z, KC_LSFT)
        SMTD_MT(CKC_X, KC_X, KC_LEFT_CTRL)
        SMTD_MT(CKC_SLA, UK_SLSH, KC_RSFT)
        SMTD_MT(CKC_DOT, UK_DOT, KC_RIGHT_CTRL)
    }
};
*/

// LED settings
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_0; }
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        static const char PROGMEM runqmk_logo[] = {0,0,0,0,152,152,152,152,152,152,24,24,24,
        152,152,24,24,24,152,152,24,24,152,152,24,24,24,152,152,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,127,127,13,13,29,63,103,64,0,63,127,96,96,96,127,63,0,0,127,127,7,12,56,
        127,127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,120,252,134,198,198,252,120,0,0,254,254,
        60,224,224,60,254,254,0,254,254,16,24,124,230,130,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,24,24,25,25,25,25,27,24,24,25,25,24,25,25,24,25,25,24,25,25,24,24,24,24,25,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0};


        oled_write_raw_P(runqmk_logo, sizeof(runqmk_logo));

        led_t led_usb_state = host_keyboard_led_state();
        oled_set_cursor(6, 3);
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUM") : PSTR(""), false);
        oled_set_cursor(6, 2);
        oled_write_P(PSTR("WPM: "), false);
        oled_write(get_u8_str(get_current_wpm(), '0'), false);
        oled_set_cursor(6, 0);
        oled_write_P(PSTR("by GroooveBob"), false);
            oled_set_cursor(6, 1);
            oled_write_P(PSTR("Layer: "), false);

    /*
        qwert = 0,
    navig,
    symbl,
    calcu,
    media,
    wasd,
    gerl,
    geru
    */
    
    switch (get_highest_layer(layer_state)) {
        case qwert:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Qwerty\n"), false);
            break;
        case navig:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Navig\n"), false);
            break;
        case symbl:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Symbol\n"), false);
            break;
        case calcu:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Calc\n"), false);
            break;
        case media:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Media\n"), false);
            break;
        case wasd:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Gaming\n"), false);
            break;
        case gerl:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("German l\n"), false);
            break;
        case geru:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("German U\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
        oled_set_cursor(6, 1);
        oled_write_ln_P(PSTR("Undefined"), false);
    }
    } else {
        static const char PROGMEM dasbob_logo[] = {
        // 'kblogo', 128x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x10, 0x20, 0x60, 0x40, 0x40, 0xd0, 0x90, 0xb0, 0xc0, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xf8, 0xf8, 0xfc, 0x3c, 0x1c, 0x1c, 0x1c, 0x3c, 0x38, 0x38, 0x78, 0x70, 0xf0, 
        0xe0, 0xc0, 0xd0, 0xb0, 0x78, 0x38, 0x38, 0x3c, 0x3c, 0x1c, 0x1c, 0x1c, 0x3c, 0x38, 0x38, 0x78, 
        0x78, 0xf0, 0xe0, 0xe0, 0xd0, 0xb0, 0x78, 0x78, 0x38, 0x3c, 0x3c, 0x1c, 0x1c, 0x1c, 0x3c, 0x38, 
        0x38, 0x38, 0x78, 0xf0, 0xf0, 0xe0, 0xc0, 0xb0, 0x70, 0x78, 0x38, 0x38, 0x3c, 0x1c, 0x1c, 0x1c, 
        0x3c, 0x3c, 0x38, 0x38, 0x78, 0xf0, 0xf0, 0xe0, 0xc0, 0xb0, 0xb0, 0x78, 0x38, 0x38, 0x3c, 0x1c, 
        0x1c, 0x1c, 0x1c, 0xfc, 0xf8, 0xf8, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x42, 0x86, 0x96, 0x14, 0x10, 0x00, 0x01, 0x00, 
        0x00, 0x00, 0x00, 0xc0, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0x70, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x0f, 0x3f, 0x7f, 0xbc, 0xc0, 0xe0, 0xf0, 0xf8, 0x78, 0x3e, 0x1e, 0x0f, 0x06, 
        0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3e, 0x7c, 0x78, 0xb0, 0xa0, 0xc0, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 
        0x0f, 0x06, 0x05, 0x03, 0x07, 0x0f, 0x0f, 0x1e, 0x3c, 0x78, 0x70, 0xa0, 0xc0, 0xe0, 0xf0, 0x78, 
        0x7c, 0x3e, 0x1f, 0x0e, 0x05, 0x01, 0x03, 0x07, 0x0f, 0x1e, 0x3c, 0x7c, 0x70, 0xb0, 0xc0, 0xe0, 
        0xf0, 0xf8, 0x7c, 0x3e, 0x1e, 0x0f, 0x06, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3e, 0x7c, 0x78, 0xb0, 
        0xc0, 0xe0, 0xf8, 0xff, 0x3f, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf9, 0x92, 0x93, 0x90, 0x39, 0x02, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x01, 0x07, 0x07, 0x0f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1e, 0x0c, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0xf0, 0xfc, 0xff, 0x3f, 0x07, 0x03, 0x0d, 0x0e, 0x1e, 0x3c, 0x78, 0xf0, 0xe0, 
        0xe0, 0x80, 0xe0, 0x70, 0x78, 0x7c, 0x3e, 0x1f, 0x0f, 0x07, 0x03, 0x05, 0x0e, 0x1e, 0x3c, 0x7c, 
        0xf0, 0xf0, 0xe0, 0xc0, 0xa0, 0x70, 0xf8, 0x78, 0x3e, 0x1e, 0x0f, 0x07, 0x03, 0x05, 0x0e, 0x1e, 
        0x3e, 0x7c, 0xf8, 0xf0, 0xe0, 0xc0, 0x80, 0x70, 0xf0, 0x78, 0x3c, 0x1e, 0x0f, 0x0f, 0x03, 0x03, 
        0x0d, 0x1e, 0x3e, 0x3c, 0x78, 0xf0, 0xe0, 0xc0, 0x80, 0x60, 0xf0, 0x78, 0x7c, 0x3e, 0x1f, 0x0f, 
        0x07, 0x03, 0x1d, 0xfe, 0xfe, 0xf8, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x24, 0x38, 0x09, 0x11, 0x20, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x1f, 0x1f, 0x1f, 0x3c, 0x3c, 0x3c, 0x1c, 0x1c, 0x1c, 0x1c, 0x1e, 0x0e, 0x0d, 
        0x03, 0x07, 0x07, 0x0f, 0x1e, 0x1e, 0x1c, 0x1c, 0x3c, 0x3c, 0x38, 0x1c, 0x1c, 0x1c, 0x1c, 0x1e, 
        0x0e, 0x0d, 0x03, 0x07, 0x07, 0x0f, 0x0e, 0x1e, 0x1c, 0x1c, 0x3c, 0x3c, 0x3c, 0x3c, 0x1c, 0x1c, 
        0x1c, 0x1e, 0x0e, 0x0d, 0x09, 0x03, 0x07, 0x0f, 0x0e, 0x1e, 0x1c, 0x1c, 0x3c, 0x3c, 0x3c, 0x3c, 
        0x1c, 0x1c, 0x1c, 0x1e, 0x1e, 0x0c, 0x0d, 0x03, 0x07, 0x0f, 0x0f, 0x1e, 0x1c, 0x1c, 0x3c, 0x3c, 
        0x1c, 0x38, 0x3c, 0x1f, 0x1f, 0x1f, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
   };
        oled_write_raw_P(dasbob_logo, sizeof(dasbob_logo));
    }
    return false;
}
#endif