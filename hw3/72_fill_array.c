#include "72_fill_array.h"
#include <stdio.h>

void fill_array(int *ptr[], int n){
    int i;
    int *arr_start;
    arr_start = ptr[0];
    for (i = 0; i < n; i++){
        *ptr[i] = i;
    }

    int max_index = 0;
    for (i=0; i<n; i++){
        int index = ptr[i] - arr_start; // calculate the number of elements 
        if (index > max_index){
            max_index = index;
        }
    }

    for (i=0; i<= max_index; i++){
        int is_pointed = 0;
        int j;
        for (j=0; j<n; j++){
            if (&arr_start[i] == ptr[j]){
                is_pointed = 1;
                break;
            }
        }

        if (!is_pointed){
            int left_value = 0, right_value = 0;
            int found_left = 0, found_right = 0;
            int left, right;
            for (left = i - 1; left >= 0; left--){
                for (j=0; j<n; j++){
                    if (&arr_start[left] == ptr[j]){
                        left_value = *ptr[j];
                        found_left = 1;
                        break;
                    }
                }
                if (found_left){
                    break; 
                };
            }

            for (right = i + 1; right <= max_index; right++){
                for (j=0; j<n; j++){
                    if (&arr_start[right] == ptr[j]){
                        right_value = *ptr[j];
                        found_right = 1;
                        break;
                    }
                }
                if (found_right){
                    break;
                }
            }
            arr_start[i] = left_value + right_value;
        }
    }
}