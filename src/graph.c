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

int edgeExists(graph & g, vertex * u, vertex * v){
    for(int i = 0; i < g.magE; i++){
        if((u == g.E[i].u && v == g.E[i].v) ||(u == g.E[i].v && v == g.E[i].u)){
            return 1;
        }
    }
    
    return 0;
}

double edgeExists(graph & g, vertex * u, vertex * v){
    for(int i = 0; i < g.magE; i++){
        if((u == g.E[i].u && v == g.E[i].v) || (u == g.E[i].v && v == g.E[i].u)){
            return g.E[i].dist;
        }
    }
    
    return 0.0;
}

// Should return an adjacency matrix of integers.
int * createAdjMatrix(graph & g){
    int matrix[g.magV][g.magV];
    int i = 0, k = 0;
    
    // For each vertex, define its connection to other vertices.
    // For each row
    for(i; i < g.magV; i++){
        // and each column in the row,
        for(k; k < g.magV; k++){
            // if the vertex at the index i is connected to the vertex
            // at the index k, place 1 in the matrix at (i,k).
            matrix[i][k] = edgeExists(g, &g.V[i], &g.V[k]);
        }
    }
    
    return matrix;
}
// Create an adjacency matrix of doubles.
double * createAdjMatrix(graph & g){
    double matrix[g.magV][g.magV];
    int i = 0, k = 0;
    
    // For each vertex, define its connection to other vertices.
    // For each row
    for(i; i < g.magV; i++){
        // and each column in the row,
        for(k; k < g.magV; k++){
            // if the vertex at the index i is connected to the vertex
            // at the index k, place 1 in the matrix at (i,k).
            matrix[i][k] = edgeExists(g, &g.V[i], &g.V[k]);
        }
    }
    
    return matrix;
}
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
int AddVertex(graph & g, vertex & v){
    g.magV++;
    g.V = realloc(g.V, g.magV);
    g.V[g.magV-1] = v;
}

// Add an edge to a graph. Must form the edge first.
int AddEdge(graph & g, edge & e){
    g.magE++;
    g.E = realloc(g.E, g.magE);
    g.E[g.magE -1] = e;
}

// Explore a graph.
void explore(graph & g, vertex & v);
void BreadthFirstSearch(graph & g, vertex & origin);
void DepthFirstSearch(graph & g, vertex & origin);
void Dijkstra(graph & g, vertex & origin);
void BellmanFord(graph & g, vertex & origin);
// Partition the graph.
graph * Partition(graph & g);