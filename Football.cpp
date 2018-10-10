#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#define ll long long
int main()
{
	ll i;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"..\\bgi");
	//ground
	line(10,300,600,300);
	//person1
	circle(50,200,25);
	line(50,225,50,250);
	line(50,250,35,300);
	line(50,250,75,300);
	//person2
	circle(250,200,25);
	line(250,225,250,250);
	line(250,250,235,300);
	line(250,250,275,300);
	//goalPost
	line(450,300,450,200);
	line(500,300,500,150);
	line(450,200,500,150);
	//moving ball in for loop
	circle(90,275,25);

	for(i=0;i<=100;i++)
	{
		delay(20);
		cleardevice();
		line(10,300,600,300);
		//person1
		circle(50,200,25);
		line(50,225,50,250);
		line(50,250,35,300);
		line(50,250,75,300);
		//person2
		circle(250,200,25);
		line(250,225,250,250);
		line(250,250,235,300);
		line(250,250,275,300);
		//goalPost
		line(450,300,450,200);
		line(500,300,500,150);
		line(450,200,500,150);
		//moving ball in for loop
		circle(90+i,275,25);
	}

	for(i=0;i<=190;i++)
	{
		delay(20);
		cleardevice();
		line(10,300,600,300);
		//person1
		circle(50,200,25);
		line(50,225,50,250);
		line(50,250,35,300);
		line(50,250,75,300);
		//person2
		circle(250,200,25);
		line(250,225,250,250);
		line(250,250,235,300);
		line(250,250,275,300);
		//goalPost
		line(450,300,450,200);
		line(500,300,500,150);
		line(450,200,500,150);
		//moving ball in for loop
		circle(285+i,275,25);
	}
	getch();
    return 0;
}
