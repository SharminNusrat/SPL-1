#include <bits/stdc++.h>
#include <graphics.h>
#define MAX_VERTICES 100

using namespace std;

int path[MAX_VERTICES];
//int rel_matrix[MAX_VERTICES][MAX_VERTICES];
//int visited[MAX_VERTICES] = {0};


/*void drawEdge (struct node pos[], int fromNode, int toNode) {
    setcolor(YELLOW);
    line(pos[fromNode].coord1, pos[fromNode].coord2, pos[toNode].coord1, pos[toNode].coord2);
}*/


void drawNode (struct node pos[], int currentNode, int srcIdx, int destIdx) {
    if(currentNode == srcIdx) {
        setfillstyle(SOLID_FILL, RED);
    }
    else if(currentNode == destIdx) {
        setfillstyle(SOLID_FILL, GREEN);
    }
    else {
        setfillstyle(SOLID_FILL, LIGHTGRAY);
    }

    setcolor(BLACK);
    circle(pos[currentNode].coord1, pos[currentNode].coord2, 10);
    floodfill(pos[currentNode].coord1, pos[currentNode].coord2, BLACK);
}



void dfsFindAllPaths(struct node pos[], int srcIdx, int destIdx, int visited[], int path[], int pathIdx) {

    int numNodes = 14;
    int i, neighbor;
    visited[srcIdx] = 1;
    path[pathIdx++] = srcIdx;
    int srcNode = srcIdx;
    int destNode = destIdx;

    /*setfillstyle(SOLID_FILL,RED);
    setcolor(RED);
    circle(pos[srcNode].coord1,pos[srcNode].coord2,10);
    floodfill(pos[srcNode].coord1,pos[srcNode].coord2,RED);*/



    if(srcIdx == destIdx) {
        for(i=0; i<pathIdx; i++) {
            printf("%s ",places[path[i]]);
            if(i<pathIdx-1) {
                printf("-->");
                setcolor(YELLOW);
                line(pos[path[i]].coord1,pos[path[i]].coord2,pos[path[i+1]].coord1,pos[path[i+1]].coord2);
                delay(2000);
                setcolor(WHITE);
                line(pos[path[i]].coord1,pos[path[i]].coord2,pos[path[i+1]].coord1,pos[path[i+1]].coord2);
            }

        }


        printf("\n");
    }

    else {
        for(neighbor = 0; neighbor<numNodes; neighbor++) {
            if(rel_matrix[srcIdx][neighbor] && !visited[neighbor]) {
                dfsFindAllPaths(pos, neighbor, destIdx, visited, path, pathIdx);
            }
        }
    }

    visited[srcIdx] = 0;


    /*if(srcIdx == destIdx) {

        for(i=0; i<pathIdx-1; i++) {
            drawEdge(pos,path[i],path[i+1]);
        }

        for(i=0; i<pathIdx; i++) {
            drawNode(pos, path[i], srcIdx, destIdx);
        }
    }



     if(srcIdx == destIdx) {

        setfillstyle(SOLID_FILL, GREEN);
        setcolor(GREEN);
        circle(pos[destIdx].coord1, pos[destIdx].coord2, 10);
        floodfill(pos[destIdx].coord1, pos[destIdx].coord2, GREEN);


    }*/
}



void userInputDFS(struct node pos[]) {

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
    dfsFindAllPaths(pos, srcIdx, destIdx, visited, path, 0);
}
