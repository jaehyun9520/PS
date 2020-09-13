#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

struct state{
	
	int x;
	int y;
	int dis;
	
	state(int a, int b, int c)
	{
		x=a;
		y=b;
		dis=c;
	}
};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
 
vector < pair <int , int > > used;
int map[51][51]={0};
int check[51][51]={0};	
queue < state > Q;	
	


int main()
{
//freopen("input.txt", "rt", stdin);

int n,m,i,j,cnt=0,x,y,nx,ny,k,dis,answer=-1;
char a[51];
scanf("%d %d",&n,&m);

for(i=1; i<=n; i++)  
{
	scanf("%s",a);
	for(j=1; j<=m; j++)
	{
		map[i][j]=a[j-1];
	}
	
}

for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{
		if(map[i][j]=='L')  //  육지일때마다 시작점으로 지정해서 BFS 
		{ cnt++;
	
		      check[i][j]=1;
			Q.push(state(i,j,0));
			
			
				while(!Q.empty())
		{
			x=Q.front().x;
			y=Q.front().y;
			dis=Q.front().dis;
			used.push_back(make_pair(x,y));
		

		
			Q.pop();
			for(k=0; k<=3; k++)
			{
				nx=x+dx[k];
				ny=y+dy[k];
				
				if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
				{
					
					if(map[nx][ny]=='L'&&check[nx][ny]==0)
					{
						
						check[nx][ny]=1;
						Q.push(state(nx,ny,dis+1));
					}
				}
			}
			
		
		}
		
			while(!used.empty())
			{
				check[used.back().first][used.back().second]=0;
				used.pop_back();
			}
		
		if(dis>answer)  // 가장 오래 걸리는 시간 갱신  
		{
			answer=dis;
		}
		}
	
	}
}
printf("%d",answer);
return 0;


}
