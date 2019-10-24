
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. tian130@purdue.edu
*  2. vounchai@purdue.edu
*  3. jgori@purdue.edu
*
*  Lab #: 06
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tues 3:30PM SC G046
*
*  Program Description: resolve the value of an expression using binary operators 
*                       '+', '-', '*', '/','%' and digits zero through nine
*
***************************************************************************/
#include <stdio.h>
#include <math.h>

void getInput(char* addoperator1, char* addoperator2, int* addoperand1, int* addoperand2, int* addoperand3);
int calcOperands(char operator1, char operator2, int operand1, int operand2, int operand3);
void displayfinalResults(char operator1, char operator2, int operand1, int operand2, int operand3, int finalresult);

int main()

{
  // Local declaration	
  
  char operator1;
  char operator2 = 33;
  int operand1;
  int operand2;
  int operand3 = -1;
  int finalresult;
  
  //Statments
    
  getInput(&operator1, &operator2, &operand1, &operand2, &operand3);	
  finalresult = calcOperands(operator1, operator2, operand1, operand2, operand3);	
  displayfinalResults(operator1, operator2, operand1, operand2, operand3, finalresult);
	
  return (0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. char*, addoperator1 // the address of operator1
*    2. char*, addoperator2 // the address of operator2
*    3. int*, addoperand1 // the address of operand1
*    4. int*, addoperand2 // the address of operand2
*    5. int*, addoperand3 // the address of operand3
*
*  Function Description: get input value of operands and operators
*
***************************************************************************/
void getInput(char* addoperator1, char* addoperator2, int* addoperand1, int* addoperand2, int* addoperand3)

{
  // Local Declarations
  
  char detector1;
  char detector2;
  
  // Statments
  
  printf("Enter expression -> ");
  scanf("%c %c ", &detector1, &detector2); 
  if (detector2 > 57 || detector2 < 48)
  {
    scanf("%d %d %d",addoperand1, addoperand2, addoperand3);
	*addoperator1 = detector2;
	*addoperator2 = detector1;
  }
  else
  {
    scanf("%d", addoperand2);
	*addoperator1 = detector1;
	*addoperand1 = (int)detector2 - 48;
  } 
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcOperands
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. char, operator1 // the value of operator1
*    2. char, operator2 // the value of operator2
*    3. int, operand1 // the value of operand1
*    4. int, operand2 // the value of operand2
*    5. int, operand3 // the value of operand3
*
*  Function Description: return the value of the final result of calculation
*                        or 1000000 as offscale value when the Denominator is 0
*
***************************************************************************/

int calcOperands(char operator1, char operator2, int operand1, int operand2, int operand3)

{
  // Local declarations
	
  int intermediate;
  int final;
	
  // Statements
	
	if ( ((operator1 == '/'|| operator1 == '%') && operand2 == 0) || ((operator2 == '/' || operator2 == '%') && operand3 == 0))
	{
		final = 1000000;
	}
	else
	{
	  if (operand3 < 0)
	  {
	  
	    switch(operator1)
	    {
	      case '+': final = operand1 + operand2;
		          break;
		  case '-': final = operand1 - operand2;
		          break;  
		  case '*': final = operand1 * operand2;
		          break;
		  case '/': final = operand1 / operand2;
		          break;
		  case '%': final = operand1 % operand2;
		          break;
	    }
	  
	  }
	  else
	  {
       if((int)operator2 % 5 == 2 && (int)operator1 % 5 != 2)
	   {
		  switch(operator2)
	    {
		  case '*': intermediate = operand2 * operand3;
		            break;
		  case '/': intermediate = operand2 / operand3;
		            break;
		  case '%': intermediate = operand2 % operand3;
		            break;
	    }
	    switch(operator1)
	    {
	      case '+': final = operand1 + intermediate;
		            break;
		  case '-': final = operand1 - intermediate;
		            break; 
	    }
	  
	   }
       else
	   {
	    switch(operator1)
	    {
	      case '+': intermediate = operand1 + operand2;
		            break;
		  case '-': intermediate = operand1 - operand2;
		            break;  
		  case '*': intermediate = operand1 * operand2;
		            break;
		  case '/': intermediate = operand1 / operand2;
		            break;
		  case '%': intermediate = operand1 % operand2;
		            break;
	    }
	  
	  	switch(operator2)
	    {
	      case '+': final = intermediate + operand3;
		            break;
		  case '-': final = intermediate - operand3;
		            break;  
		  case '*': final = intermediate * operand3;
		            break;
		  case '/': final = intermediate / operand3;
		            break;
		  case '%': final = intermediate % operand3;
		            break;
	    }
	   
	   }
	 
	  }
	  }
	  return(final);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: displayfinalResults
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. char, operator1 // the value of operator1
*    2. char, operator2 // the value of operator2
*    3. int, operand1 // the value of operand1
*    4. int, operand2 // the value of operand2
*    5. int, operand3 // the value of operand3
*    6. int, finalresult // the value of final result or a offscale value due to
*                           the Denominator is 0
*
*  Function Description:
*
***************************************************************************/

void displayfinalResults(char operator1, char operator2, int operand1, int operand2, int operand3, int finalresult)
{
  // Local statements
     char left = '(';
	 char right = ')';
  
  // Statements
  if(finalresult == 1000000)
  {
    printf("\nEquation: Cannot be evaluated!\n");
  }
  else
  {
	if (operand3 < 0)
    {
		printf("\nEquation: %d %c %d = %d\n", operand1, operator1, operand2, finalresult);
	}		
	else
    {		
	  if((int)operator2 % 5 == 2 && (int)operator1 % 5 != 2)
      {
	     printf("\nEquation: %d %c %c%d  %c %d%c = %d\n", operand1, operator1, left, operand2, operator2, operand3, right, finalresult);
	  }
	  else
	  {
		 printf("\nEquation: %c%d %c %d%c %c %d = %d\n", left, operand1, operator1, operand2, right, operator2, operand3, finalresult); 
	  }
	}
  }	
}

