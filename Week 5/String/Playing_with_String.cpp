#include<stdio.h>
#include<string.h>
int main(){
    int testcase, noq[101];
    char string[101][1001];
    char A[101][101], B[101][101];

    scanf("%d", &testcase);
    getchar();
    for(int i=0; i < testcase; i++){
        scanf("%s", string[i]);
        getchar();
        scanf("%d", &noq[i]);
        getchar();
        for(int j=0; j < noq[i]; j++){
            scanf(" %c %c", &A[i][j], &B[i][j]);
        }
    }
    for(int i=0; i < testcase; i++){
        for(int j=0; j < strlen(string[i]); j++){
            for(int k=0; k < noq[i]; k++){
                if(string[i][j] == A[i][k]){
                    string[i][j] = B[i][k];
                }
            }    
        }
        printf("Case #%d: %s\n", i+1, string[i]);
    }
    return 0;
}