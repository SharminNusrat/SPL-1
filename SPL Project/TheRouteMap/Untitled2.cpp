#include "header.h"
#define MAX_VERTICES 100

using namespace std;

/*struct node {
    int coord1;
    int coord2;
};*/

int rel_matrix[MAX_VERTICES][MAX_VERTICES] = {0};


void build_rel_matrix() {

    rel_matrix[0][3] = 160;
    rel_matrix[3][0] = 160;

    rel_matrix[2][3] = 1400;
    rel_matrix[3][2] = 1400;

    rel_matrix[0][1] = 390;
    rel_matrix[1][0] = 390;

    rel_matrix[2][7] = 1300;
    rel_matrix[7][2] = 1300;

    rel_matrix[7][6] = 1300;
    rel_matrix[6][7] = 1300;

    rel_matrix[6][8] = 750;
    rel_matrix[8][6] = 750;

    /*rel_matrix[2][6] = 7;
    rel_matrix[6][2] = 7;*/

    rel_matrix[1][5] = 520;
    rel_matrix[5][1] = 520;

    /*rel_matrix[2][1] = 2;
    rel_matrix[1][2] = 2;*/

    rel_matrix[6][10] = 1500;
    rel_matrix[10][6] = 1500;

    rel_matrix[10][11] = 270;
    rel_matrix[11][10] = 270;

    rel_matrix[11][4] = 600;
    rel_matrix[4][11] = 600;

    rel_matrix[1][10] = 650;
    rel_matrix[10][1] = 650;

    rel_matrix[8][10] = 500;
    rel_matrix[10][8] = 500;

    rel_matrix[12][10] = 450;
    rel_matrix[10][12] = 450;

    rel_matrix[5][10] = 670;
    rel_matrix[10][5] = 670;

    rel_matrix[13][6] = 350;
    rel_matrix[6][13] = 350;

    rel_matrix[4][10] = 900;
    rel_matrix[10][4] = 900;

    rel_matrix[9][10] = 1100;
    rel_matrix[10][9] = 1100;

    rel_matrix[12][9] = 1200;
    rel_matrix[9][12] = 1200;

}




int main (void) {

    int numVertices = 14, choice = 1;


    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    struct node pos[] = {
        {100,100},{200,100},{100,180},{50,140},{500,200},{300,50},{150,250},
        {70,300},{250,350},{350,365},{360,220},{410,130},{450,270},{130,370}
        };

    char places[][50] = {"TSC","Bangla Academy","VC Chottor","Ruqayya Hall","Sufia Kamal Hall",
                            "Library","IIT","Shaheed Minar","Swimming Pool","Gymnasium",
                            "Curzon Hall","Doyel Chottor","Shahidullah Hall","Mukarram Vaban"};







    //setcolor(WHITE);
    //setfillstyle(SOLID_FILL, GREEN);

    printf("----------------Menu----------------\n");
        printf("1.Find Shortest Path\n");
        printf("2.Find All Paths\n");
        printf("3.Find Optimal Cost\n");
        printf("4.Find Optimal Path\n");
        printf("5.Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);
        getchar();

        displayGraph(rel_matrix, pos, numVertices);


        switch(choice) {
            case 1:
                userInputDijkstra(pos, places, rel_matrix);
                break;
            case 2:
                userInputDFS(pos, places, rel_matrix);
                break;
            case 3:
                userInputPrims(pos, places, rel_matrix);
                break;
            case 4:
                MOGA(places);
                break;
            case 5:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }





    //delay(5000);

    getch();
    closegraph();

    return 0;
}

