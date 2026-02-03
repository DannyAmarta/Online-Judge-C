#include<stdio.h>
int recursive(int number, int *counter){
    if(number == 0|| number == 1){
        if(number == 0){
            return 1;
        }
        else{
            return 2;
        }
    }
    if(number % 3 == 0){
        (*counter)++;
    }
    if(number % 5 == 0){
        // (*counter)=0;
        return 2*number;
    }
    return recursive(number-1, counter)+number+recursive(number-2, counter)+number-2;
}
int main(){
    int testcase;
    int number[51];
    int result[51];
    int counter[51] = {0};
    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf("%d", &number[i]);
        result[i] = recursive(number[i], &counter[i]);
        printf("Case #%d: %d %d\n", i+1, result[i], counter[i]);
    }
    return 0;
}