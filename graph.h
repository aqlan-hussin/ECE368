/*********************************************************************
 *  This code is from "Algorithms in C, Third Edition,
 *  by Robert Sedgewick, Addison-Wesley, 2002.
 *********************************************************************/

#define INFINITY 9999999
#define EPSILON  0.000001

typedef struct { int v; int w; } Edge;
Edge EDGE(int v, int w);

typedef struct graph *Graph;

Graph  GRAPHinit(int V, int E);
Graph  GRAPHscan(int v, int e, FILE* file1, FILE* file2);
void   GRAPHshow(Graph G);
void   GRAPHshowsp(Graph G);
int    GRAPHsp(Graph G, int s, int d);
void   GRAPHplot(Graph G);
void   GRAPHinsertE(Graph G, Edge e);
