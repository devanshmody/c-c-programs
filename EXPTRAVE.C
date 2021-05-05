#include<stdio.h>
#include<conio.h>
int c[10][10],v[10],n,cost=0;
void travelling(int city)
{
int i,ncity;
v[city]=1;
printf("%d--->",city+1);
ncity=least(city);
if(ncity==999)
{
ncity=0;
printf("%d",ncity+1);
cost+=c[city][ncity];
return;
}
travelling(ncity);
}
int least(int a)
{
int i,nc=999;
int min=999,kmin;
for(i=0;i<n;i++)
{
if((c[a][i]!=0)&&(v[i]==0))
{
if(c[a][i]<min)
{
min=c[i][0]+c[a][i];
kmin=c[a][i];
nc=i;
}
}
}
if(min!=999)
cost+=kmin;
return nc;
}
void main()
{
int i,j;
clrscr();
printf("enter no of cities");
scanf("%d",&n);
printf("enter cost matrix\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&c[i][j]);
}
}
printf("\ncost matrix\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",c[i][j]);
}
printf("\n");
}
printf("path");
travelling(0);
printf("minimum cost");
printf("cost%d",cost);
getch();
}
