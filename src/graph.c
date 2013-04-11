#include <cgraph/graph.h>
#include <stdlib.h>
#include <types.h>

void initGraph(graph & g){
    g.E = NULL;
    g.V = NULL;    
    g.count = 0;
    g.magE = 0
    g.magV = 0;
}

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
    if(g.V == NULL){
        g.V = malloc(sizeof(vertex));
        
        if(g.V == NULL){
            return -1;
        }
        
        g.V = v;
        g.magV++;
    } else {
        g.magV++;
        vertex * oldV = malloc(sizeof(vertex)*g.magV-1);
    
        for(int i = 0; i < g.magV-1; i++){
                oldV[i] = g.V[i];
        }
    
        g.V = realloc(g.V, g.magV);
        if(g.V = NULL){
                g.magV--;
                g.V = oldV;
                return -1;
        }
        g.V[g.magV-1] = v;
        free(oldV);
    }
    
    return 1;
}

// Add an edge to a graph. Must form the edge first.
int AddEdge(graph & g, edge & e){
    if(g.E == NULL){
        g.E = malloc(sizeof(edge));
        
        if(g.E == NULL){
            return -1;
        }
        
        g.magE++;
        g.E = e;
    } else {
        edge * oldE = malloc(sizeof(edge)*g.magE);
    
        for(int i = 0; i < g.magE; i++){
                oldE[i] = g.E[i];
        }
    
        g.magE++;
        g.E = realloc(g.E, g.magE);
        if(g.E == NULL){
                g.magE--;
                g.E = oldE;
                return -1;
        }
        g.E[g.magE -1] = e;
        free(oldE);
    }
    
    return 1;
}

// Explore a graph.
void explore(graph & g, vertex & v){
    v.visit = TRUE;
    v.previsit = g.count;
    g.count++;
    
    List * edges = findEdges(g, v);
    
    for(List * current = edges; current != NULL; current = current->next){
        if(((edge *)current->data)->u == v && ((edge *)current->data)->v->visit == FALSE){
            explore(g, ((edge *)current->data)->*v);
        }
    }
    
    v.postvisit = g.count;
    g.count++;
}

void explore(graph & g, vertex & v, List & l){
    
}

void explore(graph & g, vertex & v, int & matrix){
    
}

void BreadthFirstSearch(graph & g, vertex & origin){
    
}

void DepthFirstSearch(graph & g, vertex & origin){
    for(int i = 0; i < g.magV; i++){
        g.V[i].visit = FALSE;
    }
    
    for(int k = 0; k < g.magV; k++){
        if(g.V[k].visit == FALSE){
            explore(g, g.V[k]);
        }
    }
/*
    if(g.magV > g.magE){
        List * AdjList = createAdjList(graph & g);
        
        for(List * current = AdjList; current != NULL; current = current->next){
            vertex * current_vert = ((vertex *)((List*)current->data)->data);
            if(current_vert->visit == FALSE){
                explore(g, current_vert, AdjList); 
            }
        }
    } else {
        
    }
*/
}

void Dijkstra(graph & g, vertex & origin){
    
}

void BellmanFord(graph & g, vertex & origin){
    
}

// Partition the graph.
graph * Partition(graph & g){
    
}