
#include "p1.h"
#include <stdio.h>

/*
 * Implementation file for functions
 * declared in p1.h
 */ 


int is_valid_triangle ( int n ) {

	//mask to get ten bits of each side
	int mask = 0b1111111111;
    
    //get ten lowest bits
	int s1 = n & mask;

	//get next ten lowest bits
	int s2 = (n >> 10) & mask;

	//get last ten bits
	int s3 = (n >> 20) & mask;

	//check condition for triangle
	if((s1 + s2 > s3) && (s1 + s3 > s2) && (s2 + s3 > s1))
		return 1;
	else
		return 0;

}
