#include <stdio.h>
int main(){
    int testcase, counter=0;
    unsigned long long room_number[5001];
    unsigned long long unique_room[5001];
    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf("%llu" , &room_number[i]);
        counter++;
    }

    int curr = 0;
    for(int i=0; i < counter; i++){
        int found = 0;
        for(int j=0; j <= curr; j++){
            if(unique_room[j] == room_number[i]){
                found = 1;
                break;
            }
        }
        if (!found) {
            unique_room[curr] = room_number[i];
            curr++;
        }
    }
    printf("%d\n", curr);
    return 0;
}