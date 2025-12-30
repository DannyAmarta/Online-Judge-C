#include <stdio.h>

int main() {
    int a, b, c, d;
    float total[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        total[i] = 2*a + 2*b + 2*c + d;
    }
    printf("%.2f\n", total[0]);
    printf("%.2f\n", total[1]);
    printf("%.2f\n", total[2]);
    return 0;
}
