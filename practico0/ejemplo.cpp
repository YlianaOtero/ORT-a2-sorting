#include <iostream>

using namespace std;

// método burbuja
void bubbleSort(int *v, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (v[j] < v[i]) 
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}

void bubbleSortConTope(int *v, int n, int max) 
{

    bool* arrBooleano = new bool[max+1];

    for (int i = 0; i < max+1; i++) {
        arrBooleano[i] = false;
    }

    for (int j = 0; j < n; j++) {
        int valorActual = v[j];
        arrBooleano[valorActual] = true;
    }

    int posV = 0;

    for (int posArrBooleano = 0; posArrBooleano < max+1; posArrBooleano++) {
        if (arrBooleano[posArrBooleano]) {
            v[posV] = posArrBooleano;
            posV++;
        } 
    }
}

void merge(int* arr, int inicio, int mitad, int fin) { 
    int longitud_izquierda = mitad - inicio + 1;
    int longitud_derecha = fin - mitad;
    int* izquierda = new int[longitud_izquierda];
    int* derecha = new int[longitud_derecha];

    for (int i = 0; i < longitud_izquierda; i++) {
        izquierda[i] = arr[inicio + i];
    };

    for (int j = 0; j < longitud_derecha; j++) {
        derecha[j] = arr[mitad + 1 +j];
    };
    
    
    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < longitud_izquierda && j < longitud_derecha) {
        if (izquierda[i] <= derecha[j]) { //comparo el elem izquierdo con el elem derecho
            arr[k] = izquierda[i]; // y agrego el mas chico
            i++; 
        } else {
            arr[k] = derecha[j];
            j++;
        }

        k++;
    }
    
    while (i < longitud_izquierda) {
        arr[k] = izquierda[i];
        i++;
        k++;
    }

    while (j < longitud_derecha) {
        arr[k] = derecha[j];
        j++;
        k++;
    }

}

void mergeSort(int* arr, int inicio, int fin) {

    if (inicio < fin) { //si inicio < fin entonces   
        int medio = (inicio + fin)/2; // medio = (inicio + fin) / 2
        mergeSort(arr, inicio, medio);   // Dividir y ordenar la mitad izquierda
        mergeSort(arr, medio + 1, fin);  // Dividir y ordenar la mitad derecha
        merge(arr, inicio, medio, fin);  // Combinar las dos mitades ordenadas}

    };
};


int main () {
    int max = 100000000;

    int n;

    cin >> n;

    int *vec = new int[n];

    for (int i = 0; i < n; i++) 
    {
        cin >> vec[i];
    }

    //bubbleSort(vec, n);
    //mergeSort(vec, 0, n);
    bubbleSortConTope(vec, n, max);

    for (int i = 0; i < n; i++) 
    {
        cout << vec[i] << " ";
    }

    return 0;
}