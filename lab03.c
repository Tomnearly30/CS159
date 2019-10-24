#include<stdio.h>
#include<stdlib.h>


int main()

{
  // Local declaration
  char denom1;//
  char denom2;//
  int num1;//
  int num2;//
  int total;//
  int twenties;//
  int tens;//
  int fives;//
  int ones;//

  // Statement
  printf("Insert first quantity and denomination -> ");
  scanf("%d %c", &num1, &denom1);
  printf("Insert second quantity and denomination -> ");
  scanf("%d %c", &num2, &denom2);

  total = (  1 / (abs( denom1 - 84 ) + 1 ) * 20 + 1 / (abs( denom1 - 102 ) + 1) * 5 + 1 / (abs( denom1 - 111 ) +1 ) + 1 / (abs( denom1 - 116) + 1 )* 10 ) * num1;
  total += ( 1 / (abs( denom2 - 84 ) + 1 ) * 20 + 1 / (abs( denom2 - 102 ) + 1) * 5 + 1 / (abs( denom2 - 111 ) +1 ) + 1 / (abs( denom2 - 116) + 1 ) * 10) * num2;

  printf("Total: %d\n", total);

  return(0);
}
    
