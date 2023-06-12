#include <stdio.h>
#include <math.h>

int
main (void)
{
/* Define the variables */
	int row, a, b, number;

/* Ask the user to enter the number of rows */
	printf ("\nEnter the number of rows: ");
	scanf ("%d", &row);

/* Create a loop for the first variable, a, that will be summed */
	for (a = 0; a < row; a++)
		{ 

/* Create a loop for the second variable (b) that will be summed */
		for (b = 0; b <= a; b++)
			{
				
/* Write an if statement declaring that if the sum of the numbers above 
 * the variable is 0 then the number will equal 1 or else the variable
 * will equal the the sum of the numbers */
				if (b == 0 || a == 0)
					number = 1;
				
					else
						number = number * (a - b + 1) / b;
						
/* Print the spaces in between the numbers */
				printf ("%4d", number);
			}
			
/* Print the new set of numbers in a new line after the loop is complete */
			printf ("\n");
		}

return (0);
}
