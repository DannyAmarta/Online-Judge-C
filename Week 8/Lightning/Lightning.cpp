#include<stdio.h>
#include<string.h>
FILE *fptr;
int main(){
    fptr = fopen("testdata.in", "r");
    if (!fptr) return 0;
    int T;
    fscanf(fptr, "%d", &T);
    for(int i = 0; i < T; i++){
        int total, min ,max;
        char string[10000];
        fscanf(fptr, "%d %d %d", &total, &min, &max);
        fscanf(fptr, "%s", string);
        int count = 0;
        int lightning = 0;
        // printf("s %s\n", string);
        for(int j = 0; j < strlen(string); j++){
            if(string[j] == '1'){
                count++;
            }
            // if(string[j] == '0'){
            else{
                if(count >= min && count <= max){
                    lightning++;
                }
                count = 0;
            }
        }
        if(count >= min && count <= max){
            lightning++;
        }

        printf("Case #%d: %d\n", i+1, lightning);
    }
    return 0;
}