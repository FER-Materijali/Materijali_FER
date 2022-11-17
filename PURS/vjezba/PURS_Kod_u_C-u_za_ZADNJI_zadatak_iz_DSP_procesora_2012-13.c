#include <fract.h>
#include <filter.h>
#include "signal_fract16.h"
#include "coeffs_fract16.h"
#include <cycle_count.h>
#include <stdio.h>
#include <ccblkfn.h>

#define L 21 /* broj uzoraka impulsnog odziva */
#define Nsamp 1000  /* broj koeficijenta*/

fract16 delay[L];
short idx_delay = 0;
fract16 izlbuf[Nsamp];
short idx_izlbuf = 0;



int main()
{
	int i;
	cycle_t start_count;
	cycle_t final_count;
	fir_state_fr16 state;

	
	for(i=0;i<L;i++) 
	{
		delay[i]=0;
	}
	
	START_CYCLE_COUNT(start_count);
	fir_init (state, (fract16 *)coeffs, delay, L, 1);
	fir_fr16 (signal, izlbuf, Nsamp, &state);
	STOP_CYCLE_COUNT(final_count, start_count);
	
	
	
	for(i=0;i<Nsamp;++i)
	{
		printf("Number of cycles: %d\n",final_count);
		printf("%d\n", izlbuf[i]);		
	}
	return 0;
}


