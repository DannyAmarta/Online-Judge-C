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
    fscanf(fptr, "%d\n", &TC);

    char sentence[101][101];
    for(int i = 0; i < TC; i++){
        fscanf(fptr, "%[^\n]\n", sentence[i]);
    }

    for(int i = 0; i < TC; i++){
        int count = 0;
        char temp[101];
        char finals[1000] = "";
        
        while(sentence[i][count] != '\0'){   // FIX #1
            int ctTemp = 0;

            while(sentence[i][count] != ' ' && sentence[i][count] != '\0'){
                temp[ctTemp++] = sentence[i][count];
                count++;                     // FIX #2
            }
            temp[ctTemp] = '\0';             // FIX #3

            // Match dictionary
            int replaced = 0;
            for(int j = 0; j < T; j++){
                if(strcmp(temp, shortWord[j]) == 0){
                    strcat(finals, originalWord[j]);   // FIX #4 desc, src
                    replaced = 1;
                    break;
                }
            }

            if(!replaced) strcat(finals, temp);

            if(sentence[i][count] == ' '){
                strcat(finals, " ");          // FIX #5
                count++;
            }
        }

        printf("Case #%d:\n%s\n", i+1, finals);
    }

    fclose(fptr);
    return 0;
}
