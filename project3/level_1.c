/*
 * author:
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "problem3.h"

// Implement a C function called level_1_opt. It should perform the same
// task as the implemented level_1 function.
// In the comments for the function describe why your changes make the
// function more cache friendly.
//
// Note: your function needs to compute the entire matrix C,
// not only its x entry.

long level_1(long * B, long * A, int x)
{
    long * C = (long * ) malloc (N*N*sizeof(long) );
    if (!C) return 0;

    int c, r;

    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            C[ r*N + c ] = B[ r*N + c ] + A[ c*N + r ] ;

    long ret = C[x];
    free (C); C = 0;
    return ret;
}


/*
* The original function does not take advantage of the facts that
* arrays are stored using row major order. In addition, it could further
* take advantage of temporal locality. First, by splitting the for loops
* seperately, it makes references to repeated values. Also, in the second set
* of for loops, the array C is already loaded into memory and can be easily accessed,
* greatly reducing write misses. Then for the first for loop, but switching the for loops
* from the original code, we can use stride-1 vs. stride-N patterns on C and B. In the
* second set of for loops, we can use stride-1 vs. stride-N on A. This takes advantage
* of spatial locality and helps reduce read misses.
*/

long level_1_opt(long * B, long * A, int x)
{
    // DO NOT modify the following declarations
    long * C = (long * ) malloc (N*N*sizeof(long) );
    if (!C) return 0;

    // enter your code here

    int c,r;

    // first add the corresponding element from array B to C
    // first go through c and then r
    // this will then write to C and read from B sequentially
    for(r = 0; r < N; r++)
        for(c = 0; c < N; c++)
            C[r*N + c] += B[r*N + c];

    // then add the corresponding element from array A to C
    // go through r, and then c
    // we can then read from A sequntially
    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            C[r*N + c] += A[ c*N + r ];






    //DO NOT modify the rest of this function
    long ret = C[x];
    free (C); C = 0;
    return ret;
}
