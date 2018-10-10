#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>

int main()
{
    int gd = DETECT, gm;
    int i, x, y;
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    while (!kbhit())
    {
        circle(200,200,50);
        floodfill(200,200,15);

       /* color 500 random pixels on screen */
       for(i=0; i<=500; i++)
       {
           x=rand()%getmaxx();
           y=rand()%getmaxy();
           putpixel(x,y,15);
      }
      delay(500);
      /* clears screen */
      cleardevice();
    }

    getch();
    closegraph();
    return 0;
}
