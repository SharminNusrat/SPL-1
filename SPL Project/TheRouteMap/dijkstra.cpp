
#include "header.h"


#define INFINITY 999999
#define MAX_VERTICES 100




int dist[MAX_VERTICES];
int visited[MAX_VERTICES];
int parent[MAX_VERTICES];




int minDistance(int dist[],int visited[],int nodes) {

    int min, minIdx, v;
    min = INFINITY;

    for(v=0; v<nodes; v++) {
        if(!visited[v] && dist[v]<=min) {
            min = dist[v];
            minIdx = v;
        }
    }

    return minIdx;
}


void showPath(int *finalPath, int srcIdx, int destIdx, struct node pos[], char places[][50]) {

    int count = 0;

    for(int i = 0; finalPath[i] != -1; i++) {
        if(finalPath[i] != -1) count++;
    }

    printf("Shortest path from %s to %s: ", places[srcIdx], places[destIdx]);
    for (int i = 0; finalPath[i] != -1; ++i) {
        printf("%s ", places[finalPath[i]]);
        if(i < count-1) printf("-->");
    }
    printf("\n");

    setfillstyle(SOLID_FILL,GREEN);
    setcolor(GREEN);
    circle(pos[srcIdx].coord1, pos[srcIdx].coord2, 10);
    floodfill(pos[srcIdx].coord1, pos[srcIdx].coord2, GREEN);

    setfillstyle(SOLID_FILL,RED);
    setcolor(RED);
    circle(pos[destIdx].coord1, pos[destIdx].coord2, 10);
    floodfill(pos[destIdx].coord1, pos[destIdx].coord2, RED);

    //setcolor(GREEN);
    //circle(pos[destIdx].coord1, pos[destIdx].coord2, 10);

    setcolor(YELLOW);
    for(int i = 0; finalPath[i+1] != -1; ++i) {
        line(pos[finalPath[i]].coord1, pos[finalPath[i]].coord2, pos[finalPath[i + 1]].coord1, pos[finalPath[i + 1]].coord2);

    }
}




void dijkstra(int rel_matrix[][100], int src,int dest,int nodes,struct node pos[], char places[][50]) {


    int i,v;
    for(i=0; i<nodes; i++) {
        dist[i] = INFINITY;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for(i=0; i<nodes-1; i++) {

        int u = minDistance(dist,visited,nodes);
        visited[u] = 1;

        for(v=0; v<nodes; v++) {
            if(!visited[v] && rel_matrix[u][v] && dist[u]+rel_matrix[u][v]<dist[v]) {
                dist[v] = dist[u] + rel_matrix[u][v];
                parent[v] = u;
            }
        }
    }

    int* shortestPath = (int*)malloc(nodes * sizeof(int));
    int pathIndex = 0;
    int currentVertex = dest;

    while (currentVertex != -1) {
        shortestPath[pathIndex++] = currentVertex;
        currentVertex = parent[currentVertex];
    }

    // Reverse the path array
    int* finalPath = (int*)malloc(pathIndex * sizeof(int));
    finalPath[pathIndex] = -1;
    for (int i = pathIndex - 1, j = 0; i >= 0; --i, ++j) {
        finalPath[j] = shortestPath[i];
    }

    free(shortestPath);

    printf("\n");
    printf("Shortest distance from %s to %s: %d\n",places[src],places[dest],dist[dest]);



    showPath(finalPath, src, dest, pos, places);
    //return finalPath;
}


void userInputDijkstra(struct node pos[], char places[][50], int rel_matrix[][100]) {

    int numNodes = 14, i, j, index, srcIdx, destIdx;
    char src[50], dest[50];
    cout <<"Enter the source: ";
    gets(src);
    cout <<"Enter the destination: ";
    gets(dest);



    for(i=0; i<numNodes; i++) {
        int flag = 0;
        for(j=0; src[j] != '\0'; j++) {

            if(src[j] != places[i][j]) {
                flag = 1;
                break;
            }
        }

        index = i;
        if(flag == 0) {
            srcIdx = index;
            break;
        }
    }


    for(i=0; i<numNodes; i++) {
        int flag = 0;
        for(j=0; dest[j] != '\0'; j++) {

            if(dest[j] != places[i][j]) {
                flag = 1;
                break;
            }
        }

        index = i;
        if(flag == 0) {
            destIdx = index;
            break;
        }
    }


    build_rel_matrix();
    dijkstra(rel_matrix, srcIdx, destIdx, numNodes, pos, places);

}






