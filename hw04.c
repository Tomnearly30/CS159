
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. tian130@purdue.edu
*
*  Homework #: 04
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab:
*
*  Program Description: determine whether that given month has five occurrences 
*                       of the day of the week and display those dates based on
*                       given information 
*
***************************************************************************/

#include<stdio.h>

// Global Declarations

void inputValue(int*, int*, int*);
int calcLastDec31(int);
int calcFirstday_of_week_in_month(int, int, int, int);
void outputResults(int, int, int, int);

int main()

{
  // Local Declarations
  
  int day_given; // Given day of a week
  int month_given; // Given month
  int year_given; // Given year
  int day_of_lastDec31; // the day of week of last year's December 31th
  int first_day_of_week_in_given_month; // the first date of given day of a week in the given month
  
  // Statements   
    
  inputValue(&day_given, &month_given, &year_given); 
  day_of_lastDec31 = calcLastDec31(year_given);
  first_day_of_week_in_given_month = calcFirstday_of_week_in_month(day_of_lastDec31, day_given, month_given, year_given);
  outputResults(year_given, month_given, day_given, first_day_of_week_in_given_month);
  
  return(0);      
  
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:  inputValue
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int*, address_d // the address to save input value of day in a week
*    2. int*, address_m // the address to save input value of given month
*    3. int*, address_y // the address to save input value of given year
*
*  Function Description: input values of given information
*
***************************************************************************/

void inputValue(int* address_d, int* address_m, int* address_y)
{
  // Local Declarations
  
  int day_input; // the temperate storage of input  day of week
 
  // Statements  
  
  printf("Enter day of week (1-7) -> ");
  scanf("%d", &day_input);
  printf("Enter month of the year -> ");
  scanf("%d", address_m);
  printf("Enter the year -> ");
  scanf("%d", address_y);
  *address_d = day_input - 1;
   
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcLastDec31
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, year_input // the value of given year
*
*  Function Description: calculate the day of week of last year's December 31th
*
***************************************************************************/

int calcLastDec31(int year_input)
{
  // Local Declarations 
  
  int day_of_week; // the day of week of last year's December 31th
  
  // Statements 
  
  day_of_week = (( year_input - 1) * 365 + (year_input - 1) / 4 - (year_input - 1) / 100 + (year_input - 1) / 400) % 7;
  
  return( day_of_week);
    
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcFirstday_of_week_in_month
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, d_lastDec31 // the day of week of last year's December 31th
*    2. int, day_of_week_input // input value of day in a week
*    3. int, month_input // value of given month
*    4. int, year_input // value of given year
*
*  Function Description: calculate the first date of given day in the given month
*
***************************************************************************/

int calcFirstday_of_week_in_month(int d_lastDec31,int day_of_week_input, int month_input, int year_input)
{
  // Local Declarations
  
  int days_before_month = 0; // the value of days before the input month
  int firstday_of_month; // the day of a week of the first day of given month
  int first_day_of_week_in_month; // the first date of given day in the given month
  int leap; // the logical value of whether given year is a leap year
  
  // Statements
  
  leap = (!(year_input % 4) && (year_input % 100)) || !(year_input % 400);
  
  /***********************************************************************
    This switch helps to calculate the days before the input month
  ************************************************************************/
  
  switch(month_input - 1) 
  {
    case 11: days_before_month += 30;
    case 10: days_before_month += 31;
    case 9: days_before_month += 30;
    case 8: days_before_month += 31;
    case 7: days_before_month += 31;
    case 6: days_before_month += 30;
    case 5: days_before_month += 31;
    case 4: days_before_month += 30;
    case 3: days_before_month += 31;
    case 2: days_before_month += 28 + leap;
    case 1: days_before_month += 31;
  }

  firstday_of_month = (d_lastDec31 + days_before_month + 1) % 7; 
  
  /***********************************************************************
    This selection helps to return the date of first day of week in_month
  ************************************************************************/
  
  if(firstday_of_month == day_of_week_input) 
  {
    first_day_of_week_in_month = 1;
  }
  else if(firstday_of_month < day_of_week_input)
  {
    first_day_of_week_in_month = day_of_week_input - firstday_of_month + 1;  
  }
  else
  {
    first_day_of_week_in_month = day_of_week_input - firstday_of_month + 8; 
  }      
  
  return(first_day_of_week_in_month);
  
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: outputResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, year_input // value of given year
*    2. int, month_input // value of given month
*    3. int, day_input // value of given day of a week
*    4. int, first_day_of_week_in_month // the first date of given day in the given month
*
*  Function Description: Output results based on given information
*
***************************************************************************/

void outputResults(int year_input, int month_input, int day_input, int first_day_of_week_in_month) 
{
  // Local Declarations    
  
  int days_in_month; // days in the given month
  int leap; // the logical value of whether given year is a leap year
    
    // Statements
	
  leap = (!(year_input % 4) && (year_input % 100)) || !(year_input % 400);
  
  /****************************************************************************
    This switch helps to determine the output month, and the days in that month
  *****************************************************************************/
  
  switch (month_input)
  {
    case 12:  days_in_month = 31;
	
	         /**********************************************************************************************
             This secondary switch helps to determine the output day of the week and the days in that month
             ***********************************************************************************************/
  
              switch (day_input + 1)
                 {
					 
					 	   /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
					 
                  case 1:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Sunday dates in December of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Sunday dates in December of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break; 
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 2:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Monday dates in December of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Monday dates in December of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 3:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Tuesday dates in December of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Tuesday dates in December of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;   
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 4:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Wednesday dates in December of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Wednesday dates in December of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 5:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Thursday dates in December of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Thursday dates in December of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 6:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Friday dates in December of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Friday dates in December of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 7:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Saturday dates in December of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Saturday dates in December of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }   
						   
                 }
				 
              break;       
			  
    case 11:  days_in_month = 30;
	
	         /**********************************************************************************************
             This secondary switch helps to determine the output day of the week and the days in that month
             ***********************************************************************************************/
  
              switch (day_input + 1)
                 {
					 
					 	   /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
					 
                  case 1:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Sunday dates in November of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Sunday dates in November of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break; 
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 2:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Monday dates in November of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Monday dates in November of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 3:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Tuesday dates in November of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Tuesday dates in November of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;   
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 4:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Wednesday dates in November of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Wednesday dates in November of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 5:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Thursday dates in November of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Thursday dates in November of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 6:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Friday dates in November of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Friday dates in November of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 7:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Saturday dates in November of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Saturday dates in November of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }   
						   
                 }
				 
              break;       
			  
    case 10:  days_in_month = 31;
	
	         /**********************************************************************************************
             This secondary switch helps to determine the output day of the week and the days in that month
             ***********************************************************************************************/
  
              switch (day_input + 1)
                 {
					 
					 	   /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
					 
                  case 1:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Sunday dates in October of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Sunday dates in October of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break; 
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 2:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Monday dates in October of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Monday dates in October of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 3:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Tuesday dates in October of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Tuesday dates in October of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;   
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 4:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Wednesday dates in October of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Wednesday dates in October of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 5:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Thursday dates in October of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Thursday dates in October of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 6:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Friday dates in October of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Friday dates in October of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 7:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Saturday dates in October of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Saturday dates in October of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }   
						   
                 }
				 
              break;       
			  
      case 9: days_in_month = 30;
	
	         /**********************************************************************************************
             This secondary switch helps to determine the output day of the week and the days in that month
             ***********************************************************************************************/
  
              switch (day_input + 1)
                 {
					 
					 	   /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
					 
                  case 1:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Sunday dates in September of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Sunday dates in September of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break; 
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 2:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Monday dates in September of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Monday dates in September of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 3:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Tuesday dates in September of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Tuesday dates in September of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;   
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 4:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Wednesday dates in September of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Wednesday dates in September of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 5:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Thursday dates in September of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Thursday dates in September of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 6:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Friday dates in September of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Friday dates in September of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 7:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Saturday dates in September of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Saturday dates in September of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }   
						   
                 }
				 
              break;       
			  
      case 8: days_in_month = 31;
	
	         /**********************************************************************************************
             This secondary switch helps to determine the output day of the week and the days in that month
             ***********************************************************************************************/
  
              switch (day_input + 1)
                 {
					 
					 	   /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
					 
                  case 1:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Sunday dates in August of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Sunday dates in August of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break; 
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 2:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Monday dates in August of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Monday dates in August of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 3:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Tuesday dates in August of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Tuesday dates in August of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;   
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 4:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Wednesday dates in August of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Wednesday dates in August of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 5:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Thursday dates in August of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Thursday dates in August of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 6:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Friday dates in August of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Friday dates in August of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 7:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Saturday dates in August of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Saturday dates in August of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }   
						   
                 }
				 
              break;       
			  
      case 7: days_in_month = 31;
	
	         /**********************************************************************************************
             This secondary switch helps to determine the output day of the week and the days in that month
             ***********************************************************************************************/
  
              switch (day_input + 1)
                 {
					 
					 	   /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
					 
                  case 1:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Sunday dates in July of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Sunday dates in July of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break; 
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 2:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Monday dates in July of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Monday dates in July of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 3:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Tuesday dates in July of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Tuesday dates in July of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;   
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 4:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Wednesday dates in July of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Wednesday dates in July of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 5:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Thursday dates in July of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Thursday dates in July of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 6:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Friday dates in July of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Friday dates in July of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 7:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Saturday dates in July of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Saturday dates in July of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }   
						   
                 }
				 
              break;       
			  
      case 6: days_in_month = 30;
	
	         /**********************************************************************************************
             This secondary switch helps to determine the output day of the week and the days in that month
             ***********************************************************************************************/
  
              switch (day_input + 1)
                 {
					 
					 	   /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
					 
                  case 1:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Sunday dates in June of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Sunday dates in June of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break; 
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 2:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Monday dates in June of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Monday dates in June of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 3:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Tuesday dates in June of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Tuesday dates in June of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;   
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 4:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Wednesday dates in June of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Wednesday dates in June of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 5:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Thursday dates in June of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Thursday dates in June of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 6:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Friday dates in June of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Friday dates in June of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 7:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Saturday dates in June of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Saturday dates in June of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }   
						   
                 }
				 
              break;       
			  
      case 5: days_in_month = 31;
	
	         /**********************************************************************************************
             This secondary switch helps to determine the output day of the week and the days in that month
             ***********************************************************************************************/
  
              switch (day_input + 1)
                 {
					 
					 	   /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
					 
                  case 1:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Sunday dates in May of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Sunday dates in May of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break; 
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 2:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Monday dates in May of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Monday dates in May of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 3:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Tuesday dates in May of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Tuesday dates in May of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;   
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 4:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Wednesday dates in May of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Wednesday dates in May of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 5:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Thursday dates in May of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Thursday dates in May of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 6:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Friday dates in May of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Friday dates in May of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 7:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Saturday dates in May of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Saturday dates in May of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }   
						   
                 }
				 
              break;       
			  
      case 4: days_in_month = 30;
	
	         /**********************************************************************************************
             This secondary switch helps to determine the output day of the week and the days in that month
             ***********************************************************************************************/
  
              switch (day_input + 1)
                 {
					 
					 	   /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
					 
                  case 1:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Sunday dates in April of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Sunday dates in April of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break; 
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 2:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Monday dates in April of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Monday dates in April of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 3:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Tuesday dates in April of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Tuesday dates in April of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;   
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 4:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Wednesday dates in April of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Wednesday dates in April of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 5:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Thursday dates in April of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Thursday dates in April of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 6:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Friday dates in April of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Friday dates in April of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 7:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Saturday dates in April of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Saturday dates in April of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }   
						   
                 }
				 
              break;       
			  
      case 3: days_in_month = 31;
	
	         /**********************************************************************************************
             This secondary switch helps to determine the output day of the week and the days in that month
             ***********************************************************************************************/
  
              switch (day_input + 1)
                 {
					 
					 	   /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
					 
                  case 1:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Sunday dates in March of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Sunday dates in March of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break; 
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 2:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Monday dates in March of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Monday dates in March of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 3:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Tuesday dates in March of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Tuesday dates in March of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;   
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 4:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Wednesday dates in March of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Wednesday dates in March of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 5:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Thursday dates in March of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Thursday dates in March of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 6:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Friday dates in March of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Friday dates in March of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 7:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Saturday dates in March of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Saturday dates in March of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }   
						   
                 }
				 
              break;       
			  
      case 2: days_in_month = 28 + leap;
	
	         /**********************************************************************************************
             This secondary switch helps to determine the output day of the week and the days in that month
             ***********************************************************************************************/
  
              switch (day_input + 1)
                 {
					 
					 	   /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
					 
                  case 1:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Sunday dates in February of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Sunday dates in February of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break; 
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 2:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Monday dates in February of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Monday dates in February of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 3:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Tuesday dates in February of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Tuesday dates in February of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;   
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 4:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Wednesday dates in February of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Wednesday dates in February of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 5:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Thursday dates in February of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Thursday dates in February of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 6:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Friday dates in February of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Friday dates in February of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 7:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Saturday dates in February of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Saturday dates in February of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }   
						   
                 }
				 
              break;       
			  
      case 1: days_in_month = 31;
	
	         /**********************************************************************************************
             This secondary switch helps to determine the output day of the week and the days in that month
             ***********************************************************************************************/
  
              switch (day_input + 1)
                 {
					 
					 	   /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
					 
                  case 1:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Sunday dates in January of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Sunday dates in January of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break; 
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 2:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Monday dates in January of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Monday dates in January of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 3:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Tuesday dates in January of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Tuesday dates in January of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;   
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 4:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Wednesday dates in January of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Wednesday dates in January of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 5:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Thursday dates in January of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Thursday dates in January of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 6:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Friday dates in January of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Friday dates in January of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }    
                           break;
						   
						  /*****************************************************************************************
                           This selection helps to determine whether there are 5 dates of given day in given month
                           ******************************************************************************************/
						   
                  case 7:  if(days_in_month < first_day_of_week_in_month + 28)
                           {
                             printf("\nFinding: There are not five Saturday dates in January of %d.\n",year_input);
                           }
                           else
                           {
                             printf("\nFinding: There exists five Saturday dates in January of %d.\n", year_input);
                             printf("Dates: %d %d %d %d %d\n", first_day_of_week_in_month, first_day_of_week_in_month + 7, first_day_of_week_in_month + 14, first_day_of_week_in_month + 21, first_day_of_week_in_month + 28);
                           }   
						   
                 }
				 
              break;       
			  
    }
    
}
