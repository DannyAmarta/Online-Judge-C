#include <stdio.h>
#include <math.h>

int main() {
    int testcase;
    int ANOP[1001],BPN[1001];
    int result[1001];
    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf("%d %d", &ANOP[i], &BPN[i]);
    }
    for(int i=0; i < testcase; i++){
        int N = ANOP[i];
        int X = BPN[i];

        int fromFront = X / 2;            // flips from front
        int fromBack = (N / 2) - (X / 2); // flips from back

        if (fromFront < fromBack) {
            result[i] = fromFront;
        } else {
            result[i] = fromBack;
        }
    }
    for(int i=0; i < testcase; i++){
        printf("Case #%d: %d\n", i + 1, result[i]);
    }

      return 0;
}
