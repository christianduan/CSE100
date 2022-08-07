#include <iostream>

using namespace std;

// Function for insertion sort from textbook psuedocode
void insertion_sort(int* arr, int n){
    for (int j = 1; j < n; j++){
        int key = arr[j];
        int i = j -1;
        while (i >= 0 && arr[i] > key){
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = key;

        // Prints iterations
        for (int k = 0; k <= j; k++){
            cout << arr[k] << ";";
        }
        // Creates new line
        cout << "\n";
    }
}

// Main body from previous lab
int main(int argc, char **argv){
    int* Sequence;
    int arraySize = 1;

    // Obtains array size from user input
    cin >> arraySize;
    // New array named Sequence of array size
    Sequence = new int[arraySize];

    // Obtains elements from user for array Sequence
    for(int i = 0; i < arraySize; i++){
        cin >> Sequence[i];
    }

    // Calls insertion sort function
    insertion_sort(Sequence, arraySize);

    /* Tested for user input and sorting function

    for (int i = 0; i < arraySize; i++){
        cout << Sequence[i];
    }
    */

    // Frees up allocated memory used
    delete[] Sequence;

    return 0;
}