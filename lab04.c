
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. tian130@purdue.edu
*  2. dkepich@purdue.edu
*  3. svrehas@purdue.edu (delete line if no third partner)
*
*  Lab #: 04
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tues 3:30PM SC G046
*
*  Program Description: This program determines whether the three given angles form
*                       a triangle, and if so, what type of triangle it is.
*
***************************************************************************/

#include<stdio.h>
#include<math.h>

// Global Declarations
 
int getAngle(int);
void displayResults(int, int, int, char, char);
char calcStatus(int, int, int);
int calcSameSides(int, int, int);
char calcType(int, char);

int main()
{
  // Local Declarations

  int ang1; // input value of angle 1 
  int ang2; // input value of angle 2
  int ang3; // input value of angle 3
  char tri_status; // the character of triangle status
  char tri_type; // the character of type triangle type
  int index = 0; // the angle number 
  int equal_num; // the number of sides with same length

  // Statements
  
  ang1 = getAngle(++index);
  ang2 = getAngle(++index);
  ang3 = getAngle(++index);
  tri_status = calcStatus(ang1, ang2, ang3);
  equal_num = calcSameSides(ang1, ang2, ang3);
  tri_type = calcType(equal_num, tri_status);
  displayResults(ang1, ang2, ang3, tri_status, tri_type);

  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getAngle
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, index, used for the angle number
*   
*  Function Description: This function helps recognize the number of the
*                        angle being input.
*
***************************************************************************/

int getAngle(index)
{
  // Local Declarations
  int value; // the user's value input

  // Statements
  printf("Enter angle #%d -> ", index);
  scanf("%d", &value);

  return(value);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: displayResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, ang1, the first angle value
*    2. int, ang2, the second angle value
*    3. int, ang3, the third angle value
*    4. char, tri_status, the triangle status character
*    5. char, tri_type, the triangle type character
*
*  Function Description: This function prints all given and calculated values.
*
****************************************************************************/

void displayResults(int ang1, int ang2, int ang3, char tri_status, char tri_type)
{
  // Statements
  printf("\nGiven angles [%d %d %d]\n", ang1, ang2, ang3);
  printf("Triangle Status: %c\n", tri_status);
  printf("Triangle Type: %c\n", tri_type);
  
  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcStatus
*
*  Function Return Type: char
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, ang1, the first angle value
*    2. int, ang2, the second angle value
*    3. int, ang3, the third angle value
*
*  Function Description: This function determines if the three angles form 
*                        a triangle.
*
***************************************************************************/

char calcStatus(int ang1, int ang2, int ang3)
{
  // Local Declarations
  char tri_status; // tells us if the angles form a triangle or not

  // Statements
  tri_status = (1 / ((ang1 + ang2 + ang3) % 180 + 1) + 7) * 11 + 1;

  return(tri_status);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcSameSides
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, ang1, the first angle value
*    2. int, ang2, the second angle value
*    3. int, ang3, the third angle value
*
*  Function Description: This function will determine how many sides have the
*                        same length.
*
***************************************************************************/

int calcSameSides(int ang1, int ang2, int ang3)
{
  // Local Declarations
  int value; // indexes the number of equal sides

  // Statements
  value = 1 / (ang1 % ang2 + 1);
  value += 1 / (ang1 % ang3 + 1);
  value += 1 / (ang2 % ang3 + 1);

  return(value);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcType
*
*  Function Return Type: char
*
*  Parameters (list data type, name, and comment one per line):
*    1. int, equal_num, number of equal sides of the triangle
*    2. char, tri_status, whether the sides form a triangle or not
*   
*  Function Description: This function determines the type of triangle the
*                        angles form.
*
***************************************************************************/

char calcType(int equal_num, char tri_status)
{
  // Local Declarations
  char type; // the type of triangle

  // Statements
  type = (75 - 2 * equal_num) * (equal_num % 2) * ((tri_status - 1) / 11 - 7) + 1 / (tri_status % 78 + 1) * 32 ;

  return(type);
}
