#include "displayMap1.cpp"
#include "dijkstra1.cpp"
#include "dfsFindAllPath.cpp"
#include "locationSearch.cpp"
//#include "primsOptimalCost.cpp"
#include "primsOptimalCost2.cpp"
#include <bits/stdc++.h>
#include <graphics.h>
#define MAX_VERTICES 100

using namespace std;

/*struct node {
    int coord1;
    int coord2;
};*/



int main (void) {

    int numVertices = 14, choice = 1;


    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    struct node pos[] = {
        {100,100},{200,100},{100,180},{50,140},{500,200},{300,50},{150,250},
        {70,300},{250,350},{350,365},{360,220},{410,130},{450,270},{130,370}
        };


    int rel_matrix[MAX_VERTICES][MAX_VERTICES] = {0};



    displayGraph(rel_matrix, pos, numVertices);
    //setcolor(WHITE);
    //setfillstyle(SOLID_FILL, GREEN);


    //while(1) {

        printf("----------------Menu----------------\n");
        printf("1.Find Shortest Path\n");
        printf("2.Search Location\n");
        printf("3.Find All Paths\n");
        printf("4.Find Optimal Cost\n");
        printf("5.Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);
        getchar();


        switch(choice) {
            case 1:
                userInputDijkstra(pos);
                break;
            case 2:
                userInputSearching(pos);
                break;
            case 3:
                userInputDFS(pos);
                break;
            case 4:
                userInputPrims(pos);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }



    //}





    //delay(5000);

    getch();
    closegraph();

    return 0;
}
