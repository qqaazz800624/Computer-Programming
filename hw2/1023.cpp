#include <iostream>

using namespace std;

int main(){
    int N;
    int *heights;
    int i;
    int max_height = -10000;
    int max_height_index = 0;
    int min_height = 10000;
    int min_height_index = 0;

    cin >> N;
    heights = new int[N];

    for (i = 0; i < N; i++){
        cin >> heights[i];
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
    cout << max_height_index << " " << max_height << endl;
    cout << min_height_index << " " << min_height << endl;

    delete[] heights;
}