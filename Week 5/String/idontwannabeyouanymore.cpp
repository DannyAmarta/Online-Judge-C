#include<stdio.h>
#include <ctype.h>
void string_checker(char string[101], int length, char new_string[101]){
    int curr = 0;
    for(int i=0; i < length; i++){
        if(isalpha(string[i])){
            new_string[curr++] = string[i];
        }
    }
    new_string[curr] = '\0';
}
int main(){
    int testcase, length[101];
    char string[101][101];
    char new_string[101][101];

    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf("%d", &length[i]);
        getchar() != '\0';
        scanf("%[^\n]", string[i]);
    }
    for(int i=0; i < testcase; i++){
        string_checker(string[i], length[i], new_string[i]); 
    }
    for(int i=0; i < testcase; i++){ 
        printf("Case #%d: %s\n", i+1, new_string[i]);
    }

    return 0;
}