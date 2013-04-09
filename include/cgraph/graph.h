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
    };
    
    void visited(vertex v, bool b);
    bool operator==(vertex & v1, vertex & v2);
    bool operator>(vertex & v1, vertex & v2);
    bool operator<(vertex & v1, vertex & v2);
    bool operator<=(vertex & v1, vertex & v2);
    bool operator>=(vertex & v1, vertex & v2);
    
    // Relate two vertices together.
    struct edge{
        vertex * u;
        vertex * v;
        enum type { UtoV, VtoU, BOTH } direction;
        double dist;
    };
    
    // Join vertices and edges as lists in a graph.
    struct graph{
        vertex * V;
        edge * E;
        int * magE;
        int * magV;
    };
    
    int * createAdjMatrix(graph & g);
    double * createAdjMatrix(graph & g);
    List * createAdjList(graph & g);
    bool AddVertex(graph & g, vertex v);
    bool AddEdge(graph & g, edge e);
    void explore(graph & g, vertex v);
    void BreadthFirstSearch(graph & g, vertex & origin);
    void DepthFirstSearch(graph & g, vertex & origin);
    void Dijkstra(graph & g, vertex & origin);
    void BellmanFord(graph & g, vertex & origin);
    graph * Partition(graph & g);
    

#ifdef	__cplusplus
}
#endif

#endif	/* GRAPH_H */

