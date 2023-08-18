#ifndef DISPLAYMAP1_CPP
#define DISPLAYMAP1_CPP


#include <bits/stdc++.h>
#include <graphics.h>
#define MAX_VERTICES 100


struct node {
    int coord1;
    int coord2;
};

void displayGraph(int rel_matrix[][MAX_VERTICES], struct node pos[], int n) {

    int i;

    //build_rel_matrix();
    rel_matrix[0][3] = 1;
    rel_matrix[3][0] = 1;

    line(pos[0].coord1,pos[0].coord2,pos[3].coord1,pos[3].coord2);

    rel_matrix[3][2] = 1;
    rel_matrix[2][3] = 1;

    line(pos[3].coord1,pos[3].coord2,pos[2].coord1,pos[2].coord2);

    rel_matrix[0][1] = 1;
    rel_matrix[1][0] = 1;

    line(pos[0].coord1,pos[0].coord2,pos[1].coord1,pos[1].coord2);

    rel_matrix[2][7] = 1;
    rel_matrix[7][2] = 1;

    line(pos[2].coord1,pos[2].coord2,pos[7].coord1,pos[7].coord2);

    rel_matrix[7][6] = 1;
    rel_matrix[6][7] = 1;

    line(pos[7].coord1,pos[7].coord2,pos[6].coord1,pos[6].coord2);

    rel_matrix[6][8] = 1;
    rel_matrix[8][6] = 1;

    line(pos[6].coord1,pos[6].coord2,pos[8].coord1,pos[8].coord2);

    /*rel_matrix[2][6] = 1;
    rel_matrix[6][2] = 1;

    line(pos[2].coord1,pos[2].coord2,pos[6].coord1,pos[6].coord2);*/

    rel_matrix[1][5] = 1;
    rel_matrix[5][1] = 1;

    line(pos[1].coord1,pos[1].coord2,pos[5].coord1,pos[5].coord2);

    /*rel_matrix[2][1] = 1;
    rel_matrix[1][2] = 1;

    line(pos[2].coord1,pos[2].coord2,pos[1].coord1,pos[1].coord2);*/

    rel_matrix[6][10] = 1;
    rel_matrix[10][6] = 1;

    line(pos[6].coord1,pos[6].coord2,pos[10].coord1,pos[10].coord2);

    rel_matrix[10][11] = 1;
    rel_matrix[11][10] = 1;

    line(pos[10].coord1,pos[10].coord2,pos[11].coord1,pos[11].coord2);

    rel_matrix[11][4] = 1;
    rel_matrix[4][11] = 1;

    line(pos[11].coord1,pos[11].coord2,pos[4].coord1,pos[4].coord2);

    rel_matrix[1][10] = 1;
    rel_matrix[10][1] = 1;

    line(pos[1].coord1,pos[1].coord2,pos[10].coord1,pos[10].coord2);

    rel_matrix[8][10] = 1;
    rel_matrix[10][8] = 1;

    line(pos[8].coord1,pos[8].coord2,pos[10].coord1,pos[10].coord2);

    rel_matrix[10][12] = 1;
    rel_matrix[12][10] = 1;

    line(pos[10].coord1,pos[10].coord2,pos[12].coord1,pos[12].coord2);

    rel_matrix[5][10] = 1;
    rel_matrix[10][5] = 1;

    line(pos[5].coord1,pos[5].coord2,pos[10].coord1,pos[10].coord2);

    rel_matrix[13][6] = 1;
    rel_matrix[6][13] = 1;

    line(pos[13].coord1,pos[13].coord2,pos[6].coord1,pos[6].coord2);

    rel_matrix[10][4] = 1;
    rel_matrix[4][10] = 1;

    line(pos[10].coord1,pos[10].coord2,pos[4].coord1,pos[4].coord2);

    rel_matrix[9][10] = 1;
    rel_matrix[10][9] = 1;

    line(pos[9].coord1,pos[9].coord2,pos[10].coord1,pos[10].coord2);

    rel_matrix[9][12] = 1;
    rel_matrix[12][9] = 1;

    line(pos[9].coord1,pos[9].coord2,pos[12].coord1,pos[12].coord2);








    //setbkcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    for(i=0; i<n; i++) {
        setcolor(LIGHTGRAY);
        circle(pos[i].coord1, pos[i].coord2, 10);
        floodfill(pos[i].coord1, pos[i].coord2, LIGHTGRAY);
    }

    setcolor(WHITE);
    settextstyle(SMALL_FONT, HORIZ_DIR, 4);
    outtextxy(pos[0].coord1 - 12, pos[0].coord2 - 22, "TSC");
    outtextxy(pos[1].coord1 - 12, pos[1].coord2 - 22, "Bangla Academy");
    outtextxy(pos[2].coord1 - 70, pos[2].coord2 - 4, "VC's Residence");
    outtextxy(pos[3].coord1 - 30, pos[0].coord2 + 14, "Ruqayya Hall");
    outtextxy(pos[4].coord1, pos[4].coord2 - 22, "Sufia Kamal Hall");
    outtextxy(pos[7].coord1 - 24, pos[7].coord2 + 10, "Shaheed Minar");
    outtextxy(pos[6].coord1, pos[6].coord2 - 22, "IIT");
    outtextxy(pos[8].coord1 - 18, pos[8].coord2 + 16, "Swimming Pool");
    outtextxy(pos[10].coord1 - 12, pos[10].coord2 - 22, "Curzon Hall");
    outtextxy(pos[11].coord1 - 12, pos[11].coord2 - 22, "Doyel Chottor");
    outtextxy(pos[9].coord1 - 12, pos[9].coord2 + 18, "Gymnasium");
    outtextxy(pos[12].coord1 + 16, pos[12].coord2, "Shahidullah Hall");
    outtextxy(pos[13].coord1 - 8, pos[13].coord2 + 20, "Mukarram Vaban");
    outtextxy(pos[5].coord1 - 8, pos[5].coord2 - 20, "Library");


}


#endif
