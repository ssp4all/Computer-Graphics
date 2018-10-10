#include<stdio.h>
#include<graphics.h>
#include<math.h>

void dda(int X0, int Y0, int X1, int Y1);

double a[3][20]=
                {
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
void calculate(double b[3][3],double a[3][20])
{
    double multiply[3][20];
    int c,d,k,sum=0;
    for (c = 0; c < 3; c++)
    {
      for (d = 0; d < 20; d++)
      {
        for (k = 0; k < 3; k++)
        {
            sum = sum + b[c][k]*a[k][d];
        }
        multiply[c][d] = sum;
        sum = 0;
      }
    }
    plot(multiply);
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
void reflection(double a[3][20],double b[3][3],int ax,int ay)
{

    int i,j,k,sum=0;
    double result[3][20];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 20; j++)
        {
            sum=0;
            for (k = 0; k < 3; k++)
            {
                sum = sum + b[i][k]*a[k][j];
            }

            result[i][j]=sum;
        }
    }
    for(i=0;i<20;i++)
    {
        dda(result[0][i]+ax,result[1][i]+ay,result[0][i++]+ax,result[1][i]+ay);
    }
}

int main()
{
    int n;
    int x0 , y0, x1, y1,tx,ty,sx,sy,r;
    double t;
    int gd = DETECT, gm;
    // Initialize graphics function
    initgraph (&gd, &gm, "C:\Program Files\CodeBlocks\MinGW\lib");
    //draw_shape();
    draw_shape();
    do
    {
        printf("\n *** MENU ***");
        printf("\n1 .Translation");
        printf("\n2 .Rotation");
        printf("\n3 .Scaling");
        printf("\n4 .Reflection");
        printf("\n5 .Shearing");
        printf("\n99.Exit");

        printf("\nEnter your choice :");
        scanf("\n%d",&n);
        switch(n)
        {
            case 1 :
                {
                    printf("\nEnter Translation factor along x :");
                    scanf("%d",&tx);
                    printf("\nEnter Translation factor along y :");
                    scanf("%d",&ty);

                    double translation[3][3]=
                                            {
                                                {1,0,tx},
                                                {0,1,ty},
                                                {0,0,1}
                                            };
                    calculate(translation,a);
                    getch();
                    //cleardevice();
                    break;
                }
            case 2 :
                {
      //              draw_shape();
                    printf("\n Enter the angle of rotation : ");
                    scanf("%d",&r);
                    t=3.14*r / 180;

                    double rotation[3][3]=
                                        {
                                            {cos(t),sin(t),0},
                                            {-sin(t),cos(t),0},
                                            {0,0,1}
                                        };
                    calculate(rotation,a);
                    getch();
                    //cleardevice();
                    break;
                }
            case 3 :
                {
        //            draw_shape();
                    printf("\n Enter the scaling factor along x :");
                    scanf("%d",&sx);
                    printf("\n Enter the scaling factor along y :");
                    scanf("%d",&sy);

                    double scaling[3][3]=
                                        {
                                            {sx,0,0},
                                            {0,sy,0},
                                            {0,0,1}
                                        };
                    calculate(scaling,a);
                    getch();
                    //cleardevice();
                    break;
                }
            case 4 :
                {
                    int ch;
                    printf("\n1.Reflect about x-axis");
                    printf("\n2.Reflect about y-axis");
                    printf("\n3.Reflect about origin");
                    printf("\n\nEnter your choice : ");
                    scanf("%d",&ch);
                    int ax=getmaxx();
                    int ay=getmaxy();
                    double temp[3][3]={{1,0,0},{0,1,0},{0,0,1}};
                    if(ch==1)
                    {
                       temp[1][1] = -1;
                       reflection(a,temp,0,ay);
                    }
                    else if(ch==2)
                    {
                        temp[0][0] = -1;
                        reflection(a,temp,ax,0);
                    }
                    else if(ch==3)
                    {
                        temp[1][1] = -1;
                        temp[0][0] = -1;
                        reflection(a,temp,ax,ay);
                    }
                    else
                    printf("\n\nINVALID INPUT");

                    //calculate(reflection,a);
                    getch();
                    //cleardevice();
                    break;
                }
            case 5 :
                {
                    int shx,shy;
                    printf("\n Enter the shearing factor along x :");
                    scanf("%d",&shx);
                    printf("\n Enter the shearing factor along y :");
                    scanf("%d",&shy);

                    double shearing[3][3]=
                                            {
                                                {1,shx,0},
                                                {shy,1,0},
                                                {0,0,1}
                                            };
                    calculate(shearing,a);
                    getch();
                    //cleardevice();
                    break;
                }
            case 99:
                    return 0;
            default:
                    printf("\n Invalid data");
                    break;
        }
    }while(1);

    getch();
    closegraph();
    return -1;
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
