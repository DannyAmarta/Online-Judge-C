#include<stdio.h>
unsigned long long sum(unsigned long long j){
    return j*(j+1)*((2*j)+1)/6;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        unsigned long long M;
        scanf("%llu", &M);

        unsigned long long low = 1, high = 2000000;
        while(low < high){
            unsigned long long mid = (low + high)/2;
            if(sum(mid) >= M){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        printf("Case #%d: %d\n", i+1, low);
    }
    return 0;
}