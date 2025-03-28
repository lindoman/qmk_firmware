#pragma once
#define TAPPING_TOGGLE 3
#define UNICODE_SELECTED_MODES UNICODE_MODE_LINUX
#define UNICODE_KEY_MAC	KC_LEFT_ALT	//The key to hold when beginning a Unicode sequence with the macOS input mode
#define UNICODE_KEY_LNX	LCTL(LSFT(KC_U))	//The key to tap when beginning a Unicode sequence with the Linux input mode
#define UNICODE_KEY_WINC KC_RIGHT_ALT	//The key to hold when beginning a Unicode sequence with the WinCompose input mode
//UNICODE_SELECTED_MODES	-1	A comma separated list of input modes for cycling through
//UNICODE_CYCLE_PERSIST	true	Whether to persist the current Unicode input mode to EEPROM
#define UNICODE_TYPE_DELAY	5	//The amount of time to wait, in milliseconds, between Unicode sequence keystrokes
//#define QUICK_TAP_TERM 10
#define TAPPING_TERM 150
#undef HOLD_ON_OTHER_KEY_PRESS

// some slight space saving configs:
#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT