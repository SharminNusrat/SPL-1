#ifndef HEADER_INCLUDED
#define HEADER_INCLUDED
#include <bits/stdc++.h>
#include <graphics.h>
#define MAX_VERTICES 100

using namespace std;

struct node {
    int coord1;
    int coord2;
};

int minDistance(int dist[], int vis[], int nodes);
void dijkstra(int src, int dest, int nodes, struct node pos[], char places[][50]);
void build_rel_matrix();
void showPath(int *finalPath, int sourceIndex, int destinationIndex, struct node pos[], char places[][50]);
void userInputDijkstra(struct node pos[], char places[][50], int rel_matrix[][100]);
void displayGraph(int rel_matrix[][MAX_VERTICES], struct node pos[], int n);
void userInputDFS(struct node pos[], char places[][50], int rel_matrix[][100]);
void dfsFindAllPaths(struct node pos[], int srcIdx, int destIdx, int visited[], int path[], int pathIdx, char places[][50]);
void userInputPrims(struct node pos[], char places[][50], int rel_matrix[][100]);
int MOGA(char places[][50]);
void displayGraph1();

#endif
