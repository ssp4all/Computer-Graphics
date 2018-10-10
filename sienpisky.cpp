#include<iostream>
#include<conio.h>
#include<graphics.h>
using namespace std;
void fract(int p[],int n);
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    int j=0,p[20]={100,100,100,400,500,400},i,n=10;

    p[6]=p[0];
    p[7]=p[1];

    drawpoly(4,p);

    fract(p,n);
    getch();
    closegraph();
    return 0;
}
void fract(int p[],int n)
{
    int a[8],m[8],b[8],c[8],i,k;
    for(i=0;i<8;i=i+2)
    {
        m[i]=(int)(p[i]+p[i+2])/2;
        m[i+1]=(int)(p[i+1]+p[i+3])/2;
    }
    m[6]=m[0];
    m[7]=m[1];
    drawpoly(4,m);
    k=n-1;
    if(k!=0)
    {
        a[0]=p[0];a[1]=p[1];a[2]=m[0];a[3]=m[1];a[4]=m[4];a[5]=m[5];a[6]=p[0];a[7]=p[1];
        fract(a,k);
        b[0]=p[2];b[1]=p[3];b[2]=m[0];b[3]=m[1];b[4]=m[2];b[5]=m[3];b[6]=p[2];b[7]=p[3];
        fract(b,k);
        c[0]=p[4];c[1]=p[5];c[2]=m[2];c[3]=m[3];c[4]=m[4];c[5]=m[5];c[6]=p[4];c[7]=p[5];
        fract(c,k);
    }
}
