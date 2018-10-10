///////////////////////////////  MOVING TRAIN ////////////////////////////////////////


#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

int main()
{
    int gd=DETECT,gm;
	int i=0,m=0;
	initgraph(&gd,&gm,"..\\bgi");

	while(!kbhit())
	{
		i++;
		cleardevice();

		line(80+i,270,80+i,300);
		line(80+i,300,160+i,300);
		line(160+i,300,160+i,270);
		line(80+i,270,160+i,270);
		line(140+i,270,140+i,245);
		line(140+i,245,160+i,245);
		line(160+i,245,160+i,270);
		line(152+i,245,152+i,235);
		line(152+i,235,157+i,235);
		line(157+i,235,157+i,245);
		circle(90+i,305,5);
		circle(105+i,305,5);
		circle(120+i,305,5);
		circle(135+i,305,5);
		circle(150+i,305,5);
		line(0,315,950,300);

		delay(10);
	}
	getch();
	closegraph();
    return 0;
}
