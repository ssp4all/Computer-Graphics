#include<stdio.h>
#include<math.h>
#include<graphics.h>

int a;
void drawfern(int x,int y,int l,int arg,int n)
{
	int x1,y1,i;
	int l1,xpt,ypt;

	if(n>0)
	{

    	x1=(int)(x-l*sin(arg*M_PI/180));//Tells from where to start....
    	y1=(int)(y-l*cos(arg*M_PI/180));
        line(x,y,x1,y1);//length of each line drawn ....

        drawfern(x1,y1,(int)(0.8*l),arg+a,n-1);
        drawfern(x1,y1,(int)(0.8*l),arg-a,n-1);
 	}
}

int main()
{
	int gd=DETECT,gm,x,y,l;
	initgraph(&gd, &gm, "C:\Program Files (x86)\CodeBlocks\MinGW\lib");
	//initgraph(&gd, &gm, NULL);
	initwindow(getmaxwidth(),getmaxheight());
	x=getmaxx()/2;
	y=getmaxy()/2 + 200;

	l=150;
	a=30;
	setcolor(YELLOW);
    drawfern(x,y,l,0,10);
    getch();
	return 0;
}
