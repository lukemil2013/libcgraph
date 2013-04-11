/* 
 * File:   graph.h
 * Author: Anthony Milholen
 *
 * Created on April 7, 2013, 8:56 PM
 */

#ifndef GRAPH_H
#define	GRAPH_H

#ifdef	__cplusplus
extern "C" {
#endif

    // We'll store data in the vertex structure.
    struct vertex{
        void * data;
        bool visit = false;
        int previsit;
        int postvisit;
    };
    
    void visit(vertex & v, bool b);
    int Compare(vertex & l, vertex & r);
    
    // Relate two vertices together.
    struct edge{
        vertex * u;
        vertex * v;
        enum type { ONE_WAY, TWO_WAY } direction;
        double dist;
    };
    
    int edgeExists(graph & g, vertex* u, vertex * v);
    double edgeExist(graph & g, vertex * u, vertex * v);
    
    // Join vertices and edges as lists in a graph.
    struct graph{
        vertex * V;
        edge * E;
        int * magE;
        int * magV;
        int count;
    };
    
    // Should return an adjacency matrix of integers.
    int * createAdjMatrix(graph & g);
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
    

#ifdef	__cplusplus
}
#endif

#endif	/* GRAPH_H */

