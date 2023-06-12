#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <climits>
// for this lab we will be construction a Minimum Spanning Tree.
using namespace std;

typedef pair<int, int> intPair;
priority_queue<intPair, vector<intPair>, greater<intPair>> Queue; // This gets the min.

class G{
    list<pair<int, int>> *adj; // adj will store the vertex and weight for every edge as a pair.
    int numV; // V is the number of verticies.

public:
    void mst(); 
    void addE(int u, int vertex, int weight); // adds edges to the graph
    G(int numV);
};

G::G(int numV){ // memory allocation for adj.
    this->numV = numV;
    adj = new list<intPair>[numV];
}

void G::mst() {
    int v, w;
    int root = 0;
    
    vector<int> key(numV, INT_MAX); // initialzes key as infinity.
    vector<bool> intMst(numV, false); // vertices tracker that are within mst.
    vector<int> parent(numV, -1); // parent array stored which

    Queue.push(make_pair(0, root)); //inserting root into the priority queue.
    key[root] = 0;

    while (!Queue.empty()){
        list<pair<int, int>>::iterator i;
        int u = Queue.top().second;
        Queue.pop();
        intMst[u] = true; // vertex included into mst

        for (i = adj[u].begin(); i != adj[u].end(); i++){ // checks if v isn't within mst & if weight is smaller than key v.
            v = (*i).first;
            w = (*i).second;

            if (intMst[v] == false && w < key[v]){
                key[v] = w;
                Queue.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    // Here the mst will be printed
    for (int i = 1; i < numV; ++i){
        cout << parent[i] << endl;
    }
}

void G::addE(int u, int v, int w){
    adj[v].push_back(make_pair(u, w));
    adj[u].push_back(make_pair(v, w));
}

void printG(int n, int E){ // Here the graph will be set up
    int *u = new int[E];
    int *v = new int[E];
    int *w = new int[E];
    G graphing(n);

    for (int i = 0; i < E; i++){
        cin >> u[i] >> v[i] >> w[i];
        graphing.addE(u[i], v[i], w[i]);
    }
    graphing.mst();
}

int main(int argc, char** argv){
    int E, V;
    cin >> V;
    cin >> E;
    printG(V, E);
}