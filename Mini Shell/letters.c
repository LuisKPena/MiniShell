/*
 * This is a simple c program to print out the letters
 * of the alphabet to the screen.
 *
 * @author Luis Pena (PID 6300130)
 * @version 04/07/2023
 *
 * I, Luis K. Pena, certify that this is my own original
 * program developed by me with no interenet or outside
 * help.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	
	//Initiating and initializing alphabet array 
 	char alphabet[27] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};
		
	//Iterating through array and printing each character
	for(int i = 0; i < 27; i++)
	{
		printf("%c", alphabet[i]);
	}

	//Printing bottom separator for shell
	printf("\n");

	//Exit 0 if there are no errors
	exit(0);
}
