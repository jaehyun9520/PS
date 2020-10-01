#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
	int dx[4]={1,-1,0,0};
	int dy[4]={0,0,1,-1};
	
	struct state{
		
		int x;
		int y;
		int dis;
		int cnt;
		
		state(int a, int b, int c, int d)
		{
			x=a;
			y=b;
			dis=c;
			cnt=d;
		}
	};
	

			
int main()
{
	

	
//freopen("input.txt", "rt", stdin);
int map[51][51]={0};
int check[64][51][51]={0};  
queue <state> Q;
int i,j,n,m,ans=0,x,y,xx,yy,cnt,dis;
char a[51];
scanf("%d %d",&n,&m);

for(i=1; i<=m; i++)
{
	scanf("%s",a);
	
	for(j=1; j<=n; j++)
	{
		map[i][j]=a[j-1];
		
		if(map[i][j]=='X')  // 물건일 경우 임의로 번호 부여  물건이 5개까지 있을수있으니 최대 5번까지  
		{
			map[i][j]=++ans;
		}
		if(map[i][j]=='S')   // 현재위치  
		{
			map[i][j]='.';
			check[0][i][j]=1;
			Q.push(state(i,j,0,0));
		}
	}
}

ans=(1<<ans)-1;


while(!Q.empty())
{
	x=Q.front().x;
	y=Q.front().y;
	dis=Q.front().dis;
	cnt=Q.front().cnt;  // 물건 보유 현황 최대 5가지  
	Q.pop();

	for(i=0; i<=3; i++)
	{
		xx=x+dx[i];
		yy=y+dy[i];
		
		if(xx>=1&&xx<=m&&yy>=1&&yy<=n)
		{
			if(map[xx][yy]=='.'&&check[cnt][xx][yy]==0)  // 빈곳일 경우  
			{
				check[cnt][xx][yy]=1;
				Q.push(state(xx,yy,dis+1,cnt));
			}
			
			else if(1<=map[xx][yy]&&map[xx][yy]<=5&&check[cnt][xx][yy]==0) // 물건이 있을경우  
			{
				if((cnt&1<<(map[xx][yy]-1))==0)  // 새로운 물건인지? 
				{
				
					check[cnt][xx][yy]=1;
					Q.push(state(xx,yy,dis+1,cnt|(1<<(map[xx][yy]-1)))); //물건보유현황 갱신 후 큐에 넣어줌  
				}
				
				else {
					check[cnt][xx][yy]=1;      // 새로운 물건이 아닐경우 그냥 지나감  
					Q.push(state(xx,yy,dis+1,cnt));
				}
			}
			
			else if(map[xx][yy]=='E'&&cnt==ans) // 탈출구를 발견했고 현재 물건을 모두 다 보유했으면 탈출  
			{
				printf("%d",dis+1);
				exit(0);
			}
			
		}
	}
	
}
return 0;
}
