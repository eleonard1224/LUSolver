#include "solver.h"


// This script is for solving a system of linear equations
// of the form Ax = b using LU decomposition without row exchanges

int main() {

	int r; // This is a return code
	int n; // Dimension of matrix
	int i, j; // Index through a loop
	double **A = NULL; // A is an n x n matrix
	double **L = NULL; // L is a lower triangular n x n matrix
	double **U = NULL; // L is an upper triangular n x n matrix
	double *b = NULL; // b is an n x 1 column vector
	double *x = NULL; // x is an n x 1 column vector

	n = 3; 

	// Allocating memory

	A = (double **) calloc(n, sizeof(*A));

	for(i = 0; i < n; i++) {
		A[i] = (double *) calloc(n, sizeof(**A));
	}

	
	// Example
	A[0][0] = 2.0; A[0][1] = 1.0; A[0][2] = 0.0;
	A[1][0] = 0.0; A[1][1] = 4.0; A[1][2] = 2.0;
	A[2][0] = 6.0; A[2][1] = 11.0; A[2][2] = 5.0;
	

	L = (double **) calloc(n, sizeof(*L));

	for(i = 0; i < n; i++) {
		L[i] = (double *) calloc(n, sizeof(**L));
	}

	U = (double **) calloc(n, sizeof(*U));

	for(i = 0; i < n; i++) {
		U[i] = (double *) calloc(n, sizeof(**U));
	}

	b = (double *) calloc(n, sizeof(*b));

	
	// Example
	b[0] = 3.0; b[1] = 6.0; b[2] = 22.0;
	

	x = (double *) calloc(n, sizeof(*x));


	// Calling the slv routine
	r = slv(L, U, A, x, b, n);
	

	// Printing x where Ax = b
	for(i = 0; i < n; i++) {
		printf("x[%d] = %2.1f\n",i,x[i]);
	}

	// Freeing memory
	
	for(i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);

	for(i = 0; i < n; i++) {
		free(U[i]);
	}
	free(U);

	for(i = 0; i < n; i++) {
		free(L[i]);
	}
	free(L);

	free(b);

	free(x);
	

	return r;
}