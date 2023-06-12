#include <stdio.h>
#include <math.h>

int 
main (void)
{
// Define all the variables, integers, and arrays
int num, i;
double min, max, high, low, real[100], normal[100];

// Define and open the file
	FILE* numbers = fopen ("number_file", "r");
	while (!feof(numbers))
	{
/* Identify the first number as the size of the array, the second number
 *  the minimum and the third the maximum */
		fscanf (numbers, "%d %lf %lf", &num, &min, &max);
		
// Print the titles for the columns
		printf ("\nReal Numbers:	Normalized Numebrs:\n");
		
		for (i = 0; i < num; i++)
		{
// Identify the remaining numbers in the file as the components in the array
			fscanf (numbers, "%lf", &real[i]);
		}
		
	low = real[0];
	high = real[0];
		
// Use if statements to compare the components and find the max/min values
		for (i = 0; i < num; i++)
		{
			if (real[i] < low)
			{
				low = real[i];
			}
	
			if (real[i] > high)
			{
				high = real[i];
			}
		}
		
// Apply the function given in the question to solve the normalized numbers
	for (i = 0; i < num; i++)
	{
		normal[i] = (min + (real[i] - low) * (max - min)) / (high - low);
	}
		
// Print the results
	for (i = 0; i < num; i++)
	{
		printf ("%lf      %lf\n", real[i], normal[i]);
	}
		
	normal[100] = 0;
	real[100] = 0;
		
	}
	
return (0);
}
