#include<graphics.h>
#include<conio.h>
void boundaryfill(int x,int y,int f_color,int b_color)
{
    if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
    {

        putpixel(x,y,f_color);
//        boundaryfill(x+1,y,f_color,b_color);
//        boundaryfill(x,y+1,f_color,b_color);
//        boundaryfill(x-1,y,f_color,b_color);
//        boundaryfill(x,y-1,f_color,b_color);

         boundaryfill(x+1, y,f_color,b_color);
         boundaryfill(x-1, y,f_color,b_color);
         boundaryfill(x, y-1,f_color,b_color);
         boundaryfill(x, y+1,f_color,b_color);
         boundaryfill(x+1, y+1,f_color,b_color);
         boundaryfill(x+1, y+1,f_color,b_color);
         boundaryfill(x-1, y-1,f_color,b_color);
         boundaryfill(x-1, y+1,f_color,b_color);
    }
}
main()
{
    int gd = DETECT, gm, c , x = 100, y = 50;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    //to draw thicker line
//    setlinestyle(0,0,20);
//    line(100,25,300,25);
//
//    //to draw different types of lines
//    for ( c = 0 ; c < 5 ; c++ )
//    {
//        setlinestyle(c, 0, 1);
//        line(x, y, x+200, y);
//        y = y + 25;
//    }
//    setlinestyle();
//    setcolor(YELLOW);
//    setfillstyle(5, RED);
//    circle(100, 100, 50);
//    floodfill(100, 100, YELLOW);
//
//
//    ellipse(170, getmaxy()/2, 0, 360,70,30);
//    arc(400, getmaxy()/2, 90, 360,70);
//    pieslice(300, getmaxy()/2, 90, 360,70);
    circle(200,200,100);
    boundaryfill(200,200,12,15);
    getch();
    closegraph();
    return 0;
}
