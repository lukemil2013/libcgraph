/* 
 * File:   graph.h
 * Author: anthony
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
    };
    
    // Relate two vertices together.
    struct edge{
        vertex * u;
        vertex * v;
        enum type { UtoV, VtoU, BOTH } direction;
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

#ifdef	__cplusplus
}
#endif

#endif	/* GRAPH_H */

