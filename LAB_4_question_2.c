#include <stdio.h>
#include <math.h>

int
main (void)
{
/* Use a pointer to find the data in the file, then open the file and read the data */
/* Define the variables and integers */
	FILE *datafile = fopen ("data", "r");
	int emp_num, shifts, hours, i;
	int total_h;
	float wage, gross_pay;
	total_h = 0;
	
/* Print the titles of the output data */
    printf ("Employee number:   Total hours:    Pay:\n");
    
/* Use a while loop to read the file for as long as it is open */
	while (!feof(datafile))
	{

/* Scan the data set in the file and define them as variables */
	fscanf (datafile, "%d", &emp_num);
	fscanf (datafile, "%d", &shifts);
	fscanf (datafile, "%f", &wage);

/* Make an inner loop to count the total hours */
	   for (i=1; i<=shifts; i++)
	   {
	       int hours_in_shift = 0;
	       fscanf (datafile, "%d", &hours_in_shift);
	       total_h = total_h + hours_in_shift;
	   }

/* Declare if and if else statements to determine the gross pay under the specified conditions */
    if (total_h <= 15)
		{
			gross_pay = total_h * wage;
		}
			else if (total_h > 15 && total_h <= 25)
			{
				gross_pay = (total_h * wage) * 1.05;
			}
				else if (hours > 25)
				{
					gross_pay = (total_h * wage) * 1.10;
				}

/* Print the output with the appropriate amount of spaces to make a column of data */
    printf ("%d              %d              %0.2f\n", emp_num, total_h, gross_pay);
    total_h = 0;
	}
	
/* Close the file */
    fclose (datafile);
return (0);
}
