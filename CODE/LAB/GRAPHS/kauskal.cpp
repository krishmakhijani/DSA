#include<iostream>
#include <algorithm>

using namespace std;

class Edge{
    public:
    int source ;
    int destination ;
    int weight ;

};

int findMinVertex(int* weight , bool* visited , int n){
    int minVertex = -1 ;
    for(int i = 0 ; i < n ; i++){
        if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])){
            minVertex = i ;
        }
    }
    return minVertex ;
}

bool compare(Edge e1 , Edge e2){
    return e1.weight < e2.weight ;
}
int findParent(int v , int *parent){
    if(parent[v] == v){
        return v ;
    }
    return findParent(parent[v] , parent) ;
}

void kruskal(Edge *input , int n , int E){


    sort(input , input + E , compare);
    Edge *output = new Edge[n-1] ;
    int *parent = new int[n] ;
    for(int i = 0 ; i < n ; i++){
        parent[i] = i ;
    }
    int count = 0 ;
    int i = 0 ;
    while(count != n-1){
        Edge currentEdge = input[i] ;
        int sourceParent = parent[currentEdge.source] ;
        int destinationParent = parent[currentEdge.destination] ;
        if(sourceParent != destinationParent){
            output[count] = currentEdge ;
            count++ ;
            parent[sourceParent] = destinationParent ;
        }
        i++ ;
    }

    for(int i = 0 ; i < n-1 ; i++){
        if(output[i].source < output[i].destination){
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl ;
        }else{
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl ;
        }
    }

}

int main(){
    int n , E ;
    cin >> n >> E ;
    Edge *input = new Edge[E] ;
    for(int i = 0 ; i < E ; i++){
        int s , d , w ;
        cin >> s >> d >> w ;
        input[i].source = s ;
        input[i].destination = d ;
        input[i].weight = w ;
    }
    kruskal(input , n , E) ;
    return 0 ;
}
