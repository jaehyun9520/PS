#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

queue <pair < int , int > > Q;
int map[101][101]={0};
int check[101][101]={0};

int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
int main()
{
//freopen("input.txt", "rt", stdin);
int n,m,i,j,a,b,cnt=0,k,tmpx=0,tmpy=0;

while(1)
{
cnt=0;
scanf("%d %d",&n,&m);
if(n==0&&m==0)
exit(0);

for(i=1; i<=m; i++)
{
	for(j=1; j<=n; j++)
	{
		
		scanf("%d",&map[i][j]);
		check[i][j]=0;
	}
}


for(i=1; i<=m; i++)
{
	for(j=1; j<=n; j++)
	{
		if(check[i][j]==0&&map[i][j]==1)
		{
			Q.push(make_pair(i,j));
			check[i][j]=1;
			cnt++;
			
			while(!Q.empty())
			{
				a=Q.front().first;
				b=Q.front().second;
				
				Q.pop();
				for(k=0; k<=7; k++)
				{
					tmpx=a+dx[k];
					tmpy=b+dy[k];
					
				   if(tmpx<0&&tmpx>m&&tmpy<0&&tmpy>n) continue;	
					if(map[tmpx][tmpy]==1&&check[tmpx][tmpy]==0)
					{
						check[tmpx][tmpy]=1;
						Q.push(make_pair(tmpx,tmpy));
					}
				}
			}
		}
	}
}


printf("%d \n",cnt);

}
return 0;
}
