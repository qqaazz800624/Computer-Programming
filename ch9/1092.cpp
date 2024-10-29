#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    int *p;
    
    p = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    //bubble sort 
    bool swapped;
    for (int j=n; j>1; j--){
        swapped = false;
        for (int i=0; i<j-1; i++){
            if (p[i] > p[i+1]){
                int temp = p[i];
                p[i] = p[i+1];
                p[i+1] = temp;
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
    }
    

    for (int i=0; i<n; i++){
        cout << p[i] << " ";
    }
    cout << endl;

    delete[] p;

    return 0;
}