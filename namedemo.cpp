
#include <iostream>
#include <graphics.h>
#include<time.h>
#include<dos.h>
#include<conio.h>
#include<chrono>
#include<thread>
#define ROWS 40
#define COLS 40

char name[50] = {0};
int value = 0;
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

int maze3[ROWS][COLS]=
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


int maze2[ROWS][COLS] = {
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


bool askToGoBack() {
    cleardevice();
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(150, 200, "Do you want to go back?");
    rectangle(180, 250, 420, 300);
    outtextxy(250, 275, "1. Yes");
    outtextxy(250, 325, "2. No");

    int choice;

    while (1) {
        if (ismouseclick(WM_LBUTTONDOWN)) {
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, x, y);
            clearmouseclick(WM_LBUTTONDOWN);

            if (x > 180 && x < 420) {
                if (y > 250 && y < 300) {
                    choice = 1; // Yes
                    break;
                } else if (y > 320 && y < 370) {
                    choice = 2; // No
                    break;
                }
            }
        }
    }

    return choice == 1;
}

void showScore(int score) {
    cleardevice();
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    rectangle(180, 200, 420, 250);
    outtextxy(250, 225, "Your score is:");
    char scoreStr[10];
    sprintf(scoreStr, "%d", score);
    outtextxy(300, 275, scoreStr);

    if (askToGoBack()) {
        // Reset game state and go back to the name input panel
        for (int i = 0; i < 50; i++) {
            name[i] = 0;
        }
        value = 0;
        cleardevice();
    } else {
        closegraph();
        exit(0);
    }
}





void timer(){
   int score=0;
    for(int t=60;t>=0;t--){
            score++;
        if(stopTimer1){
        cleardevice();
        //outtextxy(300, 430, "YOU WINNNNN!!!");
        //delay(1000);
        //cleardevice();
        score=60-score;
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        rectangle(150, 200, 500, 300);
        outtextxy(230, 215, "YOU WINNNNN!!!");
        sprintf(f,"Your score is-\r%d",score);
        outtextxy(200,260,f);
        delay(5000);
        break;}
        if(stopTimer2){
        cleardevice();
        //outtextxy(300, 430, "WRONG MOVEEEE!!!");
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        rectangle(180, 220, 420, 270);
        outtextxy(180, 250, "Your score is 0");
        delay(1000);
        break;}
        sprintf(a,"\r%d",t);

           outtextxy(100,430, a);
           delay(1000);
           if(t==0){
        cleardevice();
        settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
        rectangle(150, 200, 500, 300);
        outtextxy(230, 215, "Time's up!!!");
        outtextxy(200, 260, "Your score is 0");
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
    outtextxy(150, 100, "Hello ");
    outtextxy(250, 100, name);

    //outtextxy(200, 100, "Game Menu");
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

     // Draw the name input field


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

    //settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(140, 100, "How many players are there?");

    char key;
    char inputBuffer[10];
    int bufferIndex = 0;

    while (true) {
        if (kbhit()) {
            key = getch();

            if ((key >= '0' && key <= '9') || key == 13) {
                if (key == 13) { // Enter key
                    inputBuffer[bufferIndex] = '\0';
                    break;
                } else {
                    inputBuffer[bufferIndex++] = key;
                    inputBuffer[bufferIndex] = '\0';
                    outtextxy(150, 150, inputBuffer); // Display the input in real-time
                }
            }
        }
    }

    value = atoi(inputBuffer);//number of players
    //printf("the number of players is-%d",value);
    cleardevice();
    outtextxy(100, 220, "Enter Your Name: ");

    rectangle(90,200,450,250);// Initialize the name array
    int nameX = 250;
    int nameY = 220;
    int ch,no;
    int i = 0;


    while (true) {
        ch = getch();

        if (ch == 13) { // Enter key
            name[i] = '\0';
            break;
        } else if (ch == 8) { // Backspace key
            if (i > 0) {
                i--;
                nameX -= textwidth(&name[i]);
                outtextxy(nameX, nameY, " ");
            }
        } else {
            name[i] = ch;
            outtextxy(nameX, nameY, &name[i]);
            nameX += textwidth(&name[i]);
            i++;
        }
    }

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
