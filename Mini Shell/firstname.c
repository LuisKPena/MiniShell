/*
 * This is a simple c program to print out a user's
 * first name after it is passed on through the
 * command line.
 *
 * @author Luis Pena (PID 6300130)
 * @version 04/07/2023
 *
 * I, Luis K, Pena, certify that this is my own original
 * program developed by me with no internet or outside
 * help.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	//Initiating and instantializing variables
	extern char *optarg;
	extern int optind;
	int err = 0; 
	char firstname[15];
	
	/* This block of code would be to check the
	 * command line arguments, however, Professor
	 * Rahn said I was allowed to hardcode my name
	 * into the program as accepting a command line
	 * argument in a shell would be difficult. I 
	 * am leaving the block of code here so the
	 * grader may see that it was written and 
	 * implemented
	 *
	 *
	 
	//Informing user if argument is missing
	if((optind+1) > argc)
        {	
		fprintf(stderr, "%s: missing a name argument\n", argv[0]);
		exit(1);
	} 
	
	//Copying user argument to firstname array
	if(optind < argc)
	{
		strcpy(firstname, argv[optind]);
	}

	//Informing user there are no arguments left
	else
	{
		printf("no arguments left to process\n");
	}*/

	
	//Hardcoding name to firstname variable
	strcpy(firstname, "Luis");

	//Printing firstname
	printf("%s\n", firstname);

	//Exit 0 if there are no errors
	exit(0);
}
