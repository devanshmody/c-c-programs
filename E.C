

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{

   int  gd,gm,X,Y;
   int midx, midy;
   int stangle = 0, endangle = 360;
   clrscr();
   printf("enter x radius",X);
   scanf("%d",&X);
   printf("enter Y radius",Y);
   scanf("%d",&Y);
   detectgraph(&gd,&gm);
   initgraph(&gd, &gm, "");
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   setcolor(getmaxcolor());
   ellipse(midx, midy, stangle, endangle,
	   X, Y);
   getch();
   closegraph();
   return 0;
}
