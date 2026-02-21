#include<stdio.h>
#include<string.h>

void sortByLetter(char string[]){
    for(int i = 0; i < strlen(string); i++){
        for(int j = i + 1; j < strlen(string); j++){
            if(string[i] > string[j]){
                char temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }
}
void merge(char string[][201], int left, int mid, int right){
    int left_l = mid - left + 1;
    int right_l = right - mid;  
    char left_string[left_l][201];
    char right_string[right_l][201];
    for(int i = 0; i < left_l; i++){
        strcpy(left_string[i], string[i+left]);
    }
    for(int j = 0; j < right_l; j++){
        strcpy(right_string[j], string[j+mid+1]);
    }
    int i = 0, j = 0, k = left;
    while(i < left_l && j < right_l){
        if(strcmp(left_string[i], right_string[j]) >= 0 ){
            strcpy(string[k++], left_string[i++]);
        }
        else{
            strcpy(string[k++], right_string[j++]);
        }
    }
    while(i < left_l){
        strcpy(string[k++], left_string[i++]);
    }
    while(j < right_l){
        strcpy(string[k++], right_string[j++]);
    }
}
void sortByWord(char string[][201], int left, int right){
    int mid = (left + right)/2;
    if(left < right){
        sortByWord(string, left, mid);
        sortByWord(string, mid+1, right);
        merge(string, left, mid, right);
    }
}
int main(){
    int Tc, length;
    scanf("%d %d", &Tc, &length);
    char string[201][201];
    for(int i = 0; i < Tc; i++){
        scanf("%s", string[i]);
        sortByLetter(string[i]);
        // printf("string %s\n", string[i]);
    }
    sortByWord(string, 0, Tc-1);
    for(int i = 0; i < Tc; i++){
        printf("%s\n", string[i]);

    }
    return 0;
}