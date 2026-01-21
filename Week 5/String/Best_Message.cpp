#include<stdio.h>
#include<string.h>
void string_checker(char string[1001], char code[1001]){
    int length = strlen(string);
    for(int i=0; i < length; i++){
        if(string[i] == 'A'|| string[i] == 'B'|| string[i] == 'C'|| string[i] == 'D'){
            if(string[i] == 'A'){
                code[i] = '0';
            }
            else if(string[i] == 'B'){
                code[i] = '1';
            }
            else if(string[i] == 'C'){
                code[i] = '2';
            }
            else if(string[i] == 'D'){
                code[i] = '3';
            }
            string[i] = 'A';
        }
        
        else if(string[i] == 'E'|| string[i] == 'F'|| string[i] == 'G'|| string[i] == 'H'){
            if(string[i] == 'E'){
                code[i] = '0';
            }
            else if(string[i] == 'F'){
                code[i] = '1';
            }
            else if(string[i] == 'G'){
                code[i] = '2';
            }
            else if(string[i] == 'H'){
                code[i] = '3';
            }
            string[i] = 'E';
        }
        else if(string[i] == 'I'|| string[i] == 'J'|| string[i] == 'K'|| string[i] == 'L' || string[i] == 'M' || string[i] == 'N'){
            if(string[i] == 'I'){
                code[i] = '0';
            }
            else if(string[i] == 'J'){
                code[i] = '1';
            }
            else if(string[i] == 'K'){
                code[i] = '2';
            }
            else if(string[i] == 'L'){
                code[i] = '3';
            }
            else if(string[i] == 'M'){
                code[i] = '4';
            }
            else if(string[i] == 'N'){
                code[i] = '5';
            }
            string[i] = 'I';
        }
        else if(string[i] == 'O'|| string[i] == 'P'|| string[i] == 'Q'|| string[i] == 'R' || string[i] == 'S' || string[i] == 'T'){
            if(string[i] == 'O'){
                code[i] = '0';
            }
            else if(string[i] == 'P'){
                code[i] = '1';
            }
            else if(string[i] == 'Q'){
                code[i] = '2';
            }
            else if(string[i] == 'R'){
                code[i] = '3';
            }
            else if(string[i] == 'S'){
                code[i] = '4';
            }
            else if(string[i] == 'T'){
                code[i] = '5';
            }
            string[i] = 'O';
        }
        else if(string[i] == 'U'|| string[i] == 'V'|| string[i] == 'W'|| string[i] == 'X' || string[i] == 'Y' || string[i] == 'Z'){
            if(string[i] == 'U'){
                code[i] = '0';
            }
            else if(string[i] == 'V'){
                code[i] = '1';
            }
            else if(string[i] == 'W'){
                code[i] = '2';
            }
            else if(string[i] == 'X'){
                code[i] = '3';
            }
            else if(string[i] == 'Y'){
                code[i] = '4';
            }
            else if(string[i] == 'Z'){
                code[i] = '5';
            }
            string[i] = 'U';
        }
    }
    string[length] = '\0';
    code[length] = '\0';
}
int main(){
    int testcase;
    char string[101][1001];
    char code[101][1001];
    scanf("%d", &testcase);
    for(int i=0; i < testcase; i++){
        scanf("%s", string[i]);
    }
    for(int i=0; i < testcase; i++){
        string_checker(string[i], code[i]);
        printf("Case #%d:\n", i+1);
        printf("%s\n", string[i]);
        printf("%s\n", code[i]);
    }
    return 0;
}