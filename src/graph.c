#include <cgraph/graph.h>
#include <stdlib.h>
#include <types.h>

List * findEdges(graph & g, vertex * v){
    List * edgeList;
    initList(edgeList);
    
    for(int i = 0; i < g.magE; i++){
        if(g.E->u == v){
            addToList(*edgeList,g.E[i]);
        }
    }
    
    return edgeList;
}

// Should return an adjacency matrix of integers.
int * createAdjMatrix(graph & g){
    int matrix[g.magV][g.magV];
    
    // For each vertex, define its connection to other vertices.
    for(int i = 0; i < g.magV; i++){
        
        for(int k = 0; k < g.magV; k++){
            if(i==k){
                matrix[i][k] = 0;
            }else{
                
            }
        }
    }
}
// Create an adjacency matrix of doubles.
double * createAdjMatrix(graph & g);
// Create an adjacency list.
List * createAdjList(graph & g);
// Add a vertex to a graph.
int AddVertex(graph & g, vertex & v);
// Add an edge to a graph. Must form the edge first.
int AddEdge(graph & g, edge & e);
// Explore a graph.
void explore(graph & g, vertex & v);
void BreadthFirstSearch(graph & g, vertex & origin);
void DepthFirstSearch(graph & g, vertex & origin);
void Dijkstra(graph & g, vertex & origin);
void BellmanFord(graph & g, vertex & origin);
// Partition the graph.
graph * Partition(graph & g);