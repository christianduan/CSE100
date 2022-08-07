#include <iostream>
#include <algorithm>
#include <list>
#include <limits>

using namespace std;

//Creates an array to hold which node has been visited
int visited[numeric_limits<int>::infinity()];
int j = 1;

struct Graph{
    int V;
    list<int> *adj;

    Graph(int V){
        this -> V = V;
        adj = new list<int>[V];
    }
};

//DFS for given arguments
void dfs(list<int> adj[], int arr[], int size, int n){
    list<int>::iterator it;
    j++;

    for(it = adj[n].begin(); it != adj[n].end(); it++){
        if(visited[*it] != 1){
            visited[*it] = 1;
            dfs(adj, arr, size, *it);
        }
        //Adds to counter "j"
        if(visited[*it]){
            j++;
        }
    }
    arr[n] = j;
}

//Searches for key in graph
void dfsFind(list<int> trans[], int k, int size, bool found[]){
    list<int>::iterator it;

    for(int i = 0; i < size; i++){
        for(it = trans[i].begin(); it != trans[i].end(); it++){
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

//Determines whether a node has been hit/visited
void dfsHit(list<int> trans[], list<int> map[], int in, int n){
    list<int>::iterator it;

    for(it = trans[n].begin(); it != trans[n].end(); it++){
        if(visited[*it] != 1){
            map[in].push_back(n);
            visited[*it] = true;
            dfsHit(trans, map, in, *it);
        }
    }
}

void insert(list<int> adj[], int vericies, int edge){
    adj[edge].push_back(vericies);
}

void transpose(list<int> trans[], list<int> adj[], int size){
    list<int>::iterator it;

    for(int i = 0; i < size; i++){
        for(it = adj[i].begin(); it != adj[i].end(); it++){
            trans[*it].push_back(i);
        }
    }
}

void fill(int arr[], int order[], int size){
    int orders = 0;

    for(int i = 0; i < size; i++){
        orders = distance(arr, max_element(arr, arr + size));
        arr[orders] = 0;
        order[i] = orders;
    }
}

void SCC(list<int> trans[], list<int> map[], int arr[], int size){
    for(int i = 0; i < size; i++){
        if(visited[i] != 1){
            dfsHit(trans, map, arr[i], arr[i]);
        }
    }
}

int main(void){
    int edgeSize;
    int size;
    int edge;
    int vertex;

    cin >> size;
    cin >> edgeSize;


    list<int> adj[size];
    list<int> trans[size];
    list<int> map[size];
    
    int arr[size];
    int order[size];

    for(int i = 0; i < edgeSize; i++){
        cin >> vertex >> edge;
        insert(adj, edge, vertex);
    }

    transpose(trans, adj, size);
    dfs(adj, arr, size, 0);

    for(int i = 0; i < size; i++){
        if(visited[i] != 1){
            arr[i] = j + 1;
        }

        visited[i] = 0;
    }
    
    fill(arr, order, size);
    SCC(trans, map, order, size);
  
    for(int i = 0; i < size; i++){
        if(visited[i] != 1){
            map[i].push_back(i);
        }
    }

    bool lastCheck[size];
    for(int i = 0; i < size; i++){
        dfsFind(map, i, size, lastCheck);
    }

    return 0;
}