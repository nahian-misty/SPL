
#include<graphics.h>
int main(){
int gd=DETECT,gm;
initgraph(&gd,&gm, "");
line(100,150,200,250);
outtextxy(200, 100, "CIRCLE Using Graphics in C");
int x=100,y=200;
while(1){
    cleardevice();
    circle(x,y, 50);
    if(GetAsyncKeyState(VK_RIGHT)){
        x=x+10;
    }
    else if(GetAsyncKeyState(VK_LEFT)){
        x=x-10;
    }
    else if(GetAsyncKeyState(VK_UP)){
        y=y-10;
    }
    else if(GetAsyncKeyState(VK_DOWN)){
        y=y+10;
    }
    else if(GetAsyncKeyState(VK_ESCAPE)){
        break;
    }

delay(50);

}

getch();
closegraph();
return 0;
}

