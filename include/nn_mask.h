#ifndef NN_MASK_H
# define NN_MASK_H

// # if defined(__linux__)
// 	#include "../../lib/minilibx_linux/mlx.h"
// 	#include	<X11/Xlib.h>
// 	#include	<X11/Xutil.h>
// # endif
// # if defined(__APPLE__) && defined(__MACH__)
// 	#include "../../lib/minilibx_mac/mlx.h"
// # endif


// Definitions from /usr/include/X11
# define NN_KeyPressMask	(1L<<0)
# define NN_KeyPress		2

# define NN_KeyReleaseMask	(1L<<1)
# define NN_KeyRelease		3

# define NN_AnyButton            	0L	/* special Button Code, passed to GrabButton */
# define NN_ButtonPressMask			(1L<<2)
# define NN_ButtonReleaseMask		(1L<<3)
# define NN_Button1MotionMask		(1L<<8)
# define NN_Button2MotionMask		(1L<<9)
# define NN_Button3MotionMask		(1L<<10)
# define NN_Button4MotionMask		(1L<<11)
# define NN_Button5MotionMask		(1L<<12)
# define NN_ButtonMotionMask		(1L<<13)
# define NN_OwnerGrabButtonMask		(1L<<24)
# define NN_ButtonPress		4
# define NN_ButtonRelease		5
/* Key masks. Used as modifiers to GrabButton and GrabKey, results of QueryPointer,
   state in various key-, mouse-, and button-related events. */
/* button masks.  Used in same manner as Key masks above. Not to be confused
   with button names below. */
# define NN_Button1Mask		(1<<8)
# define NN_Button2Mask		(1<<9)
# define NN_Button3Mask		(1<<10)
# define NN_Button4Mask		(1<<11)
# define NN_Button5Mask		(1<<12)
# define NN_AnyModifier		(1<<15)  /* used in GrabButton, GrabKey */
/* button names. Used as arguments to GrabButton and as detail in ButtonPress
   and ButtonRelease events.  Not to be confused with button masks above.
   Note that 0 is already defined above as "AnyButton".  */
# define NN_Button1			1
# define NN_Button2			2
# define NN_Button3			3
# define NN_Button4			4
# define NN_Button5			5
/* GrabPointer, GrabButton, GrabKeyboard, GrabKey Modes */
//				 - key/button already grabbed
# define NN_XC_leftbutton	74
# define NN_XC_middlebutton	82
# define NN_XC_rightbutton	100


# define NN_ButtonPressMask	(1L<<2)
# define NN_ButtonPress		4

# define NN_EnterNotify		7
# define NN_LeaveNotify		8

# define NN_FocusIn			9
# define NN_XI_DeviceFocusIn 6
# define NN_XI_FocusIn       9
# define NN_XI_FocusInMask   (1 << NN_XI_FocusIn)

# define NN_FocusOut				10
# define NN_XI_DeviceFocusOut	7
# define NN_XI_FocusOut			10
# define NN_XI_FocusOutMask		(1 << NN_XI_FocusOut)

# define NN_KeymapNotify		11

# define NN_Expose			12
# define NN_GraphicsExpose	13
# define NN_NoExpose		14


# define NN_DestroyNotify	17
# define NN_CirculateRequest	27

# define NN_ConfigureRequest	23
# define NN_MapRequest		20
# define NN_ResizeRequest	25

# define NN_MotionNotify	6
# define NN_EnterNotify		7
# define NN_LeaveNotify		8
# define NN_KeymapNotify		11
# define NN_VisibilityNotify	15
# define NN_CreateNotify		16
# define NN_DestroyNotify		17
# define NN_UnmapNotify			18
# define NN_MapNotify			19
# define NN_ReparentNotify		21
# define NN_ConfigureNotify		22
# define NN_GravityNotify		24
# define NN_CirculateNotify		26
# define NN_PropertyNotify		28
# define NN_SelectionNotify		31
# define NN_ColormapNotify		32
# define NN_MappingNotify		34
/* Notify modes */
# define NN_NotifyNormal	0
# define NN_NotifyGrab	1
# define NN_NotifyUngrab	2
# define NN_NotifyWhileGrabbed	3
# define NN_NotifyHint			1	/* for MotionNotify events */
/* Notify detail */
# define NN_NotifyAncestor			0
# define NN_NotifyVirtual			1
# define NN_NotifyInferior			2
# define NN_NotifyNonlinear			3
# define NN_NotifyNonlinearVirtual	4
# define NN_NotifyPointer			5
# define NN_NotifyPointerRoot		6
# define NN_NotifyDetailNone			7

# define NN_ClientMessage				33

# define NN_SelectionClear				29

# define NN_SelectionRequest				30

 // libx Mask defines
 # define NN_NoEventMask					0L
 # define NN_KeyPressMask			(1L<<0)
 # define NN_KeyReleaseMask			(1L<<1)
 # define NN_ButtonPressMask			(1L<<2)
 # define NN_ButtonReleaseMask		(1L<<3)
 # define NN_EnterWindowMask			(1L<<4)
 # define NN_LeaveWindowMask			(1L<<5)
 # define NN_PointerMotionMask		(1L<<6)
 # define NN_PointerMotionHintMask	(1L<<7)
 # define NN_Button1MotionMask		(1L<<8)
 # define NN_Button2MotionMask		(1L<<9)
 # define NN_Button3MotionMask		(1L<<10)
 # define NN_Button4MotionMask		(1L<<11)
 # define NN_Button5MotionMask		(1L<<12)
 # define NN_ButtonMotionMask		(1L<<13)
 # define NN_KeymapStateMask			(1L<<14)
 # define NN_ExposureMask			(1L<<15)
 # define NN_VisibilityChangeMask	(1L<<16)
 # define NN_StructureNotifyMask		(1L<<17)
 # define NN_ResizeRedirectMask		(1L<<18)
 # define NN_SubstructureNotifyMask	(1L<<19)
 # define NN_SubstructureRedirectMask	(1L<<20)
 # define NN_FocusChangeMask			(1L<<21)
 # define NN_PropertyChangeMask		(1L<<22)
 # define NN_ColormapChangeMask		(1L<<23)
 # define NN_OwnerGrabButtonMask		(1L<<24)

 # define NN_ShiftMask		(1<<0)
 # define NN_LockMask		(1<<1)
 # define NN_ControlMask		(1<<2)
 # define NN_Mod1Mask		(1<<3)
 # define NN_Mod2Mask		(1<<4)
 # define NN_Mod3Mask		(1<<5)
 # define NN_Mod4Mask		(1<<6)
 # define NN_Mod5Mask		(1<<7)

 # define NN_Button1Mask		(1<<8)
 # define NN_Button2Mask		(1<<9)
 # define NN_Button3Mask		(1<<10)
 # define NN_Button4Mask		(1<<11)
 # define NN_Button5Mask		(1<<12)

#endif
