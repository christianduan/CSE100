// scc time シ

#include <iostream>
#include <list>
#include <climits>
#include <algorithm>

using namespace std;

int visits[INT_MAX];
int j = 1;

struct Graph{
    int V;
    list<int> *adj;

    Graph(int V){
        this -> V = V;
        adj = new list<int>[V];
    }
};

void dfs(list<int> adj[], int arr[], int size, int n){
    list<int>::iterator it;
    j = j + 1;

    for(it = adj[n].begin(); it != adj[n].end(); it++){
        if(visits[*it] != 1){
            visits[*it] = 1;
            dfs(adj, arr, size, *it);
        }

        if(visits[*it]){
            j++;
        }
      
    }
    
    arr[n] = j;
}

void dfsSearch(list<int> trans[], int k, int size, bool found[]){
    list<int>::iterator it;

    for(int i = 0; i < size; i++){
    for(it = trans[i].begin(); it != trans[i].end(); ++it){
            if(*it == k){
                cout << i << endl;
                found[k] = true;
                break;
            }
        }
    }

    if(found[k] != 1){
        cout << k << endl;
    }
}

void dfsVisit(list<int> trans[], list<int> map[], int in, int n){
    list<int>::iterator it;

    for(it = trans[n].begin(); it != trans[n].end(); it++){
        if(visits[*it] != 1){
        map[in].push_back(n);
            visits[*it] = true;
            dfsVisit(trans, map, in, *it);
        }
    }
}

void insert(list<int> adj[], int vericies, int edge){
    adj[edge].push_back(vericies);
}

void transpose(list<int> trans[], list<int>adj[], int size ){
    list<int>::iterator it;

    for(int i = 0; i < size; i++){
        for(it = adj[i].begin(); it != adj[i].end(); ++it){
            trans[*it].push_back(i);
        }
    }
}

void fillOrder(int arr[], int order[], int size){
    int orders = 0;
    
    for (int i = 0; i < size; i++){
        orders = distance(arr, max_element(arr, arr + size));
        arr[orders] = 0;
        order[i] = orders;
    }
    
}

void getSCC(list<int> trans[], list<int> map[], int arr[], int size){
    for(int i = 0; i < size; i++){
        if(visits[i] != 1){
            dfsVisit(trans, map, arr[i], arr[i]);
        }
    }
}  

int main(){
    int edgeSize, size, edge, vertex;

    cin >> size;
    cin >> edgeSize;


    list<int> adj[size];
    list<int> trans[size];
    list<int> map[size];
    
    int* arr;
    int* order;

    arr = new int[size];
    order = new int[size];

    for(int i = 0; i < edgeSize; i++){
        cin >> vertex >> edge;
        insert(adj, edge, vertex);
    }

    transpose(trans, adj, size);
    dfs(adj, arr, size, 0);

    for(int i = 0; i < size; i++){
        if(visits[i] != 1){
            arr[i] = j + 1;
        }

        visits[i] = 0;
    }
    
    fillOrder(arr, order, size);
    getSCC(trans, map, order, size);
  
    for(int i = 0; i < size; i++){
        if(visits[i] != 1){
            map[i].push_back(i);
        }
    }

    bool lastCheck[size];
    for(int i = 0; i < size; i++){
        dfsSearch(map, i, size, lastCheck);
    }
    
    delete[] arr;
    delete[] order;
}