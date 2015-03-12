/*solver_generic.cu
 * the generic integration driver for all GPU solvers
 * \file solver_generic.cu
 *
 * \author Nicholas Curtis
 * \date 03/10/2015
 *
 */

#include "header.h"
#include "solver.h"

void intDriver (const int NUM, const Real t, const Real t_end,
                const Real *pr_global, Real *y_global)
{
    int tid;
    #pragma omp parallel for shared(y_global, pr_global) private(tid)
    for (tid = 0; tid < NUM; ++tid) {

        // local array with initial values
        Real y_local[NN];
        Real pr_local = pr_global[tid];

        // load local array with initial values from global array
#pragma unroll
        for (int i = 0; i < NN; i++)
        {
            y_local[i] = y_global[tid + i * NUM];
        }

        // call integrator for one time step
        integrate (t, t_end, pr_local, y_local);

        // update global array with integrated values
#pragma unroll
        for (int i = 0; i < NN; i++)
        {
            y_global[tid + i * NUM] = y_local[i];
        }

    } //end tid loop

} // end intDriver