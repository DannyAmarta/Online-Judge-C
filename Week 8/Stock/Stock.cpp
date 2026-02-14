#include<stdio.h>
#include<string.h>
typedef struct item{
    char condition[5];
    char itemName[51];
    int qty;
}Item;
int main(){
    FILE *fptr = fopen("testdata.in", "r");
    int T;
    fscanf(fptr, "%d\n", &T);
    for(int i = 0; i < T; i++){
        int N;
        fscanf(fptr, "%d\n", &N);
        Item item[101];
        Item temp[101];
        Item tempSell[101];
        Item tempFinal[101];
        for (int x = 0; x < 101; x++) {
            temp[x].qty = 0;
            temp[x].itemName[0] = '\0';
            temp[x].condition[0] = '\0';
            tempSell[x].qty = 0;
            tempSell[x].itemName[0] = '\0';
            tempSell[x].condition[0] = '\0';
            tempFinal[x].qty = 0;
            tempFinal[x].itemName[0] = '\0';
            tempFinal[x].condition[0] = '\0';
        }
        int k = 0;
        int z = 0;
        for(int j = 0; j < N; j++){
            fscanf(fptr, "%[^#]#%[^#]#%d\n", item[j].condition, item[j].itemName, &item[j].qty);
            if(strcmp(item[j].condition, "buy") == 0){
                int found = 0;
                for(int a = 0; a < k; a++){
                    if(strcmp(temp[a].itemName, item[j].itemName)==0){
                        temp[a].qty += item[j].qty;
                        found = 1;
                        break;
                    }
                }
                if(!found){
                    temp[k++] = item[j];
                }
            }
            else{
                int found = 0;
                for(int a = 0; a < z; a++){
                    if(strcmp(tempSell[a].itemName, item[j].itemName)==0){
                        tempSell[a].qty += item[j].qty;
                        found = 1;
                        break;
                    }
                }
                if(!found){
                    tempSell[z++] = item[j];
                }
            }
        }
        int x = 0;
        printf("Case #%d:\n", i+1);
        // for(int h = 0; h < z; h++){//sell
        //     for(int j = 0; j < k; j++){//buy
        //         if(strcmp(temp[j].itemName, tempSell[h].itemName) == 0){
        //             temp[j].qty -= tempSell[h].qty;
        //             tempFinal[x++] = temp[j];
        //         }
        //     }
        // }
        // for(int j = 0; j < x; j++){//buy
        //     if(tempFinal[j].qty >= 0){
        //         printf("%s - %d\n", tempFinal[j].itemName, tempFinal[j].qty);
        //     }
        //     else{
        //         printf("stock is not enough for product %s\n", tempFinal[j].itemName);
        //     }

        // }
        // FIRST add all buy items into tempFinal
        for(int a = 0; a < k; a++){
            tempFinal[x] = temp[a];
            x++;
        }

        // THEN add sell-only items (those not found in buy list)
        for(int b = 0; b < z; b++){
            int found = 0;
            for(int a = 0; a < k; a++){
                if(strcmp(tempSell[b].itemName, temp[a].itemName) == 0){
                    found = 1;
                    break;
                }
            }
            if(!found){
                tempFinal[x] = tempSell[b];
                tempFinal[x].qty = - tempSell[b].qty;   // no buy -> negative stock
                x++;
            }
        }

        // THEN combine buy-sell
        for(int a = 0; a < x; a++){
            for(int b = 0; b < z; b++){
                if(strcmp(tempFinal[a].itemName, tempSell[b].itemName) == 0){
                    // only subtract if this is originally a buy entry
                    if(tempFinal[a].qty > 0)
                        tempFinal[a].qty -= tempSell[b].qty;
                }
            }
        }

        // Check if ANY negative
        int hasNegative = 0;
        for(int a = 0; a < x; a++){
            if(tempFinal[a].qty < 0){
                hasNegative = 1;
                break;
            }
        }

        // Print result
        // if(hasNegative){
        //     for(int a = 0; a < x; a++){
        //         if(tempFinal[a].qty < 0){
        //             printf("stock is not enough for product %s\n", tempFinal[a].itemName);
        //         }
        //     }
        // } else {
        //     for(int a = 0; a < x; a++){
        //         printf("%s - %d\n", tempFinal[a].itemName, tempFinal[a].qty);
        //     }
        // }
        //     if(hasNegative){
        // for(int a = 0; a < x; a++){
        //     if(tempFinal[a].itemName[0] == '\0') continue;
        //     if(tempFinal[a].qty < 0){
        //         printf("stock is not enough for product %s\n", tempFinal[a].itemName);
        //         }
        //     }
        // } else {
        //     for(int a = 0; a < x; a++){
        //         if(tempFinal[a].itemName[0] == '\0') continue;
        //         printf("%s - %d\n", tempFinal[a].itemName, tempFinal[a].qty);
        //     }
        // }

        if(hasNegative){
            for(int b = 0; b < z; b++){
                // check if this sell product is negative FINAL stock
                for(int a = 0; a < x; a++){
                    if(strcmp(tempFinal[a].itemName, tempSell[b].itemName) == 0 &&
                    tempFinal[a].qty < 0){
                        printf("stock is not enough for product %s\n", tempSell[b].itemName);
                        break;
                    }
                }
            }
        } else {
            for(int a = 0; a < x; a++){
                if(tempFinal[a].itemName[0] == '\0') continue;
                printf("%s - %d\n", tempFinal[a].itemName, tempFinal[a].qty);
            }
        }

        // if(hasNegative){
        //     // collect negative items
        //     Item neg[101];
        //     int negCount = 0;

        //     for(int a = 0; a < x; a++){
        //         if(tempFinal[a].qty < 0){
        //             neg[negCount++] = tempFinal[a];
        //         }
        //     }

        //     // sort lexicographically
        //     for(int a = 0; a < negCount-1; a++){
        //         for(int b = a+1; b < negCount; b++){
        //             if(strcmp(neg[a].itemName, neg[b].itemName) > 0){
        //                 Item t = neg[a];
        //                 neg[a] = neg[b];
        //                 neg[b] = t;
        //             }
        //         }
        //     }

        //     // print sorted negative products
        //     for(int a = 0; a < negCount; a++){
        //         printf("stock is not enough for product %s\n", neg[a].itemName);
        //     }

        // } else {
        //     // positive case: also sort alphabetically
        //     Item pos[101];
        //     int posCount = 0;

        //     for(int a = 0; a < x; a++){
        //         if(tempFinal[a].itemName[0] == '\0') continue;
        //         pos[posCount++] = tempFinal[a];
        //     }

        //     for(int a = 0; a < posCount-1; a++){
        //         for(int b = a+1; b < posCount; b++){
        //             if(strcmp(pos[a].itemName, pos[b].itemName) > 0){
        //                 Item t = pos[a];
        //                 pos[a] = pos[b];
        //                 pos[b] = t;
        //             }
        //         }
        //     }

        //     for(int a = 0; a < posCount; a++){
        //         printf("%s - %d\n", pos[a].itemName, pos[a].qty);
        //     }
        // }

        
    }
    fclose(fptr);
    return 0;
}