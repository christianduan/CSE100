#include <iostream>

using namespace std;

// Taken from pseudocode in the textbook
void maxHeapify(int* arr, int i, int arr_size){
    int largest = i;
    int Left = 2*i + 1;
    int Right = 2*i + 2;

    if (Left < arr_size && arr[Left] > arr[i]){
        largest = Left;
    }
    else{
        largest = i;
    }

    if(Right < arr_size && arr[Right] > arr[largest]){
        largest = Right;
    }

    if(largest != i){
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, arr_size);
    }
}

// Taken from pseudocode in the textbook
void buildMaxHeap(int* arr, int arr_size){
    for(int i = (arr_size/2) - 1; i >= 0; i--){
        maxHeapify(arr, i, arr_size);
    }
}

// Taken from pseudocode in the textbook
void heapSort(int* arr, int arr_size){
    buildMaxHeap(arr, arr_size);

    for(int i = arr_size - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        // arr_size = arr_size - 1;
        maxHeapify(arr, 0, i);
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

    heapSort(Sequence, arr_size);

    printArr(Sequence, arr_size);

    delete[] Sequence;

    return 0;
}