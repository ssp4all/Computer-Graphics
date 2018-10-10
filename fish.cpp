#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

int main() {
        /* request auto detection */
        int gdriver = DETECT, gmode;
        int errcode, i;

        /* initialize graphic mode */
        initgraph(&gdriver, &gmode, "C:/TURBOC3/BGI");
        errcode = graphresult();

        if (errcode != grOk) {
                /* error occurred */
                getch();
                printf("Error in graphics!!\n");
                return 0;
        }

        /* fish movement implementation */
        for (i = 0; i <= 300; i = i + 3) {
                /* sleep for 30 milliseconds */
                delay(30);
                /* clear graphic screen */
                cleardevice();

                /* drawing tail */
                setcolor(DARKGRAY);
                setfillstyle(SLASH_FILL, DARKGRAY);
                pieslice(90 + i, getmaxy()/2, 135, 225, 50);
                floodfill(90 + i, getmaxy()/2, DARKGRAY);

                /* drawing the body of the fish */
                setcolor(LIGHTGRAY);
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                ellipse(150 + i, getmaxy()/2, 0, 360, 80, 25);
                floodfill(150 + i, getmaxy()/2, 7);

                /* drawing pelvic fins */
                setcolor(DARKGRAY);
                setfillstyle(SLASH_FILL, DARKGRAY);
                pieslice(170 + i, getmaxy()/2, 205, 250, 40);
                floodfill(170 + i, getmaxy()/2, DARKGRAY);

                /* draw eyes for the fish */
                setcolor(BLACK);
                setfillstyle(SOLID_FILL, BLACK);
                circle(210 + i, getmaxy()/2 - 1, 2);
                floodfill(210 + i, getmaxy()/2 - 1, BLACK);

                setcolor(BLACK);
                arc(210 + i, getmaxy()/2 - 1, 70, 225, 6);

                /* sleep for 120 milliseconds */
                delay(120);
                /* clears the graphic screen */
                cleardevice();

                /* tail of the fish */
                setcolor(DARKGRAY);
                setfillstyle(SLASH_FILL, DARKGRAY);
                pieslice(90 + i, getmaxy()/2, 135, 225, 50);
                floodfill(90 + i, getmaxy()/2, DARKGRAY);

                /* body of the fish */
                setcolor(LIGHTGRAY);
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                ellipse(150 + i, getmaxy()/2, 0, 360, 80, 25);
                floodfill(150 + i, getmaxy()/2, LIGHTGRAY);

                /* place fin at different position to get motion */
                setcolor(DARKGRAY);
                setfillstyle(SLASH_FILL, DARKGRAY);
                pieslice(170 + i, getmaxy()/2, 180, 210, 40);
                floodfill(170 + i, getmaxy()/2, DARKGRAY);

                /* eye of the fish */
                setcolor(BLACK);
                setfillstyle(SOLID_FILL, BLACK);
                circle(210 + i, getmaxy()/2 - 1, 2);
                floodfill(210 + i, getmaxy()/2 - 1, BLACK);

                setcolor(BLACK);
                arc(210 + i, getmaxy()/2 - 1, 70, 225, 6);

                /* sleep for 120 milliseconds */
                delay(120);
                /* clear the graphic screen */
                cleardevice();

                /* draw fish tail */
                setcolor(DARKGRAY);
                setfillstyle(SLASH_FILL, DARKGRAY);
                pieslice(90 + i, getmaxy()/2, 135, 225, 50);
                floodfill(90 + i, getmaxy()/2, DARKGRAY);

                /* body of the fish */
                setcolor(LIGHTGRAY);
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                ellipse(150 + i, getmaxy()/2, 0, 360, 80, 25);
                floodfill(150 + i, getmaxy()/2, LIGHTGRAY);

                /* locate fin at different position to get motion */
                setcolor(DARKGRAY);
                setfillstyle(SLASH_FILL, DARKGRAY);
                pieslice(170 + i, getmaxy()/2, 125, 170, 40);
                floodfill(170 +i, getmaxy()/2, DARKGRAY);

                setcolor(BLACK);
                setfillstyle(SOLID_FILL, BLACK);
                circle(210 + i, getmaxy()/2 - 1, 2);
                floodfill(210 + i, getmaxy()/2 - 1, BLACK);

                setcolor(BLACK);
                arc(210 + i, getmaxy()/2 - 1, 70, 225, 6);
        }

        /* clears the graphic screen */
        cleardevice();

        /* deallocate memory allocated for graphic screen */
        closegraph();
        return 0;
  }

