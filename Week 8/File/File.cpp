#include<stdio.h>
#include<string.h>
int main(){
    FILE *fptr = fopen("testdata.in", "r");
    int T;
    fscanf(fptr, "%d\n", &T);
    
    char shortWord[101][51];
    char originalWord[101][51];
    for(int i = 0; i < T; i++){
        fscanf(fptr, "%[^#]#%s\n", shortWord[i], originalWord[i]);
    }
    
    int TC;
    char sentence[101][101];
    fscanf(fptr, "%d\n", &TC);

    for(int i = 0; i < TC; i++){
        fscanf(fptr, "%[^\n]\n", sentence[i]);
    }

    for(int i = 0; i < TC; i++){//ini sentences
        int count = 0;
        char temp[101];
        char finals[101];
        while(strlen(sentence[i]) == count){
            int ctTemp = 0;
            while(sentence[i][count] != ' '){
                temp[ctTemp] = sentence[i][count];
                ctTemp++;
            }
            for(int j = 0; j < T; j++){
                if(strcmp(temp, shortWord[j]) == 0){
                    int leng = strlen(originalWord[i]);
                    int k;
                    for(k = 0; k < leng; k++){
                        finals[k] = originalWord[i][k];
                    }
                    if(strlen(sentence[i]) != count) finals[k+1] = ' ';
                }
            }
        }
        printf("Case #%d:\n%s\n", i+1, finals);
     
    }
    fclose(fptr);
    return 0;
}