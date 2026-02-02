#include<stdio.h>
#include<string.h>
int reverse(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
    return 1;
}
void reverseString(char mystring[1001], int start, int end ){
    if(start > end){
        return;
    }
    reverse(&mystring[start], &mystring[end]);
    start++;
    end--;
    return reverseString(mystring, start, end);
}
int main(){
    int testcase;
    char mystring[100][1001];
    scanf("%d", &testcase);
    getchar();
    for(int i=0; i < testcase; i++){
        scanf("%[^\n]", mystring[i]);
        getchar();
        reverseString(mystring[i], 0, strlen(mystring[i])-1);
        printf("Case #%d: %s\n", i+1, mystring[i]);
    }

    return 0;
}