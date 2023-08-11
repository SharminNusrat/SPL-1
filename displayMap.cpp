#include <bits/stdc++.h>
#include <graphics.h>
//#include "dijkstra1.cpp"
#define MAX_VERTICES 100


struct node {
    int coord1;
    int coord2;
};

void displayGraph(int arr[][MAX_VERTICES], struct node pos[], int n) {

    int i;
    //int gd = DETECT, gm;
    //initgraph(&gd, &gm, (char*)"");

    arr[0][3] = 1;
    arr[3][0] = 1;

    line(pos[0].coord1,pos[0].coord2,pos[3].coord1,pos[3].coord2);

    arr[3][2] = 1;
    arr[2][3] = 1;

    line(pos[3].coord1,pos[3].coord2,pos[2].coord1,pos[2].coord2);

    arr[0][1] = 1;
    arr[1][0] = 1;

    line(pos[0].coord1,pos[0].coord2,pos[1].coord1,pos[1].coord2);

    arr[2][7] = 1;
    arr[7][2] = 1;

    line(pos[2].coord1,pos[2].coord2,pos[7].coord1,pos[7].coord2);

    arr[7][6] = 1;
    arr[6][7] = 1;

    line(pos[7].coord1,pos[7].coord2,pos[6].coord1,pos[6].coord2);

    arr[6][8] = 1;
    arr[8][6] = 1;

    line(pos[6].coord1,pos[6].coord2,pos[8].coord1,pos[8].coord2);

    arr[2][6] = 1;
    arr[6][2] = 1;

    line(pos[2].coord1,pos[2].coord2,pos[6].coord1,pos[6].coord2);

    arr[1][5] = 1;
    arr[5][1] = 1;

    line(pos[1].coord1,pos[1].coord2,pos[5].coord1,pos[5].coord2);

    arr[2][1] = 1;
    arr[1][2] = 1;

    line(pos[2].coord1,pos[2].coord2,pos[1].coord1,pos[1].coord2);

    arr[6][10] = 1;
    arr[10][6] = 1;

    line(pos[6].coord1,pos[6].coord2,pos[10].coord1,pos[10].coord2);

    arr[10][11] = 1;
    arr[11][10] = 1;

    line(pos[10].coord1,pos[10].coord2,pos[11].coord1,pos[11].coord2);

    arr[11][4] = 1;
    arr[4][11] = 1;

    line(pos[11].coord1,pos[11].coord2,pos[4].coord1,pos[4].coord2);

    arr[1][10] = 1;
    arr[10][1] = 1;

    line(pos[1].coord1,pos[1].coord2,pos[10].coord1,pos[10].coord2);

    arr[8][10] = 1;
    arr[10][8] = 1;

    line(pos[8].coord1,pos[8].coord2,pos[10].coord1,pos[10].coord2);

    arr[10][12] = 1;
    arr[12][10] = 1;

    line(pos[10].coord1,pos[10].coord2,pos[12].coord1,pos[12].coord2);

    arr[5][10] = 1;
    arr[10][5] = 1;

    line(pos[5].coord1,pos[5].coord2,pos[10].coord1,pos[10].coord2);

    arr[13][6] = 1;
    arr[6][13] = 1;

    line(pos[13].coord1,pos[13].coord2,pos[6].coord1,pos[6].coord2);

    arr[10][4] = 1;
    arr[4][10] = 1;

    line(pos[10].coord1,pos[10].coord2,pos[4].coord1,pos[4].coord2);

    arr[9][10] = 1;
    arr[10][9] = 1;

    line(pos[9].coord1,pos[9].coord2,pos[10].coord1,pos[10].coord2);

    arr[9][12] = 1;
    arr[12][9] = 1;

    line(pos[9].coord1,pos[9].coord2,pos[12].coord1,pos[12].coord2);






    //setbkcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    for(i=0; i<n; i++) {
        setcolor(LIGHTGRAY);
        circle(pos[i].coord1, pos[i].coord2, 10);
        floodfill(pos[i].coord1, pos[i].coord2, LIGHTGRAY);
    }

    //getch();
    //closegraph();


}

int main (void) {

    int numVertices = 14;
    int rel_matrix[MAX_VERTICES][MAX_VERTICES] = {0};

    struct node pos[14] = {
        {100,100},{200,100},{100,180},{50,140},{500,200},{300,50},{150,250},
        {70,300},{250,350},{350,365},{360,220},{410,130},{450,270},{130,370}
        };

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    //setcolor(WHITE);
    //setfillstyle(SOLID_FILL, GREEN);
    displayGraph(rel_matrix, pos, numVertices);
    //dijkstra(0,10,14);

    getch();
    closegraph();

    return 0;
}
