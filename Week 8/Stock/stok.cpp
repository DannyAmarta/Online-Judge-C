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

        // track first appearance order
        char order[101][51];
        int orderCnt = 0;

        // init
        for (int x = 0; x < 101; x++) {
            temp[x].qty = 0;
            temp[x].itemName[0] = '\0';
            tempSell[x].qty = 0;
            tempSell[x].itemName[0] = '\0';
            tempFinal[x].qty = 0;
            tempFinal[x].itemName[0] = '\0';
            order[x][0] = '\0';
        }

        int k = 0; // buy count
        int z = 0; // sell count

        // READ INPUT
        for(int j = 0; j < N; j++){
            fscanf(fptr, "%[^#]#%[^#]#%d\n", item[j].condition, item[j].itemName, &item[j].qty);

            // record first appearance
            int seen = 0;
            for(int u = 0; u < orderCnt; u++){
                if(strcmp(order[u], item[j].itemName) == 0){
                    seen = 1;
                    break;
                }
            }
            if(!seen){
                strcpy(order[orderCnt++], item[j].itemName);
            }

            // group buy
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
            // group sell
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

        printf("Case #%d:\n", i+1);

        // BUILD tempFinal
        int x = 0;

        // 1) add buy items
        for(int a = 0; a < k; a++){
            tempFinal[x] = temp[a];
            x++;
        }

        // 2) add sell-only items
        for(int b = 0; b < z; b++){
            int found = 0;
            for(int a = 0; a < k; a++){
                if(strcmp(tempSell[b].itemName, temp[a].itemName)==0){
                    found = 1;
                    break;
                }
            }
            if(!found){
                tempFinal[x] = tempSell[b];
                tempFinal[x].qty = -tempSell[b].qty;
                x++;
            }
        }

        // 3) subtract sells from buys
        for(int a = 0; a < x; a++){
            for(int b = 0; b < z; b++){
                if(strcmp(tempFinal[a].itemName, tempSell[b].itemName)==0){
                    if(tempFinal[a].qty > 0){
                        tempFinal[a].qty -= tempSell[b].qty;
                    }
                }
            }
        }

        // check negative stock
        int hasNegative = 0;
        for(int a = 0; a < x; a++){
            if(tempFinal[a].qty < 0){
                hasNegative = 1;
                break;
            }
        }

        // FINAL OUTPUT USING FIRST APPEARANCE ORDER
        if(hasNegative){
            for(int u = 0; u < orderCnt; u++){
                for(int a = 0; a < x; a++){
                    if(strcmp(order[u], tempFinal[a].itemName)==0 &&
                       tempFinal[a].qty < 0){
                        printf("stock is not enough for product %s\n", order[u]);
                        break;
                    }
                }
            }
        }
        else{
            for(int u = 0; u < orderCnt; u++){
                for(int a = 0; a < x; a++){
                    if(strcmp(order[u], tempFinal[a].itemName)==0 &&
                       tempFinal[a].qty >= 0){
                        printf("%s - %d\n", order[u], tempFinal[a].qty);
                        break;
                    }
                }
            }
        }

    }

    fclose(fptr);
    return 0;
}
