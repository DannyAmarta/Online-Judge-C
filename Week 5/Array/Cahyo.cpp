#include <stdio.h>
int main(){
    int testcase;
    int friends[101], rooms[101], list[101];
    int rules[101][51][51];
    int people[101][51];
    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf("%d %d %d", &friends[i], &rooms[i], &list[i]);
        for(int j=0; j < friends[i]; j++){
            for(int k=0; k < rooms[i]; k++){
                scanf("%d", &rules[i][j][k]);
            }
        }
        for(int j=0; j < list[i]; j++){
            scanf("%d", &people[i][j]);
        }
    }
    int new_rule[101][51] = {0};//TUTOR NOLin
    for(int i=0; i < testcase; i++){
        for(int l=0; l < list[i]; l++){
            for(int j=0; j < rooms[i]; j++){
                new_rule[i][j] += rules[i][people[i][l]-1][j];
            }
        }
        printf("Case #%d:\n", i+1);
        for(int j=0; j < rooms[i]; j++){
           if(new_rule[i][j] % 2 == 0){
                printf("NO\n");
            }
            else{
               printf("YES\n");
           }
        }

    }

    return 0;
}