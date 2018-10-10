/**
    cpp program to implement Cohen-sutherland Line Cliping algorithm
*/
#include<stdio.h>
#include<graphics.h>

void clip(int x0, int y0, int x1, int y1, int lx0, int ly0, int lx1, int ly1)
{
    char rc0[4], rc1[4];
    int drawx0=lx0, drawy0=ly0, drawx1=lx1, drawy1=ly1;
    double m = (ly1 - ly0) / (lx1 - lx0);
    rc0[0] = ly0>y1?'1':'0';
    rc0[1] = ly0<y0?'1':'0';
    rc0[2] = lx0>x1?'1':'0';
    rc0[3] = lx0<x0?'1':'0';

    rc1[0] = ly1>y1?'1':'0';
    rc1[1] = ly1<y0?'1':'0';
    rc1[2] = lx1>x1?'1':'0';
    rc1[3] = lx1<x0?'1':'0';
    if(strcmp(rc0,"0000") == 0 && strcmp(rc1,"0000") == 0)
    {
        line(lx0, ly0, lx1, ly1);
    }
    int flag = 0;
    for(int i = 0; i < 4; i++)
    {
        if(rc0[i] != rc1[i])
        {
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("Line is Rejected");
    }
    do
    {
        if(rc0[0] == '1')
        {
            drawy0 = y1;
            drawx0 = lx0 + (1/m)*(y1 - ly0);
            rc0[0] = '0';
        }
        if(rc0[1] == '1')
        {
            drawy0 = y0;
            drawx0 = lx0 + (1/m)*(y0 - ly0);
            rc0[1] = '0';
        }
        if(rc0[2] == '1')
        {
            drawx0 = y1;
            drawy0 = ly0 + m*(x1 - lx0);
            rc0[2] = '0';
        }
        if(rc0[3] == '1')
        {
            drawx0 = x0;
            drawy0 = ly0 + m*(x0 - lx0);
            rc0[3] = '0';
        }
        if(rc1[0] == '1')
        {
            drawy1 = y1;
            drawx1 = lx1 + (1/m)*(y1 - ly1);
            rc1[0] = '0';
        }
        if(rc1[1] == '1')
        {
            drawy1 = y0;
            drawx1 = lx1 + (1/m)*(y0 - ly1);
            rc1[1] = '0';
        }
        if(rc1[2] == '1')
        {
            drawx1 = x1;
            drawy1 = ly1 + m*(x1 - lx1);
            rc1[2] = '0';
        }
        if(rc1[3] == '1')
        {
            drawx1 = x0;
            drawy1 = ly1 + m*(x0 - lx1);
            rc1[3] = '0';
        }
    }while(strcmp(rc0, "0000") != 0 && strcmp(rc1, "0000"));

    setcolor(15);
    line(drawx0, drawy0, drawx1, drawy1);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "..\\bgi");
    int x0=100, y0=100, x1=400, y1=400, lx0=50, ly0=50, lx1=500, ly1=500;
//    printf("Enter 2 diagonal co-ordinates of Window : ");
//    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
//    printf("Enter co-ordinates of Line: ");
//    scanf("%d %d %d %d", &lx0, &ly0, &lx1, &ly1);
    setcolor(14);
    line(lx0,ly0,lx1,ly1);
    rectangle(x0,y0,x1,y1);
    getch();
    cleardevice();
    rectangle(x0,y0,x1,y1);
    clip(x0, y0, x1, y1, lx0, ly0, lx1, ly1);
    getch();
    closegraph();
    return 0;
}
