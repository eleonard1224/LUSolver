#include <stdlib.h>
#include <math.h>
#include <stdio.h>

int slu(double **L, double **U, double **A, int n);
int slv(double **L, double **U, double **A, double *x, double *b, int n);