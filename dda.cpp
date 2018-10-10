/**
    C program for DDA line generation to draw STAR
*/
#include<stdio.h>
#include<graphics.h>

//Function for finding absolute value
int abs (int n)
{
    return ( (n>0) ? n : ( n * (-1)));
}

//DDA Function for line generation
void dda(int X0, int Y0, int X1, int Y1)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;

    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // calculate increment in x & y for each steps
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;

    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        //if( i%9 > 6)//dashed star
        //if(i%2 == 0)//dotted star
        putpixel (X,Y,WHITE);  // put pixel at (X,Y)
        X += Xinc;           // increment in x at each step
        Y += Yinc;           // increment in y at each step
        //delay(1);          // for visualization of line-
                             // generation step by step
    }
}

// Driver program
int main()
{
    int gd = DETECT, gm;

    // Initialize graphics function
    initgraph (&gd, &gm, "");

    int X0 , Y0, X1, Y1;
    dda(0,225,650,225);
    dda(325,0,325,500);

    //future line drawings

    dda(75,100,175,100);
    dda(75,100,125,200);
    dda(175,100,125,200);
    dda(75,175,175,175);

    dda(125,80,75,175);
    dda(125,80,175,175);
    getch();
    closegraph();
    return 0;
}
