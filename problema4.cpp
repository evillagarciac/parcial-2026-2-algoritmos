#include <iostream>
#include <vector>
#include <utility>
using namespace std;

// Adicional del problema 4. Los tres empiezan con [7, 4, 6, 2, 5].
// Base: diapositivas de Insertion/Merge (pag. 4 y 10) y Quick (pag. 9).
void mostrar(int arr[], int left, int right) {
    cout << "[";
    for (int i = left; i <= right; i++) {
        if (i > left) cout << ", ";
        cout << arr[i];
    }
    cout << "]";
}

// Mismo procedimiento de clase; agrego la salida de cada pasada.
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Desplazo los mayores para abrirle espacio a key.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        cout << "Pasada " << i << ", inserto " << key << ": ";
        mostrar(arr, 0, n - 1);
        cout << '\n';
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    // En clase aparecen L[n1] y R[n2]. Uso vector porque los tamanos
    // variables de arreglos locales no forman parte de C++ estandar.
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    cout << "Fusion: ";
    mostrar(arr, left, mid);
    cout << " + ";
    mostrar(arr, mid + 1, right);

    int i = 0, j = 0, k = left;
    // Comparo las cabezas y copio el menor al arreglo original.
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { arr[k] = L[i]; i++; }
        else { arr[k] = R[j]; j++; }
        k++;
    }
    // Una mitad puede terminar antes que la otra.
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
    cout << " -> ";
    mostrar(arr, left, right);
    cout << '\n';
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return; // Cero o un elemento: ya esta ordenado.
    int mid = left + (right - left) / 2;
    cout << "Division: ";
    mostrar(arr, left, right);
    cout << " -> ";
    mostrar(arr, left, mid);
    cout << " y ";
    mostrar(arr, mid + 1, right);
    cout << '\n';
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Adaptacion explicita: clase usa arr[low] y dos indices.
// Aqui uso Lomuto con arr[high], como exige el pivote final de la
// practica y para reproducir exactamente las particiones del informe.
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // El pivote queda en su lugar definitivo.
    return i + 1;
}

// Misma recursion de clase; n solo sirve para mostrar el arreglo completo.
void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        cout << "Subarreglo: ";
        mostrar(arr, low, high);
        int pivot = arr[high];
        int pivotIndex = partition(arr, low, high);
        cout << ", pivote " << pivot << " -> ";
        mostrar(arr, low, pivotIndex - 1);
        cout << " | " << pivot << " | ";
        mostrar(arr, pivotIndex + 1, high);
        cout << "\nArreglo completo: ";
        mostrar(arr, 0, n - 1);
        cout << '\n';
        quickSort(arr, low, pivotIndex - 1, n);
        quickSort(arr, pivotIndex + 1, high, n);
        // No hay merge: ambas partes se ordenaron en el mismo arreglo.
    }
}

bool comprobar(int arr[], int n) {
    int esperado[] = {2, 4, 5, 6, 7};
    if (n != 5) return false;
    for (int i = 0; i < n; i++)
        if (arr[i] != esperado[i]) return false;
    return true;
}

int main() {
    // Copias separadas: ningun algoritmo recibe la salida del anterior.
    int arr1[] = {7, 4, 6, 2, 5};
    int arr2[] = {7, 4, 6, 2, 5};
    int arr3[] = {7, 4, 6, 2, 5};
    cout << "INSERTION SORT\n";
    insertionSort(arr1, 5);
    cout << "\nMERGE SORT\n";
    mergeSort(arr2, 0, 4);
    cout << "\nQUICK SORT (ultimo elemento como pivote)\n";
    quickSort(arr3, 0, 4, 5);
    cout << "\nComprobaciones contra [2, 4, 5, 6, 7]:\n";
    cout << "Insertion: " << (comprobar(arr1, 5) ? "OK" : "ERROR") << '\n';
    cout << "Merge: " << (comprobar(arr2, 5) ? "OK" : "ERROR") << '\n';
    cout << "Quick: " << (comprobar(arr3, 5) ? "OK" : "ERROR") << '\n';
    return comprobar(arr1, 5) && comprobar(arr2, 5) && comprobar(arr3, 5) ? 0 : 1;
}
