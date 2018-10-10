#include<stdio.h>
#include<graphics.h>
#include<math.h>

float xPoint(int a[][2], int n, float u);
float yPoint(int a[][2], int n, float u);
int fact(int n);
int nCr(int n,int r);

int main()
{

	int gd = DETECT, gm;
	int  i, n=11;
	float u, x, y;
	initgraph(&gd, &gm, "..\\bgi");
//	printf("\nEnter the number of points: ");
//	scanf("%d", &n);
	//printf("\nEnter the points: \n");
//	for(i = 0; i < n; i++) {
//		printf("[x%d, y%d]: ", i, i);
//		scanf("%d%d", &a[i][0], &a[i][1]);
//	}
    int a[11][2]=
                    {
                        {100,100},
                        {200,200},
                        {110,250},
                        {50,270},
                        {150,300},
                        {175,500},
                        {350,300},
                        {550,270},
                        {375,520},
                        {300,200},
                        {400,100},
                    };

	for(u = 0; u < 1; u += 0.000005)
    {
		x = xPoint(a, n, u);
		y = yPoint(a, n, u);
		putpixel(x, y,WHITE);
	}
	closegraph();
	getch();
	return 0;
}

float xPoint(int a[][2], int n, float u) {
	int i;
	float x;
	x = 0;
	for(i = 0; i < n; i++)
    {
		x += nCr(n - 1, i) * pow((1 - u), (n - 1 - i)) * pow(u, i) * a[i][0];
	}
	return x;
}


float yPoint(int a[][2], int n, float u)
{
	int i;
	float y;
	y = 0;
	for(i = 0; i < n; i++)
    {
		y += nCr(n - 1, i) * pow((1 - u), (n - 1 - i)) * pow(u, i) * a[i][1];
	}
	return y;
}

int nCr(int n, int r)
{
	return ((fact(n)) / (fact(n-r) * fact(r)));
}

int fact(int n)
{
	if(n == 0)
    {
		return 1;
	}
    else
    {
		return n * fact(n - 1);
	}
}



