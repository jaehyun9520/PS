#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
int dx[8]={-1,-2,-2,-1,1,2,2,1};
int dy[8]={-2,-1,1,2,-2,-1,1,2};

struct state{
	int x;
	int y;
	int cnt;
	
	state(int a, int b, int c)
	{
		x=a;
		y=b;
		cnt=c;
	}
};

using namespace std;

int main()
{
//freopen("input.txt", "rt", stdin);
int i,j,t,k,a,b,c,d,cnt,x,y,nx,ny,flag=0;
int map[300][300]={0};
int check[300][300]={0};
queue < state > Q;
vector < pair < int , int > > move;

scanf("%d",&t);

for(k=1; k<=t; k++)  // 테스트 케이스가 몇개인지  
{
	cnt=0;  
	scanf("%d",&i);  // 맵의 크기  
	scanf("%d %d",&a,&b);  // 나이트의 현재위치  
	Q.push(state(a,b,0));
	move.push_back(make_pair(a,b));
	check[a][b]=1;
	
	scanf("%d %d",&c,&d); // 목표위치  
	
	if(a==c&&b==d)  // 위치가 같은지  
	{
		printf("0\n");
	}
	
	
	else{
	
	flag=0;  
	while(!Q.empty()&&flag==0)  // BFS 
	{
		
		x=Q.front().x;
		y=Q.front().y;
		cnt=Q.front().cnt;
		
	
	
		Q.pop();
		
		for(j=0; j<=7; j++)  
		{
			nx=x+dx[j];
			ny=y+dy[j];
			
			if(nx>=0&&nx<=i-1&&ny>=0&&ny<=i-1&&check[nx][ny]==0)
			{
				
				
				check[nx][ny]=1;
				move.push_back(make_pair(nx,ny));
				if(nx==c&&ny==d)  // 목표위치에 도달하면 중단  
				{ 
				     flag=1;
					printf("%d\n",cnt+1);
				}
				else
				{
					
					Q.push(state(nx,ny,cnt+1));
				}
			}
				
			
			
		}
		
	
	}
}

while(!Q.empty())
{
	Q.pop();
}
		while(!move.empty())
		{
			x= move.back().first;
			y=move.back().second;
			
			check[x][y]=0;
			move.pop_back();
		}
}

return 0;
}

