#include <stdio.h>
#include <math.h>

int
main (void)
{
	double quiz1, quiz2, quiz3, quiz4, quiz5, quiz6, quiz7, quiz8, quiz9, quiz10, quizT, quizzes, midterm, exam, grade, midtermf, examf;

/* Ask the user to enter the mark they got on their quizzes */
	printf ("\nPlease enter the grade of Quiz 1 (between 0 and 10): ");
	scanf ("%lf", &quiz1);
	
	printf ("Please enter the grade of Quiz 2 (between 0 and 10): ");
	scanf ("%lf", &quiz2);
	
	printf ("Please enter the grade of Quiz 3 (between 0 and 10): ");
	scanf ("%lf", &quiz3);
	
	printf ("Please enter the grade of Quiz 4 (between 0 and 10): ");
	scanf ("%lf", &quiz4);
	
	printf ("Please enter the grade of Quiz 5 (between 0 and 10): ");
	scanf ("%lf", &quiz5);
	
	printf ("Please enter the grade of Quiz 6 (between 0 and 10): ");
	scanf ("%lf", &quiz6);
	
	printf ("Please enter the grade of Quiz 7 (between 0 and 10): ");
	scanf ("%lf", &quiz7);
	
	printf ("Please enter the grade of Quiz 8 (between 0 and 10): ");
	scanf ("%lf", &quiz8);
	
	printf ("Please enter the grade of Quiz 9 (between 0 and 10): ");
	scanf ("%lf", &quiz9);
	
	printf ("Please enter the grade of Quiz 10 (between 0 and 10): ");
	scanf ("%lf", &quiz10);
	
/* Drop the lowest quiz mark (between quiz1 and quiz10) by comparing them */
	if (quiz1 > quiz10)
		quiz10 = 0;
	
		else 
			quiz1 = 0;
			
	if (quiz1 == quiz10)
		quiz1 = 0;
				
/* Find the average of the 9 quizzes by summing them up and dividing it by the total */
	quizT = ((quiz1 + quiz2 + quiz3 + quiz4 + quiz5 + quiz6 + quiz7 + quiz8 + quiz9 + quiz10) / 90) * 100;
	
/* Since the quizzes are worth 25% multiply 0.25 by the average */
	quizzes = quizT * 0.25;
	
/* Print the results of the calculations */
	printf ("\nThe average of the 10 quizzes is %0.2lf%%", quizT);
	printf ("\nand the quizzes are worth %0.2lf%% out of 100 \n", quizzes);
	
/* Ask the user to enter the mark they got on the midterm and the exam */
	printf ("\nPlease enter the grade of you got on the midterm (between 0 and 100): ");
	scanf ("%lf", &midterm);
	
	printf ("Please enter the grade of you got on the final exam (between 0 and 100): ");
	scanf ("%lf", &exam);
	
/* Give the conditions of the marking scheme */
	if (midterm >= exam)
		{ midtermf = midterm * 0.35;
		examf = exam * 0.40; }
		
	if (exam > midterm)
		{ midtermf = midterm * 0.25;
		examf = exam * 0.50; }
		
/* Calculate the final grade */
	grade = examf + midtermf + quizzes;
	
	printf ("\nYour final grade is %0.2lf%%", grade);

return (0);
}
