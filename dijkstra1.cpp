#ifndef DIJKSTRA1_CPP
#define DIJKSTRA1_CPP


#include <bits/stdc++.h>
#include <graphics.h>
#define INFINITY 999999
#define MAX_VERTICES 100
using namespace std;


/*struct node {
    int coord1;
    int coord2;
};*/


int rel_matrix[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];
int visited[MAX_VERTICES];
int parent[MAX_VERTICES];
//struct node pos[MAX_VERTICES];


char places[][50] = {"TSC","Bangla Academy","VC's Residence","Ruqayya Hall","Sufia Kamal Hall",
                            "Library","IIT","Shaheed Minar","Swimming Pool","Gymnasium",
                            "Curzon Hall","Doyel Chottor","Shahidullah Hall","Mukarram Vaban"};



void build_rel_matrix() {

    rel_matrix[0][3] = 5;
    rel_matrix[3][0] = 5;

    rel_matrix[2][3] = 6;
    rel_matrix[3][2] = 6;

    rel_matrix[0][1] = 12;
    rel_matrix[1][0] = 12;

    rel_matrix[2][7] = 4;
    rel_matrix[7][2] = 4;

    rel_matrix[7][6] = 15;
    rel_matrix[6][7] = 15;

    rel_matrix[6][8] = 10;
    rel_matrix[8][6] = 10;

    /*rel_matrix[2][6] = 7;
    rel_matrix[6][2] = 7;*/

    rel_matrix[1][5] = 11;
    rel_matrix[5][1] = 11;

    /*rel_matrix[2][1] = 2;
    rel_matrix[1][2] = 2;*/

    rel_matrix[6][10] = 14;
    rel_matrix[10][6] = 14;

    rel_matrix[10][11] = 17;
    rel_matrix[11][10] = 17;

    rel_matrix[11][4] = 3;
    rel_matrix[4][11] = 3;

    rel_matrix[1][10] = 1;
    rel_matrix[10][1] = 1;

    rel_matrix[8][10] = 8;
    rel_matrix[10][8] = 8;

    rel_matrix[12][10] = 20;
    rel_matrix[10][12] = 20;

    rel_matrix[5][10] = 19;
    rel_matrix[10][5] = 19;

    rel_matrix[13][6] = 16;
    rel_matrix[6][13] = 16;

    rel_matrix[4][10] = 23;
    rel_matrix[10][4] = 23;

    rel_matrix[9][10] = 25;
    rel_matrix[10][9] = 25;

    rel_matrix[12][9] = 29;
    rel_matrix[9][12] = 29;

}



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


void showPath(int *finalPath, int srcIdx, int destIdx, struct node pos[]) {

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




void dijkstra(int src,int dest,int nodes,struct node pos[]) {

    //build_rel_matrix();


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



    showPath(finalPath, src, dest, pos);
    //return finalPath;
}


void userInputDijkstra(struct node pos[]) {

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
    dijkstra(srcIdx, destIdx, numNodes, pos);

}




#endif


