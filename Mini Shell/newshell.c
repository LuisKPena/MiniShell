/*
 * This a c program that runs a limited shell with various
 * options for the user. It forks off children in order to
 * run the programs letters.c, numbers.c, firstname.c, and
 * userinput.c in various forms and with various types of 
 * output.
 *
 * @author Luis Pena(PID 6300130)
 * @version 04/13/2023
 *
 * I, Luis K. Pena, certify that this is my own original
 * program developed by me with no internet or outside
 * help.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main()
{
	//Instantiating and intializing variables
	char *cmd[] = {"", "letters", "numbers", "firstname", "userinput"};
	int i;
	int file_id = creat("outfile", 0640);
     	
	//Running while loop for shell menu
	while (1)
	{
		//Printing menu U.I. for user
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", "1 letters", "2 numbers", "3 firstname", "4 userinput", "5 letters > outfile", "6 letters | userinput", "7 firstname | userinput", "8 exit");
	 
		//Printing input space for user
		printf(">> ");	

		//Getting user input
		scanf("%d", &i); 

		//Executing commands 1 through 4
		if(i < 5)
		{
			//Forking off children to run programs
			if(fork() == 0)
			{
				
				//Executing command line arguments 
				execlp(cmd[i], cmd[i], (char *) 0);
				
				//Printing error and informing user if anything goes wrong
				printf ("error: execlp failed\n");
				exit(1);
			}
			
			//Waiting for child processes to end
			else
			{
				wait((int *) 0);
			}
		}
		
		//Executing command 5
		else if(i == 5)
		{
			//Checking for errors during outfile creation 
			if(file_id < 0)
			{
				printf("Error: creation of outfile failed\n");
				exit(1);
			}
			
			//Forking off child to run program
			if(fork() == 0)
			{
				//Redirecting stdout to outfile
				dup2(file_id, 1);

				//Closing file descriptors
				close(file_id);

				//Excuting program letters.c
				execlp("letters", "ls", 0);
				
				//Printing error and informing user if anything goes wrong
				printf("Error: excelp failed\n");
				exit(1);
			}

			//Waiting for child processes to end
			else
			{
				wait((int *) 0); 
			}	

		}

		//Executing command 6
		else if(i == 6)
		{
			//Instantiating variables
			int pid;
			int status;
			int fd[2];
			
			//Opening pipe
			pipe(fd);
			
			//Designating pipe source 
			switch(pid = fork())
			{
			
				//Executing letters.c for piping
				case 0:

					dup2(fd[1], 1);
					close(fd[0]);
					execlp("letters", "ls", 0);
					perror("letters");

				default:

					break;

				//Checking for errors
				case -1:
					
					perror("fork");
					exit(1);	
			}			
			
			//Designating pipe end
			switch(pid = fork())
			{
				//Executing userinput.c for piping
				case 0:

					dup2(fd[0], 0);
					close(fd[1]);
					execlp("userinput", "ls", 0);
					perror("userinput");

				default: 

					break;

				//Checking for errors	
				case -1:

					perror("fork");
					exit(1);	
			}

			//Closing file descriptors
			close(fd[0]);
			close(fd[1]);

			//Waiting for child processes to end
			while((pid = wait(&status)) != -1); 
		}

		//Executing command 7
		else if(i == 7)
		{
			//Instantiating variables
			int pid;
			int status;
			int fd[2];

			//Opening pipe
			pipe(fd);

			//Designating pipe source
			switch(pid = fork())
			{
				//Executing firstname.c for piping
				case 0:

					dup2(fd[1], 1);
					close(fd[0]);
					execlp("firstname", "ls", 0);
					perror("firstname");

				default:

					break;

				//Checking for errors
				case -1:

					perror("fork");
			}

			//Designating pipe end
			switch(pid = fork())
			{
				//Executing userinput.c for piping
				case 0: 
					dup2(fd[0], 0);
					close(fd[1]);
					execlp("userinput", "ls", 0);
					perror("userinput");

				default:

					break;

				//Checking for errors	
				case -1:

					perror("fork");
					exit(1);	
			}

			//Closing file descriptors
			close(fd[0]);
			close(fd[1]);

			//Waiting for child processes to end
			while((pid = wait(&status)) != -1);
		}	
			
		//Executing command 8
		else if(i == 8)
	  	{
			//End while shell loop and exit
			exit(0);
	  	}

		//Else informing user of input error 
		else
		{
			printf("Error: input was not a number value. Exiting.\n");
			exit(1);
		}
     	}
     
	return(0);
}
 
