#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;


int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct state{
	
	int x;
	int y;
	int time;
	
	state(int a, int b , int c)
	{
		x=a;
		y=b;
		time=c;
	}
};

int n,m,min1=99999999;
int map[51][51]={0};
int check[51][51]={0};
 queue <state> Q;

void DFS(int cnt, int x, int y )  // cnt= 활성화 시킨 바이러스의 개수 , 2차원 배열 좌표 x y 
{
	
	int i,j,xx,yy,nx,ny,time,time1=0,count=0;
	if(cnt==m)  // m개만큼 뽑은경우 모든 빈칸에 몇초만에 퍼트리는지 확인 
	{
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				check[i][j]=map[i][j];
				if(map[i][j]=='*')
				{
					Q.push(state(i,j,0));
				}
				
				if(map[i][j]==0)
				{
					count++;
				}
			}
		}

		while(!Q.empty())
		{

			xx=Q.front().x;
			yy=Q.front().y;
			time=Q.front().time;
			Q.pop();
			
			for(int i=0; i<=3; i++)
			{
				nx=xx+dx[i];
				ny=yy+dy[i];
				
				if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
				{
					if(check[nx][ny]==0)
					{
						count--;
						check[nx][ny]=time+1;
						Q.push(state(nx,ny,time+1));
						time1=time+1;
					}
					
					if(check[nx][ny]=='-')
					{
						check[nx][ny]=time+1;
						Q.push(state(nx,ny,time+1));
					}
					
					
				}
			}
		
		}
		
		if(count==0)  // 최소값 구하기  
			{
				if(min1>time1)
			    {
			    	min1=time1;
				}
			}
		
		
	}
	
	
	else if(cnt<m)  // 바이러스의 개수 중 m개만큼 뽑기 ( 경우의 수) 
	{
		for(j=y+1; j<=n; j++)
		{
			if(map[x][j]=='-')
			{
				map[x][j]='*';
				DFS(cnt+1,x,j);
				map[x][j]='-';
				
			}
		}
		
		for(i=x+1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(map[i][j]=='-')
			   {
			   
			   	    map[i][j]='*';
			   	    DFS(cnt+1,i,j);
			   	    map[i][j]='-';
				   }	
			
			}
		}
		
	}
	
	
	
}



int main()
{
//freopen("input.txt", "rt", stdin);

int i,j,a;
scanf("%d %d",&n,&m);

for(i=1; i<=n; i++) 
{
	for(j=1; j<=n; j++)
	{
		
		scanf("%d",&a);
		if(a==1)
		{
			map[i][j]=-1;
		}
		
		else if(a==2)
		{
			map[i][j]='-';
		}
		
		else if(a==0)
		{
			map[i][j]=0;
		}
	}
}

DFS(0,1,0);


if(min1==99999999)
{
	printf("-1");
}

else
printf("%d",min1);


return 0;


}
