#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
int main()
{
    int i=0,j=260,k=30,l=150,m=90;
    int n=230,o=10,p=280,q=220;
    float pi=3.1424,a,b,c,d,e,f,g,h,z;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"d:\\tc\\bgi");
    outtextxy(0,10,"SOLAR SYSTEM");
    outtextxy(500,10,"press any key...");
    circle(320,240,20); /* sun */

    setfillstyle(1,4);
    floodfill(320,240,15);
    outtextxy(310,237,"sun");
    circle(260,240,8);
    setfillstyle(1,2);
    floodfill(258,240,15);
    floodfill(262,240,15);
    outtextxy(240,220,"mercury");
    circle(320,300,12);
    setfillstyle(1,1);
    floodfill(320,298,15);
    floodfill(320,302,15);
    outtextxy(335,300,"venus");
    circle(320,160,10);
    setfillstyle(1,5);
    floodfill(320,161,15);
    floodfill(320,159,15);
    outtextxy(332,150, "earth");
    circle(453,300,11);
    setfillstyle(1,6);
    floodfill(445,300,15);
    floodfill(448,309,15);
    outtextxy(458,280,"mars");
    circle(520,240,14);
    setfillstyle(1,7);
    floodfill(519,240,15);
    floodfill(521,240,15);
    outtextxy(500,257,"jupiter");
    circle(169,122,12);
    setfillstyle(1,12);
    floodfill(159,125,15);
    floodfill(175,125,15);
    outtextxy(130,137,"saturn");

    circle(320,420,9);
    setfillstyle(1,13);
    floodfill(320,417,15);
    floodfill(320,423,15);
    outtextxy(310,400,"uranus");
    circle(40,240,9);
    setfillstyle(1,10);
    floodfill(38,240,15);
    floodfill(42,240,15);
    outtextxy(25,220,"neptune");
    circle(150,420,7);
    setfillstyle(1,14);
    floodfill(150,419,15);
    floodfill(149,422,15);
    outtextxy(120,430,"pluto");
    getch();
    while(!kbhit()) /*animation*/
    {
        a=(pi/180)*i;
        b=(pi/180)*j;
        c=(pi/180)*k;
        d=(pi/180)*l;
        e=(pi/180)*m;
        f=(pi/180)*n;
        g=(pi/180)*o;
        h=(pi/180)*p;
        z=(pi/180)*q;
        cleardevice();
        circle(320,240,20);
        setfillstyle(1,4);
        floodfill(320,240,15);
        outtextxy(310,237,"sun");
        circle(320+60*sin(a),240-35*cos(a),8);

        setfillstyle(1,2);
        pieslice(320+60*sin(a),240-35*cos(a),0,360,8);
        ellipse(320,240,0,360,70,25) ;
        circle(320+100*sin(b),240-60*cos(b),12);
        setfillstyle(1,1);
        pieslice(320+100*sin(b),240-60*cos(b),0,360,12);
        ellipse(320,240,0,360,90,50) ;
        circle(320+130*sin(c),240-80*cos(c),10);
        setfillstyle(1,5);
        pieslice(320+130*sin(c),240-80*cos(c),0,360,10);
        ellipse(320,240,0,360,140,70) ;
        circle(320+170*sin(d),240-100*cos(d),11);
        setfillstyle(1,6);
        pieslice(320+170*sin(d),240-100*cos(d),0,360,11);
        ellipse(320,240,0,360,160,90) ;
        circle(320+200*sin(e),240-130*cos(e),14);
        setfillstyle(1,7);
        pieslice(320+200*sin(e),240-130*cos(e),0,360,14);
        ellipse(320,240,0,360,200,120) ;
        circle(320+230*sin(f),240-155*cos(f),12);
        setfillstyle(1,12);
        pieslice(320+230*sin(f),240-155*cos(f),0,360,12);
        circle(320+260*sin(g),240-180*cos(g),9);
        ellipse(320,240,0,360,220,150) ;
        setfillstyle(1,13);
        pieslice(320+260*sin(g),240-180*cos(g),0,360,9);
        circle(320+280*sin(h),240-200*cos(h),9);
        ellipse(320,240,0,360,260,190) ;
        setfillstyle(1,10);
        pieslice(320+280*sin(h),240-200*cos(h),0,360,9);
        circle(320+300*sin(z),240-220*cos(z),7);
        ellipse(320,240,0,360,280,200) ;
        setfillstyle(1,14);
        pieslice(320+300*sin(z),240-220*cos(z),0,360,7);

        ellipse(320,240,0,360,300,220) ;
        delay(20);
        i++;
        j++;
        k++;
        l++;
        m++;
        n++;
        o++;
        p++;
        q+=2;
    }
    getch();
    closegraph();
    return 0;
}
