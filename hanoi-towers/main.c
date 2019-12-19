#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <dos.h>
#define c1x 32
#define c2x 59
#define c3x 86
#define cy 24
int disk_c[9]={14,9,10,11,12,13,8,5,3},diskx[9]={c1x,c1x,c1x,c1x,c1x,c1x,c1x,c1x,c1x},disky[9]={cy,cy,cy,cy,cy,cy,cy,cy,cy},l[3];
int speed = 2;
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c);
}
void color (int x)
{
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),x) ;
}
void drawcolumn()
{
	    int i,x=5,y,j;
		color(7);
    gotoxy(20,25);
    for (i=1;i<=80;i++)
        printf("%c",178);
	for (j=1;j<=3;j++)
	{
	x+=27;
	y=25;
	gotoxy(x,y);
		for (i=1;i<=20;i++)
		{
			printf("%c",178);
			y--;
			gotoxy(x,y);
		}
	}
	printf("\n\n\n");
}
void drawdisk(int n,int x,int y,int c)
{
	int i,j;
	x=x-n;
	for (j=1;j<2;j++)
	{
	gotoxy(x,y);
	color(c);
	for(i=1;i<=2*n+1;i++)
		printf("%c",219);
	y--;
	}
}
int moveup(int n,int x, int y,int c)
{
	int i,j;
	x=x-n;
	for (j=1;y>3;j++)
	{
	Sleep(speed);
	Beep(750,300);
	gotoxy (x,y);
	color(0);
	for (i=1;i<=n;i++)
		printf("%c",0);
	if (y<=5){
		color(0);
		printf("%c",178);
	}
	else{
	color(7);
	printf("%c",178);
	}
	color(c);
	for (i=1;i<=n;i++)
		printf("%c",0);
	y--;
	gotoxy (x,y);
	color(c);
	for(i=1;i<=2*n+1;i++)
		printf("%c",219);
	}
	return y;
}
int movedown(int n,int x,int y, int c,int l)
{
	int i,j;
	x=x-n;
	for (j=1;y<24;j++)
	{
	if (y>=l)
		return y;
	Sleep(speed);
	Beep(750,300);
	gotoxy (x,y);
	color(0);
	for (i=1;i<=n;i++)
		printf("%c",0);
	if (y<=5){
		color(0);
		printf("%c",178);
	}
	else{
	color(7);
	printf("%c",178);
	}
	color(c);
	for (i=1;i<=n;i++)
		printf("%c",0);
	y++;
	gotoxy (x,y);
	color(c);
	for(i=1;i<=2*n+1;i++)
		printf("%c",219);
	}
	return y;
}
int moveright(int n,int x,int y,int a,int c)
{
	int i,j;
	x-=n;
	for (i=1;i<=a*27;i++)
	{
	Sleep(speed);
	Beep(750,300);
	gotoxy (x,y);
	color(0);
		printf("%c",219);
		x+=2*n+1;
	gotoxy(x,y);
	color(c);
		printf("%c",219);
	x-=2*n;
	}
	x+=n;
	return x;
}
int moveleft(int n,int x,int y,int a,int c)
{
	int i,j;
	x+=n;
	for (i=1;i<=a*27;i++)
	{
	Sleep(speed);
	Beep(750,300);
	gotoxy(x,y);
	color(0);
		printf("%c",219);
	x-=2*n+1;
	gotoxy (x,y);
	color(c);
		printf("%c",219);
	x+=2*n;
	}
	x-=n;
	return x;
}
int transfer (int from,int temp,int to,int n)
{
	if (n>1)
	{
		transfer (from,to,temp,n-1);
			disky[n-1]=moveup(n,diskx[n-1],disky[n-1],disk_c[n-1]);
			l[from-1]++;
			if (to-from>0)
				diskx[n-1]=moveright(n,diskx[n-1],disky[n-1],to-from,disk_c[n-1]);
			else
				diskx[n-1]=moveleft(n,diskx[n-1],disky[n-1],from-to,disk_c[n-1]);
			disky[n-1]=movedown(n,diskx[n-1],disky[n-1],disk_c[n-1],l[to-1]);
			l[to-1]=disky[n-1]-1;
		transfer (temp,from,to,n-1);
	}
	else
	{
		disky[0]=moveup(1,diskx[0],disky[0],disk_c[0]);
		l[from-1]++;
		if (to-from<0)
			diskx[0]=moveleft(1,diskx[0],disky[0],from-to,disk_c[0]);
		else
			diskx[0]=moveright(1,diskx[0],disky[0],to-from,disk_c[0]);
		disky[0]=movedown(1,diskx[0],disky[0],disk_c[0],l[to-1]);
		l[to-1]=disky[0]-1;
	}
	return 0;
}

int main()
{
	int i,j=0,n,from=1,to=3,temp=2;
	diskx[0]=c1x;
	disky[0]=cy;
	l[2]=cy;
	l[1]=cy;
	drawcolumn();
	gotoxy(0,0);
	printf("please enter the number of disks\n");
	scanf("%d",&n);
	for (i=n-1;i>=0;i--)
	{
		drawdisk(i+1,diskx[i],disky[i],disk_c[i]);
		j++;
		diskx[i-1]=diskx[i];
		disky[i-1]=disky[i]-1;
	}
	gotoxy(0,27);
	printf("game will start in  ");
	Sleep(500);
	printf("3 ");
	Sleep(700);
	printf("2 ");
	Sleep(700);
	printf("1 ");
	Sleep(700);
	l[0]=disky[0]-1;
	transfer (from,temp,to,n);
	gotoxy(0,28);
    return 0;
}
