#include <iostream>
#include <vector>

using namespace std;

void radixSort(vector <vector <int>> &a, int d){
    // vector <vector <int>> b(a.size());
    int k = 4;
    for(int p = d - 1; p >= 0; p--){
        vector <vector <int>> b(a.size());
        
        for(int i = 0; i < a.size(); i++){
            for(int j= 0; j < 10; j++){
                b[i].push_back(0);
            }
        }

        int* c = new int[k];

        for(int i = 0; i < k; i++){
            c[i] = 0;
        }
        for(int j = 0; j < a.size(); j++){
            c[a[j][p]] = c[a[j][p]] + 1;
        }

        for(int i = 1; i < k; i++){
            c[i] = c[i] + c[i - 1];
        }

        for(int j = a.size() - 1; j >= 0; j--){
            b[c[a[j][p]] - 1] = a[j];
            c[a[j][p]] = c[a[j][p]] - 1;
        }

        for(int i = 0; i < a.size(); i++){
            for(int j = 0; j < 10; j++){
                a[i][j] = b[i][j];
            }
        }
        delete [] c;
    }
}

void printArr(vector <vector <int>> &a, int arr_size){
    for(int i = 0; i < arr_size; i++){
        for(int j= 0; j < 10; j++){
            cout << a[i][j] << ";";
        }
        cout << endl;
    }
}

int main(int argc, char **argv){
    int arr_size;
    int i;
    
    cin >> arr_size;

    vector <vector <int>> a(arr_size);

    int input = 0;

    for(int i = 0; i < arr_size; i++){
        for(int j= 0; j < 10; j++){
            cin >> input;
            a[i].push_back(input);
        }
    }

    radixSort(a, 10);

    printArr(a, arr_size);

    return 0;
}