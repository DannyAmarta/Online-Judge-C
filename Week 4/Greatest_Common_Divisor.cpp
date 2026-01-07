#include <stdio.h>

int main() {
    int t;
    int n[100];
    int a[101];
    int apalah[101][101];   
    int apalah_2[101];      
    int res[10];

    scanf("%d", &t); 

    for(int j = 0; j < t; j++){
        int counter_apalah = 0; 
        scanf("%d", &n[j]);     

        for(int i = 0; i < n[j]; i++){
            int counter = 0; 
            scanf("%d", &a[i]);

            for(int k = 1; k * k <= a[i]; k++) {
                if(a[i] % k == 0) {
                    apalah[i][counter++] = k;
                    if(k != a[i] / k) {
                        apalah[i][counter++] = a[i] / k;
                    }
                }
            }


            if(i == 0){//first time gk ad apalah2, apalah2 ngecopy apalah(kayak prev)
                for(int x = 0; x < counter; x++){
                    apalah_2[x] = apalah[i][x];
                }
                counter_apalah = counter;
            } 
        
            else{//kalo sama curr dan prev take & break untuk save memo
                int temp[101];
                int temp_count = 0;

                for(int x = 0; x < counter_apalah; x++){
                    for(int y = 0; y < counter; y++){
                        if(apalah_2[x] == apalah[i][y]){
                            temp[temp_count++] = apalah_2[x];
                            break;
                        }
                    }
                }

                for(int x = 0; x < temp_count; x++){
                    apalah_2[x] = temp[x];
                }
                counter_apalah = temp_count;
            }//apalah2 jadi temp dan next itteration
        }
        //ambil highest
        int mx = 1;
        for (int x = 0; x < counter_apalah; x++) {
            if (apalah_2[x] > mx) mx = apalah_2[x];
        }
        res[j] = mx;
    }

    for(int i = 0; i < t; i++){
        printf("Case #%d: %d\n", i + 1, res[i]);
    }

    return 0;
}
