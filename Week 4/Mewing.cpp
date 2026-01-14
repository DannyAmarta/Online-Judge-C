#include <stdio.h>
int main(){
    float ipk;
    scanf("%f", &ipk);
    if(ipk >= 3.5){
        printf("Cumlaude");
    }
    else if(ipk >= 3.0){
        printf("Outstanding");
    }
    else if(ipk >= 2.5){
        printf("Very Good");
    }
    else if(ipk >= 2.0){
        printf("Good");
    }
    else{
        printf("Poor");
    }

    return 0;
}