#include<stdio.h>
#include<string.h>
int main(){
    FILE *fptr = fopen("testdata.in", "r"); 
    if (!fptr) return 0;
    int N;
    fscanf(fptr, "%d\n", &N);
    char name[101][41];
    char friends[101][41];
    int a = 0;
    int b = 0;
    for(int i = 0; i < N; i++){
        fscanf(fptr, "%[^#]#%[^\n]\n", name[a++], friends[b++]);
    }
    int T;
    fscanf(fptr, "%d\n", &T);
    char friend_S[101][41];
    int c = 0;
    for(int i = 0; i < T; i++){
        fscanf(fptr, "%[^\n]\n", friend_S[c++]);
    }
    bool is_valid;
    for(int i = 0; i < T; i++){
        is_valid = false;
        for(int j = 0; j < N; j++){
            if(strcmp(name[j], friend_S[i]) == 0){
                printf("Case #%d: %s\n", i+1, friends[j]);
                is_valid = true;
                break;
            }
        }
        if(is_valid == false){
            printf("Case #%d: N/A\n", i+1);
        }
    }
    fclose(fptr);
    return 0;
}