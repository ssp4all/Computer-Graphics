#include <graphics.h>
using namespace std;
#include <iostream>
void dda(int ,int, int,int);
int main()
{
    int x0,y0,x1,y1,x,y;//Variables declarations

    //Graph initialize
    int gd = DETECT , gm ;
    initgraph( &gd , &gm, "C:\Program Files\CodeBlocks\MinGW\lib" );

    //This two are for drawing axis
    dda(0,225,650,225);
    dda(325,0,325,500);

    //future line drawings
    dda(75,50,75,170);
    dda(75,170,150,200);
    dda(150,50,150,170);
    dda(75,50,150,50);
    dda(150,70,17(0,70);
    dda(150,75,165,70);
    dda(170,70,170,140);

    dda(150,140,170,140);
    dda(165,75,165,135);

    dda(150,135,165,135);
    dda(75,60,150,60);

    getch();
    closegraph();
    return -1;

}

void dda( int x0,int y0 ,int x1,int y1)
{
    int dx , dy , l;
    dx = x1-x0;
    dy = y1-y0;

    if(dx > dy)
    {
        l = abs(dx);
    }
    else
    {
        l = abs(dy);
    }
    int incx = dx / l ;
    int incy = dy / l ;
    int x=x0;
    int y=y0;
    for( int i=0 ; i<l ; i++)
    {
        putpixel(x ,y ,WHITE);
        x=x+incx;
        y=y+incy;
    }
    return;
}


