#include <iostream>
#include <climits>

using namespace std;

int find_max_crossing_subarray(int* a, int min, int mid, int max){
   int left_sum = INT_MIN;
   int sum = 0;

   for(int i = mid; i >= min; i--){
       sum = sum + a[i];
       
       if(sum > left_sum){
           left_sum = sum;
       }
   }

   int right_sum = INT_MIN;
   sum = 0;

   for(int j = mid + 1; j <= max; j++){
       sum = sum + a[j];

       if(sum > right_sum){
           right_sum = sum;
       }
   }

   return (left_sum + right_sum);
}

int find_max_subarray(int* a, int min, int max){
    if (max == min){
        return (min, max, a[min]);
    }
    else{   
        int mid = ((min + max) / 2);
        int left_sum = find_max_subarray(a, min, mid);
        int right_sum = find_max_subarray(a, mid + 1, max);
        int cross_sum = find_max_crossing_subarray(a, min, mid, max);

        if(left_sum >= right_sum && left_sum >= cross_sum){
            return left_sum;
        }
        else if(right_sum >= left_sum && right_sum >= cross_sum){
            return right_sum;
        }
        else{
            return cross_sum;
        }
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

    cout << find_max_subarray(Sequence, 0, arr_size - 1);

    delete[] Sequence;

    return 0;
}