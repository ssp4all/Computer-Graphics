#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<winbgim.h>
void mcircle(int xc,int yc,int x,int y)
{
	    putpixel(xc+x,yc+y,7);
	    putpixel(xc+y,yc+x,7);
	    putpixel(xc-y,yc+x,7);
	    putpixel(xc-x,yc+y,7);
	    putpixel(xc-x,yc-y,7);
	    putpixel(xc-y,yc-x,7);
	    putpixel(xc+y,yc-x,7);
	    putpixel(xc+x,yc-y,7);
}
int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C://TURBOC3//bgi");
    int r=100,x,y,Pk,xc=200,yc=200,i=0;
//    printf("enter the radius of circle\n");
//    scanf("%d",&r);
//    printf("enter the position of radius of the circle\n");
//    scanf("%d",&xc);
//    scanf("%d",&yc);
    x=0;
    y=r;
    Pk=1-r;
    mcircle(xc,yc,x,y);
    while(x<y)
    {
        i++;
        if(Pk<0)
        {
                x=x+1;
                Pk=Pk+(2*x)+1;
        }
        else
        {
                x=x+1;
                y=y-1;
                Pk=Pk+(2*x)-(2*y)+1;
        }
        if(i%5 ==0){
        mcircle(xc,yc,x,y);
        }
    }
     getch();
    closegraph();
    return 0;
}
