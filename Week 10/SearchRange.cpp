#include<stdio.h>
#include<string.h>
char name[15005][255];
int binarySearch(char nameO[], int T){
    int left = 0, right = T-1;
    while(left <= right){
        int mid = (left + right)/2;
        if(strcmp(nameO, name[mid]) == 0){
            return mid;
        }
        else if(strcmp(nameO, name[mid]) < 0){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}
int main(){
    int T;
    scanf("%d", &T);
    int value[15005];
    for(int i = 0; i < T; i++){
        scanf("%s %d", name[i], &value[i]);
    }
    int search;
    scanf("%d", &search);
    for(int i = 0; i < search; i++){
        char name2[255], name3[255];
        scanf("%s %s", name2, name3);
        if(strcmp(name2, name3) == 0){
            printf("not valid\n");
            continue;
        }
        // printf("%s %s", name2, name3);
        int idx2 = binarySearch(name2, T);
        int idx3 = binarySearch(name3, T);
        // printf("idx%d %d\n", idx2, idx3);

        if(idx2 == -1 || idx3 == -1){
            printf("not found\n");
            continue;
        }
        
        int newValue = value[idx2] - value[idx3];
        if(newValue < 0) newValue = -newValue;

        int newIndex = idx2 - idx3;
        if(newIndex < 0) newIndex = -newIndex;

        printf("%d %d\n", newValue, newIndex);
    }
    return 0;
}