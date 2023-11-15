#include "header.h"
#define MAX_VERTICES 100

using namespace std;

int path[MAX_VERTICES];
//int rel_matrix[MAX_VERTICES][MAX_VERTICES];
//int visited[MAX_VERTICES] = {0};






void dfsFindAllPaths(int rel_matrix[][100], struct node pos[], int srcIdx, int destIdx, int visited[], int path[], int pathIdx, char places[][50]) {

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
                delay(1000);
                setcolor(WHITE);
                line(pos[path[i]].coord1,pos[path[i]].coord2,pos[path[i+1]].coord1,pos[path[i+1]].coord2);
            }

        }


        printf("\n");
    }

    else {
        for(neighbor = 0; neighbor<numNodes; neighbor++) {
            if(rel_matrix[srcIdx][neighbor] && !visited[neighbor]) {
                dfsFindAllPaths(rel_matrix, pos, neighbor, destIdx, visited, path, pathIdx, places);
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



void userInputDFS(struct node pos[], char places[][50], int rel_matrix[][100]) {

    int numNodes = 14, i, j, index, srcIdx, destIdx;
    int visited[MAX_VERTICES] = {0};
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
    dfsFindAllPaths(rel_matrix, pos, srcIdx, destIdx, visited, path, 0, places);
}
