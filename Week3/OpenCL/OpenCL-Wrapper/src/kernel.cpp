#include "kernel.hpp" // note: unbalanced round brackets () are not allowed and string literals can't be arbitrarily long, so periodically interrupt with )+R(
string opencl_c_container() { return R( // ########################## begin of OpenCL C code ####################################################################



kernel void add_kernel(global float* A, global float* B, global float* C) { // equivalent to "for(uint n=0u; n<N; n++) {", but executed in parallel
	const uint n = get_global_id(0);
	C[n] = A[n]+B[n];
}

kernel void mul_kernel(global float* A2, global float* B2, global float* C2) {
	// TASK 1 CODE BEGINS HERE
	const uint n = get_global_id(0);
	C2[n] = A2[n]*B2[n];
	return;
	// TASK 1 CODE ENDS HERE
}

kernel void matMul (__global float* A, __global float *B, __global float *C, int aCol, int cRow, int cCol) {
	// TASK 2 CODE BEGINS HERE
	// HINT : IMPLEMENT DOT PRODUCT HERE
	const uint a = get_global_id(0);
	//const uint col = get_global_id(1);
	const uint row = a/cCol;
	const uint col = a%cCol;
	if  (row<cRow && col < cCol){
		for (int k=0; k<aCol; k++){
			C[row*cCol + col] += A[row*aCol + k]*B[k*cCol + col];
			//std::cout<<"ROW"<<row<<" COL"<<col;
			//C[row*cCol + col] = row;
		}
	}
	return;
	// TASK 2 CODE ENDS HERE
}


);} // ############################################################### end of OpenCL C code #####################################################################
