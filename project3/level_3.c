/*
 * author:
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "problem3.h"

// Implement a C function called level_3_opt. It should perform the same
// task as the implemented level_3 function.
// In the comments for the function describe why your changes make the
// function more cache friendly.
// Note that this function does not return any value. It modifies the array
// that is passed to it, instead.

void level_3 (int *A, int n)
{
    int  i, j;
    for (i = 0; i < n; i++)
	    for (j = 0; j < n; j++)
	        A[j*n + i] = A[j*n + i] || A[i*n + j];

}


/*
* The original problem does not take advantage of the spatial 
* locality of arrays. For example by running through j, and then i
* we are accessing and overwriting the values in A at the order of
* A[0], A[n], A[2n], etc. By switching the for loops, we can take 
* advantage of the row-major ordering of memory. 
*/
void level_3_opt (int *A, int n)
{
	int i,j;

	// switch the original for loops 
	// will first read from memory sequentially
	for(j = 0; j < n; j++)
		for(i = 0; i < n; i++)
			A[j*n + i] = A[j*n + i] || A[i*n + j];

}
