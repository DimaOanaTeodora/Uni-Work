#include <iostream> 
using namespace std;
void heapify(int arr[], int n, int i)
{
    int smallest = i;        // radacina
    int l = 2 * i + 1;       // stanga
    int r = 2 * i + 2;      // dreapta


    //daca copilul din stanga este mai mic ca radacina
    if (l < n && arr[l] > arr[smallest])
        smallest = l; //schimb radacina

    // la fel pentru dreapta
    if (r < n && arr[r] > arr[smallest])
        smallest = r;

    // daca cel mai mic nu e radacina
    int aux;
    if (smallest != i)
    {

        aux = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = aux;

        // functie recursiva pentru subarborele modificat
        heapify(arr, n, smallest);
    }
}


void heapSort(int arr[], int n)
{
    int aux, i;
    //construiesc min-heap
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    
    for (i = n - 1; i >= 0; i--)
    {
        // Mut radacina la final
        aux = arr[0];
        arr[0] = arr[i];
        arr[i] = aux;

        //reduc heapul 
        heapify(arr, i, 0);
    }
    
}


void af(int arr[], int n)//afisare
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


int main()
{
    int arr[] = { 4, 6, 3, 2, 9 };
    int n = 5;

    heapSort(arr, n);

    cout << "Vectorul sortat este: " << endl;
    af(arr, n);
    return 0;

}