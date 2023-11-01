#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph{
public:
    vector<vector<int> > adjList;

    void addEdge(int u, int v, bool direction){
        // direction = 0 -> undirected
        // direction = 1 -> directed

        int n = max(u, v) + 1;
        if (adjList.size() < n){
            adjList.resize(n);
        }

        adjList[u].push_back(v);
        // if undirected
        if (direction == 0)
            adjList[v].push_back(u); // edge created from v to u
    }

    void printAdjList(){
        for (int u = 0; u < adjList.size(); u++){
            cout << u << "-> ";
            for(int v : adjList[u]){
                cout << v << ", ";
            }
            cout << endl;
        }
    }
};
int main(){
    Graph g;
    cout << " Enter the number of nodes " << endl;
    int n;
    cin >> n;
    cout << " Enter the number of edges " << endl;
    int e;
    cin >> e;
    for(int i = 0;i<e;i++){
        int u,v,direction;
        cin>>u>>v>>direction;
        g.addEdge(u,v,direction);
    }
    g.printAdjList();
    return 0;
}