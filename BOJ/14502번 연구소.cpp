#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>



using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int max1=-1232323;
int n,m;
int map[9][9]={};
int test[9][9]={};

queue < pair < int , int > > Q;

void DFS(int x,int y,int cnt)
{
	int i,j,nowx,nowy,nextx,nexty,count;
	if(cnt==3)
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				test[i][j]=map[i][j];				
			}
		}		
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
			   if(test[i][j]==2)
			   {
			   	 Q.push(make_pair(i,j));			   	
			   }
				
			}
		}
		
		while(!Q.empty())
		{
			nowx=Q.front().first;
			nowy=Q.front().second;
			Q.pop();
			for(i=0; i<=3; i++)
			{
			      nextx=nowx+dx[i];
				  nexty=nowy+dy[i];
				
				if(nextx>=0&&nextx<n&&nexty>=0&&nexty<m)
				{
				    
				  if(test[nextx][nexty]==0)
				  {
				  	     test[nextx][nexty]=2;
				  	     Q.push(make_pair(nextx,nexty));
					  }	
				}
			}
		}
		   
		   count=0;
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(test[i][j]==0)
				{
					count++;
				}
			}
		}
		
		if(max1<count)
		{
			max1=count;
		}
		
		
		
		
	}
	
	else{
		
			for( j=y+1; j<m; j++)
			{
				if(map[x][j]==0)
				{
					map[x][j]=1;
					DFS(x,j,cnt+1);
					map[x][j]=0;
				}
			}
			
			
			for(i=x+1; i<n; i++)
			{
				for(j=0 ;j<m; j++)
				{
					if(map[i][j]==0)
					{
						map[i][j]=1;
						DFS(i,j,cnt+1);
						map[i][j]=0;
					}
				}
			}
		}
	}
	




int main()
{
//freopen("input.txt", "rt", stdin);
int i,j;
scanf("%d %d",&n,&m);





for(i=0; i<n; i++)
{
	for(j=0; j<m; j++)
	{
		scanf("%d",&map[i][j]);
		
	}
	
}


for(i=0; i<n; i++)
{
	for(j=0; j<m; j++)
	{
		if(map[i][j]==0)
		{
			
			map[i][j]=1;
			
			DFS(i,j,1);
			
			map[i][j]=0;
		}
	}
}

printf("%d",max1);
return 0;
}
