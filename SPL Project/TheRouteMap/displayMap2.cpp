#include "header.h"

#include <bits/stdc++.h>
#include <graphics.h>
#define MAX_VERTICES 100


void displayGraph1() {

    line(100,200,150,100);
    line(150,100,200,200);
    line(200,200,250,100);
    line(250,100,300,200);

    setfillstyle(SOLID_FILL, WHITE);

    setcolor(LIGHTGRAY);
    circle(100,200,10);
    floodfill(100,200,LIGHTGRAY);

    setcolor(LIGHTGRAY);
    circle(150,100,10);
    floodfill(150,100,LIGHTGRAY);

    setcolor(LIGHTGRAY);
    circle(200,200,10);
    floodfill(200,200,LIGHTGRAY);

    setcolor(LIGHTGRAY);
    circle(250,100,10);
    floodfill(250,100,LIGHTGRAY);

    setcolor(LIGHTGRAY);
    circle(300,200,10);
    floodfill(300,200,LIGHTGRAY);


    setcolor(WHITE);
    settextstyle(SMALL_FONT, HORIZ_DIR, 8);
    outtextxy(100 - 24, 200 , "3");
    outtextxy(150 , 100 - 28, "0");
    outtextxy(200 - 24, 200 , "2");
    outtextxy(250 , 100 - 28, "1");
    outtextxy(300 - 24, 200 , "4");

}
