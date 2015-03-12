/*rational_approximant.cu
*	The generic initialization file for poles/hosts for RA based evaulation of the matrix exponential
* \file rational_approximant.cu
*
* \author Nicholas Curtis
* \date 03/09/2015
*
* Contains initialization and declaration of RA
*/

//cf
#include "header.h"
#include "cf.h"
#include <complex.h>

double complex poles[N_RA];
double complex res[N_RA];

void find_poles_and_residuals()
{
	// get poles and residues for rational approximant to matrix exponential
    double *poles_r = (double *) calloc (N_RA, sizeof(double));
    double *poles_i = (double *) calloc (N_RA, sizeof(double));
    double *res_r = (double *) calloc (N_RA, sizeof(double));
    double *res_i = (double *) calloc (N_RA, sizeof(double));

    cf (N_RA, poles_r, poles_i, res_r, res_i);

    double complex polesHost[N_RA];
    double complex resHost[N_RA];

    for (int i = 0; i < N_RA; ++i)
    {
        poles[i] = poles_r[i] + poles_i[i] * _Complex_I;
        res[i] = res_r[i] + res_i[i] * _Complex_I;
    }

    // free memory
    free (poles_r);
    free (poles_i);
    free (res_r);
    free (res_i);
}