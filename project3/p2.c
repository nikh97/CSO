#include <stdio.h>
#include "p2.h"

/*
* Author: Nikhil Gosike
*
* This is a file that has three functions that take in
* an array of foo structs and evaluates the structs
* for each data field in the foo struct
*/


/*
* This is a function that finds and returns the minimum long value stored
* among all the foo structs in the array of foo structs
*/
long bar1(foo * p, int s){

	// checks if p is null or whether the s (the size) is zero
	if(p == 0 || s == 0)
		return 0;

	// minimum value, first assume the first struct has the minimum long value
	long m = p[0].y;

	int i;

	// then iterate from the second foo struct to the sth foo struct
	for(i = 1; i < s; i++){

		//continously check if the struct at index i has a long value less than m
		if(p[i].y <= m)

			//if so, update m
			m = p[i].y;
	}
	
	return m;
}


/*
* This is a function that finds and returns the minimum char value stored
* among all the foo structs in the array of foo structs
*/
int bar2(foo * p, int s){

	// checks if p is null or whether the s (the size) is zero
	if(p == 0 || s == 0)
		return 0;

	// minimum value, first assume the first struct has the minimum char value
	int m = p[0].z;

	int i;

	// then iterate from the second foo struct to the sth foo struct
	for(i = 1; i < s; i++){

		//continously check if the struct at index i has a char value less than m
		if(p[i].z <= m)

			//if so, update m
			m = p[i].z;
	}
	
	return m;
}

/*
* This is a function that finds and returns the minimum int value stored
* among all the foo structs in the array of foo structs
*/
int bar3(foo * p, int s){

	// checks if p is null or whether the s (the size) is zero
	if(p == 0 || s == 0)
		return 0;

	// minimum value, first assume the first struct has the minimum int value
	int m = p[0].x;

	int i;

	// then iterate from the second foo struct to the sth foo struct
	for(i = 1; i < s; i++){

		//continously check if the struct at index i has a int value less than m
		if(p[i].x <= m)

			//if so, update m
			m = p[i].x;
	}
	
	return m;
}