#include<stdio.h>
#include<math.h>

// Gloabal Declarations

double calcHexa_SurfArea(double side);
double calcHexa_Volume(double side);
double calcPenta_SurfArea(double side);
double calcPenta_Volume(double side);
double calcCube_SurfArea(double side);
double calcCube_Volume(double side);
double calcTriangular_SurfArea(double side);
double calcTriangular_Volume(double side);

 int main()

{
  // Local Declarations
  
  double side; // Length value of each side 
  
  double hexa_A; // surface area of given length side right regular hexagonal prism
  double hexa_V; // volume of given length side right regular hexagonal prism
  double penta_A; // surface area of given length side right regular pentagonal prism
  double penta_V; // volume of given length side right regular pentagonal prism
  double cube_A; // surface area of given length side cube 
  double cube_V; // volume of given length side cube 
  double triangular_A; // surface area of given length side triangular prism
  double triangular_V; // volume of given length side triangular prism
  
  
  //  Statements 
  
  printf("Input testing side length -> ");
  scanf("%lf", &side);
  
  hexa_A = calcHexa_SurfArea(side);
  hexa_V = calcHexa_Volume(side);
  
  penta_A = calcPenta_SurfArea(side);
  penta_V = calcPenta_Volume(side);

  cube_A = calcCube_SurfArea(side);
  cube_V = calcCube_Volume(side);
  
  
  triangular_A = calcTriangular_SurfArea(side);
  triangular_V = calcTriangular_Volume(side);
  
  // Testing
  
  printf("\nGenerated Length:%7.3lf\n\n", side);
  printf("Shape      Surface Area   Volume\n");
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf(" Hexagonal:%10.2lf%12.2lf\n", hexa_A, hexa_V);
  printf("Pentagonal:%10.2lf%12.2lf\n", penta_A, penta_V);
  printf("      Cube:%10.2lf%12.2lf\n", cube_A, cube_V);
  printf("Triangular:%10.2lf%12.2lf\n", triangular_A, triangular_V);
  
  return(0);

}


/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcHexa_SurfArea(double s)
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, s, the same value of the length of all the sides
*
*  Function Description: This function use the value of length of side to
*                        calculate the surface area of a right regular
*                        hexagonal prism
*
***************************************************************************/




double calcHexa_SurfArea(double s)

{
  // Local Declarations

  double hexa_A; // the surface area of Hexagonal with the given side value
 
  // Statements
 
  hexa_A = (6 + 3 * sqrt(3)) * pow(s,2);

  return (hexa_A);
}


/***************************************************************************
*
*  Function Information
*
*  Name of Function:calcHexa_Volume(double s) 
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, s, the same value of the length of all the side 
*
*  Function Description: This function use the value of length of side to
*                        calculate the volume of a right regular 
*                        hexagonal prim
*
***************************************************************************/

double calcHexa_Volume(double s)
{
  // Local Declarations
  double hexa_V; // the volume of Hexagonal with the given side value

  // Statements

  hexa_V = 0.5 * 3 * sqrt(3) * pow(s, 3);

  return( hexa_V);

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcPenta_SurfArea(double s)
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, s, the same value of the length of all the sides
*
*  Function Description: This function use the value of length of side to
*                        calculate the surface area of a right regular
*                        pentagonal prism
*
***************************************************************************/




double calcPenta_SurfArea(double s)

{
  // Local Declarations

  double penta_A; // the surface area of Pentagonal with the given side value
 
  // Statements
 
  penta_A = 5 * pow(s, 2) + 0.5 * sqrt(5 * ( 5 + 2 * sqrt(5) )) * pow(s,2);

  return (penta_A);
}


/***************************************************************************
*
*  Function Information
*
*  Name of Function:calcPenta_Volume(double s) 
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, s, the same value of the length of all the side 
*
*  Function Description: This function use the value of length of side to
*                        calculate the volume of a right regular 
*                        pentagonal prim
*
***************************************************************************/

double calcPenta_Volume(double s)
{
  // Local Declarations
  double penta_V; // the volume of Pentagonal with the given side value

  // Statements

  penta_V = 0.25 * sqrt(5*(5 + 2 * sqrt(5))) * pow(s, 3);

  return( penta_V);

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcCube_SurfArea(double s)
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, s, the same value of the length of all the sides
*
*  Function Description: This function use the value of length of side to
*                        calculate the surface area of a cube
*
***************************************************************************/




double calcCube_SurfArea(double s)

{
  // Local Declarations

  double cube_A; // the surface area of cube with the given side value
 
  // Statements
 
  cube_A = 6 * pow(s,2);

  return (cube_A);
}


/***************************************************************************
*
*  Function Information
*
*  Name of Function:calcCube_Volume(double s) 
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, s, the same value of the length of all the side 
*
*  Function Description: This function use the value of length of side to
*                        calculate the volume of a cube
*
***************************************************************************/

double calcCube_Volume(double s)
{
  // Local Declarations
  double cube_V; // the volume of cube with the given side value

  // Statements

  cube_V =  pow(s, 3);

  return( cube_V);

}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: calcTriangular_SurfArea(double s)
*
*  Function Return Type:double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, s, the same value of the length of all the sides
*
*  Function Description: This function use the value of length of side to
*                        calculate the surface area of a triangular prism
*
***************************************************************************/




double calcTriangular_SurfArea(double s)

{
  // Local Declarations

  double triangular_A; // the surface area of triangular  prism with the given side value
 
  // Statements
 
  triangular_A = 3 * pow(s,2) + 0.5 * sqrt(3 * pow(s,4));

  return (triangular_A);
}


/***************************************************************************
*
*  Function Information
*
*  Name of Function:calcTriangular_Volume(double s) 
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, s, the same value of the length of all the side 
*
*  Function Description: This function use the value of length of side to
*                        calculate the volume of a a triangular prism
*
***************************************************************************/

double calcTriangular_Volume(double s)
{
  // Local Declarations
  double triangular_V; // the volume of triangular prism with the given side value

  // Statements

  triangular_V = 0.25 * s * sqrt(3 * pow(s,4));

  return(triangular_V);

}

