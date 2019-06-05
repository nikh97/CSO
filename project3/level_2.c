/*
 * author:
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "problem3.h"

// Implement a C function called level_2_opt. It should perform the same
// task as the implemented level_2 function.
// In the comments for the function describe why your changes make the
// function more cache friendly.


void level_2(data * list, double * sum_d, int * sum_n)
{
    int i;

    for(i = 0; i < LARGER; i++){
        *sum_d += list[i].d;
    }

    for(i = 0; i < LARGER; i++){
        *sum_n += list[i].n1 ;
    }

    for(i = 0; i < LARGER; i++){
        *sum_n += list[i].n2;
    }

}

/*
* The original code does not take advantage of the temporal 
* locality of the data object at each index i. Rather than 
* referencing the object's data fields all at once, it does it 3
* seperate times, essentially increasing read misses by 3x the amount
* it could be. By just referencing the object and its fields once during
* the program, we can greatly improve temporal locality.
*/

void level_2_opt(data * list, double * sum_d, int * sum_n)
{
    int i;

    // use one for loop rather than once
    // only needs to access each data object once
    for(i = 0; i < LARGER; i++){

        // add the data field values to the corresponding sum variable
        *sum_d += list[i].d;
        *sum_n += list[i].n1;
        *sum_n += list[i].n2;
    }

}
