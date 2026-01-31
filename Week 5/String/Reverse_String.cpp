#include <stdio.h>
#include <string.h>
void reverse(char string[1001]){
    for(int i = 0, j = strlen(string)-1; i < j; i++, j--){
       char temp = string[i];
       string[i] = string[j];
       string[j] = temp;
    }
}
int main(){
    int testcase;
    char string[101][1001];
    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf(" %s", string[i]);
    }
    for(int i=0; i < testcase; i++){
        reverse(string[i]);
        printf("Case #%d : %s\n", i+1, string[i]);
    }
    return 0;
}