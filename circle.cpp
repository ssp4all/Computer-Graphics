#include<graphics.h>

int main()
{
int gd = DETECT, gm;
int x = 320, y = 240, radius;

initgraph(&gd, &gm, "C:\\TC\\BGI");

for ( radius = 25; radius <= 125 ; radius = radius + 1)
circle(x, y, radius);

getch();
closegraph();
return 0;
}