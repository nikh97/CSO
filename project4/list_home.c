#include <stdio.h>
#include <stdlib.h>
#include "csapp.h"

/*
* Author: Nikhil Gosike
*
* This is a program that displays the contents
* of the home directory, regardless of the 
* actual working directory. 
*
* This is the equivalent of running
* "ls -l ~" in terminal.
*
*/


//create the heading that takes in the 
//number of arguments, arguments array, and the environment array
//only the third argument of the main array can take in and store the environment varibles
int main(int argc, char** argv, char ** envp){

	//first get the "HOME" environment variable using getenv()
	char * home = getenv("HOME");

	//create an array that stores the command line arguments for "ls -l ~" (tilda cannot be stored in this)
	char * commands[] = {"ls", "-l"};

	//instantiate a process ID variable
	pid_t pid; 

	//create the child process and set pid to the returned Fork() value
	if((pid = Fork()) == 0){

		//in the child process, change the directory from which it works
		chdir(home);

		//call execve to run the "ls -l" command
		Execve("/bin/ls", commands , envp);
	}

	//wait on the child process before ending to prevent a zombie
	Wait(&pid);

	
	return 0;
}