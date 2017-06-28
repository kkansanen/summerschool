#include <stdio.h>

int main(int argc, char *argv[])
{
   // declare integers, floats, and doubles
	int a, b;
	float c;
	double f, g;
	
	a=10;
	b=5;
	c=3.14;
	f=3.14;
	

   // evaluate expressions, e.g. c = a + 2.5 * b
   // and print out results. Try to combine integers, floats
   // and doubles and investigate what happens in type conversions
	a=a+b;
	c=c*f
	g=f/2.5;
	printf("a+b equals %d.\n", a);
	printf("c*f equals %f.\n", c);
	printf("f/2.5 equals %f.\n", g);
   return 0;
}
