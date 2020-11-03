#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int R,C,T,upx,upy,downx,downy;  
int map[51][51]={0};
int map2[51][51]={0};
queue <pair <int, int > > ap; // 미세먼지 위치를 담는 큐  


int main()
{
//freopen("input.txt", "rt", stdin);	
scanf("%d %d %d",&R,&C,&T);
int i,j,flag=0,cnt=0,x,y,xx,yy,val,ans=0;

for(i=1; i<=R; i++)
{
	for(j=1; j<=C; j++)
	{
		scanf("%d",&map[i][j]);
		map2[i][j]=map[i][j];
		if(map[i][j]>0)  ap.push(make_pair(i,j));
		
		else if(map[i][j]==-1)
		{
			if(flag==0) 
			{
			upx=i; upy=j; flag++;
		}
			
			else if(flag==1)
			{
			
			downx=i; downy=j; 
		}
		}
			}
}

while(1)
{
	cnt++;
	
	if(cnt>T) break;
	
	
	while(!ap.empty())  // 미세먼지 확산  
	{
		flag=0;
		x=ap.front().first;
		y=ap.front().second;
		val=map[x][y]/5;
		ap.pop();
		
		
		for(i=0; i<=3; i++)
		{
			xx=x+dx[i];
			yy=y+dy[i];
			
			if(xx>=1&&xx<=R&&yy>=1&&yy<=C&&map[xx][yy]!=-1)
			{
				flag++;
				map2[xx][yy]+=val;
			}
		}
		
		val=val*flag;  map2[x][y]-=val;
	}

   for(i=upx-1; i>=2 ;i--)  //위쪽 공기청정기 작동  
	{
			map2[i][1]=map2[i-1][1];
			
		 
	}
	
	for(j=1; j<=C-1; j++)
	{
		
		map2[1][j]=map2[1][j+1];
		
	}
	
	for(i=1; i<=upx-1; i++)
	{
		map2[i][C]=map2[i+1][C];
	}
	
	for(j=C; j>=3; j--)
{
	
	  map2[upx][j]=map2[upx][j-1];
	  
}
map2[upx][j]=0;



for(i=downx+1; i<=R-1; i++)  //아래쪽 공기청정기 작동  
{	
	map2[i][1]=map2[i+1][1];	
}
	
for(j=1; j<=C-1; j++)
{
	
map2[R][j]=map2[R][j+1];
			
	}	
	
for(i=R; i>=downx+1; i--)
{	
	map2[i][C]=map2[i-1][C];	
	}
	
for(j=C; j>=3; j--)
{
	map2[downx][j]=map2[downx][j-1];
	
		}		
	
	map2[downx][j]=0;



for(i=1; i<=R; i++)  // 미세먼지 확산을 위해 넣어주기  
{
	for(j=1; j<=C; j++)
	{
		map[i][j]=map2[i][j];
		if(map[i][j]>0)  ap.push(make_pair(i,j));
	}
	}	
}

while(!ap.empty())   
{
	
	ans+=map[ap.front().first][ap.front().second];
	ap.pop();
}

printf("%d",ans);
return 0;
}
