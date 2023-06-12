#include <stdio.h>
#include <math.h>

int 
main (void)
{
	double mhr, age, rhr, fitness_level, thr;
	char gender, inten; 
	
/* Ask the user to enter the inputs */
	printf("Please select a gender (male or female): "); 
	scanf (" %s", &gender);
	
	printf ("Please enter your age (number): ");
	scanf ("%lf", &age);
	
	printf ("Please enter your resting heart rate (number): ");
	scanf ("%lf", &rhr);
	
	printf ("Please enter your fitness level [L (low), I (intermediate), H (high)]: ");
	scanf (" %s", &inten);
	
/* Make a switch statement defining which equation to use based on gender */
	switch (gender) 
	{
		
		case 'M':
		case 'm':
					mhr = 203.7 / (1 + exp(0.033 * (age - 104.3)));
					break;
			
		case 'F':
		case 'f':
					mhr = 190.2 / (1 + exp(0.0453 * (age - 107.5)));
					break;
	}
	
/* Make a switch statement defining the value of the fitness level based on the input */
	switch (inten)
	{
		case 'H':
		case 'h':
					fitness_level = 0.80;
					break;
		
		case 'I': 
		case 'i':
					fitness_level = 0.65;
					break;
		
		case 'L':
		case 'l':
					fitness_level = 0.55;
					break;
	}
	
/* Write the equation for calculating the training heart rate */
	thr = (mhr - rhr) * fitness_level + rhr;
	
/* Print the results */
	printf ("\nYour training heart rate is %0.0lf", thr);

return (0);

}
