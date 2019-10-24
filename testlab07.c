
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. login1@purdue.edu
*  2. login2@purdue.edu
*  3. login3@purdue.edu (delete line if no third partner)
*
*  Lab #:
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab:
*
*  Program Description:
*
***************************************************************************/

#include <stdio.h>
#include <math.h>

// Global Declarations

void inputValue(int*, int*);
int calcMonth(int, int);
int calcDate_in_month(int, int, int, int*);
int calcLastDec31(int);
int calcDay_of_week(int, int);
int calcOrdinal_numeral(int);
void outputResult(int, int, int, int, int);

int main()

{
  // Local declarations
  
  int year_given;
  int day_given;
  int month_calculated;
  int date_in_month;
  int days_before_calculated_month;
  int day_of_week_of_last_Dec31;
  int day_of_week_of_given_day;
  int numeral_of_given_day;

  
  // Statements
  
  inputValue(&year_given, &day_given);
  month_calculated = calcMonth(year_given, day_given);
  date_in_month = calcDate_in_month(month_calculated, day_given, year_given, &days_before_calculated_month);
  day_of_week_of_last_Dec31 = calcLastDec31(year_given);
  day_of_week_of_given_day = calcDay_of_week(day_of_week_of_last_Dec31, day_given);
  numeral_of_given_day = calcOrdinal_numeral(date_in_month);
  outputResult(month_calculated, date_in_month, year_given, numeral_of_given_day, day_of_week_of_given_day);
  
  return(0);
}


/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
***************************************************************************/

void inputValue(int* add_y_given, int* add_d_given)
{
  // Local Declarations
  
  int leapyear;
  
  // Statements
  
  printf("Enter the year -> ");
  scanf("%d", add_y_given);
  leapyear = (!(*add_y_given % 4) && (*add_y_given % 100)) || !(*add_y_given % 400);
  printf("Enter day number of year (1-%d) -> ", 365 + leapyear);
  scanf("%d", add_d_given);
  
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
***************************************************************************/

int calcMonth(int y_given, int d_given)
{
  // Local Declarations
  
  int leapyear;
  int calculated_month;
  
  // Statements
 
  leapyear = (!(y_given % 4) && (y_given % 100)) || !(y_given % 400);
  
  /***********************************************************************
   This selection helps to calculate the month based on given day
  ************************************************************************/
  
  if (d_given > 334 + leapyear)
  {
    calculated_month = 12;
  }
  else if (334 + leapyear >= d_given && d_given > 304 + leapyear)
  {
    calculated_month = 11;
  }
  else if (304 + leapyear >= d_given && d_given > 273 + leapyear)
  {
    calculated_month = 10;
  }
  else if (273 + leapyear >= d_given && d_given > 243 + leapyear)
  {
    calculated_month = 9;
  }
  else if (243 + leapyear >= d_given && d_given > 212 + leapyear)
  {
    calculated_month = 8;
  }
  else if (212 + leapyear >= d_given && d_given > 181 + leapyear)
  {
    calculated_month = 7;
  }
  else if (181 + leapyear >= d_given && d_given > 151 + leapyear)
  {
    calculated_month = 6;
  }
  else if (151 + leapyear >= d_given && d_given > 120 + leapyear)
  {
    calculated_month = 5;
  }
  else if (120 + leapyear >= d_given && d_given > 90 + leapyear)
  {
    calculated_month = 4;
  }
  else if (90 + leapyear >= d_given && d_given > 59 + leapyear)
  {
    calculated_month = 3;
  }
  else if (59 + leapyear >= d_given && d_given > 31)
  {
    calculated_month = 2;
  }
  else
  {
    calculated_month = 1;
  }
  
  return(calculated_month);
  
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
***************************************************************************/

int calcDate_in_month(int calc_month, int d_given, int y_given, int* d_before_month)
{
  // Local Declarations
  
  int leap;
  int days_before_month = 0;
  int date;
  
  // Statements
  
  leap = (!(y_given % 4) && (y_given % 100)) || !(y_given % 400);
  
  /***********************************************************************
    This switch helps to calculate the days before the input month
  ************************************************************************/
  
  switch(calc_month - 1) 
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
  
  *d_before_month = days_before_month;
  date = d_given - days_before_month;
  
  return(date);

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

int calcLastDec31(int y_given)
{
  // Local Declarations 
  
  int d_lastDec31; // the day of week of last year's December 31th
  
  // Statements 
  
  d_lastDec31 = (( y_given - 1) * 365 + (y_given - 1) / 4 - (y_given - 1) / 100 + (y_given - 1) / 400) % 7;
  
  return( d_lastDec31);
    
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
***************************************************************************/

int calcDay_of_week(int d_lastDec31, int d_given)
{
  // Local Declarations
  
  int day_of_week;
  
  // Statements
  
  day_of_week = d_given % 7 + d_lastDec31;
  
  return(day_of_week);
  
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
***************************************************************************/

int calcOrdinal_numeral(int d_in_month)
{
  // Local Declarations
  
  int num;
  
  // Statements
  
  num = (d_in_month - 1) / 7 + 1;
  
  return(num);
  
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function:
*
*  Function Return Type:
*
*  Parameters (list data type, name, and comment one per line):
*    1.
*    2.
*    3.
*
*  Function Description:
*
***************************************************************************/

void outputResult(int calc_month, int d_in_month, int y_given, int num, int day_of_week)
{
  // Statements
  
  printf("\nDate: ");
  
  switch(calc_month) 
  {
    case 12: printf("December");
             break;
    case 11: printf("November");
             break;
    case 10: printf("October");
             break;
    case 9: printf("September");
            break;
    case 8: printf("August");
            break;
    case 7: printf("July");
            break;
    case 6: printf("June");
            break;
    case 5: printf("May");
            break;
    case 4: printf("April");
            break;
    case 3: printf("March");
            break;
    case 2: printf("February");
            break;
    case 1: printf("January");
            break;
  }
  printf(" %d, %d\n", d_in_month, y_given);
  printf("Occurrence: ");
  
  switch(num) 
  {
    case 5: printf("5th ");
            break;
    case 4: printf("4th ");
            break;
    case 3: printf("3rd ");
            break;
    case 2: printf("2nd ");
            break;
    case 1: printf("1st ");
            break;
  }
  
  switch(day_of_week)
  {
    case 0: printf("Sunday\n");
            break;
    case 6: printf("Saturday\n");
            break;
    case 5: printf("Friday\n");
            break;
    case 4: printf("Thursday\n");
            break;
    case 3: printf("Wednesday\n");
            break;
    case 2: printf("Tuesday\n");
            break;
    case 1: printf("Monday\n");
            break;
  }
  
}
