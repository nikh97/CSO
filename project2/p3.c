#include <stdio.h>

/*
* Author: Nikhil Gosike
*
* This program contains a method to check the status of two characters and an integer
*/


int check_status(char x, char y, int z){

	//first check if the first argument equals 78, otherwise return zero
	if(x == 0x4e){

		// check if the second argument equals 77, otherwise return zero
		if( y == 0x4d){

			//check if the unsigned value of the third argument minus 18 is greater than 8
			if(((unsigned)z - 0x12) > 0x8)

				// if so, return 0
				return 0;
			else

				// if not, return 1
				return 1;

		}else
			return 0;

	} else
		return 0;
}