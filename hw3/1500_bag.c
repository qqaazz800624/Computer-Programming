#include "bag.h"
#include <stdio.h>

void ans(int n,int k, int a[]){
    int number_of_item=0, total_weight_of_item=0;
    int i;
    
    for(i = 0; i < n; i++){
        if(a[i] <= k){
            number_of_item++;
            total_weight_of_item += a[i];
        }
    }
    printf("%d %d\n",number_of_item,total_weight_of_item);
}