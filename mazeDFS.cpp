#include <iostream>
#include <graphics.h>
#define ROWS 40
#define COLS 40

int maze[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0},
    {1,1,1,1,0,0,0,0,0,1,1,0,1,1,1,1,1,1},
    {1,1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,1},
    {1,1,1,0,0,0,1,1,1,0,1,1,1,0,1,1,0,1},
    {1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,0,0,1},
    {1,1,1,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1},
    {1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1},
    {1,0,0,0,1,0,1,0,0,0,0,1,1,0,0,0,0,1},
    {1,0,1,1,1,0,1,0,1,1,0,1,1,1,1,1,0,1},
    {1,0,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1},

};

int win= 0;
int path[12][18];

void visualizeMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <COLS; j++) {
            int x = j * 35;
            int y = i * 35;

            if (maze[i][j] == 1) {
                rectangle(x, y, x + 35, y + 35);
            } else if (maze[i][j] == 2) {
                setcolor(YELLOW);
                 setfillstyle(SOLID_FILL, RED);
                //circle(x + 17, y + 17, 15);
                rectangle(x+5, y+5, x + 30, y + 30);
                //floodfill(312,415,15);
                setcolor(WHITE);
            }
        }
    }
}

void printPaths(int row, int col) {
    if (row < 0 || col < 0 || row >= 12 || col >= 18 || win || maze[row][col] == 1 || path[row][col] == 1) {
        return;
    }

    path[row][col] = 1;

    if (maze[row][col] == 2) {
        win = 1;
        return;
    }

    printPaths(row + 1, col);
    printPaths(row, col + 1);
    printPaths(row, col - 1);
    printPaths(row - 1, col);

    if (!win) {
        path[row][col] = 0;
    }
}

void drawPathOnMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (path[i][j] == 1) {
                setfillstyle(SOLID_FILL, MAGENTA);
                delay(100);
                bar(j * 35 + 5, i * 35 + 5, (j + 1) * 35 - 5, (i + 1) * 35 - 5);
            }

        }
    }
}

int main() {
    int startRow;
    int startCol;
     int k=0;
//searching for the start point
        for (int j = 0; j < 18; j++){
            if(maze[k][j]==0){
                     startRow =k;
                     startCol = j;}
        }
        //printf("%d\n%d\n",startingRow,startingCol);

    int graphicsDriver = DETECT, graphicsMode;
    initgraph(&graphicsDriver, &graphicsMode, "");

    cleardevice();

    visualizeMaze();

    printPaths(startRow, startCol);

    if (win) {
        printf("Path to reach the goal:\n") ;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 18; j++) {
                if (path[i][j] == 1) {printf("->(%d,%d) ",i,j) ;}
            }
            printf("\n") ;
        }
    } else {
         printf("Path to the goal not found...\n");
    }

    if (win) {
        drawPathOnMaze();
    }

    getch();
    closegraph();

    return 0;
}
