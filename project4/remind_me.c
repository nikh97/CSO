#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include "csapp.h"

/*
* 
* Author: Nikhil Gosike
*
* This is program that delivers an inputed message 
* after an alloted number of seconds inputed by the user.
* It also allows the user to continue work in terminal,
* during the alloted time before the message is delivered.
*
*/

//create a global message variable to be used throughout the program
char * message;

//header for the concat function
void concat(int size, char ** arguments);
	
/*
* this is a function that prints the message 
* after the signal is recieved by the child process after 
* the allotted number of seconds
*/
void alarm_handler(int sig){

	//print message
	printf("%s\n", message);

	//free the memory allocated to the message in the child process
	Free(message);

	//exit the system
	exit(0);

}

int main(int argc, char ** argv){

	//error check if the number of arguments is less than 3, if so print print a usage error message
	if(argc < 3){

		printf("ERROR: this program needs at least two command line arguments\n");
        printf("\tUsage: %s time [ message text ]\n\n", argv[0] ); 
        exit(1); 
	}

	//convert the first command line argument to an integer and set t equal to the value
	int t = atoi(argv[1]);

	//install the alarm_handler 
	Signal(SIGALRM, alarm_handler);

	//call concat to put the message text into the variable message as a single string
	concat(argc, argv);

	//instiate pid to store process ID number
	pid_t pid;

	//print usage error if the time is less than 0
	if(t < 0){

		printf("ERROR: time must be greater than or equal to zero.\n");
		exit(1);
	}

	//if time is 0, Alarm() cannot take in 0 as a parameter, so immediatly print the message, and exit
	if( t == 0){

		printf("%s\n", message);

		//free the memory alloted in message and then just exit normally
		Free(message);
		exit(0);
	}	

	else{

		//create the child process, set pid to this process id
		if((pid = Fork()) == 0){

			//call Alarm() to send a signal after t seconds
			Alarm(t);

			//pause the child process to wait for the signal
			Pause();
		
		}
	}

	//print process id
	printf(",/remind_me process-id: %d\n", pid);

	// free the memory alloted for the message in the parent process
	Free(message);
	return 0;

}

/*
* this is a helper method to take the command line arguments
* and make them into a single string and assigns the string
* to the global variable message
*/
void concat(int size, char ** arguments){

	// counter keeps track of the total number of characters
	int counter = 0;

	//use for loop to get the total number of characters, add one to account for space and null character 
	int i;
	for(i = 2; i < size; i++){

		counter += strlen(arguments[i]) + 1;
	}

	//allocate the memory for message
	message = Malloc(counter);

	//copy the first part of the message into the variable message
	strcpy(message, arguments[2]);

	// add a space
	strcat(message, " ");

	//do the same thing for all th other parts of the message
	for(i = 3; i < size; i++){

		strcat(message, arguments[i]);
		strcat(message, " ");
	}
}
