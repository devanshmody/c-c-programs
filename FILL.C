#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void boundary(int x,int y,int b,int f)
{
if(getpixel(x,y)!=b&&getpixel(x,y)!=f)
{
putpixel(x,y,f);
delay(5);
boundary(x+1,y,b,f);
boundary(x,y+1,b,f);
boundary(x-1,y,b,f);
boundary(x,y-1,b,f);
boundary(x+1,y+1,b,f);
boundary(x-1,y-1,b,f);
boundary(x-1,y+1,b,f);
boundary(x+1,y-1,b,f);
}
}
void flood(int x,int y,int b,int f)
{
if(getpixel(x,y)==b)
{
putpixel(x,y,f);
delay(5);
flood(x+1,y,b,f);
flood(x-1,y,b,f);
flood(x,y+1,b,f);
flood(x,y-1,b,f);
flood(x+1,y+1,b,f);
flood(x-1,y-1,b,f);
flood(x-1,y+1,b,f);
flood(x+1,y-1,b,f);
}
}
void main()
{
int i,p[20],p1[20],j=0,n,x,y,x1,y1,gd=DETECT,gm;
clrscr();
initgraph(&gd,&gm,"");
printf("enter no of vertex");
scanf("%d",&n);
for(i=0;i<2*n+2;i+=2)
{
j++;
if(i<(2*n))
{
printf("enter x and y coordinates");
scanf("%d%d",&p[i],&p[i+1]);
p1[i]=p[i]+20;
p1[i+1]=p[i+1]+20;
}
else
{
p[i]=p[0];
p[i+1]=p[1];
p1[i]=p1[0];
p1[i+1]=p1[1];
}
}
drawpoly(n+1,p);
setcolor(6);
drawpoly(n+1,p1);
printf("enter the coordinate of seed point for flood");
scanf("%d%d",&x,&y);
flood(x,y,0,10);
printf("enter the coordinates of seed point for boundry");
scanf("%d%d",&x1,&y1);
boundary(x1,y1,6,4);
getch();
closegraph();
}

