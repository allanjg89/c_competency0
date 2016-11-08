#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>


/*
int main(void) {
	printf("%d", mypow(3.4, 3));
	getchar();
}
*/

float mypow(float base, int power) {
	float returnVal = 1;
	int i;
	for ( i = 0; i < power; i++)
	{
		returnVal *= base;
	}

	return returnVal;
}