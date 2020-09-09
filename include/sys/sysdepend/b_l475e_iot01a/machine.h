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
 *	machine.h
 *
 *	Machine type definition (STM32L4 Discovery kit IoT node depended)
 */

#ifndef __SYS_SYSDEPEND_MACHINE_H__
#define __SYS_SYSDEPEND_MACHINE_H__

/*
 * [TYPE]_[CPU]		TARGET SYSTEM
 * CPU_xxxx		CPU type
 * CPU_CORE_xxx		CPU core type
 */

/* ----- STM32L4 Discovery kit IoT node (CPU: STM32L475VGT6) definition ----- */

#define B_L475E_IOT01A		1				/* Target system : STM32L4 Discovery kit IoT node */
#define CPU_STM32L475VGT6	1				/* Target CPU : STMicroelectronics STM32L475VGT6 */
#define CPU_CORE_ACM4		1				/* Target CPU-Core : ARM Cortex-M4 */

#define TARGET_DIR		b_l475e_iot01a			/* Sysdepend-Directory name */

/*
 **** CPU-depeneded profile (STM32L475)
 */
#include "../cpu/stm32l475/machine.h"


#endif /* __SYS_SYSDEPEND_MACHINE_H__ */
