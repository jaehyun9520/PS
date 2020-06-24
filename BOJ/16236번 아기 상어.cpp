#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>



using namespace std;
int map[21][21]={0};
int check[21][21]={0};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct shark{
	int x;
	int y;
	int level;
	int exp;    
};

struct state {
	int x;
	int y;
	int dis;
	
	state(int a, int b , int c)
	{
		x=a;
		y=b;
		dis=c;
	}
	
	bool operator <(const state &b) const
	{  if(dis==b.dis)
	{
		    if(x==b.x)
		    {
		    	return y > b.y;
			}
			else
			{
				return x >b.x;
			}
	}
	else
	      return dis>b.dis;
	}
};


int main()
{
	freopen("input.txt", "rt", stdin);
int n,i,j,x=0,y=0,dis=0,xx=0,yy=0,cnt=0,result=0;
shark s1;
priority_queue <state> PQ;
scanf("%d" ,&n);

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		scanf("%d",&map[i][j]);
		
		if(map[i][j]==9)
		{
			s1.x=i;
			s1.y=j;
			s1.level=2;
			s1.exp=0;
			PQ.push(state(i,j,0));
			map[i][j]=0;
			check[i][j]=1;
		}
		if(map[i][j]!=0&&map[i][j]!=9)
		{
			cnt++;
		}
	}
}

if(cnt==0)
{
	printf("0");
	exit(0);
}

while(!PQ.empty())
{
	x= PQ.top().x;
	y= PQ.top().y;
	dis=PQ.top().dis;
	
	PQ.pop();	
	if(map[x][y]!=0&&map[x][y]<s1.level)
	{
		
		cnt--;
		result=dis;
		if(cnt==0)
		{
			printf("%d",result);
			exit(0);
		}
		s1.x=x;
		s1.y=y;
		
		s1.exp++;
		if(s1.exp==s1.level)
		{
			s1.exp=0;
			s1.level++;
		}
		map[x][y]=0;
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				check[i][j]=0;
			}
		}
		check[x][y]=1;
		
		while(!PQ.empty())
        {PQ.pop();
				}
				
				PQ.push(state(s1.x,s1.y,dis));		
	}
	
	
	else {
	
	
for(i=0; i<=3; i++)
{
	 xx=x+dx[i];
	 yy=y+dy[i];
	 
	 if(xx>0&&yy>0&&xx<=n&&yy<=n&&map[xx][yy]<=s1.level&&check[xx][yy]==0)
	 {
	 	check[xx][yy]=1;
	 	PQ.push(state(xx,yy,dis+1));
	 }
	}	
	
}
}
printf("%d",result);
return 0;
}
