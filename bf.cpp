#include<stdio.h>
#include<graphics.h>
void boundaryfill(int x,int y,int f_color,int b_color)
{
    if(getpixel(x,y)!=b_color && getpixel(x,y)!=f_color)
    {
        putpixel(x,y,f_color);
        boundaryfill(x+1,y,f_color,b_color);
        boundaryfill(x,y+1,f_color,b_color);
        boundaryfill(x-1,y,f_color,b_color);
        boundaryfill(x,y-1,f_color,b_color);
        boundaryfill(x+1,y+1,f_color,b_color);
        boundaryfill(x-1,y-1,f_color,b_color);
        boundaryfill(x+1,y+1,f_color,b_color);
        boundaryfill(x-1,y-1,f_color,b_color);
    }
}
int main()
{
    int gm,gd=DETECT,radius,radius1,radius2;
    int x,y;
   printf("Enter the co-ordintes for center of the circle\n");
    scanf("%d%d",&x,&y);
    printf("Enter radius of circle\n");
    scanf("%d",&radius);
    printf("Enter radius of circle\n");
    scanf("%d",&radius1);
    printf("Enter radius of circle\n");
    scanf("%d",&radius2);
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    circle(x,y,radius);
    circle(x,y,radius1);
    circle(x,y,radius2);
    rectangle(70,70,350,370);
    boundaryfill(x,y,LIGHTBLUE,WHITE);
    delay(50);
    closegraph();
    return 0;
}
