/* radau2a_init.cu
*  Implementation of the necessary initialization for the Radau2A solver
 * \file radau2a_init.cu
 *
 * \author Nicholas Curtis
 * \date 03/09/2015
 *
 */

 #include "solver_init.cuh"

 void init_solver_log() {
 	
 }

 void solver_log() {
 	
 }

 const char* solver_name() {
 	const char* name = "radau2a-int-gpu";
 	return name;
 }

 size_t required_solver_size() {
 	//return the size (in bytes), needed per cuda thread
 	size_t num_bytes = 0;
  //regular jacobian factorization
  num_bytes += NSP * NSP * sizeof(double);
  //complex jacobian factorization
  num_bytes += NSP * NSP * sizeof(cuDoubleComplex);
 	//an error scale array
 	num_bytes += NSP * sizeof(double);
  //two pivot index arrays
  num_bytes += 2 * NSP * sizeof(int);
 	//6 RHS and interpolant arrays
 	num_bytes += 6 * NSP * sizeof(double);
 	//continuation array of size 3 * NSP
 	num_bytes += 3 * NSP * sizeof(double);
 	//y0
 	num_bytes += NSP * sizeof(double);
 	//3 work arrays
 	num_bytes += 3 * NSP * sizeof(double);
  //1 complex work array
  num_bytes += NSP * sizeof(double);
  //result flag
  num_bytes += 1 * sizeof(int);
  
  return num_bytes;
 }

void createAndZero(void** ptr, size_t size)
{
  cudaErrorCheck(cudaMalloc(ptr, size));
  cudaErrorCheck(cudaMemset(*ptr, 0, size));
}

void initialize_solver(const int padded, solver_memory** h_mem, solver_memory** d_mem) {
  // Allocate storage for the device struct
  cudaErrorCheck( cudaMalloc(d_mem, sizeof(solver_memory)) );
  //allocate the device arrays on the host pointer
  createAndZero((void**)&((*h_mem)->E1), NSP * NSP * padded * sizeof(double));
  createAndZero((void**)&((*h_mem)->E2), NSP * NSP * padded * sizeof(cuDoubleComplex));
  createAndZero((void**)&((*h_mem)->scale), NSP * padded * sizeof(cuDoubleComplex));
  createAndZero((void**)&((*h_mem)->ipiv1), NSP * padded * sizeof(int));
  createAndZero((void**)&((*h_mem)->ipiv2), NSP * padded * sizeof(int));
  createAndZero((void**)&((*h_mem)->Z1), NSP * padded * sizeof(double));
  createAndZero((void**)&((*h_mem)->Z2), NSP * padded * sizeof(double));
  createAndZero((void**)&((*h_mem)->Z3), NSP * padded * sizeof(double));
  createAndZero((void**)&((*h_mem)->DZ1), NSP * padded * sizeof(double));
  createAndZero((void**)&((*h_mem)->DZ2), NSP * padded * sizeof(double));
  createAndZero((void**)&((*h_mem)->DZ3), NSP * padded * sizeof(double));
  createAndZero((void**)&((*h_mem)->CONT), 3 * NSP * padded * sizeof(double));
  createAndZero((void**)&((*h_mem)->y0), NSP * padded * sizeof(double));
  createAndZero((void**)&((*h_mem)->work1), NSP * padded * sizeof(double));
  createAndZero((void**)&((*h_mem)->work2), NSP * padded * sizeof(double));
  createAndZero((void**)&((*h_mem)->work3), NSP * padded * sizeof(double));
  createAndZero((void**)&((*h_mem)->work4), NSP * padded * sizeof(cuDoubleComplex));
  createAndZero((void**)&((*h_mem)->result), padded * sizeof(int));

  //copy host struct to device
  cudaErrorCheck( cudaMemcpy(*d_mem, *h_mem, sizeof(solver_memory), cudaMemcpyHostToDevice) );
}

 void cleanup_solver(solver_memory** h_mem, solver_memory** d_mem) {
  cudaErrorCheck(cudaFree((*h_mem)->E1));
  cudaErrorCheck(cudaFree((*h_mem)->E2));
  cudaErrorCheck(cudaFree((*h_mem)->scale));
  cudaErrorCheck(cudaFree((*h_mem)->ipiv1));
  cudaErrorCheck(cudaFree((*h_mem)->ipiv2));
  cudaErrorCheck(cudaFree((*h_mem)->Z1));
  cudaErrorCheck(cudaFree((*h_mem)->Z2));
  cudaErrorCheck(cudaFree((*h_mem)->Z3));
  cudaErrorCheck(cudaFree((*h_mem)->DZ1));
  cudaErrorCheck(cudaFree((*h_mem)->DZ2));
  cudaErrorCheck(cudaFree((*h_mem)->DZ3));
  cudaErrorCheck(cudaFree((*h_mem)->CONT));
  cudaErrorCheck(cudaFree((*h_mem)->y0));
  cudaErrorCheck(cudaFree((*h_mem)->work1));
  cudaErrorCheck(cudaFree((*h_mem)->work2));
  cudaErrorCheck(cudaFree((*h_mem)->work3));
  cudaErrorCheck(cudaFree((*h_mem)->work4));
  cudaErrorCheck(cudaFree((*h_mem)->result));
  cudaErrorCheck(cudaFree(*d_mem));
}