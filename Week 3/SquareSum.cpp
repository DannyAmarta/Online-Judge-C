#include <stdio.h>
int main(){
    int counter = 0;
    float num1[3], num2[3], num3[3], num4[3];
    float points[3];
    
    scanf("%f %f %f %f", &num1[0], &num2[0], &num3[0], &num4[0]);
    scanf("%f %f %f %f", &num1[1], &num2[1], &num3[1], &num4[1]);
    scanf("%f %f %f %f", &num1[2], &num2[2], &num3[2], &num4[2]);

    do{
        float square[4][4];
        square[0][0] = square[3][3] = num1[counter];
        square[0][1] = square[1][0] = square[2][3] = square[3][2] = num2[counter];
        square[0][2] = square[2][0] = square[1][1] = square[1][3] = square[2][2] = square[3][1] = num3[counter];
        square[0][3] = square[3][0] = square[1][2] = square[2][1] = num4[counter];
        float point = 0;
        for(int i=0; i < 4; i++){
            for(int j=0; j < 4; j++){
                if(square[i][j] == num2[counter]){
                    point += square[i][j]/2;
                }
                else if(square[i][j] == num3[counter]){
                    point += square[i][j]/3;
                }
                else if(square[i][j] == num4[counter]){
                    point += square[i][j]/4;
                }
                else{
                    point += square[i][j];
                }
            }
        }
        points[counter] = point;
        counter++;
    }while(counter < 3);

    printf("%.2f\n", points[0]);
    printf("%.2f\n", points[1]);
    printf("%.2f\n", points[2]);
    return 0;
}