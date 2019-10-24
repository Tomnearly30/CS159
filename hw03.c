/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. tian130@purdue.edu
*
*  Homework #: 03
*
*  Academic Integrity Statement:
*
*  I have not used source code obtained from any other unauthorized source, 
*  either modified or unmodified.  Neither have I provided access to my code 
*  to another. The effort I am submitting is my own original work.
*
*  Day, Time, Location of Lab: Tuesday 3:30PM SC G046
*
*  Program Description: Using given  launch velocity, angle and average speed of rover
*                       of a projectile to determine the total flight time,
*                       flight range, maximum height and the retrieval time  
*                       of the projectile in flight.                 
*
***************************************************************************/

#include<stdio.h>
#include<math.h>

// Global Declarations

void inputValues(double* address_velocity, double* address_angle, double* address_rover_speed);
double calcFlight_time(double velocity, double angle, double g);
double calcFlight_range(double velocity, double angle, double flight_time);
double calcMaximum_height(double velocity, double angle, double flight_time);
double calcRetrieval_time(double flight_range, double rover_speed);
void resultDisplay(double flight_time, double flight_range, double maximum_height, double retrieval_time);

int main()
{

  // Local Declarations

  double lau_velocity; // the value of launch velocity
  double angle; // the value of launching  angle
  double flight_time; // the time of the flight last
  double flight_range; // the horizontal distance of the flight last
  double maximum_height; // the maximum height during the flight
  double rover_speed; // the value of rover speed
  double g = 9.80665; // the value of gravitational constant 
  double retrieval_time; // the value of Retrieval Time

  // Statements

  inputValues(&lau_velocity, &angle, &rover_speed);
  flight_time = calcFlight_time(lau_velocity, angle, g);
  flight_range = calcFlight_range(lau_velocity, angle, flight_time);
  maximum_height = calcMaximum_height(lau_velocity, angle, flight_time);
  retrieval_time = calcRetrieval_time(flight_range, rover_speed);
  resultDisplay(flight_time, flight_range, maximum_height, retrieval_time);
  
  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: inputValues
*
*  Function Return Type: Void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double*, velocity, the address variable of variable launch velocity
*    2. double*, angle, the address variable of variable launch angle
*    3. double*, rover_speed, the address variable of variable rover_speed
*
*  Function Description: this function scan the input and pass the input through addrerss
*
***************************************************************************/

void inputValues(double* address_velocity, double* address_angle, double* address_rover_speed)
{
  
  // Statements
  printf("Enter launch velocity (m/s) -> ");
  scanf ("%lf", address_velocity);
  printf("Enter launch angle (degrees) -> ");
  scanf ("%lf", address_angle);
  printf("Enter average speed of rover (km/h) -> ");
  scanf ("%lf", address_rover_speed);
  
  return;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcFlight_time
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double, velocity, the value of initial launching velocity
*    2. double, angle, the value of initial launching velocity
*    3. double, g, the constant value of gravitational constant
*
*  Function Description: this function return the Flight time in seconds (s) based on 
*                        given initial launching velocity and angle 
*
***************************************************************************/

double calcFlight_time(double velocity, double angle, double g)
{
  // Local Declarations
  double time; // the flight time based on given information
  
  // Statements
  time = 2 *  velocity * sin(angle * M_PI / 180 ) / g;
  
  return(time);
  
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcFlight_range
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double, velocity, the value of initial launching velocity
*    2. double, angle, the value of initial launching velocity
*    3. double, flight_time, the time of the flight last
*
*  Function Description: this function return the Flight horizontal range 
*                        in meters (m) based on given initial launching 
*					     velocity and calculated flight time
*
***************************************************************************/

double calcFlight_range(double velocity, double angle, double flight_time)
{
  // Local Declarations
  double range; // the horizontal distance of the flight last
  
  // Statements
  range = velocity * cos(angle * M_PI / 180 ) * flight_time;
  
  return(range);
  
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcMaximum_height
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double, velocity, the value of initial launching velocity
*    2. double, angle, the value of initial launching velocity
*    3. double, flight_time, the time of the flight last
*
*  Function Description: this function return the maximum height 
*                        in meters (m) based on given initial launching 
*					     velocity, launching angle and flight time
*
***************************************************************************/

double calcMaximum_height(double velocity, double angle, double flight_time)
{
  // Local Declarations
  double maximum_h; // the maximum height of this flight
  
  // Statements
  maximum_h = 0.25 * velocity * sin(angle * M_PI / 180 )* flight_time;
  
  return(maximum_h);
  
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcRetrieval_time
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double, flight_range, the horizontal distance of the flight last
*    2. double, rover_speed, the retrieval speed in km/h
*
*  Function Description: this function return the retrive time 
*                        in seconds (s) based on given flight range 
*					     velocity and retrieval speed
*
***************************************************************************/

double calcRetrieval_time(double flight_range, double rover_speed)
{
  // Local Declarations
  double time_retr; // the time for retriving projectile
  
  // Statements
  time_retr = 2 * flight_range / ( rover_speed / 3.6 );
  
  return(time_retr);
  
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: resultDisplay
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. double, flight_time, the time of the flight last
*    2. double, flight_range, the horizontal distance of the flight last
*    3. double, maximum_height, the maximum height during the flight
*    4. double, retrieval_time, the retrieval time for this flight
*
*  Function Description: this function display the results in a required manner 
*
***************************************************************************/

void resultDisplay(double flight_time, double flight_range, double maximum_height, double retrieval_time)
{
  // Local Declarations
  int hs; // temperate variable for storing hour number during time format transfer
  int mins; // temperate variable for storing min number during time format transfer
  double seconds; // // temperate variable for storing second number during time format transfer
  
  // Statements
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  hs = flight_time / 3600;
  mins = (flight_time - 3600 * hs) / 60;
  seconds = flight_time - 3600 * hs - 60 * mins;
  printf("Flight Time   : %d (hrs) %02d (minutes) %3.1lf (seconds)\n", hs, mins, seconds);
  printf("\nFlight Range  :%12.1lf meters\n", flight_range);
  printf("Maximum Height:%12.1lf meters\n", maximum_height);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  hs = retrieval_time / 3600;
  mins = (retrieval_time - 3600 * hs) / 60;
  seconds = retrieval_time - 3600 * hs - 60 * mins;
  printf("Retrieval Time: %d (hrs) %02d (minutes) %3.1lf (seconds)\n", hs, mins, seconds);
  
  return;
  
}
