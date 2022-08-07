#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// Taken from the pseudocode provided by the textbook
int partition(int* arr, int p, int r){
    int x = arr[r];
    int i = p - 1;

    for(int j = p; j <= r - 1; j++){
        if(arr[j] <= x){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i = (i + 1);
}

// Taken from the pseudocode provided by the textbook
int randomizedPartition(int* arr, int p, int r){
    srand(time(NULL));
    int i = rand() % (r - p) + p;

    swap(arr[r], arr[i]);
    return partition(arr, p, r);
}

// Taken from the pseudocode provided by the textbook
void randomizedQuicksort(int* arr, int p, int r){
    if(p < r){
        int q = randomizedPartition(arr, p, r);
        randomizedQuicksort(arr, p, q - 1);
        randomizedQuicksort(arr, q + 1, r);
    }
}

void printArr(int* arr, int arr_size){
    for(int i = 0; i < arr_size; i++){
        cout << arr[i] << ";";
    }
}

int main(int argc, char **argv){
    int* Sequence;
    int arr_size;
    int i;

    cin >> arr_size;

    Sequence = new int[arr_size];

    for(i = 0; i < arr_size; i++){
        cin >> Sequence[i];
    }

    randomizedQuicksort(Sequence, 0, arr_size - 1);

    printArr(Sequence, arr_size);

    delete[] Sequence;

    return 0;
}