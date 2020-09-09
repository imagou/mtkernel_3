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
 *    tm_com.c
 *    T-Monitor Communication low-level device driver (STM32L4 Discovery kit IoT node)
 */

#include <tk/typedef.h>
#include <tk/syslib.h>
#include <sys/sysdef.h>
#include "../../libtm.h"

#ifdef USE_COM_B_L475E_IOT01A

#define	USART_BASE		0x40013800
#define USART_CR1		(USART_BASE + 0x0000)
  #define USART_CR1_UE		0x00000001
  #define USART_CR1_RE		0x00000004
  #define USART_CR1_TE		0x00000008
  #define USART_CR1_RXNEIE	0x00000020
  #define USART_CR1_TXEIE	0x00000080
#define USART_BRR		(USART_BASE + 0x000C)
#define USART_ISR		(USART_BASE + 0x001C)
  #define USART_ISR_RXNE	0x00000020
  #define USART_ISR_TC		0x00000040
#define USART_RDR		(USART_BASE + 0x0024)
#define USART_TDR		(USART_BASE + 0x0028)


EXPORT	void	tm_snd_dat( const UB* buf, INT size )
{
	UB	*b;

	for( b = (UB *)buf; size > 0; size--, b++ ){
		low_wrw(USART_TDR, *b);
		while (!(low_rew(USART_ISR) & USART_ISR_TC));
	}
}


EXPORT	void	tm_rcv_dat( UB* buf, INT size )
{
	for( ; size > 0; size--, buf++ ){
		while (!(low_rew(USART_ISR) & USART_ISR_RXNE));
		*buf = (UB)(low_rew(USART_RDR) & 0xFF);
	}
}

EXPORT	void	tm_com_init(void)
{
	/* USART */
	low_setw(USART_CR1, (USART_CR1_UE | USART_CR1_RE | USART_CR1_TE));
	UW apbclock = CLOCK_fsys;
	UW brr = (apbclock + (115200 / 2)) / 115200;
	low_wrw(USART_BRR, brr);
	low_clrw(USART_CR1, (USART_CR1_TXEIE | USART_CR1_RXNEIE));
	low_setw(USART_CR1, USART_CR1_UE);
}

/* Temporary implementation */
EXPORT BOOL tm_com_rcv_rdy(void)
{
	return (low_rew(USART_ISR) & USART_ISR_RXNE);
}

#endif /* USE_COM_B_L475E_IOT01A */
