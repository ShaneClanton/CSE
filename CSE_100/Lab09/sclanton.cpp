#include<iostream>
#include<queue>
#include<map>
using namespace std;

map<char, string>C;
// struct Node is just a Tree node
struct  Node {
    char symbol;
    int freq;
    Node *left, *right;    
};

// 
struct compare {
    bool operator()(Node* left, Node* right){
        // Defining prority on the basis of frequency.
        return (left->freq > right->freq);
        }
};

priority_queue<Node *, deque<Node *>, compare> Q;
// used priority queue as it was mentioned in the book.
// This is done to encode the data in a easy and efficient way.
Node* acquire(char symbol, int freq){
    Node* node= new Node();
    node->freq=freq, node->symbol=symbol;
    node->left = node->right=NULL;
    return node;
}

// encode helps traverse the Huffman Tree and store it's code in a map.
void encode(Node *Q, string child, int c) {
    char symbols[]={'A','B','C','D','E','F'};
    
    if (Q==NULL) {
        return;
    }
    if (Q->symbol == symbols[c]) {
        C.insert(make_pair (symbols[c],child));
    }
    if (Q->symbol!= symbols[c]){
    // lines below assign within the tree, the left child 0's and right child 1's.
    encode(Q->left, child + "0", c);
    encode(Q->right, child + "1", c);
    }
};

void HUFFMAN(){
    // Here we will establish new nodes for x,y and z.
    Node *x, *y, *z = NULL;

    for(int n=6; n!=1;n--){
        // .top and .pop are essentially the EXTRACT-MIN(Q) from the books psuedo code.
        // .top is used to return a reference to the top element and then pop removes the top element.
        x = Q.top();
        Q.pop();
        y = Q.top();
        Q.pop();
        // Acquire the addition of both x and y nodes based on frequency just like the book.
        z = acquire(' ', (x->freq + y->freq));
        // Node z has x as the left child and y as the right child.
        z->left = x;
        z->right = y;
        Q.push(z);
    }
}

int main(){
    int freq;
    int i=0;
    while (i!=6){
        cin>>freq;
        if (i==0){
            // .push is used to see if there is any room in the stack and if so it then adds the element
            // into the top of the stack in which this case the stack maxes out at 6.
            Q.push(acquire('A', freq));
        }
        if (i==1){
            Q.push(acquire('B', freq));

        }
        if (i==2){
            Q.push(acquire('C', freq));

        }
        if (i==3){
            Q.push(acquire('D', freq));

        }
        if (i==4){
            Q.push(acquire('E', freq));

        }
        if (i==5){
            Q.push(acquire('F', freq));

        }
        i++;
    }

    HUFFMAN();
    for (int i = 0; i < 6; i++) {
        encode(Q.top(), "",i);
    }
    // Symbols are printed here
     map<char, string>::iterator key = C.begin();
        while(key != C.end()){
            cout<<key->first<<":"<<key->second<<endl;
            key++;
         }
}