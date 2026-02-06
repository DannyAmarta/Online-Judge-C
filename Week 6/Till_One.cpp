#include<stdio.h>
int Till_One(unsigned long long n){
    if(n == 1){
        return 1;
    }
    if(n % 2 == 0){
        return Till_One(n / 2);
    }
    else{
        return Till_One(n - 1) + Till_One(n + 1);
    }
}
int main(){
    int T;
    unsigned long long N[11];
    scanf("%d",  &T);
    for(int i = 0; i < T; i++){
        scanf("%llu", &N[i]);
        printf("Case #%d: %d\n", i+1, Till_One(N[i]));
    }

    return 0;
}