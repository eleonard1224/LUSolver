# LUSolver
Contains C/C++ code for an LU decomposition linear algebra solver

This repository contains C/C++ code which solves Ax = b through LU decomposition and contains three files.  main.cpp is the entry point to the program where the example arrays are created and the solution is printed out.  solver.cpp contains the linear algebra routines.  solver.h is a header file.  The code is currently programmed with the following example, A = [2 1 0; 0 4 2; 6 11 5] and b = [3 6 22] which leads to x = [1 1 1].  The solution, x, is printed out. 
