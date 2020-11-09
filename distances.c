/****************************************************************************
 *  Reads in a map from stdin and repeatedly reads in two integers s and d
 *  and computes the shortest path from s to d. Prints the distances to stdout.
 * 
 *  % gcc distances.c graph.c point.c pqindex.c -o distances
 *  % distances < usa.txt
 *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "graph.h"

int main(int argc, char *argv[]) {
    int i, j, v, e, q, s, d, sp;
    Graph G;

    if(argc!=3){
		printf("Not enough argument!\n");
		exit(1);
	}
	FILE *map = fopen(argv[1], "r");
	if(map==NULL){
		printf("File not found.\n");
		exit(1);
	}

	FILE *query = fopen(argv[2], "r");
	if(query==NULL){
		printf("File not found.\n");
		exit(1);
	}

	//Checking the number of vertices
	fscanf(map, "%d %d", &v, &e);

    // read in graph
    G = GRAPHscan(v,e,map,query);

    // read in shortest path queries and process
    fscanf(query, "%d", &q);
    //printf("%d\n",q);
    j = 0;
    for(i=0; i<q; i++){
    	fscanf(query,"%d %d", &s, &d);
      if(s >= v || d >= v){
        printf("INF\n");
        printf("%d %d\n",s,d);;
        break;
      }
    	sp = GRAPHsp(G, s, d);
    	if(sp == INFINITY) {
    		printf("INF\n");
    	}
    	else {
       		printf("%d\n", sp);
      }
      //GRAPHshow(G);
      GRAPHshowsp(G);
   	}

    return 0;
  }

