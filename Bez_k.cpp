#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

int fact(int n)
{
    int i;
    int fact = 1;
    for(i=1 ; i<=n ; i++)
    {
        fact *= i;
    }
    return fact;
}

int combin(int n, int i)
{
    return fact(n)/(fact(i) * fact (n-i));
}

void bezier (int x[10], int y[10], int n)
{
    int i;
    double t;
    for (t = 0.0; t < 1.0; t += 0.0005)
    {
        double xt = 0, yt = 0;
        for(i=0 ; i<n ; i++)
        {
            xt += combin(n-1, i) * pow(1-t, (n-1)-i) * pow(t, i) * x[i];
            yt += combin(n-1, i) * pow(1-t, (n-1)-i) * pow(t, i) * y[i];
        }
        putpixel (xt, yt, WHITE);
    }
    for (i=0; i<n; i++)
        putpixel (x[i], y[i], YELLOW)
    return;
}

int main()
{
    int gd = DETECT, gm;
    int n;

    int x[10]={160,340};
    int y[10]={130,130};
    int a[10]={250,250};
    int b[10]={130,280};
    int p[10]={250,150,150,250};
    int q[10]={200,120,290,220};
    int c[10]={250,350,350,250};
    int d[10]={200,120,290,220};

    initgraph (&gd, &gm, "C://TC/BGI");
    /*
    x={100,300};
    y={100,100};
    bezier (x, y, 2);

    x={250,250};
    y={100,307};
    bezier (x, y, 2);

    x={150,275,175,135,120,163,200};
    y={100,175,375,375,225,245,225};
    bezier (x, y, 7);
    */
    bezier(x,y,2);
    bezier(a,b,2);
    bezier(p,q,4);
    bezier(c,d,4);
    getch();
    closegraph();
    return 0;
}


