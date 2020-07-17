#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

int n,m;
int map[301][301]={0};
int test[301][301]={0};
int check[301][301]={0};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void DFS(int x, int y)
{
	int xx,yy,cnt=0;
	
	
	for(int i=0; i<=3; i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		
		
		if(map[xx][yy]==0)
		{
			cnt++;
		}
		
		else if(map[xx][yy]!=0&&check[xx][yy]==0)
		{
			check[xx][yy]=1;
			DFS(xx,yy);
		}
		
	}
	       test[x][y]=map[x][y]-cnt;
	       if(test[x][y]<0)
	       {
	       	  test[x][y]=0;
		   }
}



int main()
{
//freopen("input.txt", "rt", stdin);
int i,j,cnt=0,time=0,flag=0;
scanf("%d %d",&n,&m);

for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{
		scanf("%d",&map[i][j]);
		test[i][j]=map[i][j];
	}
}


while(1)
{
flag=0;
cnt=0;
for(i=1; i<=n; i++)     
{
	for(j=1; j<=m; j++)
	{
		if(map[i][j]!=0&&check[i][j]==0)
		{
			cnt++;
			check[i][j]=1;
			flag=1;
			DFS(i,j);
		}
	}
}



if(flag==0)
{
	printf("0");
	exit(0);
}

if(cnt>1)
{
	printf("%d",time);
	exit(0);
}
for(i=1; i<=n; i++)      
	{
		for(j=1; j<=m; j++)
		{
			check[i][j]=0;
			map[i][j]=test[i][j];
		}
	}
time++;

}
return 0;
}
