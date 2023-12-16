
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");


    setcolor(MAGENTA);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);

    outtextxy(150, 180, "WELCOME TO");

    setcolor(GREEN);

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(80, 240, "A-MAZING MAZE WORLD");

    getch();
    closegraph();
    return 0;
}
