#include <iostream>
#include <climits>

using namespace std;

void extendedBottomUpCutRod(int* p, int size){
    int* r = new int[size + 1];
    int* s = new int[size + 1];

    r[0] = 0;

    for(int j = 1; j <= size; j++){
        int q = INT_MIN;

        for(int i = 1; i <= j; i++){
            if (q < p[i] + r[j - i]){
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }

    cout << r[size] << endl;

    while(size > 0){
        cout << s[size] << " ";
        size = size - s[size];
    }
    cout << "-1" << endl;

    delete[] r;
    delete[] s;
}

int main(int argc, char **argv){
    int arrSize = 0;

    cin >> arrSize;

    int* Sequence = new int[arrSize+1];
    Sequence[0] = 0;

    for(int i = 1; i <= arrSize; i++){
        cin >> Sequence[i];
    }

    extendedBottomUpCutRod(Sequence, arrSize);

    delete[] Sequence;

    return 0;
}