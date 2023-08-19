#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;


void searchLocation (struct node pos[], int locIdx) {

    setfillstyle(SOLID_FILL, RED);
    setcolor(RED);
    circle(pos[locIdx].coord1, pos[locIdx].coord2, 10);
    floodfill(pos[locIdx].coord1, pos[locIdx].coord2, RED);
}


void userInputSearching (struct node pos[]) {

    int numNodes = 14, i, j, index, flag, locIdx;
    char loc[50];

    cout << "Enter location you want to search: ";
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

    searchLocation(pos, locIdx);
}
