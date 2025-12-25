#include <stdio.h>
int main(){
    double num1;
    double num2;
    scanf("%lf %lf", &num1, &num2);
    for(int i=0; i < 3; i++){
        num1 = num1 + (num1 * (num2/100));
    }
    printf("%.2lf\n", num1);
    return 0;
}