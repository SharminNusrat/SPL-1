#include <bits/stdc++.h>
#include <graphics.h>
#define MAX_VERTICES 100

using namespace std;

int path[MAX_VERTICES];
//int rel_matrix[MAX_VERTICES][MAX_VERTICES];
//int visited[MAX_VERTICES] = {0};



void dfsFindAllPaths(int srcIdx, int destIdx, int visited[], int path[], int pathIdx) {

    int numNodes = 14;
    int i, neighbor;
    visited[srcIdx] = 1;
    path[pathIdx++] = srcIdx;

    if(srcIdx == destIdx) {
        for(i=0; i<pathIdx; i++) {
            printf("%s ",places[path[i]]);
            if(i<pathIdx-1) printf("-->");
        }
        printf("\n");
    }

    else {
        for(neighbor = 0; neighbor<numNodes; neighbor++) {
            if(rel_matrix[srcIdx][neighbor] && !visited[neighbor]) {
                dfsFindAllPaths(neighbor, destIdx, visited, path, pathIdx);
            }
        }
    }

    visited[srcIdx] = 0;
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
    dfsFindAllPaths(srcIdx, destIdx, visited, path, 0);
}
