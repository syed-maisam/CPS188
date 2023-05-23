#include <stdio.h>
#include <math.h>

/* define the function of the speed of sound */
double spsound (double fahrenheit)
{
	double speed;
	speed = 1086 * (sqrt ((5 * fahrenheit + 297) / (247)));
	return (speed);
}

int 
main (void)
{
	double celcius, fahrenheit, result;
	
	/* ask for the input temperature in degrees celcius */
	printf ("Enter the temperature in degrees celcius: ");
	scanf ("%lf", &celcius);
	
	/* convert celcius to fahrenheit */
	fahrenheit = (celcius * 9) / (5) + 32; 
	
	/* convert the speed in ft/s to km/h */
	result = spsound(fahrenheit) * 1.097;
	
	printf ("The speed of sound is %0.2lf km/h at the", result); 
	printf ("\ntemperature of %0.2lf degrees fahrenheit.", fahrenheit);
	

return (0);
}
