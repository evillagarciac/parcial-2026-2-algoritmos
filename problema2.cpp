#include <iostream>
using namespace std;

bool ordenado(int arr[], int n) {
    if (n <= 1) return true;

    bool ok = ordenado(arr, n - 1);
    return ok && arr[n - 2] <= arr[n - 1];
}

int main() {
    int arr1[] = {1, 2, 3, 5, 8};
    int arr2[] = {1, 2, 2, 5, 8};
    int arr3[] = {1, 4, 2, 8};

    cout << (ordenado(arr1, 5) ? "verdadero" : "falso") << endl;
    cout << (ordenado(arr2, 5) ? "verdadero" : "falso") << endl;
    cout << (ordenado(arr3, 4) ? "verdadero" : "falso") << endl;

    return 0;
}
