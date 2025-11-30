#include<stdio.h>
int main (){
	
	int radius;
	double area;
	scanf("%d", &radius);
	area = 3.14 * (radius * radius);
	printf("%lf", area);
	return 0;
}