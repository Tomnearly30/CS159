
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. tian130@purdue.edu
*
*  Homework #: 01
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday 3:30PM SC G046
*
*  Program Description: Transformation of a given time
*
***************************************************************************/

#include <stdio.h>

int main (void)

{
  // Local Declarations
  int input_hour; // the hour of given time
  int input_minute; // the minute of given time   
  int output_hour; // the hour of transferred time   
  int output_minute; // the minute of transferred time   

  // Statements
  printf("Enter hour [0-23]\n");
  scanf("%d", &input_hour);
  printf("Enter minute [0-59]\n");
  scanf("%d", &input_minute);

  //Calculation for the time transformation
  output_hour = ( input_hour * 60 + input_minute ) * 1000 / ( 24 * 60 ) / 100;
  output_minute = ( input_hour * 60 + input_minute ) * 1000 / ( 24 * 60 ) % 100;

  printf("\n-=-=-=-=-=-=-=-=-=-");
  printf("\nGiven Time: %02d-%02d", input_hour, input_minute);
  printf("\nMetric Time: %02d-%02d", output_hour, output_minute);
  printf("\n-=-=-=-=-=-=-=-=-=-\n");

  return 0;
}

