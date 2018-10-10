#include<stdio.h>
#include<graphics.h>
#include<math.h>

void dda(int X0, int Y0, int X1, int Y1);

double multiply20[3][20];
double multiply3[3][3];

double a[3][20]={
                {75,75,75,150,150,150,75,150,150,170,150,165,170,170,150,170,165,165,150,165},
                {50,170,170,170,50,170,50,50,70,70,75,75,70,140,140,140,75,135,135,135},
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
             };
void plot(double a[][20])
{
    int i;
    for(i=0;i<20;i++)
    {
        dda(a[0][i],a[1][i],a[0][i++],a[1][i]);
    }
    return;
}

void draw_shape()
{
    //This two are for drawing axis
    dda(0,225,650,225);
    dda(325,0,325,500);
    plot(a);//plot cup
    return;
}
void calculate20(double b[3][3],double a[3][20])
{
    int c,d,k;
    double sum=0;
    for (c = 0; c < 3; c++)
    {
      for (d = 0; d < 20; d++)
      {
        for (k = 0; k < 3; k++)
        {
            sum = sum + b[c][k]*a[k][d];
        }
        multiply20[c][d] = sum;
        sum = 0;
      }
    }
    plot(multiply20);
    return;
}

void calculate3(double b[3][3],double a[3][3])
{
    int c,d,k;
    double sum=0;
    for (c = 0; c < 3; c++)
    {
      for (d = 0; d < 3; d++)
      {
        for (k = 0; k < 3; k++)
        {
            sum = sum + b[c][k]*a[k][d];
        }
        multiply3[c][d] = sum;
        sum = 0;
      }
    }
    return;
}
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
        putpixel (X,Y,WHITE);  // put pixel at (X,Y)
        X += Xinc;           // increment in x at each step
        Y += Yinc;           // increment in y at each step
        //delay(1);          // for visualization of line-
                             // generation step by step
    }
}

int main()
{
    int tx,ty,r;
    double t;
    printf("Enter x co-ordinate : ");
    scanf("%d",&tx);
    printf("Enter y co-ordinate : ");
    scanf("%d",&ty);
    printf("Enter angle : ");
    scanf("%d",&r);

    t=3.14*r / 180;

    int gd = DETECT, gm;
    // Initialize graphics function
    initgraph (&gd, &gm, "C:\Program Files\CodeBlocks\MinGW\lib");
    draw_shape();
    double inverse_translation[3][3]=
                        {
                            {1,0,-tx},
                            {0,1,-ty},
                            {0,0,1}
                        };
    double rotation[3][3]=
                        {
                            {cos(t),sin(t),0},
                            {-sin(t),cos(t),0},
                            {0,0,1}
                        };

    double translation[3][3]=
                        {
                            {1,0,tx},
                            {0,1,ty},
                            {0,0,1}
                        };


    calculate3(rotation,inverse_translation);
    calculate3(translation,multiply3);
    calculate20(multiply3,a);

    getch();
    closegraph();
    return -1;

}
