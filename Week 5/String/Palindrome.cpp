#include<stdio.h>
#include<string.h>
int checker(char string[501]){
    for(int i = 0, j = strlen(string)-1; i < j; i++, j--){
       if(string[i] != string[j]){
        return -1;
       }
    }
    return 1;
}
int main(){
    int testcase;
    char string[1001][501];
    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf("%s", string[i]);
    }
    for(int i=0; i < testcase; i++){
        printf("Case #%d: ", i+1);
        if(checker(string[i]) == 1){
            printf("Yay, it's a palindrome\n");
        }
        else{
            printf("Nah, it's not a palindrome\n");
        }
    }


    return 0;
}