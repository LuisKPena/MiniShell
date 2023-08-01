/*
 * This is a simple c program to print out the numbers
 * 0 through 9 to the screen.
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
	//Initiating and instantializing num variable
	int num = 0;

	//For loop to increment and print num variable
	for(num; num < 10; num++)
	{
		printf("%d\n", num);
	}
	
	//Exit 0 if there are no errors
	exit(0);
}
