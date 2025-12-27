#include <stdio.h>
int main(){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("%.4f%%\n", (float(num2)/num1)*100);

    return 0;
}