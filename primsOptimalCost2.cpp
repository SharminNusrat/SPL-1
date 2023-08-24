#include <bits/stdc++.h>
#include <graphics.h>
#define INFINITY 999999
#define MAX_VERTICES 100

using namespace std;


void build_cost_matrix() {

    rel_matrix[0][3] = 5;
    rel_matrix[3][0] = 5;

    rel_matrix[3][2] = 15;
    rel_matrix[2][3] = 15;

    rel_matrix[0][1] = 15;
    rel_matrix[1][0] = 15;

    rel_matrix[2][7] = 20;
    rel_matrix[7][2] = 20;

    rel_matrix[7][6] = 15;
    rel_matrix[6][7] = 15;

    rel_matrix[6][8] = 0;
    rel_matrix[8][6] = 0;

    rel_matrix[1][5] = 10;
    rel_matrix[5][1] = 10;

    rel_matrix[6][10] = 15;
    rel_matrix[10][6] = 15;

    rel_matrix[10][11] = 0;
    rel_matrix[11][10] = 0;

    rel_matrix[11][4] = 20;
    rel_matrix[4][11] = 20;

    rel_matrix[1][10] = 15;
    rel_matrix[10][1] = 15;

    rel_matrix[8][10] = 0;
    rel_matrix[10][8] = 0;

    rel_matrix[10][12] = 15;
    rel_matrix[12][10] = 15;

    rel_matrix[5][10] = 25;
    rel_matrix[10][5] = 25;

    rel_matrix[13][6] = 0;
    rel_matrix[6][13] = 0;

    rel_matrix[10][4] = 15;
    rel_matrix[4][10] = 15;

    rel_matrix[9][10] = 0;
    rel_matrix[10][9] = 0;

    rel_matrix[9][12] = 15;
    rel_matrix[12][9] = 15;
}


void primsMST(int rel_matrix[MAX_VERTICES][MAX_VERTICES], int numNodes, int locIdx, struct node pos[]) {

    int numEdges;
    int selected[numNodes];

    for(int i=0; i<numNodes; i++) {
        selected[i] = 0;
    }

    numEdges = 0;
    selected[locIdx] = 1;

    int x;
    int y;
    int totalOptimalCost = 0;


    while(numEdges < numNodes - 1) {

        int min = INFINITY;
        x = 0;
        y = 0;

        for(int i=0; i<numNodes; i++) {
            if(selected[i]) {
                for(int j=0; j<numNodes; j++) {
                    if(!selected[j] && rel_matrix[i][j]) {
                        if(rel_matrix[i][j] < min) {
                            min = rel_matrix[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }


        totalOptimalCost += rel_matrix[x][y];
        if(x != 0 || y != 0)
        printf("%s to %s - %d\n",places[x],places[y],rel_matrix[x][y]);
        selected[y] = 1;
        numEdges++;
    }

    printf("\nTotal optimal cost: %d\n",totalOptimalCost);

}


void userInputPrims(struct node pos[]) {

    int locIdx, numNodes = 14, i, j, flag, index;
    char loc[50];

    cout << "Enter starting location: ";
    gets(loc);

    for(i=0; i<numNodes; i++) {

        flag = 0;
        for(j=0; loc[j] != '\0'; j++) {

            if(loc[j] != places[i][j]) {
                flag = 1;
                break;
            }
        }

        index = i;
        if(flag == 0) {
            locIdx = index;
            break;
        }
    }

    build_cost_matrix();
    primsMST(rel_matrix,numNodes,locIdx,pos);
}
