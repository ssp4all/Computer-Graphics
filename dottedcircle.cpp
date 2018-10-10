/**
    Circle drawing using Bresenham
*/
#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;

void plot(int x, int y, int xc, int yc);
void firstcircle(int xc, int yc,int r);

int t=0,i=2;
int main()
{
    //Variable initialization
    int r=100, xc=200,yc=200, pk, x, y ,r2=125;
//    Input from user
//	cout<<"Enter the center co-ordinates\n";
//	cin>>xc>>yc;
//	cout<<"Enter the radius of outer and inner circle\n";
//	cin>>r>>r2;
    //Graph initialization
	int gd = DETECT, gm;
	initgraph(&gd, &gm,"C:\Program Files\CodeBlocks\MinGW\lib");
    //Function Initialization

    putpixel(xc,yc,WHITE);
    firstcircle(xc,yc,r);
	getch();
	closegraph();
	return -1;
}
void firstcircle(int xc, int yc,int r)
{
    int x,y;
    int pk = 3 - 2*r;
	x=0;
	y = r;
	plot(x,y,xc,yc);
	while(x < y)
	{
	    while(i% 0)
        {
            if(pk <= 0)
            {
                pk = pk + (4*x) + 6;
                plot(++x,y,xc,yc);
                i++;
            }
            else
            {
                pk = pk + (4*(x-y)) + 10;
                plot(++x,--y,xc,yc);
                i--;
            }
        }
	}
}
void plot(int x, int y, int xc, int yc)
{
	putpixel(x+xc, y+yc, WHITE);
	putpixel(-x+xc, y+yc, WHITE);
	putpixel(x+xc, -y+yc, WHITE);
	putpixel(-x+xc, -y+yc, WHITE);
	putpixel(y+xc, x+yc, WHITE);
	putpixel(y+xc, -x+yc, WHITE);
	putpixel(-y+xc, x+yc, WHITE);
	putpixel(-y+xc, -x+yc, WHITE);
}

