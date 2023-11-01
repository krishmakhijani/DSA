#include<iostream>
#include<climits>

using namespace std;

void findMinVertex(int* distance, bool* visited, int n, int& minVertex){
    minVertex = -1;
    for(int i = 0; i < n; i++){
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])){
            minVertex = i;
        }
    }
}

void prim(int** edges, int n){
    int* parent = new int[n];
    int* distance = new int[n];
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++){
        distance[i] = INT_MAX;
        visited[i] = false;
    }

   parent[0] = -1;
    distance[0] = 0;
    for(int i = 0; i < n - 1; i++){
        int minVertex;
        findMinVertex(distance, visited, n, minVertex);
        visited[minVertex] = true;
        for(int j = 0; j < n; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                if(edges[minVertex][j] < distance[j]){
                    distance[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    for(int i = 1; i < n; i++){
        if(parent[i] < i){
            cout << parent[i] << " " << i << " " << distance[i] << endl;
        }else{
            cout << i << " " << parent[i] << " " << distance[i] << endl;
        }
    }
    delete [] visited;
    delete [] distance;
    delete [] parent;
}

int main(){
    int n;
    int e;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i = 0; i < n; i++){
        edges[i] = new int[n];
        for(int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0; i < e; i++){
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }
    cout << endl;
    prim(edges, n);
    for(int i = 0; i < n; i++){
        delete [] edges[i];
    }
    delete [] edges;
    return 0;
}