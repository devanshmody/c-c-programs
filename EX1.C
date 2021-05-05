#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main()
{
float a[3][3],b[3][3],c[3][3],d[4][3],i,j,k,x1,y1,x2,y2,x3,y3,theta;
int choice,gd,gm;
clrscr();
printf("enter choice\n");
printf("1-translation\t2-rotation\t3-scaling\t4-shearing\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("enter input matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
scanf("%f",&a[i][j]);
}
}
printf("input matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%f\t",a[i][j]);
}
printf("\n");
}
printf("enter translation matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
scanf("%f",&b[i][j]);
}
}
printf("translation matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%f\t",b[i][j]);
}
printf("\n");
}
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{
	c[i][j]=0;
	for(k=0;k<3;k++)
	{
	c[i][j]+=(a[i][k]*b[k][j]);
	}
	}
	}
printf("output matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%f\t",c[i][j]);
}
printf("\n");
}
getch();
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"");
line(a[0][0],a[0][1],a[1][0],a[1][1]);
line(a[1][0],a[1][1],a[2][0],a[2][1]);
line(a[2][0],a[2][1],a[0][0],a[0][1]);
line(c[0][0],c[0][1],c[1][0],c[1][1]);
line(c[1][0],c[1][1],c[2][0],c[2][1]);
line(c[2][0],c[2][1],c[0][0],c[0][1]);
break;
case 2:
printf("enter input matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
scanf("%f",&a[i][j]);
}
}
printf("input matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%f\t",a[i][j]);
}
printf("\n");
}
printf("enter value of theta:");
scanf("%f",&theta);
b[0][0]=cos(theta);
b[0][1]=sin(theta);
b[0][2]=0;
b[1][0]=-sin(theta);
b[1][1]=cos(theta);
b[1][2]=0;
b[2][0]=0;
b[2][1]=0;
b[2][2]=1;
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{
	c[i][j]=0;
	for(k=0;k<3;k++)
	{
	c[i][j]+=(a[i][k]*b[k][j]);
	}
	}
	}
printf("output matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%f\t",c[i][j]);
}
printf("\n");
}
getch();
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"");
line(a[0][0],a[0][1],a[1][0],a[1][1]);
line(a[1][0],a[1][1],a[2][0],a[2][1]);
line(a[2][0],a[2][1],a[0][0],a[0][1]);
line(c[0][0],c[0][1],c[1][0],c[1][1]);
line(c[1][0],c[1][1],c[2][0],c[2][1]);
line(c[2][0],c[2][1],c[0][0],c[0][1]);
break;
case 3:
printf("enter input matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
scanf("%f",&a[i][j]);
}
}
printf("input matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%f\t",a[i][j]);
}
printf("\n");
}
printf("enter scaling matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
scanf("%f",&b[i][j]);
}
}
printf("scaling matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%f\t",b[i][j]);
}
printf("\n");
}
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{
	c[i][j]=0;
	for(k=0;k<3;k++)
	{
	c[i][j]+=(a[i][k]*b[k][j]);
	}
	}
	}
printf("output matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%f\t",c[i][j]);
}
printf("\n");
}
getch();
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"");
line(a[0][0],a[0][1],a[1][0],a[1][1]);
line(a[1][0],a[1][1],a[2][0],a[2][1]);
line(a[2][0],a[2][1],a[0][0],a[0][1]);
line(c[0][0],c[0][1],c[1][0],c[1][1]);
line(c[1][0],c[1][1],c[2][0],c[2][1]);
line(c[2][0],c[2][1],c[0][0],c[0][1]);
break;
case 4:
printf("enter input matrix:\n");
for(i=0;i<4;i++)
{
for(j=0;j<3;j++)
{
scanf("%f",&d[i][j]);
}
}
printf("input matrix:\n");
for(i=0;i<4;i++)
{
for(j=0;j<3;j++)
{
printf("%f\t",d[i][j]);
}
printf("\n");
}
printf("enter shearing matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
scanf("%f",&b[i][j]);
}
}
printf("shearing matrix:\n");
for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%f\t",b[i][j]);
}
printf("\n");
}
for(i=0;i<3;i++)
{
	for(j=0;j<4;j++)
	{
	c[i][j]=0;
	for(k=0;k<3;k++)
	{
	c[i][j]+=(d[i][k]*b[k][j]);
	}
	}
	}
printf("output matrix:\n");
for(i=0;i<4;i++)
{
for(j=0;j<3;j++)
{
printf("%f\t",c[i][j]);
}
printf("\n");
}
getch();
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"");
line(d[0][0],d[0][1],d[1][0],d[1][1]);
line(d[1][0],d[1][1],d[2][0],d[2][1]);
line(d[2][0],d[2][1],d[3][0],d[3][1]);
line(d[3][0],d[3][1],d[0][0],d[0][1]);
line(c[0][0],c[0][1],c[1][0],c[1][1]);
line(c[1][0],c[1][1],c[2][0],c[2][1]);
line(c[2][0],c[2][1],c[3][0],c[3][1]);
line(c[3][0],c[3][1],c[0][0],c[0][1]);
break;
}
getch();
closegraph();
}
