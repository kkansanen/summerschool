#include <stdio.h>

int main(int argc, char *argv[])
{
   	int f0, f1, f2;
 	f0 = 0;
	f1 = 1;
	f2 = 0;
	printf("%d\n",f0);
	printf("%d\n",f1);
   // initialize variables and write the while loop
   // Remember to update all variables within the loop
	while (f2<100){
		f2=f1+f0;
		if (f2>=100){
		break;
		}else{	
		printf("%d\n",f2);
		f0 = f1;
		f1 = f2;
		}
	}
   return 0;
}
