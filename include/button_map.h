/* *****************************************************************************

	This file maps most keyboard key values of mac and linux. `ARCH` is used as
	Linux distro to get keyboard value from a simple DELL keyboard and for MAC
	the `OS X (EL Capitan)` is used to get key valus from an apple keyboard
	(normal)

***************************************************************************** */

#ifndef BUTTON_MAP_H
# define BUTTON_MAP_H

#if defined(__linux__)

	#define MOUSE_LEFT	1
	#define MOUSE_MIDLE	2
	#define MOUSE_RIGHT	3
	#define MOUSE_GOUP	4	// Scrole up (far from you)
	#define MOUSE_GODWN	5	// scrole down (tword you)



	#define BTN_ESC		65307

	#define BTN_F1 		65470
	#define BTN_F2		65471
	#define BTN_F3		65472
	#define BTN_F4		65473
	#define BTN_F5		65474
	#define BTN_F6		65475
	#define BTN_F7		65476
	#define BTN_F8		65477
	#define BTN_F9		65478
	#define BTN_F10		65479
	#define BTN_F11		65480
	#define BTN_F12		65481

	#define BTN_TAB		65289
	#define BTN_CAP		65509
	#define BTN_SHIFT_L	65505
	#define BTN_SHIFT_R	65506
	#define BTN_CTRL_L	65507
	#define BTN_CTRL_R	65508
	#define BTN_POWER_L	65515
	#define BTN_POWER_R	65516
	#define BTN_ALT_L	65513
	#define BTN_ALT_R	65027

	#define BTN_SPACE	32
	#define BTN_RETURN	65293
	#define BTN_BAC_SPC	65288
	#define BTN_DELETE	65535

	#define BTN_UP		65362
	#define BTN_DOWN	65364
	#define BTN_LEFT	65361
	#define BTN_RIGT	65363

	#define BTN_NUM_LOC 65407
	#define BTN_NUM_0	65438
	#define BTN_NUM_1	65436
	#define BTN_NUM_2	65433
	#define BTN_NUM_3	65435
	#define BTN_NUM_4	65430
	#define BTN_NUM_5	65437
	#define BTN_NUM_6	65432
	#define BTN_NUM_7	65429
	#define BTN_NUM_8	65431
	#define BTN_NUM_9	65434
	#define BTN_NUM_RET	65421

	// #define BTN_PLUS	65451
	// #define BTN_MINUS	65453
	#define BTN_PLUS	43
	#define BTN_MINUS	45

	#define BTN_MULT	65450
	#define BTN_DIV		65455
	#define BTN_DOT		65439

	#define BTN_A		97
	#define BTN_B		98
	#define BTN_C		99
	#define BTN_D		100
	#define BTN_E		101
	#define BTN_F		102
	#define BTN_G		103
	#define BTN_H		104
	#define BTN_I		105
	#define BTN_J		106
	#define BTN_K		107
	#define BTN_L		108
	#define BTN_M		109
	#define BTN_N		110
	#define BTN_O		111
	#define BTN_P		112
	#define BTN_Q		113
	#define BTN_R		114
	#define BTN_S		115
	#define BTN_T		116
	#define BTN_U		117
	#define BTN_V		118
	#define BTN_W		119
	#define BTN_X		120
	#define BTN_Y		121
	#define BTN_Z		122
#endif
#if defined(__APPLE__) && defined(__MACH__)


	#define MOUSE_LEFT	1
	#define MOUSE_MIDLE	3
	#define MOUSE_RIGHT	2
	// #define MOUSE_GOUP	5	// Scrole up (far from you) (Was not working with gaming mouse)
	#define MOUSE_GOUP	4	// Scrole up (far from you)
	// #define MOUSE_GODWN	7	// scrole down (tword you)
	#define MOUSE_GODWN	5	// scrole down (tword you) (Was not working with gaming mouse)

	#define BTN_ESC		53

	#define BTN_F1 		122
	#define BTN_F2		120
	#define BTN_F3		99
	#define BTN_F4		118
	#define BTN_F5		96
	#define BTN_F6		97
	#define BTN_F7		98
	#define BTN_F8		100
	#define BTN_F9		101
	#define BTN_F10		109
	#define BTN_F11		110	// Not sure of this value, it's a guessed value
	#define BTN_F12		111

	#define BTN_F13		105
	#define BTN_F14		107
	//#define BTN_F15		IT QUITES THE PROGRAMME
	#define BTN_F16		106
	#define BTN_F17		64
	#define BTN_F18		79
	#define BTN_F19		80

	#define BTN_TAB		48
	#define BTN_CAP		272
	#define BTN_SHIFT_L	257
	#define BTN_SHIFT_R	258
	#define BTN_CTRL_L	256
	#define BTN_CTRL_R	269
	#define BTN_POWER_L	261
	#define BTN_POWER_R	262
	#define BTN_ALT_L	259
	#define BTN_ALT_R	260

	#define BTN_SPACE	49
	#define BTN_RETURN	36
	#define BTN_BAC_SPC	51
	#define BTN_DELETE	117

	#define BTN_UP		126
	#define BTN_DOWN	125
	#define BTN_LEFT	123
	#define BTN_RIGT	124

	#define BTN_NUM_LOC 71
	#define BTN_NUM_0	82
	#define BTN_NUM_1	83
	#define BTN_NUM_2	84
	#define BTN_NUM_3	85
	#define BTN_NUM_4	86
	#define BTN_NUM_5	87
	#define BTN_NUM_6	88
	#define BTN_NUM_7	89
	#define BTN_NUM_8	91
	#define BTN_NUM_9	92
	#define BTN_NUM_RET	76

	#define BTN_PLUS	69
	#define BTN_MINUS	78
	#define BTN_MULT	67
	#define BTN_DIV		75
	#define BTN_DOT		65

	#define BTN_A		0
	#define BTN_B		11
	#define BTN_C		8
	#define BTN_D		2
	#define BTN_E		14
	#define BTN_F		3
	#define BTN_G		5
	#define BTN_H		4
	#define BTN_I		34
	#define BTN_J		38
	#define BTN_K		40
	#define BTN_L		37
	#define BTN_M		46
	#define BTN_N		45
	#define BTN_O		31
	#define BTN_P		35
	#define BTN_Q		12
	#define BTN_R		15
	#define BTN_S		1
	#define BTN_T		17
	#define BTN_U		32
	#define BTN_V		9
	#define BTN_W		13
	#define BTN_X		7
	#define BTN_Y		16
	#define BTN_Z		6

#endif
#endif
