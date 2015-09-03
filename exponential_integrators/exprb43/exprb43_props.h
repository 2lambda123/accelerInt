/*rb43_props.h
 *Various macros controlling behaviour of RB43 algorithm
 * \file rb43_props.h
 * \author Nicholas Curtis
 * \date 03/10/2015
 */

#ifndef RB43_PROPS_H
#define RB43_PROPS_H

#include "header.h"

//if defined, uses (I - h * Hm)^-1 to smooth the krylov error vector
//#define USE_SMOOTHED_ERROR
//max order of the phi functions (i.e. for error estimation)
#define P 4
//order of embedded methods
#define ORD 3
#define M_MAX NN
#define STRIDE (M_MAX + P)

#ifdef LOG_KRYLOV_AND_STEPSIZES
 	//the size of the logging arrays
 	#define MAX_STEPS 10000
#endif

#endif