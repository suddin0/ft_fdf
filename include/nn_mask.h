/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nn_mask.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:40:52 by suddin            #+#    #+#             */
/*   Updated: 2018/03/28 15:05:46 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NN_MASK_H
# define NN_MASK_H

# define NN_KEYPRESSMASK (1L<<0)
# define NN_KEYPRESS 2
# define NN_KEYRELEASEMASK (1L<<1)
# define NN_KEYRELEASE 3
# define NN_ANYBUTTON 0L
# define NN_BUTTONPRESSMASK (1L<<2)
# define NN_BUTTONRELEASEMASK (1L<<3)
# define NN_BUTTON1MOTIONMASK (1L<<8)
# define NN_BUTTON2MOTIONMASK (1L<<9)
# define NN_BUTTON3MOTIONMASK (1L<<10)
# define NN_BUTTON4MOTIONMASK (1L<<11)
# define NN_BUTTON5MOTIONMASK (1L<<12)
# define NN_BUTTONMOTIONMASK (1L<<13)
# define NN_OWNERGRABBUTTONMASK (1L<<24)
# define NN_BUTTONPRESS 4
# define NN_BUTTONRELEASE 5
# define NN_BUTTON1MASK (1<<8)
# define NN_BUTTON2MASK (1<<9)
# define NN_BUTTON3MASK (1<<10)
# define NN_BUTTON4MASK (1<<11)
# define NN_BUTTON5MASK (1<<12)
# define NN_ANYMODIFIER (1<<15)
# define NN_BUTTON1 1
# define NN_BUTTON2 2
# define NN_BUTTON3 3
# define NN_BUTTON4 4
# define NN_BUTTON5 5
# define NN_XC_LEFTBUTTON 74
# define NN_XC_MIDDLEBUTTON 82
# define NN_XC_RIGHTBUTTON 100
# define NN_BUTTONPRESSMASK (1L<<2)
# define NN_BUTTONPRESS 4
# define NN_ENTERNOTIFY 7
# define NN_LEAVENOTIFY 8
# define NN_FOCUSIN 9
# define NN_XI_DEVICEFOCUSIN 6
# define NN_XI_FOCUSIN 9
# define NN_XI_FOCUSINMASK (1 << NN_XI_FOCUSIN)
# define NN_FOCUSOUT 10
# define NN_XI_DEVICEFOCUSOUT 7
# define NN_XI_FOCUSOUT 10
# define NN_XI_FOCUSOUTMASK (1 << NN_XI_FOCUSOUT)
# define NN_KEYMAPNOTIFY 11
# define NN_EXPOSE 12
# define NN_GRAPHICSEXPOSE 13
# define NN_NOEXPOSE 14
# define NN_DESTROYNOTIFY 17
# define NN_CIRCULATEREQUEST 27
# define NN_CONFIGUREREQUEST 23
# define NN_MAPREQUEST 20
# define NN_RESIZEREQUEST 25
# define NN_MOTIONNOTIFY 6
# define NN_ENTERNOTIFY 7
# define NN_LEAVENOTIFY 8
# define NN_KEYMAPNOTIFY 11
# define NN_VISIBILITYNOTIFY 15
# define NN_CREATENOTIFY 16
# define NN_DESTROYNOTIFY 17
# define NN_UNMAPNOTIFY 18
# define NN_MAPNOTIFY 19
# define NN_REPARENTNOTIFY 21
# define NN_CONFIGURENOTIFY 22
# define NN_GRAVITYNOTIFY 24
# define NN_CIRCULATENOTIFY 26
# define NN_PROPERTYNOTIFY 28
# define NN_SELECTIONNOTIFY 31
# define NN_COLORMAPNOTIFY 32
# define NN_MAPPINGNOTIFY 34
# define NN_NOTIFYNORMAL 0
# define NN_NOTIFYGRAB 1
# define NN_NOTIFYUNGRAB 2
# define NN_NOTIFYWHILEGRABBED 3
# define NN_NOTIFYHINT 1
# define NN_NOTIFYANCESTOR 0
# define NN_NOTIFYVIRTUAL 1
# define NN_NOTIFYINFERIOR 2
# define NN_NOTIFYNONLINEAR	 3
# define NN_NOTIFYNONLINEARVIRTUAL 4
# define NN_NOTIFYPOINTER 5
# define NN_NOTIFYPOINTERROOT 6
# define NN_NOTIFYDETAILNONE 7
# define NN_CLIENTMESSAGE 33
# define NN_SELECTIONCLEAR 29
# define NN_SELECTIONREQUEST 30
# define NN_NOEVENTMASK 0L
# define NN_KEYPRESSMASK (1L<<0)
# define NN_KEYRELEASEMASK (1L<<1)
# define NN_BUTTONPRESSMASK (1L<<2)
# define NN_BUTTONRELEASEMASK (1L<<3)
# define NN_ENTERWINDOWMASK (1L<<4)
# define NN_LEAVEWINDOWMASK (1L<<5)
# define NN_POINTERMOTIONMASK (1L<<6)
# define NN_POINTERMOTIONHINTMASK (1L<<7)
# define NN_BUTTON1MOTIONMASK (1L<<8)
# define NN_BUTTON2MOTIONMASK (1L<<9)
# define NN_BUTTON3MOTIONMASK (1L<<10)
# define NN_BUTTON4MOTIONMASK (1L<<11)
# define NN_BUTTON5MOTIONMASK (1L<<12)
# define NN_BUTTONMOTIONMASK (1L<<13)
# define NN_KEYMAPSTATEMASK (1L<<14)
# define NN_EXPOSUREMASK (1L<<15)
# define NN_VISIBILITYCHANGEMASK (1L<<16)
# define NN_STRUCTURENOTIFYMASK (1L<<17)
# define NN_RESIZEREDIRECTMASK (1L<<18)
# define NN_SUBSTRUCTURENOTIFYMASK (1L<<19)
# define NN_SUBSTRUCTUREREDIRECTMASK (1L<<20)
# define NN_FOCUSCHANGEMASK (1L<<21)
# define NN_PROPERTYCHANGEMASK (1L<<22)
# define NN_COLORMAPCHANGEMASK (1L<<23)
# define NN_OWNERGRABBUTTONMASK (1L<<24)
# define NN_SHIFTMASK (1<<0)
# define NN_LOCKMASK (1<<1)
# define NN_CONTROLMASK (1<<2)
# define NN_MOD1MASK (1<<3)
# define NN_MOD2MASK (1<<4)
# define NN_MOD3MASK (1<<5)
# define NN_MOD4MASK (1<<6)
# define NN_MOD5MASK (1<<7)
# define NN_BUTTON1MASK (1<<8)
# define NN_BUTTON2MASK (1<<9)
# define NN_BUTTON3MASK (1<<10)
# define NN_BUTTON4MASK (1<<11)
# define NN_BUTTON5MASK (1<<12)
#endif
