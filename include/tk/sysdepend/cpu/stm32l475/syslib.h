/*
 *----------------------------------------------------------------------
 *    micro T-Kernel 3.00.01
 *
 *    Copyright (C) 2006-2020 by Ken Sakamura.
 *    This software is distributed under the T-License 2.2.
 *----------------------------------------------------------------------
 *
 *    Released by TRON Forum(http://www.tron.org) at 2020/05/29.
 *
 *----------------------------------------------------------------------
 */

/*
 *	syslib.h
 *
 *	micro T-Kernel System Library  (STM32L475 depended)
 */

#ifndef __TK_SYSLIB_CPU_DEPEND_H__
#define __TK_SYSLIB_CPU_DEPEND_H__

#include "../core/acm4/syslib.h"

/* ------------------------------------------------------------------------ */
/*
 * Interrupt number
 */
#define	STM32L475_INT0		0
#define	STM32L475_INT1		1
#define	STM32L475_INT2		2
#define	STM32L475_INT3		3
#define	STM32L475_INT4		4
#define	STM32L475_INT5		5
#define	STM32L475_INT6		6
#define	STM32L475_INT7		7
#define	STM32L475_INT8		8
#define	STM32L475_INT9		9
#define	STM32L475_INTA		10
#define	STM32L475_INTB		11
#define	STM32L475_INTC		12
#define STM32L475_INTD		13
#define	STM32L475_INTUSBWKUP		34
#define STM32L475_INTRMCRX		74
#define	STM32L475_INTRTC		99

/* ------------------------------------------------------------------------ */
/*
 * Interrupt mode ( SetIntMode )
 */
#define IM_LEVEL	0x0002		/* Level trigger */
#define IM_EDGE		0x0000		/* Edge trigger */
#define IM_HI		0x0000		/* H level/Interrupt at rising edge */
#define IM_LOW		0x0001		/* L level/Interrupt at falling edge */


/* ------------------------------------------------------------------------ */
/*
 * I/O port access
 *	for memory mapped I/O
 */
Inline void out_w( UW port, UW data )
{
	*(_UW*)port = data;
}
Inline void out_h( UW port, UH data )
{
	*(_UH*)port = data;
}
Inline void out_b( UW port, UB data )
{
	*(_UB*)port = data;
}

Inline UW in_w( UW port )
{
	return *(_UW*)port;
}
Inline UH in_h( UW port )
{
	return *(_UH*)port;
}
Inline UB in_b( UW port )
{
	return *(_UB*)port;
}

/* ------------------------------------------------------------------------ */
/*
 * Low-level access
 */
Inline UW low_rew(UW addr)			{ UW val = *((const volatile UW*)(addr)); return val; }
Inline void low_wrw(UW addr, UW x)	{ *((volatile UW*)(addr)) = x; }
#define low_setw(addr, x)		low_wrw((addr), (low_rew(addr) | (x)))
#define low_clrw(addr, x)		low_wrw((addr), (low_rew(addr) & ~(x)))
#define low_modw(addr, x, y)	low_wrw((addr), (low_rew(addr) & (~x)) | (y))

#endif /* __TK_SYSLIB_DEPEND_H__ */
