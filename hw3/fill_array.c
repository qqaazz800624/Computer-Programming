#include "fill_array.h"
#include <stdio.h>

void fill_array(int *ptr[], int n) {
    int *base = ptr[0]; 
    int max_index = 0;

    for (int i = 0; i < n; i++) {
        int idx = ptr[i] - base;  
        if (idx > max_index) {
            max_index = idx;
        }
    }

    for (int i = 0; i <= max_index; i++) {
        base[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int idx = ptr[i] - base;  
        base[idx] = i;            
    }

    for (int i = 0; i <= max_index; i++) {
        if (base[i] == -1) {  
            int left = i - 1;
            int right = i + 1;

            while (left >= 0 && base[left] == -1) left--;

            while (right <= max_index && base[right] == -1) right++;

            int left_value = (left >= 0) ? base[left] : 0;
            int right_value = (right <= max_index) ? base[right] : 0;

            base[i] = left_value + right_value; 
        }
    }
}