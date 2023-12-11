
#include <iostream>
#include <graphics.h>
#include<time.h>
#include<dos.h>
#include<conio.h>
#include<chrono>
#include<thread>
#define ROWS 40
#define COLS 40


int maze[ROWS][COLS]=
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};
int maze1[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,1,1,1,0,1,0,1},
    {1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1},
};

int maze2[ROWS][COLS]=
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},
    {1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1},
    {1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1},
    {1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1},
    {1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1},
    {1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,1},
    {1,0,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0,1},
    {1,0,1,1,0,0,0,1,0,1,0,1,1,1,1,1,0,1},
    {1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};


int maze3[ROWS][COLS] = {
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

void mainMaze(int dem[ROWS][COLS]){
    for(int i=0;i<12;i++){
        for(int j=0;j<18;j++){
            maze[i][j]=dem[i][j];
        }
    }

}
int win= 0;
int path[12][18];
char a[60],f[60];
bool stopTimer1 = false;
bool stopTimer2=false;

void visualizeMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <COLS; j++) {
            int x = j * 35;
            int y = i * 35;

            if (maze[i][j] == 1) {
                rectangle(x, y, x + 35, y + 35);
            }
            /*else if (maze[i][j] == 2) {
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

                setcolor(WHITE);*/
                else if (maze[i][j] == 2) {

                 setcolor(YELLOW);
                 rectangle(x+2, y+2, x + 33, y + 33);
                setcolor(WHITE);
            }
            }
        }
    }








void timer(){
   int score=0;
    for(int t=60;t>=0;t--){
            score++;
        if(stopTimer1){
        cleardevice();
        outtextxy(300, 430, "YOU WINNNNN!!!");
        delay(1000);
        cleardevice();
        score=60-score;
        sprintf(f,"your score is-\r%d",score);
        outtextxy(200,230,f);
        delay(2000);
        break;}
        if(stopTimer2){
        cleardevice();
        outtextxy(300, 430, "WRONG MOVEEEE!!!");
        outtextxy(300, 250, "Your score is 0");
        delay(1000);
        break;}
        sprintf(a,"\r%d",t);

           outtextxy(100,430, a);
           delay(1000);
           if(t==0){
        cleardevice();
        outtextxy(100, 430, "Time's up!!!");
        outtextxy(300, 250, "Your score is 0");
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
    int i=0,x,j;
    for(j=0;j<18;j++){
       if( maze[i][j]==0){
        if(j==8){
            x=298;
            break;
        }
        else if(j==15){
            x=542;
            break;
        }
        else if(j==14){
            x=508;
            break;
        }
       }

    }
    //int x=298,j=8;
    //int x=542,j=15;
    //int x=508,j=14;
    int y=18,rad=12;



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
        cleardevice();
        //outtextxy(200, 250, "your score is 0");
        break;

    }
    else if(GetAsyncKeyState(VK_RIGHT) && maze[i][j+1]==1){
         outtextxy(200, 450, "you failed...the shortest path to win was-");
        drawPathOnMaze();
        stopTimer2=true;
        cleardevice();
        //outtextxy(200, 250, "your score is 0");
        break;
    }
     else if(GetAsyncKeyState(VK_UP) && maze[i-1][j]==1){
        outtextxy(200, 450, "you failed...the shortest path to win was-");
        drawPathOnMaze();
        stopTimer2=true;
        cleardevice();
        //outtextxy(200, 250, "your score is 0");
        break;
    }
     else if(GetAsyncKeyState(VK_DOWN) && maze[i+1][j]==1){
        outtextxy(200,450, "you failed...the shortest path to win was-");
        drawPathOnMaze();
        stopTimer2=true;
        cleardevice();
        //outtextxy(200, 250, "your score is 0");
        break;
    }
     else if(GetAsyncKeyState(VK_DOWN) && maze[i+1][j]==2){
        stopTimer1=true;
        outtextxy(150,430, "CONGRATULATIONS!!!!YOU HAVE SOLVED THE MAZE!!!");
        cleardevice();
        //sco();
        break;


    }

    else if(GetAsyncKeyState(VK_ESCAPE)){
        break;
    }

delay(100);
//cleardevice();

    }

}


void drawMenu() {
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(200, 100, "Game Menu");
    rectangle(180, 150, 420, 200);
    rectangle(180, 220, 420, 270);
    rectangle(180, 290, 420, 340);

    outtextxy(200, 175, "1. Start Game");
    outtextxy(200, 245, "2. Instructions");
    outtextxy(200, 315, "3. Exit");
}

int getMenuChoice() {
    int x, y;
    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);

            if (x > 180 && x < 420) {
                if (y > 150 && y < 200) {
                    return 1; // Start Game
                } else if (y > 220 && y < 270) {
                    return 2; // Instructions
                } else if (y > 290 && y < 340) {
                    return 3; // Exit
                }
            }
        }
    }
}


void drawLevel() {
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(200, 100, "Select a level");
    rectangle(180, 150, 420, 200);
    rectangle(180, 220, 420, 270);
    rectangle(180, 290, 420, 340);

    outtextxy(250, 175, "1. Level 1");
    outtextxy(250, 245, "2. Level 2");
    outtextxy(250, 315, "3. Level 3");
}

int getLevelChoice() {
    int x, y;
    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);

            if (x > 180 && x < 420) {
                if (y > 150 && y < 200) {
                    return 1; // level 1
                } else if (y > 220 && y < 270) {
                    return 2; // level 2
                } else if (y > 290 && y < 340) {
                    return 3; // level 3
                }
            }
        }
    }
}

void startGame() {
    cleardevice();

    while (1) {
        cleardevice();
        drawLevel();
        int level = getLevelChoice();

        if(level==1){
            mainMaze(maze1);
            break;
        }
        else if(level==2){
            mainMaze(maze2);
            break;
        }
        else if(level==3){
            mainMaze(maze3);
            break;
        }

        }
cleardevice();
    // Add your game logic here
    outtextxy(200, 200, "Game Started!");
    delay(1000);



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
    //delay(1000);
}

void showInstructions() {
    cleardevice();
    // Display game instructions
    outtextxy(200, 200, "Game Instructions");
    delay(1000);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int choice;

    while (1) {
        cleardevice();
        drawMenu();
        choice = getMenuChoice();

        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                showInstructions();
                break;
            case 3:
                closegraph();
                exit(0);
        }
    }



    getch();
    closegraph();
    return 0;
}
