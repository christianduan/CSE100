#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>

using namespace std;

map<string, string> code;

struct Node{
    int freq;
    string c;
    Node *left;
    Node *right;

    Node(){
        freq = 0;
        c = ' ',
        left = NULL;
        right = NULL;
    }

    Node(string c){
        freq = 0;
        this -> c = c;
        left = NULL;
        right = NULL;
    }

    void printCode(Node* root, string str){
        if(root -> left == NULL && root -> right == NULL){
            code[root -> c] = str;
            return;
        }

        printCode(root -> left, str + "0");
        printCode(root -> right, str + "1");
    }
};

struct compare{
    bool operator()(Node* l, Node* r){
        return (l -> freq > r -> freq);
    }
};

Node* huffmanCode(vector<Node*> code){
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    for(int i = 0; i < code.size(); i++){
        minHeap.push(code[i]);
    }

    while(minHeap.size() > 1){
        Node * top = new Node();

        Node * left = minHeap.top();
        minHeap.pop();

        Node * right = minHeap.top();
        minHeap.pop();

        top -> freq = left -> freq + right -> freq;
        top -> left = left;
        top -> c = left -> c + right -> c;
        top -> right = right;

        minHeap.push(top);
    }
    return minHeap.top();
}

int main(void){
    vector<Node*> C;

    for(int i = 0; i < 6; i++){
        char c = 'A' + i;
        string s = "";
        s += c;
        Node* n = new Node(s);
        cin >> n->freq;
        C.push_back(n);
    }

    Node* root = huffmanCode(C);
    root->printCode(root, "");

    for(map<string, string>::iterator it = code.begin(); it != code.end(); it++){
        cout << it->first << ":" << it->second << endl;
    }

    return 0;
}