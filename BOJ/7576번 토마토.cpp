#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int map[1001][1001]={0};
int check[1001][1001]={0};
queue < pair < int , int > > Q;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main()
{
//freopen("input.txt", "rt", stdin);
int n, m, i, j,flag=0,xx,yy,a,b,val;
scanf("%d %d",&n,&m);

for(i=1; i<=m; i++)
{
	for(j=1; j<=n; j++)
	{
		scanf("%d",&map[i][j]);
		
		if(map[i][j]==1)
		{
			Q.push(make_pair(i,j));
		}
		
		if(map[i][j]==0)
		{
			flag=1;
		}
	}
 } 
 
 if(flag==0)
 {
 	printf("0");
 	exit(0);
 }
 
 
while(!Q.empty())
{
	xx=Q.front().first;
	yy=Q.front().second;
	
	
	Q.pop();
	for(i=0; i<=3; i++)
	{
		a=xx+dx[i];
		b=yy+dy[i];
		
		if(a>=1&&a<=m&&b>=1&&b<=n)
		{
			if(map[a][b]==0)
			{
				map[a][b]=1;
				Q.push(make_pair(a,b));
				check[a][b]=check[xx][yy]+1;
				
				val=check[a][b];
			}
		}
	}
}
 
 for(i=1; i<=m; i++)
 {
 	for(j=1; j<=n; j++)
 	{
 		if(map[i][j]==0)
 		{
		 
 		printf("-1");
 		exit(0);
 	}
	 }
 }
 
 printf("%d",val);
return 0;
}
