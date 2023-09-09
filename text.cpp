
// C Implementation for drawing circle
#include <graphics.h>


int main()
{

	int gd = DETECT, gm;

	initgraph(&gd, &gm, "");


	//circle(250, 200, 50);
	settextstyle(8,0,4);
    setcolor(YELLOW);
    outtextxy(200,150,"Welcome to");
    	settextstyle(3,0,5);
    outtextxy(80,250,"A-mazing Maze World");

	getch();


	closegraph();

	return 0;
}
