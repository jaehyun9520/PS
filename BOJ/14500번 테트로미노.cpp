#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int map[501][501]={};
int check[501][501]={};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m, ans=0;

void DFS(int x, int y, int cnt, int sum,int k)
{int xx,yy;
	if(cnt==4)
	{
		if(ans<sum)
		{
			ans=sum;
		}
	}
	
	
	else
	{
		for(int i=0; i<=3; i++)
		{
			
			xx=x+dx[i];
			yy=y+dy[i];
		

					
			
			
			if(xx>=1&&xx<=n&&yy>=1&&y<=m)
			{
			
				if(check[xx][yy]==0&&k==0)
				{    
			
		                  
					check[xx][yy]=1;
						DFS(xx,yy,cnt+1,sum+map[xx][yy],k);
					
					
					check[xx][yy]=0;
				}
				else if(check[xx][yy]==0&&k==1)
				{    
			
		                  
					check[xx][yy]=1;
						DFS(x,y,cnt+1,sum+map[xx][yy],k);
					
					
					check[xx][yy]=0;
				}
			}
			
		}
	}
}





int main()
{
//freopen("input.txt", "rt", stdin);
int i,j,sum=0;
scanf("%d %d",&n,&m);




for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{
		scanf("%d",&map[i][j]);
		
	}
}
for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{     
	      check[i][j]=1;  
		 DFS(i,j,1,map[i][j],0); 
		 DFS(i,j,1,map[i][j],1); 
		
		
		 check[i][j]=0;   
	}
}

	printf("%d",ans);

return 0;
}
