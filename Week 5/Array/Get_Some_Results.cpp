#include<stdio.h>
void input_matrices(int x[51][51], int N){
    for(int j=0; j < N; j++){
        for(int k=0; k < N; k++){
            scanf("%d", &x[j][k]);
        }
    }
}
void multiply_matrices(int x[51][51], int y[51][51], int res[51][51], int N){
    for(int j=0; j < N; j++){
        for(int k=0; k < N; k++){
            res[j][k] = 0;
            for(int i=0; i < N; i++){
                res[j][k] += x[j][i] * y[i][k];   
            }
        }
    }
}
int main(){
    int testcase, N[11];
    int final[11][51][51];
    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf("%d", &N[i]);
        int matrix[11][51][51];
        int matrix2[11][51][51];
        int matrix3[11][51][51];
        input_matrices(matrix[i], N[i]);
        input_matrices(matrix2[i], N[i]);
        input_matrices(matrix3[i], N[i]);
        int res[11][51][51];
        multiply_matrices(matrix[i], matrix2[i], res[i], N[i]);
        multiply_matrices(res[i], matrix3[i], final[i], N[i]);
        
    }
    for(int i=0; i < testcase; i++){
        printf("Case #%d:\n", i+1);
        for(int j=0; j < N[i]; j++){
            for(int k=0; k < N[i]; k++){
                printf("%d", final[i][j][k]);
                if(k < N[i]-1){
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
    }