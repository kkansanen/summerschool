#include <stdio.h>

int main(int argc, char *argv[])
{
   // declare integers, floats, and doubles
	int *p, a, b;
	float*q, c;
	double f, g;
	
	a=10;
	b=5;
	c=3.14;
	f=3.14;
	p=&a;
	q=&c;

   // evaluate expressions, e.g. c = a + 2.5 * b
   // and print out results. Try to combine integers, floats
   // and doubles and investigate what happens in type conversions
	a=a+b;
	c=c*f;
	g=f/b;
	printf("a+b equals %d.\n", a);
	a=(*p)+2;
	printf("pointerstuff with a equals %d.\n", a);
	printf("value of p equals %d.\n",*p);
	printf("c*f equals %f.\n", c);
	printf("the value that q points to is %f.\n", *q);
	
	c=(*q)*f;

	printf("the value of pointer q times f %f.\n", c);
	printf("f/b equals %f.\n", g);
   return 0;
}
