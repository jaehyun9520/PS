#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int dx[4]={0,0,1,1};
int dy[4]={0,1,0,1};
int n,ans=0;
int map[17][17]={0};


void DFS(int type, int x, int y)  
{
	int xx,yy,i,cnt=0;
	
		
	if(x==n&&y==n)  // n n 에 도달하면 방법의 수 추가  
	{
		ans++;
	}
	
	
else {

	for(i=1; i<=3; i++)  // 오른쪽 , 밑쪽,  오른쪽 대각선 밑쪽  
	{
		
		xx=x+dx[i];
		yy=y+dy[i];
		
		if(xx<=n&&yy<=n)
		{
			
			if(map[xx][yy]==0)
			{  cnt++;
			
				if(i==1)  
				{
					if(type==1)  //현재 파이프의 방향 가로 
					{
					
					map[xx][yy]=2;
					map[x][y-1]=0; 
				    DFS(type,xx,yy);	
				    map[xx][yy]=0;
					map[x][y-1]=2;
				}
				 
				   if(type==3)    // 현재 파이프의 방향 대각선   
				   {
				   	map[xx][yy]=2;
					map[x-1][y-1]=0; 
				    DFS(1,xx,yy);	
				    map[xx][yy]=0;
					map[x-1][y-1]=2;
				   }
				
				 }
				 
				 else if(i==2)
				 {
				 	if(type==2)  //현재 파이프의 방향 세로  
				 	{
				 		map[xx][yy]=2;
				 		map[x-1][y]=0;
				 		DFS(type,xx,yy);
				 		map[xx][yy]=0;
				 		map[x-1][y]=2;
				 		
					 }
					 
					 else if(type==3)
					 {
					 	map[xx][yy]=2;
					  map[x-1][y-1]=0; 
				       DFS(2,xx,yy);	
				      map[xx][yy]=0;
					   map[x-1][y-1]=2;
					 	
					 }
				 	
				  } 
				 
				 
			}
		}
		
	}
	
	
	if(cnt==3)   // 밑쪽 오른쪽 , 오른쪽 대각선 밑쪽 모두 비어있는경우  
	{
		if(type==1)
		{
			map[xx][yy]=2;
					map[x][y-1]=0; 
				    DFS(3,xx,yy);	
				    map[xx][yy]=0;
					map[x][y-1]=2;
		}
		
		else if(type==2)
		{	
		map[xx][yy]=2;
		map[x-1][y]=0;
		DFS(3,xx,yy);
		map[xx][yy]=0;
		map[x-1][y]=2;
				 		
			
		}
		
		else if(type==3)
		{
				map[xx][yy]=2;
					  map[x-1][y-1]=0; 
				       DFS(3,xx,yy);	
				      map[xx][yy]=0;
					   map[x-1][y-1]=2;
		}
	}
	
}
	
	
	
}

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j;

scanf("%d",&n);

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		scanf("%d",&map[i][j]);
	}
}
map[1][1]=2;     
map[1][2]=2;  //파이프 초기위치  

DFS(1,1,2); // 1: 초기방향 (가로)    (1,2) 파이프 위치  

printf("%d",ans);
return 0;
}
