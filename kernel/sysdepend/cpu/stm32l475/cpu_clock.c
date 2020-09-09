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
 *	cpu_clock.c (STM32L475)
 *	Clock Setting
 */

#include <tk/tkernel.h>

#include "sysdepend.h"
#include "sys_timer.h"

/*
 *  PLL Setting
 */
EXPORT void enable_pll(UB pll_mode)
{
#define POLLING_(expr, msec)	\
	tick = 0;	\
	while (!(expr)) {	\
		if (tick > (msec)) goto error_loop;	\
		tick++;	\
		WaitUsec(1);	\
	}

	UW tick;

	/* For Call WaitUsec() */
	knl_init_hw_timer();

	/* Backup Domain */
	low_setw(RCC_APB1ENR1, RCC_APB1ENR1_PWREN);
	low_setw(PWR_CR1, PWR_CR1_DBP);
	POLLING_(low_rew(PWR_CR1) & PWR_CR1_DBP, (100 * 1000));
	low_setw(RCC_BDCR, RCC_BDCR_LSEON);
	POLLING_(low_rew(RCC_BDCR) & RCC_BDCR_LSERDY, (5000 * 1000));
	low_clrw(RCC_APB1ENR1, RCC_APB1ENR1_PWREN);

	/* Latency to 2 */
	UW latency = 2;
	low_modw(FLASH_ACR, FLASH_ACR_LATENCY, latency);
	if ((low_rew(FLASH_ACR) & FLASH_ACR_LATENCY) != latency)
		goto error_loop;

	/* RCC MSI */
	low_setw(RCC_CR, RCC_CR_MSIRGSEL);
	low_modw(RCC_CR, RCC_CR_MSIRANGE, 11 << 4);
	low_setw(RCC_CR, RCC_CR_MSIPLLEN);
	low_setw(RCC_CCIPR, RCC_CCIPR_CLK48SEL);

	/* PLL Enable */
	low_wrw(RCC_PLLCFGR, (
		(1	<< 0) |		// PLLSRC - MSI
		(5	<< 4) |		// PLLM - 6
		(40	<< 8) |		// PLLN - 40
		(0	<< 17) |	// PLLP - 7
		(1	<< 21) |	// PLLQ - 4
		(1	<< 25)		// PLLR - 4
	));
	low_setw(RCC_CR, RCC_CR_PLLON);
	low_setw(RCC_PLLCFGR, RCC_PLLCFGR_PLLREN);
	POLLING_(low_rew(RCC_CR) & RCC_CR_PLLRDY, (5000 * 1000));

	/* Latency to 4 */
	latency = 4;
	low_modw(FLASH_ACR, FLASH_ACR_LATENCY, latency);
	if ((low_rew(FLASH_ACR) & FLASH_ACR_LATENCY) != latency)
		goto error_loop;

	/* SYSCLK to PLL */
	low_modw(RCC_CFGR, RCC_CFGR_SW, RCC_CFGR_SW_PLL);
	POLLING_((low_rew(RCC_CFGR) & RCC_CFGR_SWS) == RCC_CFGR_SWS_PLL, (5000 * 1000));

	return;

error_loop:
	while (1) {}

#undef POLLING_
}


EXPORT void disable_pll()
{

}

#endif /* CPU_STM32L475VGT6 */
