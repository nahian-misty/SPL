#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    //int score = 100;  // Replace this with your actual score

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Set text color and size
    //setcolor(YELLOW);
    //settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    int x=100,y=100;
    // Convert the score to a string
    char scoreStr[5];
    int name[5]={1,2,3,4,0};
    for(int i=0;i<5;i++){
    sprintf(scoreStr, "Score: %d", name[i]);
    y=y+20;
    // Display the score on the screen
    outtextxy(x, y, scoreStr);}

    getch();
    closegraph();
    return 0;
}
