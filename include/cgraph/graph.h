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
    
#ifndef FALSE
#define FALSE 0
#define TRUE 1
#endif

    // We'll store data in the vertex structure.
    struct vertex{
        // data can be of any type.
        void * data;
        // This should be one if visited, 0 otherwise.
        int visit;
        // To keep track of visitation.
        int previsit;
        int postvisit;
    };
    
    // This may not be needed.
    int Compare(vertex & l, vertex & r);
    
    // Relate two vertices together.
    struct edge{
        // If edge is one way directional, u should be the starting node.
        vertex * u;
        // Should be the ending node.
        vertex * v;
        // Indicate the direction of the edge.
        // Undirected edges should be treated as two way directional.
        enum type { ONE_WAY, TWO_WAY } direction;
        // The distance between the two nodes.
        double dist;
    };
    
    // Check if an edge exists between vertices u and v.
    // If it exists, return 1 or
    int edgeExists(graph & g, vertex* u, vertex * v);
    // the distance between them.
    double edgeExist(graph & g, vertex * u, vertex * v);
    
    // Join vertices and edges as lists in a graph.
    struct graph{
        // This should be an array allocated using malloc and added to
        // using realloc. Applies to V and E.
        vertex * V;
        edge * E;
        // The number of edges in the graph, i.e. size of array.
        int magE;
        // The number of vertices in the graph.
        int magV;
        // Used for a vertices previsit and postvisit numbers.
        int count;
    };
    
    /*
     * Every graph should be initialized before it is used. Allocates space
     * for one structure each for the vertex and edge arrays.
     * Input: A graph reference.
     */
    void initGraph(graph & g);
    
    /* 
     * Should return an adjacency matrix of integers. The row and column indices
     * represent the indices for the vertices in the graph's vertex array. An
     * edge is represented by a one.
     * Input: A graph reference.
     * Output: A two-dimensional integer array of size g.magV * g.magV
     */
    int * createAdjMatrix(graph & g);
    
    /*
     * Returns an adjacency matrix of doubles. Same as the integer matrix, but
     * the non-zero double values represent the distance between the nodes.
     * Input: A graph reference.
     * Output: A two-dimensional double array of size g.magV * g.magV
     */
    double * createAdjMatrix(graph & g);
    
    /*
     * Returns an adjacency matrix representation of the graph.
     * Input: A graph reference.
     * Output: A linked list adjacency matrix.
     * @TODO: Look into using an array of Lists instead of a List of Lists.
     * @TODO: It might be easier to work with. Can allocate and expand array
     * @TODO: using malloc and realloc functions.
     */
    List * createAdjList(graph & g);
    
    /*
     * Uses realloc to expand the vertex array of the graph and add a new 
     * vertex to the end.
     * Input: A graph and vertex reference.
     * Output: 1 indicates success and -1 indicates an error in the reallocation
     *          process.
     */
    int AddVertex(graph & g, vertex & v);
    /*
     * Uses realloc to expand the edge array of the graph and add a new edge to 
     * to the end.
     * Input: A graph and edge reference.
     * Output: 1 indicates success and -1 indicates an error in the reallocation
     *          process.
     */
    int AddEdge(graph & g, edge & e);
  
    /*
     * Explore a graph vertex by vertex. Used by DepthFirstSearch.
     * Input: A graph and vertex reference.
     */
    void explore(graph & g, vertex & v);
    
    /*
     * Explore a graph using a vertex's neighbors first and update it's distance
     * from a starting vertex.
     * Input: A graph and vertex reference.
     */
    void BreadthFirstSearch(graph & g, vertex & origin);
    void DepthFirstSearch(graph & g, vertex & origin);
    void Dijkstra(graph & g, vertex & origin);
    void BellmanFord(graph & g, vertex & origin);
    
    /*
     * Partition the graph.
     * @TODO: Need to think about this one. We could use it for selecting subgraphs
     * @TODO: or change it to return a list of the vertices connecting the
     * @TODO: the subgraphs in the graph. Not sure what we are looking for.
     */
    graph * Partition(graph & g);
    

#ifdef	__cplusplus
}
#endif

#endif	/* GRAPH_H */

