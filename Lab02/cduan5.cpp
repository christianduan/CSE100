#include <iostream>
#include <climits>

using namespace std;

// Psuedocode presented in the textbook
void merge(int* arr, int const left, int const mid, int const right){
    int num1 = mid - left + 1;
    int num2 = right - mid;

    // Creates two new arrays that are used for merging to a sorted array
    int *left_arr = new int[num1 + 1];
    int *right_arr = new int[num2 + 1];

    for(int i = 0; i < num1; i++){
        left_arr[i] = arr[left + i];
    }
    for(int j = 0; j < num2; j++){
        right_arr[j] = arr[mid + j + 1];
    }

    left_arr[num1] = INT_MAX;
    right_arr[num2] = INT_MAX;

    int i = 0;
    int j = 0;

    // Compares elements to each other from the two different arrays
    for(int k = left; k <= right; k++){
        if(left_arr[i] <= right_arr[j]){
            arr[k] = left_arr[i];
            i++;
        }
        else{
            arr[k] = right_arr[j];
            j++;
        }
    }

    // Frees up memory allocated for the two merge arrays
    delete [] left_arr;
    delete [] right_arr;
}

// Sorts the arrays from merge function
void merge_sort(int* arr, int  first, int  last){
    if(first < last){
        int mid = (first + last) / 2;
        merge_sort(arr, first, mid);
        merge_sort(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
}

// Prints out elements of the arrays
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

    merge_sort(Sequence, 0, arr_size - 1);

    printArr(Sequence, arr_size);

    delete[] Sequence;

    return 0;
}