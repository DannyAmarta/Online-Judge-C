#include <stdio.h>
int main(){
    int tc;
    int x[10];
    scanf("%d", &tc);
    for(int i=0; i < tc; i++){
        scanf("%d", &x[i]);
    }
    for(int i=0; i < tc; i++){

        for(int j=0; j < x[i]; j++){
            for(int l = x[i]-1; l > j; l--){
                printf(" ");
            }
            for(int k=0; k < j; k++){
                printf("*");
            }
            for(int m=0; m <= j; m++){
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}