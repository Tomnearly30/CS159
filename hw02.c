
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. tian130@purdue.edu
*
*  Homework #: 02
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday 3:30PM SC G046
*
*  Program Description: Calculation of direction and magnitude of three 
*                       different vectors with given values of start-end points
*
***************************************************************************/

#include<stdio.h>
#include<math.h>

int main()

{
  // Local declarations
  double x_value_a; // X value of point A
  double y_value_a; // Y value of point A
  double x_value_b; // X value of point B
  double y_value_b; // Y value of point B
  double x_value_c; // X value of point C
  double y_value_c; // Y value of point C
  double mag_q; // magnitude of vector Q
  double direc_q; // direction of vector Q
  double mag_r; // magnitude of vector R
  double direc_r; // direction of vector  R
  double mag_s; // magnitude of vector S
  double direc_s; //direction of vector S

  // Statments
  printf("\nEnter the x and y values for point A -> ");
  scanf("%lf %lf", &x_value_a, &y_value_a);
  printf("Enter the x and y values for point B -> ");
  scanf("%lf %lf", &x_value_b, &y_value_b);
  printf("Enter the x and y values for point C -> ");
  scanf("%lf %lf", &x_value_c, &y_value_c);

  // Calculation of Magnitude& Direction for each vector
  mag_q = sqrt( pow( x_value_b - x_value_a, 2) + pow( y_value_b - y_value_a, 2));
  direc_q = atan(( y_value_b - y_value_a) / ( x_value_b - x_value_a)) * 180 / M_PI;
  mag_r = sqrt( pow( x_value_c - x_value_b, 2) + pow( y_value_c - y_value_b, 2));
  direc_r = atan(( y_value_c - y_value_b) / ( x_value_c - x_value_b)) * 180 / M_PI;
  mag_s = sqrt( pow( x_value_c - x_value_a, 2) + pow( y_value_c - y_value_a, 2));
  direc_s = atan(( y_value_c - y_value_a) / ( x_value_c - x_value_a)) * 180 / M_PI;
 
  printf("\n    Magnitude  Direction\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Q:%9.2lf%10.2lf deg\n", mag_q, direc_q);
  printf("R:%9.2lf%10.2lf deg\n", mag_r, direc_r);
  printf("S:%9.2lf%10.2lf deg\n", mag_s, direc_s);

  return(0);
}
