#include "solver.h"

// This source file has the routines for the LU decomposition and solution

// Square LU factorization with no row exchanges
int slu(double **L, double **U, double **A, int n) {

	double tol; // Tolerance limit for pivot
	int i, j, k; // Indices
	double m; // Multiplier

	tol = 1.0e-06;

	// Copying A over to U
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			U[i][j] = A[i][j];
		}
	}

	for(i = 0; i < (n-1); i++) {
		if (abs(U[i][i]) < tol) {
			return 0;
		}
		L[i][i] = 1.0;
		for(j = (i+1); j < n; j++) {
			m = -1.0*U[j][i]/U[i][i];
			L[j][i] = -1.0*m;
			for(k = i; k < n; k++) {
				U[j][k] = U[j][k] + m*U[i][k];
			}
		}
	}

	L[n-1][n-1] = 1.0;

	return 1;
}

// This solves Lc = b and then Ux = c
int slv(double **L, double **U, double **A, double *x, double *b, int n) {

	int r; // Return code
	int i,j; // Indices
	double csum, xsum;
	double *c; // This is for Lc = b

	// Allocating memory for c
	c = (double *) calloc(n, sizeof(*c));
	
	// Getting L and U
	r = slu(L,U,A,n);

	/*
	// Test
	if(r == 1) {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				printf("L[%d][%d] = %2.1f, U[%d][%d] = %2.1f\n", i, j, L[i][j], i, j, U[i][j]);
			}
		}
	}
	else {
		printf("Pivot is too close to zero\n");
		return r;
	}
	*/

	// Solving Lc = b
	for(i = 0; i < n; i++) {
		csum = 0.0;
		for(j = 0; j < i; j++) {
			csum = csum + c[j]*L[i][j];
		}
		c[i] = b[i] - csum;
	}

	/*
	// Test
	for(i = 0; i < n; i++) {
		printf("c[%d] = %2.1f\n",i,c[i]);
	}
	*/

	// Solving Ux = c
	for(i = (n-1); i > -1; i--) {
		xsum = 0.0;
		for(j = (n-1); j > i; j--) {
			xsum = xsum + x[j]*U[i][j];
		}
		x[i] = c[i] - xsum;
		x[i] = x[i]/U[i][i];
	}

	/*
	// Test
	for(i = 0; i < n; i++) {
		printf("x[%d] = %2.1f\n",i,x[i]);
	}
	*/


	free(c);

	return r;
}