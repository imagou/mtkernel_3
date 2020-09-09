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
 *	sysdef.h
 *
 *	System dependencies definition (STM32L475 depended)
 *	Included also from assembler program.
 */

#ifndef __TK_SYSDEF_DEPEND_CPU_H__
#define __TK_SYSDEF_DEPEND_CPU_H__


/* CPU Core-dependent definition */
#include "../core/acm4/sysdef.h"

/* ------------------------------------------------------------------------ */
/*
 * Internal Memorie (Main RAM)  0x20000000 - 0x20017FFF
 */
#define INTERNAL_RAM_SIZE       0x00018000
#define INTERNAL_RAM_START      0x20000000
#define INTERNAL_RAM_END        (INTERNAL_RAM_START+INTERNAL_RAM_SIZE)

/* ------------------------------------------------------------------------ */
/*
 * Initial Stack pointer (Used in initialization process)
 */
#define	INITIAL_SP		INTERNAL_RAM_END


/* ------------------------------------------------------------------------ */
/*
 * Reset and Clock Control
 */

#define RCC_BASE		0x40021000
#define RCC_CR			(RCC_BASE + 0x0000)
  #define RCC_CR_MSIPLLEN			0x00000004
  #define RCC_CR_MSIRGSEL			0x00000008
  #define RCC_CR_MSIRANGE			0x000000F0
  #define RCC_CR_PLLON				0x01000000
  #define RCC_CR_PLLRDY				0x02000000
#define RCC_CFGR		(RCC_BASE + 0x0008)
  #define RCC_CFGR_SW				0x00000003
  #define RCC_CFGR_SW_PLL			0x00000003
  #define RCC_CFGR_SWS				0x0000000C
  #define RCC_CFGR_SWS_PLL			0x0000000C
#define RCC_PLLCFGR		(RCC_BASE + 0x000C)
  #define RCC_PLLCFGR_PLLSRC_MSI	0x00000001
  #define RCC_PLLCFGR_PLLREN		0x01000000
#define RCC_AHB2ENR		(RCC_BASE + 0x004C)
#define RCC_APB1ENR1	(RCC_BASE + 0x0058)
  #define RCC_APB1ENR1_PWREN		0x10000000
#define RCC_APB2ENR		(RCC_BASE + 0x0060)
#define RCC_CCIPR		(RCC_BASE + 0x0088)
  #define RCC_CCIPR_CLK48SEL		0x0C000000
#define RCC_BDCR		(RCC_BASE + 0x0090)
  #define RCC_BDCR_LSEON			0x00000001
  #define RCC_BDCR_LSERDY			0x00000002


/* ------------------------------------------------------------------------ */
/*
 * Clock Control
 */

/* Clock Generator Registers */
//#define CLKCTRL_BASE		0x400F3000
//#define CLKCTRL_CGSYSCR		(CLKCTRL_BASE + 0x0000)
//#define CLKCTRL_CGOSCCR		(CLKCTRL_BASE + 0x0004)
//#define CLKCTRL_CGSTBYCR	(CLKCTRL_BASE + 0x0008)
//#define CLKCTRL_CGPLLSEL	(CLKCTRL_BASE + 0x000C)
//#define CLKCTRL_CGCKSTP		(CLKCTRL_BASE + 0x0018)
//#define CLKCTRL_CGPROTECT	(CLKCTRL_BASE + 0x003C)
//#define CLKCTRL_CGIMCG		(CLKCTRL_BASE + 0x0040)
//#define CLKCTRL_CGICRCG		(CLKCTRL_BASE + 0x0060)

/* PLL Selection */
//#define	CLKCTRL_CGPLLSEL_4X		0x00005A0F
//#define	CLKCTRL_CGPLLSEL_6X		0x00006296

//#define CLKCTRL_CGPLLSEL_PLLSEL		0x00000001

/* Oscillation control */
//#define CLKCTRL_CGOSCCR_ALWAYSWRITE	0x00000030

//#define CLKCTRL_CGOSCCR_WUEON		0x00000001
//#define CLKCTRL_CGOSCCR_WUEF		0x00000002
//#define CLKCTRL_CGOSCCR_PLLON		0x00000004
//#define CLKCTRL_CGOSCCR_WUPSEL_XT1	0x00000008

//#define CLKCTRL_CGOSCCR_WUPT(usec,MHz)	( (usec * MHz) >> 4 ) << 20

//#define HISPEED_CLOCK_MHz	12

//#define PLL_MODE_4X		4
//#define PLL_MODE_6X		6

//#define	CLOCK_fPLL		(HISPEED_CLOCK_MHz * PLL_MODE_6X * 1000000)
#define	CLOCK_fPLL		(80 * 1000000)
//#define	CLOCK_fc		(CLOCK_fPLL)
//#define	CLOCK_fgear		(CLOCK_fc / 2)
//#define	CLOCK_fsys		(CLOCK_fgear)
#define	CLOCK_fsys		(CLOCK_fPLL)
//#define	CLOCK_fperiph		(CLOCK_fgear)
//#define	CLOCK_T0		(CLOCK_fperiph)

#define TMCLK			(CLOCK_fsys / 1000000)	/* Timer clock input (MHz) */
#define TMCLK_KHz		(CLOCK_fsys / 1000)	/* Timer clock input (kHz) */

/*
 * Settable interval range (millisecond)
 */
#define MIN_TIMER_PERIOD	1
#define MAX_TIMER_PERIOD	50


/* ------------------------------------------------------------------------ */
/*
 * Power Control
 */

#define PWR_BASE		0x40007000
#define PWR_CR1			(PWR_BASE + 0x0000)
  #define PWR_CR1_DBP				0x00000100


/* ------------------------------------------------------------------------ */
/*
 * Embedded Flash memory (FLASH)
 */

#define FLASH_R_BASE	0x40022000
#define FLASH_ACR		(FLASH_R_BASE + 0x0000)
  #define FLASH_ACR_LATENCY			0x00000007


/* ------------------------------------------------------------------------ */
/*
 * Number of Interrupt vectors
 */
//#define N_INTVEC		128	/* Number of Interrupt vectors */
#define N_INTVEC		98	/* Number of Interrupt vectors */

/*
 * The number of the implemented bit width for priority value fields.
 */
#define INTPRI_BITWIDTH		3


/* ------------------------------------------------------------------------ */
/*
 * Interrupt Priority Levels
 */
#define INTPRI_MAX_EXTINT_PRI	1	/* Highest Ext. interrupt level */
#define INTPRI_SVC		0	/* SVCall */
#define INTPRI_SYSTICK		1	/* SysTick */
#define INTPRI_FORCE_DISPATCH	6	/* Force Dispatch */
#define INTPRI_PENDSV		7	/* PendSV */

/*
 * Time-event handler interrupt level
 */
//#define TIMER_INTLEVEL		0


/* ------------------------------------------------------------------------ */
/*
 * Watchdog Timer
 */
//#define WDOG_BASE		0x400F2000

//#define	WDOG_WDMOD		(WDOG_BASE + 0x0000)	/* Mode Reg. */
//#define	WDOG_WDCR		(WDOG_BASE + 0x0004)	/* Control Reg. */

//#define	WDOG_WDMOD_WDTE		0x00000080	/* Enable */
//#define	WDOG_WDCR_DISABLE	0x000000B1	/* Disable Code */


/* ------------------------------------------------------------------------ */
/*
 * GPIO
 */
#define GPIOB_BASE		0x48000400

#define	MODER(n)	(GPIO##n##_BASE + 0x00)
#define	OTYPER(n)	(GPIO##n##_BASE + 0x04)
#define	OSPEEDR(n)	(GPIO##n##_BASE + 0x08)
#define	PUPDR(n)	(GPIO##n##_BASE + 0x0C)
#define	AFRL(n)		(GPIO##n##_BASE + 0x20)

/* ------------------------------------------------------------------------ */
/*
 * Coprocessor
 */
//#define CPU_HAS_FPU			0
//#define CPU_HAS_DPS			0

/*
 *  Number of coprocessors to use. 
 *    There is no coprocessor for this microcomputer.
 */
//#define NUM_COPROCESSOR		0

#endif /* __TK_SYSDEF_DEPEND_CPU_H__ */
