/*
 * This is a simple c program to print out a user's
 * input with all letters in uppercase.
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
#include <ctype.h>

int main(int argc, char **argv)
{
	//Initiating and instantializing variables
	char input[30];
	
	//Accepting user input
	scanf("%[^\t\n]", input);

	//Changing all characters in input to uppercase
	for(int i = 0; i < strlen(input); i++)
	{
		input[i] = toupper(input[i]);
	}
			
	//Printing input
	printf("%s\n", input);

	//Exit 0 if there are no errors
	exit(0);
}
