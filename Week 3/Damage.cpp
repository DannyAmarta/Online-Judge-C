#include <stdio.h>
int main(){
    double num1, num2, num3;
    scanf("%lf %lf %lf", &num1, &num2, &num3);
    num1 = num1*20/100;
    num2 = num2*30/100;
    num3 = num3*50/100;
    printf("%.2lf\n", num1+num2+num3);
    return 0;
}