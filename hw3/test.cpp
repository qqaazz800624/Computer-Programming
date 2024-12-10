#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50}; // Array of integers
    int* ptr[3] = {&arr[1], &arr[3], &arr[4]}; // Pointers to specific elements in the array

    int* arr_start = &arr[0]; // Points to the start of the array

    // Compute indices relative to arr_start
    for (int i = 0; i < 3; i++) {
        int index = ptr[i] - arr_start; // Index of the element pointed to by ptr[i]
        cout << "ptr[" << i << "] points to arr[" << index << "]: " << *ptr[i] << endl;
    }

    return 0;
}
