#include <stdio.h>
#include <math.h>

int
main (void)
{
	/* step 1 */
	double base, height, hypotenuse, perimeter, area;
	
	/* step 2 */
	printf ("Enter a value for the base: ");
	scanf ("%lf", &base);
	printf ("\nEnter a value for the height: ");
	scanf ("%lf", &height);
	
	/* step 3 */
	area = (base * height) / 2;
	hypotenuse = sqrt ((base*base) + (height*height)); 
	perimeter = base + height + hypotenuse;
	
	/* step 4 */
	printf ("\nA triangle with the base of %lf cm, ", base);
	printf ("\nand the height the of height of %lf cm, ", height);
	printf ("has an area of %lf cm2,\n", area);
	printf ("and a perimeter of %lf cm.\n", perimeter);
	
	return (0);
}
