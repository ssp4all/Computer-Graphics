#include<graphics.h>
#include<stdio.h>

void floodFill(int,int,int,int);

int main()
{
    int x,y,o=0,xc,yc;

    int gDriver=DETECT,gmode;
    initgraph(&gDriver,&gmode, NULL);

    int r=100;

    xc = getmaxx()/2, yc = getmaxy()/2;
    circle(xc,yc,r);
    circle(xc,yc,r+1);
    circle(xc,yc,r+2);

    circle(xc+r+25,yc,r);
    circle(xc+r+25,yc,r+1);
    circle(xc+r+25,yc,r+2);

    circle(xc-r-25,yc,r);
    circle(xc-r-25,yc,r+1);
    circle(xc-r-25,yc,r+2);

    floodFill(xc,yc,o,4);
    floodFill(xc+r+30,yc,o,2);
    floodFill(xc+r-30,yc,o,3);
    floodFill(xc-r-30,yc,o,1);
    floodFill(xc-r+30,yc,o,5);

    getch();
    closegraph();
    return 0;
}

void floodFill(int x, int y, int old, int fill_colour)
{
	int current;
	current=getpixel(x,y);
	if(current==old)
	{
		putpixel(x,y,fill_colour);
        floodFill(x+1,y,old,fill_colour);
		floodFill(x-1,y,old,fill_colour);
		floodFill(x, y+1,old,fill_colour);
        floodFill(x,y-1,old,fill_colour);
        floodFill(x+1,y+1,old,fill_colour);
        floodFill(x+1,y-1,old,fill_colour);
        floodFill(x-1,y+1,old,fill_colour);
        floodFill(x-1,y-1,old,fill_colour);
	}
}
