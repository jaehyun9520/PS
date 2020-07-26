#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int hx[8]={-2,-1,-2,-1,1,2,1,2};
int hy[8]={-1,-2,1,2,-2,-1,2,1};
struct state{
	int x;
	int y;
	int count;
	int flag;
	
	
	state(int a, int b, int c, int d)
	{
		x=a;
		y=b;
		count=c;
		flag=d;
	}
};
int main()
{
//freopen("input.txt", "rt", stdin);
int w,h,i,j,k,x,y,xx,yy,count,flag;
scanf("%d",&k);
scanf("%d %d",&w,&h);

queue <state> Q;
int map[h+1][w+1]={0};
int check[h+1][w+1]={0};

memset(check,-1,sizeof(check));
for(i=1; i<=h; i++)
{
	for(j=1; j<=w; j++)
	{
		scanf("%d",&map[i][j]);
	}
}


Q.push(state(1,1,0,k));



while(!Q.empty())
{
	x=Q.front().x;
	y=Q.front().y;
	count=Q.front().count;
	flag=Q.front().flag;
	
	Q.pop();
	
	if(x==h&&y==w)
	{
		printf("%d",count);
		exit(0);
	}
	
	for(i=0; i<=3; i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		
		if(xx>=1&&xx<=h&&yy>=1&&yy<=w)
		{
		    if(check[xx][yy]<flag&&map[xx][yy]==0)
		    {
		    	check[xx][yy]=flag;
		    	Q.push(state(xx,yy,count+1,flag));
		    	
		    	if(xx==h&&yy==w)
			{
				printf("%d",count+1);
				exit(0);
			}
		    	
			}
			
			
		}
	}
	if(flag>=1)
	{
	
	for(i=0; i<=7; i++)
	{
		xx=x+hx[i];
		yy=y+hy[i];
		
	if(xx>=1&&xx<=h&&yy>=1&&yy<=w)
		{
			if(check[xx][yy]<flag-1&&map[xx][yy]==0)
			{
				check[xx][yy]=flag-1;
				Q.push(state(xx,yy,count+1,flag-1));
				
				if(xx==h&&yy==w)
				{
					printf("%d",count+1);
					exit(0);
				}
			}
			
	}
		
	}
}

}

printf("-1");
return 0;
}
