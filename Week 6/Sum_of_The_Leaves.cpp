#include<stdio.h>
int leafCount = 0;
int leafSums[101][101];
void SumOfTheLeaves(int index, int currentSum, int number, int leaves[], int testIndex){
    if(index > number) return;
    currentSum += leaves[index - 1];// ngisi buat nanti nambahin kalo berhasil

    int left = index * 2;
    int right = index * 2 + 1;
    if(left > number && right > number){
        leafSums[testIndex][leafCount++]= currentSum;
    }
    if(left <= number){
        SumOfTheLeaves(left, currentSum, number, leaves, testIndex);
    }
    if(right <= number){
        SumOfTheLeaves(right, currentSum, number, leaves, testIndex);
    }
}
int main(){
    int testcase;
    int number[101];
    int leaves[101][101];
    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf("%d", &number[i]);
        for(int j=0; j < number[i]; j++){
            scanf("%d", &leaves[i][j]);
        }
        
    }
    for(int i = 0; i < testcase; i++){
        leafCount = 0;
        SumOfTheLeaves(1, 0, number[i], leaves[i], i);
        printf("Case #%d:\n", i+1);
        for(int j = 0; j < leafCount; j++) {
            printf("%d\n", leafSums[i][j]);
        }
    }

    
    return 0;
}