#include <iostream>
#include <cstring>

using namespace std;

int main() {

    int *p;
    int n;
    cin >> n;
    p = new int[n];

    memset(p, 0, n*sizeof(int));
    for (int i=0; i<n; i++){
        cout << p[i] << " ";
    }
    cout << endl;

    delete [] p;
    
    return 0;
}