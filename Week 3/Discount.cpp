#include <stdio.h>
int main(){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    float percentage = float(num2)/num1;
    printf("%.2f%%\n", (100-(percentage*100)));
    return 0;
}