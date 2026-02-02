#include<stdio.h>
void Fibo_String(char result[], int n, char a, char b, int *index){
    if(n < 0){
        return;
    }
    if(n == 0){
        result[(*index)++] = a; 
    }
    else if(n == 1){
        result[(*index)++] = b; 
    }
    else{
        Fibo_String(result, n-1, a, b, index);
        Fibo_String(result, n-2, a, b, index);
    }
}
int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        int n;
        char a;
        char b;
        scanf("%d %c %c", &n, &a, &b);
        char result[1000];
        int index = 0;
        Fibo_String(result, n, a, b, &index);
        result[index] = '\0';
        printf("Case #%d: %s\n", i+1, result);
    }
    return 0;
}