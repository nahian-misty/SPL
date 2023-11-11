#include <iostream>
#include <graphics.h>
#include<time.h>
#include<dos.h>
#include<conio.h>
#include<chrono>
#include<thread>
#define ROWS 40
#define COLS 40

int maze[ROWS][COLS] = {
    {1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1},
    {0,0,0,0,0,1,1,1,0,1,1,0,0,0,0,0,0,0},
    {1,1,1,1,0,0,0,0,0,1,1,0,1,1,1,1,1,1},
    {1,1,1,1,1,0,1,1,1,0,0,0,0,0,1,1,1,1},
    {1,1,1,0,0,0,1,1,1,0,1,1,1,0,1,1,0,1},
    {1,1,1,0,1,1,1,1,1,0,1,1,1,0,0,0,0,1},
    {1,1,1,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1},
    {1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1},
    {1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,1},
    {1,0,1,1,1,0,1,0,1,1,0,1,1,1,1,1,0,1},
    {1,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1},

};

int win= 0;
int path[12][18];
char a[60];
bool stopTimer1 = false;
bool stopTimer2=false;

void visualizeMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <COLS; j++) {
            int x = j * 35;
            int y = i * 35;

            if (maze[i][j] == 1) {
                rectangle(x, y, x + 35, y + 35);
            } else if (maze[i][j] == 2) {
              for(int k=0;k<3;k++){
                         setcolor(YELLOW);

                        // rectangle(x+k+5, y+k+5, x + 30-k, y + 30-k);

                        line(290+k,385+k,290+k,420+k);
                        //setcolor(RED);
                        setfillstyle(SOLID_FILL, RED);
                        line(290+k,385+k,310+k,400+k);
                        line(310+k,400+k,290+k,400+k);
                       // floodfill(300,295,10);

                }

                setcolor(WHITE);
            }
        }
    }





}

void timer(){
    for(int t=60;t>=0;t--){
        if(stopTimer1){
        cleardevice();
        outtextxy(300, 430, "YOU WINNNNN!!!");
        delay(10000);
        break;}
        if(stopTimer2){
        cleardevice();
        outtextxy(300, 430, "WRONG MOVEEEE!!!");
        delay(10000);
        break;}
        sprintf(a,"\r%d",t);
           outtextxy(100,430, a);
           delay(1000);
           if(t==0){
        cleardevice();
        outtextxy(100, 430, "Time's up!!!");
        break;}

           //cleardevice();

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
    for(int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (path[i][j] == 1) {
                setfillstyle(SOLID_FILL, MAGENTA);
                delay(100);
                bar(j * 35 + 5, i * 35 + 5, (j + 1) * 35 - 5, (i + 1) * 35 - 5);
            }

        }
    }
}

void manualPLAY(){
    int i=0,j=8;
    int x=298,y=18,rad=12;



    while(1){
        circle(x,y,rad);

    //cleardevice();

    if(GetAsyncKeyState(VK_RIGHT) && maze[i][j+1]==0){
        x=x+35;
        j=j+1;
    }
    else if(GetAsyncKeyState(VK_LEFT) && maze[i][j-1]==0){
        x=x-35;
        j=j-1;
    }
    else if(GetAsyncKeyState(VK_UP) && maze[i-1][j]==0){
        y=y-35;
        i=i-1;
    }
    else if(GetAsyncKeyState(VK_DOWN) && maze[i+1][j]==0){
        y=y+35;
        i=i+1;
    }
     else if(GetAsyncKeyState(VK_LEFT) && maze[i][j-1]==1){
        outtextxy(200, 450, "you failed...the shortest path to win was-");
        drawPathOnMaze();
        stopTimer2=true;
    }
    else if(GetAsyncKeyState(VK_RIGHT) && maze[i][j+1]==1){
         outtextxy(200, 450, "you failed...the shortest path to win was-");
        drawPathOnMaze();
        stopTimer2=true;
    }
     else if(GetAsyncKeyState(VK_UP) && maze[i-1][j]==1){
        outtextxy(200, 450, "you failed...the shortest path to win was-");
        drawPathOnMaze();
        stopTimer2=true;
    }
     else if(GetAsyncKeyState(VK_DOWN) && maze[i+1][j]==1){
        outtextxy(200,450, "you failed...the shortest path to win was-");
        drawPathOnMaze();
        stopTimer2=true;
    }
     else if(GetAsyncKeyState(VK_DOWN) && maze[i+1][j]==2){
        stopTimer1=true;
        outtextxy(150,430, "CONGRATULATIONS!!!!YOU HAVE SOLVED THE MAZE!!!");
        break;


    }

    else if(GetAsyncKeyState(VK_ESCAPE)){
        break;
    }

delay(100);
//cleardevice();

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
    //timer();

    printPaths(startRow, startCol);
     std::thread timerThread(timer);
    std::thread manualPlayThread(manualPLAY);

    // Wait for both threads to finish
    timerThread.join();
    manualPlayThread.join();

    //manualPLAY();


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

    //if (win) {
       // drawPathOnMaze();
   // }
  // visualizeMaze();


    getch();
    closegraph();

    return 0;
}
