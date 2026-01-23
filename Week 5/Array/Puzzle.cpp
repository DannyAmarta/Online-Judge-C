#include <stdio.h>
#include <stdbool.h>
int main(){
    int size;
    int matrix[101][101];
    bool is_valid = false;
    scanf("%d", &size);

    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++){
            scanf("%d", &matrix[i][j]);
        }
    }
    for(int i=0; i < size && !is_valid; i++){
        for(int j=0; j < size && !is_valid; j++){
            for(int k= j+1; k < size; k++){
                if(matrix[i][j] == matrix[i][k]){
                    is_valid = true;
                    break;
                }
                if(matrix[j][i] == matrix[k][i]){
                    is_valid = true;
                    break;
                }                
            }
        }
    }
    if(is_valid == true){
        printf("Nay\n");
    }
    else{
        printf("Yay\n");
    }
    return 0;
}