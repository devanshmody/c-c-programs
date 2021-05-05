#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int lev=0;
void draw(int lev,int x1,int y1,int x5,int y5)
{
int x,y,x2,y2,x3,y3,x4,y4;
float cosan,sinan;
cosan=cos(45*3.14/180);
sinan=sin(45*3.14/180);
x2=(x1+x5)/2;
y2=(y1+y5)/2;
line(x1,y1,x2,y2);
if(lev==0)
{
line(x1,y1,x5,y5);
}
else
{
x3=(x5-x2)*cosan+(y2-y5)*sinan+x2;
y3=(x5-x2)*sinan+(y5-y2)*cosan+y2;
x4=(x5-x2)*cosan+(y5-y2)*sinan+x2;
y4=(x2-x5)*sinan+(y5-y2)*cosan+y2;
draw(lev-1,x2,y2,x3,y3);
draw(lev-1,x2,y2,x4,y4);
}
}
void main()
{
int gd=DETECT,gm;
clrscr();
printf("enter depth of recursion");
scanf("%d",&lev);
initgraph(&gd,&gm,"");
draw(lev,200,280,150,50);
draw(lev,200,280,250,50);
getch();
closegraph();
}
