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

#include <sys/machine.h>
#ifdef B_L475E_IOT01A

/*
 *	hw_setting.c (STM32L4 Discovery kit IoT node)
 *	startup / shoutdown processing for hardware
 */

#include "kernel.h"
#include <tm/tmonitor.h>

#include "sysdepend.h"

/* 
 * Setup pin functions Tadle
 */
typedef struct {
	UW	addr;
	UW	data;
} T_SETUP_REG;

LOCAL const T_SETUP_REG setup_regs[] = {
	// GPIOBEN
	{RCC_AHB2ENR,	0x00000002},
	// USART1EN
	{RCC_APB2ENR,	0x00004000},

	// PB6 - UART1_TX
	// PB7 - UART1_RX
	{MODER(B),		0xFFFFAFFF},
	{OSPEEDR(B),	0x0000F000},
	{OTYPER(B),		0x00000000},
	{PUPDR(B),		0x00005000},
	{AFRL(B),		0x77000000},

	{0, 0}
};


/*
 * Startup Device
 */
EXPORT void knl_startup_hw(void)
{
	const T_SETUP_REG	*p;

	enable_pll(0 /* Not Used */);

	/* Setup Pin Function */
	for(p = setup_regs; p->addr != 0; p++) {
//		*(_UW*)(p->addr) = p->data;
		low_wrw(p->addr, p->data);
	}
}

#if USE_SHUTDOWN
/*
 * Shutdown device
 */
EXPORT void knl_shutdown_hw( void )
{
	disint();
	while(1);
}
#endif /* USE_SHUTDOWN */

/*
 * Re-start device
 *	mode = -1		reset and re-start	(Reset -> Boot -> Start)
 *	mode = -2		fast re-start		(Start)
 *	mode = -3		Normal re-start		(Boot -> Start)
 */
EXPORT ER knl_restart_hw( W mode )
{
	switch(mode) {
	case -1: /* Reset and re-start */
		SYSTEM_MESSAGE("\n<< SYSTEM RESET & RESTART >>\n");
		return E_NOSPT;
	case -2: /* fast re-start */
		SYSTEM_MESSAGE("\n<< SYSTEM FAST RESTART >>\n");
		return E_NOSPT;
	case -3: /* Normal re-start */
		SYSTEM_MESSAGE("\n<< SYSTEM RESTART >>\n");
		return E_NOSPT;
	default:
		return E_PAR;
	}
}


#endif /* B_L475E_IOT01A */
