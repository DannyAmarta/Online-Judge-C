#include<stdio.h>
#include<string.h>
int main(){
    int testcase;
    int n[101];
    unsigned long long k[101];
    char mystring[101][101];
    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf("%d %llu", &n[i], &k[i]);
        scanf("%s", mystring[i]);
    }
    for(int i=0; i < testcase; i++){
        char temp[101];
        for(int j=0; j < n[i]; j++){
            unsigned long long asci = mystring[i][j]-97;
            unsigned long long let = (asci + k[i]) % 26;
            temp[j] = 97+let;
        }
        temp[n[i]] = '\0';
        strcpy(mystring[i],temp);
        
    }
    for(int i=0; i < testcase; i++){
        printf("Case #%d: %s\n", i+1, mystring[i]);
    }
    return 0;
}