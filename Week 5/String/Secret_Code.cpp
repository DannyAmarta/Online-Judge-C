#include <stdio.h>
#include <string.h>

int main() {
    int T;
    static int Q[101];
    static short L[101][1001], R[101][1001];  // use short: values ≤ 1000, saves memory
    static char S[101][1001];                  // store codes directly in contiguous memory

    scanf("%d", &T);

    // ---- Input ----
    for (int i = 0; i < T; i++) {
        scanf("%d %s", &Q[i], S[i]);
        for (int j = 0; j < Q[i]; j++)
            scanf("%hd %hd", &L[i][j], &R[i][j]);
    }

    // ---- Processing ----
    for (int i = 0; i < T; i++) {
        char *str = S[i];               // pointer alias for faster access
        for (int j = 0; j < Q[i]; j++) {
            int left = L[i][j] - 1;
            int right = R[i][j] - 1;

            // reverse using two-pointer swap
            while (left < right) {
                char tmp = str[left];
                str[left++] = str[right];
                str[right--] = tmp;
            }
        }
    }

    // ---- Output ----
    for (int i = 0; i < T; i++)
        printf("Case #%d: %s\n", i + 1, S[i]);

    return 0;
}

// #include<stdio.h>
// #include<string.h>
// int main(){
//     int testcase;
//     int q[101];
//     int a[101][1001], b[101][1001];
//     char string[101][1001];
//     scanf("%d", &testcase);
//     for(int i=0; i < testcase; i++){
//         scanf("%d %s", &q[i], string[i]);
//         for(int j=0; j < q[i]; j++){
//             scanf("%d %d", &a[i][j], &b[i][j]);
//         }
//     }
//     for(int i=0; i < testcase; i++){
//         for(int y=0; y < q[i]; y++){
//             int left = a[i][y] - 1;
//             int right = b[i][y] - 1;

//             while(left < right){
//                 char temp = string[i][left];
//                 string[i][left] = string[i][right];
//                 string[i][right] = temp;
//                 left++;
//                 right--;
//             }
//         }
//         printf("Case #%d: %s\n", i+1, string[i]);
//     }
   
//     return 0;
// }