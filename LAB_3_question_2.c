#include <stdio.h>
#include <math.h>

int 
main(void)
{
	double weight, height, BMI;

/* Ask user to enter their weight and height */
	printf ("\nPlease enter your weight (in kilograms): ");
	scanf ("%lf", &weight);
	
	printf ("Please enter your height (in meters): ");
	scanf ("%lf", &height);

/* Calculate the BMI using the given formula */
	BMI = weight / pow (height, 2);
	
/* Print the results*/
	printf ("\nYour BMI is %0.2lf, ", BMI);
	
/* Give the conditions of the classificaction based on the results of the BMI */
	if (BMI < 18.5)
		{printf ("which means that you classify as underweight.");}
			
			else if (18.5 <= BMI && BMI <= 24.9)
				{printf ("which means that you classify as normal.");}
			
			else if (25 <= BMI && BMI <= 29.9)
				{printf ("which means that you classify as overweight");}
					
			else if (BMI >= 30)
				{printf ("which means that you classify as obesse.");}
	
return(0);
}
