// merge sort time シ

#include<iostream>
#include<climits>

using namespace std;

void merge(int A[], int beg, int mid, int end){
    int test1 = mid - beg + 1;
    int test2 = end - mid;
    
    int* L;
    int* R;
    
    L = new int[test1+1];
    R = new int[test2+1];

    for (int i = 0; i < test1; i++){
        L[i] = A[beg + i];
    }

    for (int j = 0; j < test2; j++){
        R[j] = A[mid + j + 1];
    }

    L[test1] = INT_MAX;
    R[test2] = INT_MAX;

    int i = 0;
    int j = 0;

    for (int k = beg; k <= end; k++){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i = i + 1;
        }

        else{
            A[k] = R[j];
            j = j + 1;
        }
    }
}

void mergesort(int A[], int beg, int end){
    if (beg < end){
        int mid = ((beg + end)/2);
        mergesort(A, beg, mid);
        mergesort(A, mid + 1, end);
        merge(A, beg, mid, end);
    }
}

int main(){
    int* arr;
    int array_size;

    cin >> array_size;

    arr = new int[array_size];

    for(int i = 0; i < array_size; i++){
        cin >> arr[i];
    }

    mergesort(arr, 0, array_size);

    for(int i = 0; i < array_size; i++){
        cout << arr[i] << ";";
    }

    delete[] arr;
}