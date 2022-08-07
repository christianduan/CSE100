#include <iostream>
#include <list>

using namespace std;

class LinkedList{
    list<int>* hTable;
    int m;

    public:
        LinkedList(int m);
        ~LinkedList();
        int h(int key);
        void i(int key);
        void d(int key);
        void s(int key);
        void o();
};

LinkedList::LinkedList(int size){
    this -> m = size;
    hTable = new list<int>[m];
}

LinkedList::~LinkedList(){

}

int LinkedList::h(int key){
    return (key % m);
}

void LinkedList::i(int key){
    int i = h(key);
    hTable[i].push_front(key);
}

void LinkedList::d(int key){
    int hash = h(key);
    bool deleted = false;

    for(list<int>::iterator it=hTable[hash].begin(); it != hTable[hash].end(); ++it){
        if(*it == key){
            hTable[hash].erase(it);
            cout << key << ":DELETED" << ";" << endl;
            deleted = true;
            break;
        }
    }
    if(deleted != true){
        cout << key << ":DELETE_FAILED" << ";" << endl;
    }
}

void LinkedList::s(int key){
    int hash = h(key);
    int i = 0;
    bool found = false;

    for(list<int>::iterator it=hTable[hash].begin(); it != hTable[hash].end(); ++it){
        if(*it == key){
            cout << key << ":FOUND_AT" << hash << "," << i  << ";" << endl;
            found = true;
            break;
        }
        i++;
    }
    if(found != true){
        cout << key << ":NOT_FOUND" << ";" << endl;
    }

}

void LinkedList::o(){
    for(int i = 0; i < m; i++){
        cout << i << ":";
        for(auto j : hTable[i]){
            cout << j << "->";
        }
        cout << ";" << endl;
    }
}


int main(int argc, char **argv){
    int m;
    char input;
    int key;

    // Obtains number of buckets
    cin >> m;

    LinkedList LinkedList(m);
    
    
    do{
        // Obtains the key
        cin >> input;

        if(input == 'i'){
            cin >> key;
            LinkedList.i(key);
        }
        if(input == 's'){
            cin >> key;
            LinkedList.s(key);
        }
        if(input == 'd'){
            cin >> key;
            LinkedList.d(key);
        }
        if(input == 'o'){
            LinkedList.o();
        }
        if(input == 'e'){
            return 0;
        }

    }
    // Stops program if input character is 'e'
    while(input != 'e');

    return 0;
}