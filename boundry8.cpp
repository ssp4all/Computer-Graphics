#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
using namespace std;
class Circle
{
    int XCoord;
    int YCoord;
    int Radius;
    void PlotPoint(int,int,int);
    public:
    Circle()
    {
        XCoord=0;
        YCoord=0;
        Radius=0;
    }

    Circle(int x, int y, int z)
    {
        XCoord=x;
        YCoord=y;
        Radius=z;
    }

    void CircleMidpoint();
    void InitGraphs();
    void BoundryFill(int,int,int,int);
    void BoundryFillRound();
};

void Circle :: InitGraphs()
{
    int gMode, gDriver=DETECT;
    int errorcode;
    initgraph(&gDriver,&gMode,"c:\\tc\\bgi");
    errorcode = graphresult();

    if (errorcode != grOk)  /* an error occurred */
    {
       cout<<"Graphics error: "<< grapherrormsg(errorcode);
       cout<<"Press any key to halt:";
       getch();
       exit(1);             /* return with error code */
    }
    setbkcolor(3);
}

void Circle :: PlotPoint(int x,int y,int z)
{
    delay(20);
    putpixel(XCoord+x,YCoord+y,z);
    putpixel(XCoord-x,YCoord+y,z);
    putpixel(XCoord+x,YCoord-y,z);
    putpixel(XCoord-x,YCoord-y,z);
    putpixel(XCoord+y,YCoord+x,z);
    putpixel(XCoord-y,YCoord+x,z);
    putpixel(XCoord+y,YCoord-x,z);
    putpixel(XCoord-y,YCoord-x,z);
}

void Circle :: CircleMidpoint()
{
    int x,y;
    int p;
    x=0;
    y=Radius;
    PlotPoint(x,y,15);

    p=1-Radius;
    while(x<y)
    {
        if(p<0)
            x+=1;
        else
        {
            x+=1;
            y-=1;
        }

        if(p<0)
            p=p+2*x+1;
        else
        {
            p=p + 2 *(x-y) + 1;
        }
        PlotPoint(x,y,15);
    }
}

void Circle :: BoundryFillRound()
{
    int x,y;
    int p;
    for(int iCntr=1;iCntr<Radius;iCntr++)
    {
    x=0;
    y=iCntr;
    PlotPoint(x,y,5);

    p=1-iCntr;
    while(x<y)
    {
        if(p<0)
            x+=1;
        else
        {
            x+=1;
            y-=1;
        }

        if(p<0)
            p=p+2*x+1;
        else
        {
            p=p + 2 *(x-y) + 1;
        }
        PlotPoint(x,y,5);
    }
//    sleep(1);
    }
}

void Circle :: BoundryFill(int x, int y,int fill,int bound)
{
    int cur;
    cur=getpixel(x,y);
    if(cur!=bound && cur!= fill)
    {
        putpixel(x,y,fill);
        Circle :: BoundryFill(x+1, y,fill,bound);
        Circle :: BoundryFill(x-1, y,fill,bound);
        Circle :: BoundryFill(x, y-1,fill,bound);
        Circle :: BoundryFill(x, y+1,fill,bound);
        Circle :: BoundryFill(x+1, y+1,fill,bound);
        Circle :: BoundryFill(x-1, y+1,fill,bound);
        Circle :: BoundryFill(x-1, y-1,fill,bound);
        Circle :: BoundryFill(x+1, y-1,fill,bound);
    }
}

int main()
{
    Circle cObj(250,250,42);
    cObj.InitGraphs();
    cObj.CircleMidpoint();
    cObj.BoundryFillRound();
    //cObj.BoundryFill(250,250,11,15);
    getch();
    closegraph();
    return 0;
}
