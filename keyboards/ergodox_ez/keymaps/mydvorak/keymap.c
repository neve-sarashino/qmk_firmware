#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"

#define BASE 0 // default layer
#define SFTL 1 // shift layer
#define SYMB 2 // symbols
#define MDIA 3 // media keys

// macros
enum {
  OPEN_CLOSE_PAREN = 0,
  OPEN_CLOSE_BRACKET,
  OPEN_CLOSE_CURLY,
  OPEN_CLOSE_SINGLE_QUOTE,
  OPEN_CLOSE_DOUBLE_QUOTE,
  OPEN_CLOSE_GRV,
  EMACS_SAVE,
  LSP_FN,
  RARROW,
  LARROW,
  LOCKING_SCROLL,
  UNDS_CTL,
  HASH_SCTL,
  SPC_SFTL,
  S_GUI_TAB,
  SYMB_ENT
};

enum{
  TD_SINGLE_QUOTE = 0,
  TD_DOUBLE_QUOTE,
  TD_GRV,
  TD_CTL_TAB,
  TD_CTL_S_TAB,
  TD_ALT_TAB,
  TD_ALT_S_TAB,
  TD_HASH_TILD,
  TD_DLR_AT,
  TD_BSLS_SLSH,
  TD_FTS,
  TD_FEF,
  TD_PAREN,
  TD_CURLY,
  TD_BRACKET,
  TD_COLN2SCLN
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(MDIA),
  [2] = ACTION_LAYER_TAP_TOGGLE(SYMB)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *http://www.keyboard-layout-editor.com/##@@_x:3.5%3B&={%0A3&_x:10.5%3B&=%25%0A8%3B&@_y:-0.875&x:2.5%3B&=[%0A2&_x:1%3B&=}%0A4&_x:8.5%3B&=%2F=%0A7&_x:1%3B&=%2F%2F%0A9%3B&@_y:-0.875&x:5.5%3B&=]%0A5&=F2%0A-%3E%0AF6&_x:4.5%3B&=F11%0A%3C-&=%2F&%0A6%3B&@_y:-0.875&w:1.5%3B&=ESC&=$%0A1&_x:14.5%3B&=^%0A0&_w:1.5%3B&=*%3B&@_y:-0.375&x:3.5%3B&=.%0A%3E&_x:10.5%3B&=C%3B&@_y:-0.875&x:2.5%3B&=,%0A%3C&_x:1%3B&=P&_x:8.5%3B&=G&_x:1%3B&=R%3B&@_y:-0.875&x:5.5%3B&=Y&_h:1.5%3B&=%28%0A%0A%0A%0A%0A%0A!&_x:4.5&h:1.5%3B&=%29%0A%0A%0A%0A%0A%0A%3F&=F%3B&@_y:-0.875&w:1.5%3B&=Tab%0A%0A%0ANumPad&=%2F:%0A%2F%3B&_x:14.5%3B&=L&_w:1.5%3B&=%2F%2F%0A|%0A\%3B&@_y:-0.375&x:3.5%3B&=E&_x:10.5%3B&=T%3B&@_y:-0.875&x:2.5%3B&=O&_x:1%3B&=U&_x:8.5%3B&=H%0A%0A%C3%9F&_x:1%3B&=N%3B&@_y:-0.875&x:5.5%3B&=I&_x:6.5%3B&=D%3B&@_y:-0.875&w:1.5%3B&=%2F_%0A%23%0A%0ACtrl&=A%0A%0A%0ASuper&_x:14.5%3B&=S%0A%0A%0ASuper&_w:1.5%3B&=-%0A~%0A%0ACtrl%3B&@_y:-0.625&x:6.5&h:1.5%3B&=Alt%0A%0A%0A%0A%0A%0A+Tab&_x:4.5&h:1.5%3B&=Ctrl%0A%0A%0A%0A%0A%0A+Tab%3B&@_y:-0.75&x:3.5%3B&=J&_x:10.5%3B&=W%3B&@_y:-0.875&x:2.5%3B&=Q&_x:1%3B&=K&_x:8.5%3B&=M&_x:1%3B&=V%3B&@_y:-0.875&x:5.5%3B&=X&_x:6.5%3B&=B%3B&@_y:-0.875&w:1.5%3B&=%22%0A%0A%22|%22&=%27%0A%0A%27|%27&_x:14.5%3B&=Z&_w:1.5%3B&=%27%0A%0A%60|%60%0AShift%3B&@_y:-0.375&x:3.5%3B&=PgDN&_x:10.5%3B&=Up%3B&@_y:-0.875&x:2.5%3B&=PgUP&_x:1&a:7%3B&=&_x:8.5&a:4%3B&=Left&_x:1%3B&=Down%3B&@_y:-0.75&x:0.5%3B&=Ctrl%0AR%0A%0AL%0A%0A%0AAlt&_a:7%3B&=&_x:14.5&a:4%3B&=Right&=%2F@%0A%0A%0ANumP%3B&@_r:30&rx:6.5&ry:4.25&y:-1&x:1&a:5%3B&=Ctrl+X%0A%0A%0A%0A%0A%0ACtrl+S&_a:7%3B&=Home%3B&@_a:5&h:2%3B&=%0AShift%0A%0A%0A%0A%0ASpace&_a:7&h:2%3B&=Alt&_a:5%3B&=Ctrl+%0A%0A%0A%0A%0A%0ADel%3B&@_x:2%3B&=Ctrl+%0A%0A%0A%0A%0A%0ABkspc%3B&@_r:-30&rx:13&y:-1&x:-3&a:7%3B&=End&=Del%3B&@_x:-3%3B&=Alt&_a:5&h:2%3B&=%0ASYMB%0A%0A%0A%0A%0AEnter&_a:4&h:2%3B&=%0A%0A%0AMedia%0A%0A%0A%0A%0A%0ABkspc%3B&@_x:-3&a:7%3B&=Media
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
                KC_ESC,      TD(TD_DLR_AT),   TD(TD_BRACKET),    TD(TD_CURLY),KC_RCBR,    KC_RBRC,    TD(TD_FTS),
                GUI_T(KC_TAB),        TD(TD_COLN2SCLN),         KC_COMM,          KC_DOT,              KC_P,       KC_Y,    TD(TD_PAREN),
                M(UNDS_CTL),        KC_A,     KC_O,            KC_E,            KC_U,     KC_I,
                TD(TD_DOUBLE_QUOTE),    TD(TD_SINGLE_QUOTE),     KC_Q,             KC_J,              KC_K,       KC_X,        TD(TD_ALT_TAB),
                LCTL(LALT(KC_RGHT)),      KC_NO,       KC_PGUP,      KC_PGDN,     KC_NO,
                                              // thumb cluster
                                                      M(EMACS_SAVE),KC_HOME,
                                                               LCTL(KC_DEL),
                                    M(SPC_SFTL),   KC_LALT,   LCTL(KC_BSPC),
        // right hand
                TD(TD_FEF),      KC_AMPR,       KC_PERC,   S(KC_EQL),    KC_TILD,      KC_CIRC,       KC_PAST,
                KC_RPRN,        KC_F,        KC_G,        KC_C,          KC_R,         KC_L,                   TD(TD_BSLS_SLSH),
                        KC_D,        KC_H,        KC_T,          KC_N,     KC_S,    CTL_T(KC_MINS),
                  TD(TD_CTL_TAB),   KC_B,        KC_M,        KC_W,          KC_V,         KC_Z,              KC_EQL,
                                 // lower keys - browser tab control
                KC_LEFT,     KC_UP,    KC_DOWN,       KC_RGHT,     LGUI(KC_X),
             // thumb cluster
             KC_END,KC_DEL,
             KC_NO,
                TT(SYMB),KC_ENT, LT(MDIA,KC_BSPC)
                  ),
/* Keymap 1: shift layer
 *
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[SFTL] = KEYMAP(  // layer 1 : shift layer
        // left hand
        KC_TRNS,                KC_1,                 KC_2,       KC_3,       KC_4,        KC_5,       M(RARROW),
        M(S_GUI_TAB),  TD(TD_COLN2SCLN),         S(KC_COMM),  S(KC_DOT),    S(KC_P),     S(KC_Y),        S(KC_1),
        M(HASH_SCTL),S(KC_A),        S(KC_O),    S(KC_E),    S(KC_U),     S(KC_I),
        KC_TRNS,          KC_TRNS,              S(KC_Q),    S(KC_J),    S(KC_K),     S(KC_X),     S(LALT(KC_TAB)),
        LCTL(LALT(KC_LEFT)),          KC_TRNS,             KC_TRNS,    KC_TRNS,    KC_TRNS,
                                              // thumb cluster
                                                           KC_TRNS, KC_TRNS,
                                                                    KC_TRNS,
        KC_TRNS,S(KC_LALT), KC_TRNS,
        // right hand
        M(LARROW),      KC_6,        KC_7,        KC_8,          KC_9,         KC_0,       KC_TRNS,
        S(KC_SLSH),  S(KC_F),     S(KC_G),     S(KC_C),       S(KC_R),      S(KC_L),       KC_PIPE,
        S(KC_D),     S(KC_H),     S(KC_T),       S(KC_N), S(KC_S), S(CTL_T(KC_EQL)),
        S(RCTL(KC_TAB)),S(KC_B),  S(KC_M),     S(KC_W),       S(KC_V),      S(KC_Z),       TD(TD_GRV),
        S(KC_LEFT),     S(KC_UP),    S(KC_DOWN),       S(KC_RGHT), KC_NO,
             // thumb cluster
        KC_TRNS,S(KC_DEL),
             KC_TRNS,
             KC_TRNS, KC_TRNS, KC_TRNS
                  ),
/* Keymap 2: Symbol Layer
 * http://www.keyboard-layout-editor.com/##@@_x:3.5%3B&=F3&_x:10.5%3B&=F10%3B&@_y:-0.875&x:2.5%3B&=F2&_x:1%3B&=F4&_x:8.5%3B&=F9&_x:1%3B&=F11%3B&@_y:-0.875&x:5.5%3B&=F5&=F6&_x:4.5%3B&=F7&=F8%3B&@_y:-0.875&w:1.5%3B&=ESC&=F1&_x:14.5%3B&=F12&_a:7&w:1.5%3B&=%3B&@_y:-0.375&x:3.5&a:4%3B&=eq%0A%0A%0A%0A%0A%0Anarray&_x:10.5%3B&=8%0AUp%3B&@_y:-0.875&x:2.5%3B&=eq&_x:1%3B&=%C3%97&_x:8.5%3B&=7%0AHome&_x:1%3B&=9%0APgUp%3B&@_y:-0.875&x:5.5%3B&=%E2%8B%85&_h:1.5%3B&=%C2%B1&_x:4.5&h:1.5%3B&=%28%29&=Tab%3B&@_y:-0.875&a:6&w:1.5%3B&=BASE&_a:4%3B&=\[%20%20%20\]&_x:14.5%3B&=*&_w:1.5%3B&=%2F%2F%3B&@_y:-0.375&x:3.5%3B&=\begin%0A%0A%0A%0A%0A%0A\end&_x:10.5%3B&=5%3B&@_y:-0.875&x:2.5%3B&=\no%0A%0A%0A%0A%0A%0Anumber&_x:1%3B&=\math%0A%0A%0A%0A%0A%0Arm&_x:8.5%3B&=4%0ALeft&_x:1%3B&=6%0ARight%3B&@_y:-0.875&x:5.5%3B&=\frac&_x:6.5%3B&=%2F&%3B&@_y:-0.875&a:6&w:1.5%3B&=BASE&_a:4%3B&=align&_x:14.5%3B&=+&_w:1.5%3B&=-%3B&@_y:-0.625&x:6.5&h:1.5%3B&=%E2%88%93&_x:4.5&h:1.5%3B&={}%3B&@_y:-0.75&x:3.5%3B&=%C2%AC&_x:10.5%3B&=2%0ADown%3B&@_y:-0.875&x:2.5%3B&=%E2%88%83&_x:1%3B&=%E2%86%92&_x:8.5%3B&=1%0AEnd&_x:1%3B&=3%0APgDn%3B&@_y:-0.875&x:5.5%3B&=%E2%86%A6&_x:6.5%3B&=%25%3B&@_y:-0.875&w:1.5%3B&=BASE%0A%0A%0AShift&=%E2%88%80&_x:14.5%3B&=^&_w:1.5%3B&=%2F_%3B&@_y:-0.375&x:3.5%3B&=Y&_x:10.5%3B&=.%0ADel%3B&@_y:-0.875&x:2.5%3B&=X&_x:1%3B&=Z&_x:8.5%3B&=,&_x:1%3B&=0%0AIns%3B&@_y:-0.75&x:0.5&a:6%3B&=Media&_a:4%3B&=\math%0A%0A%0A%0A%0A%0Abf&_x:14.5%3B&=%2F=&_a:6%3B&=BASE%3B&@_r:30&rx:6.5&ry:4.25&y:-1&x:1&a:5%3B&=Ctrl+X%0A%0A%0A%0A%0A%0ACtrl+S&_a:7%3B&=Home%3B&@_h:2%3B&=Space&_h:2%3B&=Ctrl&_a:5%3B&=Ctrl+%0A%0A%0A%0A%0A%0ADel%3B&@_x:2%B&=Ctrl+%0A%0A%0A%0A%0A%0ABkspc%3B&@_r:-30&rx:13&y:-1&x:-3&a:7%3B&=End&=Del%3B&@_x:-3%3B&=Alt&_h:2%3B&=Enter&_h:2%3B&=Bkspc%3B&@_x:-3%3B&=Media
 *
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS,   KC_F1,              KC_F2,          KC_F3,             KC_F4,          KC_F5,          KC_F6,
       KC_TRNS,           KC_NO,       KC_WH_U,   KC_MS_U, KC_WH_D, KC_NO,   KC_NO,
       KC_TRNS,           KC_COPY,     KC_MS_L,   KC_MS_D, KC_MS_R, KC_PASTE,
       KC_LSFT,   KC_NO,    KC_WH_L,   KC_NO,   KC_WH_R, KC_NO,   KC_NO,
       KC_TRNS,           KC_NO,       KC_NO,     KC_NO,   KC_NO,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_LALT,KC_TRNS,
       // right hand
       KC_F7,               KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_NO,
       M(OPEN_CLOSE_PAREN), KC_TAB,  KC_7,  KC_8,   KC_9,   KC_PAST, KC_PSLS,
                            KC_AMPR, KC_4,  KC_5,   KC_6,   KC_PPLS, KC_PMNS,
       M(OPEN_CLOSE_CURLY), KC_PERC, KC_1,  KC_2,   KC_3,   S(KC_6), KC_UNDS,
       KC_COMM,  KC_DOT, KC_0,   KC_EQL, KC_TRNS,
       KC_TRNS, KC_DEL,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Media and mouse keys
 * http://www.keyboard-layout-editor.com/##@@_x:3.5&a:7%3B&=&_x:10.5%3B&=%3B&@_y:-0.875&x:2.5%3B&=&_x:1%3B&=&_x:8.5%3B&=&_x:1%3B&=%3B&@_y:-0.875&x:5.5%3B&=&=&_x:4.5%3B&=&=%3B&@_y:-0.875&a:4&w:1.5%3B&=RESET&_a:7%3B&=&_x:14.5%3B&=&_w:1.5%3B&=%3B&@_y:-0.375&x:3.5&a:4%3B&=MsUp&_x:10.5%3B&=Up%3B&@_y:-0.875&x:2.5%3B&=Wh%2F_U&_x:1%3B&=Wh%2F_D&_x:8.5%3B&=PgUp&_x:1%3B&=PgDn%3B&@_y:-0.875&x:5.5&a:7%3B&=&_h:1.5%3B&=&_x:4.5&h:1.5%3B&=&=%3B&@_y:-0.875&a:6&w:1.5%3B&=%0A%0ANumPad&_a:7%3B&=&_x:14.5%3B&=&_w:1.5%3B&=%3B&@_y:-0.375&x:3.5&a:4%3B&=MsDn&_x:10.5%3B&=Down%3B&@_y:-0.875&x:2.5%3B&=MsL&_x:1%3B&=MsR&_x:8.5%3B&=Left&_x:1%3B&=Right%3B&@_y:-0.875&x:5.5%3B&=Paste&_x:6.5&a:7%3B&=%3B&@_y:-0.875&a:6&w:1.5%3B&=BASE&_a:4%3B&=Copy&_x:14.5%3B&=Shift&_a:7&w:1.5%3B&=%3B&@_y:-0.625&x:6.5&h:1.5%3B&=&_x:4.5&h:1.5%3B&=%3B&@_y:-0.75&x:3.5%3B&=&_x:10.5%3B&=%3B&@_y:-0.875&x:2.5&a:4%3B&=Wh%2F_L&_x:1%3B&=Wh%2F_R&_x:8.5%3B&=Copy&_x:1%3B&=Paste%3B&@_y:-0.875&x:5.5&a:7%3B&=&_x:6.5%3B&=%3B&@_y:-0.875&a:6&w:1.5%3B&=%0A%0ANumPad&_a:7%3B&=&_x:14.5%3B&=&_w:1.5%3B&=%3B&@_y:-0.375&x:3.5%3B&=&_x:10.5%3B&=%3B&@_y:-0.875&x:2.5%3B&=&_x:1%3B&=&_x:8.5%3B&=&_x:1&a:4%3B&=Vol%0A%0A%0A%0A%0A%0AUp%3B&@_y:-0.75&x:0.5&a:6%3B&=BASE&_a:7%3B&=&_x:14.5&a:4%3B&=Vol%0A%0A%0A%0A%0A%0ADown&=Vol%0A%0A%0A%0A%0A%0AMute%3B&@_r:30&rx:6.5&ry:4.25&y:-1&x:1&a:7%3B&=&=%3B&@_a:6&h:2%3B&=Rclk&_h:2%3B&=Lclk&_a:7%3B&=%3B&@_x:2&a:4%3B&=Mclk%3B&@_r:-30&rx:13&y:-1&x:-3%3B&=New%0A%0A%0A%0A%0A%0Atab&=Close%0A%0A%0A%0A%0A%0Atab%3B&@_x:-3&a:7%3B&=&_a:4&h:2%3B&=Brwser%0A%0A%0A%0A%0A%0ABack&_h:2%3B&=Brwser%0A%0A%0A%0A%0A%0AFwd%3B&@_x:-3&a:7%3B&=
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS,              KC_NO,    KC_NO,   KC_NO,   KC_NO, KC_NO,    KC_NO,
       KC_NO,    KC_NO,  KC_WH_U, KC_MS_U, KC_WH_D, KC_NO,    KC_NO,
       KC_NO,    KC_NO,  KC_MS_L, KC_MS_D, KC_MS_R, KC_PASTE,
       KC_LSFT,              KC_NO,  KC_WH_L,   KC_NO, KC_WH_R, KC_NO,    KC_NO,
       KC_NO,              KC_NO,    KC_NO,   KC_NO,   KC_NO,
                                               KC_NO, KC_NO,
                                                      KC_NO,
                                  KC_BTN2, KC_BTN1, KC_BTN3,
    // right hand
       KC_NO,      KC_NO,   KC_NO,   KC_NO,  KC_NO,   KC_NO,   RESET,
       KC_NO,      KC_NO,   KC_PGUP, KC_NO,  KC_PGDN, KC_NO,   KC_NO,
                   KC_NO,   KC_LEFT, KC_UP,  KC_DOWN, KC_RGHT, KC_RALT,
       KC_NO,      KC_NO,    KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_LSFT,
       KC_NO, KC_VOLU,  KC_VOLD, KC_MUTE, M(LOCKING_SCROLL),
       LCTL(KC_T), LCTL(KC_W),
       KC_NO,
       KC_TRNS, KC_TRNS,KC_TRNS
)
};

static uint16_t
  key_timer_uc,
  key_timer_hs,
  key_timer_se,
  key_timer_sgt,
  key_timer_ss;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
      case OPEN_CLOSE_PAREN:
        if (record->event.pressed) {
          return MACRO( D(LSFT), T(LPRN), T(RPRN), U(LSFT), T(LEFT), END);
        }
        break;
  case OPEN_CLOSE_BRACKET:
    if (record->event.pressed) {
      return MACRO( T(LBRC), T(RBRC), T(LEFT), END);
    }
    break;        
  case OPEN_CLOSE_CURLY:
    if (record->event.pressed) {
      return MACRO( D(LSFT), T(LCBR), T(RCBR), U(LSFT), T(LEFT), END);
    }
    break;                
  case OPEN_CLOSE_SINGLE_QUOTE:
    if (record->event.pressed) {
      return MACRO( T(QUOT), T(QUOT), T(LEFT), END);
    }
    break;        
  case OPEN_CLOSE_DOUBLE_QUOTE:
    if (record->event.pressed){
      return MACRO( D(LSFT), T(QUOT), T(QUOT), U(LSFT), T(LEFT), END);
    }
    break;
  case OPEN_CLOSE_GRV:
    if (record->event.pressed) {
      return MACRO( T(GRV), T(GRV), T(LEFT), END);
    }
    break;
  case EMACS_SAVE:
    if (record->event.pressed) {
      return MACRO( D(LCTL) ,T(X), T(S), U(LCTL), END );
    }
    break;
  case LSP_FN:
    if (record->event.pressed) {
      return MACRO( D(LSFT), T(3), U(LSFT), T(QUOT), END );
    }
    break;
  case RARROW:
    if (record->event.pressed) {
      return MACRO( T(MINS), D(LSFT), T(DOT), U(LSFT), END );
    }
    break;
  case LARROW:
    if (record->event.pressed) {
      return MACRO( D(LSFT), T(COMM), U(LSFT), T(MINS), END );
    }
    break;
  case LOCKING_SCROLL:
    if (record->event.pressed) {
      return MACRO( T(LOCKING_SCROLL), T(LOCKING_SCROLL), END );
    }
    break;
  case UNDS_CTL:
    if (record->event.pressed) {
      key_timer_uc = timer_read();
      register_code(KC_LCTL);
    }else{
      if (timer_elapsed(key_timer_uc) > 140) { // 150 being 150ms, the threshhold we pick for counting something as a tap.
        unregister_code(KC_LCTL);
      }else{
        unregister_code(KC_LCTL);
        register_code(KC_LSFT);
        register_code(KC_MINS);
        unregister_code(KC_MINS);
        unregister_code(KC_LSFT);
      }
    }
    break;
  case HASH_SCTL:
    if (record->event.pressed) {
      key_timer_hs = timer_read();
      register_code(KC_LSFT);
      register_code(KC_LCTL);
    }else{
      if (timer_elapsed(key_timer_hs) > 140) { // 150 being 150ms, the threshhold we pick for counting something as a tap.
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
     }else{
        unregister_code(KC_LCTL);
        register_code(KC_3);
        unregister_code(KC_3);
        unregister_code(KC_LSFT);
      }
    }
    break;
  case SPC_SFTL:
    if (record->event.pressed) {
      key_timer_ss = timer_read();
      layer_on(SFTL);
    }else{
      if (timer_elapsed(key_timer_ss) > 100) { // 150 being 150ms, the threshhold we pick for counting something as a tap.
        layer_off(SFTL);
        clear_mods();
      }else{
          layer_off(SFTL);
          register_code(KC_SPC);
          unregister_code(KC_SPC);
      }
    }
    break;
  case S_GUI_TAB:
    if (record->event.pressed) {
      key_timer_sgt = timer_read();
      register_code(KC_LSFT);
      register_code(KC_LGUI);
    }else{
      if (timer_elapsed(key_timer_sgt) > 140) { // 150 being 150ms, the threshhold we pick for counting something as a tap.
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
      }else{
        unregister_code(KC_LGUI);
        register_code(KC_TAB);
        unregister_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
    }
    break;
  case SYMB_ENT:
    if (record->event.pressed) {
      key_timer_se = timer_read();
      layer_on(SYMB);
    }else{
      if (timer_elapsed(key_timer_se) > 100) { // 150 being 150ms, the threshhold we pick for counting something as a tap.
        layer_off(SYMB);
        clear_mods();
      }else{
        layer_off(SYMB);
        register_code(KC_ENT);
        unregister_code(KC_ENT);
      }
    }
    break;
  }
  return MACRO_NONE;
};


void dance_op_single(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_QUOT);
    unregister_code (KC_QUOT);
    reset_tap_dance (state);
  }else{
    register_code (KC_QUOT);
    unregister_code (KC_QUOT);
    register_code (KC_QUOT);
    unregister_code (KC_QUOT);
    register_code (KC_LEFT);
    unregister_code (KC_LEFT);
    reset_tap_dance(state);
  }
}

    void dance_op_double(qk_tap_dance_state_t *state, void *user_data) {
  register_code (KC_LSFT);
  if (state->count == 1) {
    register_code (KC_QUOT);
    unregister_code (KC_QUOT);
    unregister_code (KC_LSFT);
    reset_tap_dance (state);
  }else{
    register_code (KC_QUOT);
    unregister_code (KC_QUOT);
    register_code (KC_QUOT);
    unregister_code (KC_QUOT);
    unregister_code (KC_LSFT);
    register_code (KC_LEFT);
    unregister_code (KC_LEFT);
    reset_tap_dance (state);
  }
}

void dance_op_grv(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_GRV);
    unregister_code (KC_GRV);
    reset_tap_dance (state);
  }else{
    register_code (KC_GRV);
    unregister_code (KC_GRV);
    register_code (KC_GRV);
    unregister_code (KC_GRV);
    register_code (KC_LEFT);
    unregister_code (KC_LEFT);
    reset_tap_dance (state);
  }
}

void dance_fef(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_F11);
    unregister_code (KC_F11);
    reset_tap_dance(state);
  }else{
    register_code (KC_LALT);
    register_code (KC_F4);
    unregister_code (KC_F4);
    unregister_code (KC_LALT);
    reset_tap_dance (state);
  }
}

 void dance_paren(qk_tap_dance_state_t *state, void *user_data) {
   if (state->count == 1) {
     register_code (KC_LSFT);
     register_code (KC_9);
     unregister_code (KC_9);
     unregister_code (KC_LSFT);
     reset_tap_dance (state);
   }else{
     register_code (KC_LSFT);
     register_code (KC_9);
     unregister_code (KC_9);
     register_code (KC_0);
     unregister_code (KC_0);
     unregister_code (KC_LSFT);
     register_code (KC_LEFT);
     unregister_code (KC_LEFT);
     reset_tap_dance (state);
   }
}

 void dance_curly(qk_tap_dance_state_t *state, void *user_data) {
   if (state->count == 1) {
     register_code (KC_LSFT);
     register_code (KC_LBRC);
     unregister_code (KC_LBRC);
     unregister_code (KC_LSFT);
     reset_tap_dance (state);
   }else{
     register_code (KC_LSFT);
     register_code (KC_LBRC);
     unregister_code (KC_LBRC);
     register_code (KC_RBRC);
     unregister_code (KC_RBRC);;
     unregister_code (KC_LSFT);
     register_code (KC_LEFT);
     unregister_code (KC_LEFT);
     reset_tap_dance (state);
   }
 }
 void dance_bracket(qk_tap_dance_state_t *state, void *user_data) {
   if (state->count == 1) {
     register_code (KC_LBRC);
     unregister_code (KC_LBRC);
     reset_tap_dance (state);
   }else{
     register_code (KC_LBRC);
     unregister_code (KC_LBRC);
     register_code (KC_RBRC);
     unregister_code (KC_RBRC);
     register_code (KC_LEFT);
     unregister_code (KC_LEFT);
     reset_tap_dance (state);
   }
 }



void dance_ctl_tab_each(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_LCTL);
    register_code(KC_TAB);
    unregister_code(KC_TAB);
  }else{
    register_code(KC_TAB);
    unregister_code(KC_TAB);
  }
}
void dance_ctl_tab_finish(qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_LCTL);
  reset_tap_dance (state);
}
void dance_ctl_s_tab_each(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_LSFT);
    register_code(KC_LCTL);
    register_code(KC_TAB);
    unregister_code(KC_TAB);
  }else{
    register_code(KC_TAB);
    unregister_code(KC_TAB);
  }
}
void dance_ctl_s_tab_finish(qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_LCTL);
  unregister_code(KC_LSFT);
  reset_tap_dance (state);
}


void dance_alt_tab_each(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_LALT);
    register_code(KC_TAB);
    unregister_code(KC_TAB);
  }else{
    register_code(KC_TAB);
    unregister_code(KC_TAB);
  }
}
void dance_alt_tab_finish(qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_LALT);
  reset_tap_dance (state);
}
void dance_alt_s_tab_each(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code(KC_LSFT);
    register_code(KC_LALT);
    register_code(KC_TAB);
    unregister_code(KC_TAB);
  }else{
    register_code(KC_TAB);
    unregister_code(KC_TAB);
  }
}
void dance_alt_s_tab_finish(qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_LALT);
  unregister_code(KC_LSFT);
  reset_tap_dance (state);
}



qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SINGLE_QUOTE]  = ACTION_TAP_DANCE_FN(dance_op_single),
  [TD_DOUBLE_QUOTE]  = ACTION_TAP_DANCE_FN(dance_op_double),
  [TD_GRV] = ACTION_TAP_DANCE_FN (dance_op_grv),
  [TD_CTL_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(dance_ctl_tab_each,dance_ctl_tab_finish,NULL),
  [TD_CTL_S_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(dance_ctl_s_tab_each,dance_ctl_s_tab_finish,NULL),
  [TD_ALT_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(dance_alt_tab_each,dance_alt_tab_finish,NULL),
  [TD_ALT_S_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(dance_alt_s_tab_each,dance_alt_s_tab_finish,NULL),
  [TD_HASH_TILD] = ACTION_TAP_DANCE_DOUBLE (KC_HASH,KC_TILD),
  [TD_DLR_AT] = ACTION_TAP_DANCE_DOUBLE (KC_DLR,KC_AT),
  [TD_BSLS_SLSH] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH,KC_BSLS),
  [TD_PAREN] = ACTION_TAP_DANCE_FN(dance_paren),
  [TD_CURLY] = ACTION_TAP_DANCE_FN(dance_curly),
  [TD_BRACKET] = ACTION_TAP_DANCE_FN(dance_bracket),
  [TD_FTS] = ACTION_TAP_DANCE_DOUBLE (S(KC_1), S(KC_SLSH)),
  [TD_FEF] = ACTION_TAP_DANCE_FN (dance_fef),
  [TD_COLN2SCLN] = ACTION_TAP_DANCE_DOUBLE (KC_COLN,KC_SCLN)
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  ergodox_led_all_on();
  for (int i = LED_BRIGHTNESS_HI; i > LED_BRIGHTNESS_LO; i--) {
    ergodox_led_all_set (i);
    wait_ms (5);
  }
  wait_ms(1000);
  for (int i = LED_BRIGHTNESS_LO; i > 0; i--) {
    ergodox_led_all_set (i);
    wait_ms (10);
  }
  ergodox_led_all_off();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
  case 2:
    ergodox_right_led_1_on();
    break;
  case 3:
    ergodox_right_led_2_on();
    break;
  case 1:
    ergodox_right_led_3_on();
    break;
  default:
    // none
    break;
  }

};

