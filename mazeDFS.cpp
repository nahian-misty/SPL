#include <iostream>
#include <graphics.h>
#define MAZE_ROWS 40
#define MAZE_COLS 40

int mazeLayout[MAZE_ROWS][MAZE_COLS] = {
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

int goalFound = 0;
int pathTaken[12][18];

void renderMaze() {
    for (int i = 0; i < MAZE_ROWS; i++) {
        for (int j = 0; j < MAZE_COLS; j++) {
            int x = j * 35;
            int y = i * 35;

            if (mazeLayout[i][j] == 1) {
                rectangle(x, y, x + 35, y + 35);
            } else if (mazeLayout[i][j] == 2) {
                setcolor(YELLOW);
                //circle(xCoord + 17, yCoord + 17, 15);
                rectangle(x+5, y+5, x + 30, y + 30);
                setcolor(WHITE);
            }
        }
    }
}

void explorePaths(int row, int col) {
    if (row < 0 || col < 0 || row >= 12 || col >= 18 || goalFound || mazeLayout[row][col] == 1 || pathTaken[row][col] == 1) {
        return;
    }

    pathTaken[row][col] = 1;

    if (mazeLayout[row][col] == 2) {
        goalFound = 1;
        return;
    }

    explorePaths(row + 1, col);
    explorePaths(row, col + 1);
    explorePaths(row, col - 1);
    explorePaths(row - 1, col);

    if (!goalFound) {
        pathTaken[row][col] = 0;
    }
}

void drawPathOnMaze() {
    for (int i = 0; i < MAZE_ROWS; i++) {
        for (int j = 0; j < MAZE_COLS; j++) {
            if (pathTaken[i][j] == 1) {
                setfillstyle(SOLID_FILL, YELLOW);
                delay(100);
                bar(j * 35 + 5, i * 35 + 5, (j + 1) * 35 - 5, (i + 1) * 35 - 5);
            }

        }
    }
}

int main() {
    int startingRow;
    int startingCol;
     int k=0;
//searching for the start point
        for (int j = 0; j < 18; j++){
            if(mazeLayout[k][j]==0){
                     startingRow =k;
                    startingCol = j;}
        }
        //printf("%d\n%d\n",startingRow,startingCol);

    int graphicsDriver = DETECT, graphicsMode;
    initgraph(&graphicsDriver, &graphicsMode, "");

    cleardevice();

    renderMaze();

    explorePaths(startingRow, startingCol);

    if (goalFound) {
        printf("Path to reach the goal:\n") ;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 18; j++) {
                if (pathTaken[i][j] == 1) {printf("->(%d,%d) ",i,j) ;}
            }
            printf("\n") ;
        }
    } else {
         printf("Path to the goal not found...\n");
    }

    if (goalFound) {
        drawPathOnMaze();
    }

    getch();
    closegraph();

    return 0;
}
