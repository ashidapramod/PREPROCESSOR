#include<stdio.h>
#define A 10
#define B 20
#define SUM(x,y) (x+y)
#define SQUARE(x) (x*x)

int main()
{
//printing macro without arguments
printf("A = %d\n",A);
printf("B = %d\n",B);

/* 
printing macro with arguments
SUM take two arguments
SQUARE takes one argument 
*/
printf("Sum = %d\n",SUM(A,B));
printf("Square = %d\n",SQUARE(5));

return 0;
}
