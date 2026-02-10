#include<stdio.h>
#include<string.h>
int main(){
    FILE *fptr = fopen("testdata.in", "r");

    int T;
    fscanf(fptr, "%d\n", &T);
    char X[101][101];
    for(int i = 0; i < T; i++){
        fscanf(fptr, "%s\n", &X);
    }
    
    int N;
    fscanf(fptr, "%d\n", &N);
    char from[101];
    char into[101];
    for(int i = 0; i < N; i++){
        fscanf(fptr, "%c %c\n", from[i], into[i]);
    }
    
    for(int k = 0; k < T; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < strlen(X[i]); j++){
                if(X[k][j] == from[i]){
                    X[k][j] = into[i];
                }
            }
        }
    }
    for(int i = 0; i < T; i++){
        printf("%s", X[i]);
    }
    fclose(fptr);
    return 0;
}