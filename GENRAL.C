#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
float s1=0,s2=0,x,y,x1,y1,x2,y2,e,dx,dy,length;
int i,gd,gm,exc;
clrscr();
printf("enter for x1:");
scanf("%f",&x1);
printf("enter for y1:");
scanf("%f",&y1);
printf("enter for x2:");
scanf("%f",&x2);
printf("enter for y2:");
scanf("%f",&y2);
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"");
dx=abs(x2-x1);
dy=abs(y2-y1);
x=x1;
y=y1;
s1=sin(dx);
s2=sin(dy);
if(dy>dx)
{
dx=dy;
exc=1;
}
else
{
dy=dx;
exc=0;
}
e=2*dy-dx;
i=1;
do
{
putpixel(x,y,15);
while(e>=0)
{
if(exc==1)
{
x=x+s1;
}
else
{
y=y+s2;
}
e=e-2*dx;
}
while(e<0)
{
if(exc==1)
{
y=y+s2;
}
else
{
x=x+s1;
}
e=e+2*dy;
}
i=i+1;
}
while(i<=dx);
getch();
closegraph();
}


