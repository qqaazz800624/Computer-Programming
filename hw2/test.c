#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int N;
    int *heights;
    int i;
    int max_height = -10000;
    int max_height_index = 0;
    int min_height = 10000;
    int min_height_index = 0;

    scanf("%d", &N);
    heights = (int*)malloc(sizeof(int)*N);
    for (i = 0; i < N; i++){
        scanf("%d", &heights[i]);
    }

    for (i = 0; i < N; i++){
        if (heights[i] > max_height){
            max_height = heights[i];
            max_height_index = i + 1;
        }
        if (heights[i] < min_height){
            min_height = heights[i];
            min_height_index = i + 1;
        }
    }

    printf("%d %d\n", max_height_index, max_height);
    printf("%d %d\n", min_height_index, min_height);

    free(heights);

    return 0;
}