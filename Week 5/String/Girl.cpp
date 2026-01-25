#include<stdio.h>
#include<string.h>

int main (){
    int testcase;
    char string[101][10001];
    scanf("%d", &testcase);

    for(int i = 0; i < testcase; i++){
        scanf("%s", string[i]);
    }

    int counter[101];

    for(int i = 0; i < testcase; i++){
        int seen[256] = {0}; // Faster character tracking
        counter[i] = 0;

        for(int j = 0; string[i][j] != '\0'; j++){
            unsigned char c = string[i][j];
            if (!seen[c]) {
                seen[c] = 1;
                counter[i]++;
            }
        }

        if(counter[i] % 2 == 0){
            printf("Case #%d: Yay\n", i + 1);
        } else {
            printf("Case #%d: Ewwww\n", i + 1);
        }
    }

    return 0;
}

// #include<stdio.h>
// #include<string.h>
// int main (){
//     int testcase;
//     char string[101][10001];
//     scanf("%d", &testcase);
//     for(int i=0; i < testcase; i++){
//         scanf("%s", string[i]);
//     }
//     int counter[101];
//     for(int i=0; i < testcase; i++){
//         char temp[101][10001];
//         counter[i] = 0;
//         for(int j=0; j < strlen(string[i]); j++){
//             int ban = 0;
//             for(int k=0; k <= counter[i]; k++){
//                 if(string[i][j] == temp[i][k]){
//                     ban = 1;
//                     break;
//                 }
                
//             }
//             if(ban == 0){
//                 temp[i][counter[i]] = string[i][j];
//                 counter[i]++;
//             }
//         }
//         if(counter[i] % 2 == 0){
//             printf("Case #%d: Yay\n", i+1);
//         }
//         else{
//             printf("Case #%d: Ewwww\n", i+1);
//         }
//     }

//     return 0;
// }