using namespace std;
#include <iostream>
#include <graphics.h>
#include <cstdio>
#include <cmath>

void fish(int x, int y){

    //Body
    ellipse(x, y, 0, 360, 50, 20);
    //eye
    circle(x+25, y-5, 5);
    //back fin
    line(x-50, y, x-70, y-10);
    line(x-50, y, x-70, y+10);
    line(x-70, y-10, x-70, y+10);
    //top fin
    line(x+10,y-18, x-15, y-40);
    line(x-10,y-18, x-15, y-40);
    //bottom fin
    line(x+10,y+18, x-15, y+40);
    line(x-10,y+18, x-15, y+40);
    //stripes
    line(x+15,y-17,x,y+17);
    line(x,y-17,x-15,y+17);
}

int main(){
    initwindow(getmaxwidth(), getmaxheight());
    int x1 = 100;
    int y1 = getmaxheight()/2;

    int x2 = 400;
    int y2 = getmaxheight()/2-200;
    while(1){
        //fish 1
        fish(x1, y1);
        x1+=3;
        y1+=rand()%11-5;

        //fish 2
        fish(x2, y2);
        x2+=2;
        y2+=rand()%11-5;

        delay(100);
        cleardevice();
    }

    getch();
    closegraph();
    return 1;
}
