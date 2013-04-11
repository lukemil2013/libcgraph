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
    List * adjList = createAdjList(g);
    int i = 0, k = 0;
    
    // For each vertex, define its connection to other vertices.
    for(List * current_row = adjList; current_row != NULL; current_row = current_row->next){
        for(List * current_column = ((List *)current_row->data)->next; current_column != NULL; current_column = current_column->next){
            
        }
    }
}
// Create an adjacency matrix of doubles.
double * createAdjMatrix(graph & g);
// Create an adjacency list.
List * createAdjList(graph & g){
    List * tempList;
    initList(tempList);
    
    for(int i = 0; i < g.magV; i++){
        List * temp;
        initList(temp);
        addToList(temp, g.V[i]);
        appendToList(temp,findEdges(g,g.V[i]));
        addToList(tempList, temp);
    }
    
    return tempList;
}
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