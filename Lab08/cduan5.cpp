#include <iostream>
#include <climits>

using namespace std;

void printOptimalParens(int** s, int i, int j){
    if(i == j){
        cout << 'A' << i - 1;
    }
    else{
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int matrixChainOrder(int* p, int size){
    int n = size + 1;
    // m[n][n]
    int** m = new int*[n];
    for(int i = 1; i <= n; i++){
        m[i] = new int[n];
    }

    for(int i = 1; i <= n; i++){
        m[i][i] = 0;
    }
    // s[n][n]
    int** s = new int*[n];
    for(int i = 1; i <= n; i++){
        s[i] = new int[n];
    }
    // For chain order
    for(int l = 2; l < n; l++){
        for(int i = 1; i < n - l + 1; i++){
            int j = i + l - 1;
            // Sets for infinity
            m[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; k++){
                int q = m[i][k] + m[k + 1][j] + p[i - 1]*p[k]*p[j];

                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    int temp = m[1][n-1];
    cout << temp << endl;
    printOptimalParens(s, 1, n - 1);
    cout << endl;
    return temp;
}

int main(int argc, char **argv){
    int size;

    cin >> size;

    int* p = new int[size + 1];
    p[0] = 0;

    for(int i = 0; i <= size; i++){
        cin >> p[i];
    }

    matrixChainOrder(p, size);

    return 0;
}
