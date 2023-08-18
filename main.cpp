#include "displayMap1.cpp"
#include "dijkstra1.cpp"
#include "dfsFindAllPath.cpp"
#include <bits/stdc++.h>
#include <graphics.h>
#define MAX_VERTICES 100

using namespace std;

/*struct node {
    int coord1;
    int coord2;
};*/



int main (void) {

    int numVertices = 14;


    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    struct node pos[] = {
        {100,100},{200,100},{100,180},{50,140},{500,200},{300,50},{150,250},
        {70,300},{250,350},{350,365},{360,220},{410,130},{450,270},{130,370}
        };



    int rel_matrix[MAX_VERTICES][MAX_VERTICES] = {0};


    //setcolor(WHITE);
    //setfillstyle(SOLID_FILL, GREEN);
    displayGraph(rel_matrix, pos, numVertices);
    //userInputDijkstra(pos);
    userInputDFS(pos);

    getch();
    closegraph();

    return 0;
}
