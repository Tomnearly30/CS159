
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. tian130@purdue.edu
*  2. svrehas@purdue.edu
*  3. dkepich@purdue.edu
*
*  Lab #:01
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Tuesday 3:30 pm - 5:20 pm SC G046
*
*  Program Description: This program calculates the volume and surface areas of a right circular frustum.
*
***************************************************************************/

#include <stdio.h>

int main (void)
{
  // Local Declarations
  float upper_radius; // the upper radius of the frustum
  float lower_radius; // the lower radius of the frustum   
  float height; // the height of the frustum
  float side; // the side height of the frustum
  float volume; // the volume of the frustum 
  float lateral_surf; // lateral surface area of frustum
  float top_surf; // top surface area of frustum
  float bottom_surf; // bottom surface area of frustum
  float totalsurf; // total surface area of frustum

  // Statements
  printf("Enter the value for the upper radius (r)\n");
  scanf("%f", &upper_radius);
  printf("Enter the value for the lower radius (R)\n");
  scanf("%f", &lower_radius);
  printf("Enter the value for the height (h)\n");
  scanf("%f", &height);
  printf("Enter the value for the side (s)\n");
  scanf("%f", &side);

  //Calculation of Volume and Surface
  volume = 3.14 * height / 3 * ( upper_radius * upper_radius + lower_radius * lower_radius + upper_radius * lower_radius );
  lateral_surf = 3.14 * ( upper_radius + lower_radius ) * side;
  top_surf = 3.14 * upper_radius * upper_radius;
  bottom_surf = 3.14 * lower_radius * lower_radius;
  totalsurf = lateral_surf + top_surf + bottom_surf;

  printf("\nVolume is : %10.2f", volume);
  printf("\nLateral Surface Area is : %10.2f", lateral_surf);
  printf("\nTop Surface Area is : %10.2f", top_surf);
  printf("\nBottom Surface Area is : %10.2f", bottom_surf);
  printf("\nTotal Surface Area is : %10.2f\n", totalsurf);

  return 0;
}

