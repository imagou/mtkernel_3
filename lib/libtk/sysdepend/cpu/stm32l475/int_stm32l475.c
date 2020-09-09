/*
 *----------------------------------------------------------------------
 *    micro T-Kernel 3.00.00
 *
 *    Copyright (C) 2006-2019 by Ken Sakamura.
 *    This software is distributed under the T-License 2.1.
 *----------------------------------------------------------------------
 *
 *    Released by TRON Forum(http://www.tron.org) at 2019/12/11.
 *
 *----------------------------------------------------------------------
 */

#include <sys/machine.h>
#ifdef CPU_STM32L475VGT6

/*
 *	int.c
 *
 *	Interrupt controller (STM32L475)
 */
#include <tk/tkernel.h>
#include <tk/syslib.h>
/*
 * Clear interrupt
 */
EXPORT void ClearInt(UINT intno)
{
	ClearPendingInt(intno);		/* Un-pends the associated interrupt */

	/* Not implemented. */
}

/*
 * Set interrupt mode
 */
EXPORT void SetIntMode(UINT intno, UINT mode)
{
	/* Not implemented. */
}

#endif /* CPU_STM32L475VGT6 */
