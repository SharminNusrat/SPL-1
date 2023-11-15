#include "header.h"

#define INFINITY 999999
#define MAX_VERTICES 100

using namespace std;
int parentPrims[MAX_VERTICES];
int primsEdgeCount = 0;


void build_cost_matrix(int rel_matrix[][100]) {

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

    rel_matrix[8][10] = 1;
    rel_matrix[10][8] = 1;

    rel_matrix[10][12] = 15;
    rel_matrix[12][10] = 15;

    rel_matrix[5][10] = 20;
    rel_matrix[10][5] = 20;

    rel_matrix[13][6] = 10;
    rel_matrix[6][13] = 10;

    rel_matrix[10][4] = 15;
    rel_matrix[4][10] = 15;

    rel_matrix[9][10] = 0;
    rel_matrix[10][9] = 0;

    rel_matrix[9][12] = 15;
    rel_matrix[12][9] = 15;
}


int minKey(int key[], bool mstSet[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < 14; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}


void printMST3(int parent[], int graph[][MAX_VERTICES], char places[][50])
{
    cout << "Source \t\t Destination\n";
    for (int i = 1; i < primsEdgeCount - 1; i++)
    {
        if(strcmp(places[parent[i]], "")!=0 && strcmp(places[i], "")!=0) {
            cout <<  places[parent[i]] << " - " << places[i] << " \t\t"
             << graph[i][parent[i]] << " \n";
        }
    }
}

void primMST3(int graph[MAX_VERTICES][MAX_VERTICES], int srcIdx, char places[][50])
{


    int key[MAX_VERTICES];

    bool mstSet[MAX_VERTICES];

    for (int i = 0; i < MAX_VERTICES; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[srcIdx] = 0;

    parentPrims[srcIdx] = -1;

    for (int count = 0; count < 14 - 1; count++) {

        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < 14; v++)

            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v]) {
                    primsEdgeCount++;
                    parentPrims[v] = u, key[v] = graph[u][v];
                }
    }

   printMST3(parentPrims, graph, places);
}

string convertCharPtoString(char s[]) {
    int index = 0;
    string ret = "";
    while(s[index]!='\0') {
        ret += s[index];
        index++;
    }
    return ret;
}


void userInputPrims(struct node pos[], char places[][50], int rel_matrix[][100]) {

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

    build_cost_matrix(rel_matrix);

    primMST3(rel_matrix, locIdx, places);

    cout<< "please enter a destination that you want to visit: ";
    int destinationIdx;
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
            destinationIdx = index;
            break;
        }
    }

    int totalCost = 0;
    vector<string> path;

    while(parentPrims[destinationIdx] != -1) {
        string s = convertCharPtoString(places[destinationIdx]);
        path.push_back(s);
        totalCost += rel_matrix[destinationIdx][parentPrims[destinationIdx]];

        destinationIdx = parentPrims[destinationIdx];
    }
    path.push_back(places[locIdx]);
    reverse(path.begin(), path.end());
    for(int i=0; i< path.size(); i++) {
    cout<< path[i];
    if(i < path.size() - 1) {
        cout<< "->";
    }
    }
    cout<< "\n total cost: "<< totalCost << endl;



}
