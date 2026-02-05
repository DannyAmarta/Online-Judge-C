#include<stdio.h>
int Team_Trees(int numbers[], int N){
    if(N == 0){
        return 0;
    }
    return numbers[N-1] + Team_Trees(numbers, N-1); 
}
int main (){
    int T;
    int N[101];
    int numbers[101][1001];//Ai
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d", &N[i]);
        for(int j = 0; j < N[i]; j++){
            scanf("%d", &numbers[i][j]);
        }
        printf("Case #%d: %d\n", i+1, Team_Trees(numbers[i], N[i]));
    }
   
    return 0;
}