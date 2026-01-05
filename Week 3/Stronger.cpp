#include <stdio.h>
int main(){
    long long num1, hit;
    long long total = 100;
    scanf("%lld", &num1);
    for(long long i=1; i<num1; i++){
        hit = 100;
        hit+=(50*i);
        total += hit;
    }
    printf("%lld\n", total);
    return 0;
}