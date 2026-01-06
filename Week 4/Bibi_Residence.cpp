#include <stdio.h>
#include <math.h>
int main() {
    int testcase;
    int numebers[1000];
    int a[100000];
    int gap[10][100000];
    int curr[10];
    scanf("%d", &testcase); 

    for(int j = 0; j < testcase; j++){ 
        scanf("%d", &numebers[j]);     
        
        for(int i = 0; i < numebers[j]; i++){
            scanf("%d", &a[i]);
        }
        curr[j] = 2000000000;  
        for(int i = 1; i < numebers[j]; i++){
            gap[j][i-1] = a[i] - a[i-1]; 
            int g = abs(gap[j][i-1]);    
            if (g < curr[j]) {
                curr[j] = g;              
            }
        }
    }
 
    for(int j = 0; j < testcase; j++){ 
        printf("Case #%d: %d\n", j + 1, curr[j]);
    }

    return 0;
}
