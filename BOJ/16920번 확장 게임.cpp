#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct state{   
	int x;
	int y;  
	int cnt;  
	
	state(int a, int b, int c)
	{
		x=a; y=b;  cnt=c;
	}
}; 

int map[1001][1001]={0}; 
int check[1001][1001]={0};  
int n,m,p,i,j,x,y,xx,yy,max1=0,cnt,flag=1;
queue <state> Q; 
int player[10];  
vector < pair < int , int > > tmp[10];  
char a[1001];                        
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int ans[10]={0};  // 답  

int main()
{	
//freopen("input.txt", "rt", stdin);

scanf("%d %d %d",&n,&m,&p);

for(i=1; i<=p; i++)
{
	scanf("%d",&player[i]);  
}

for(i=1; i<=n; i++)
{
	scanf("%s",a);
	for(j=1; j<=m; j++)
	{
		if(a[j-1]>='1'&&a[j-1]<='9')
		{
			map[i][j]=a[j-1]-48;
			ans[map[i][j]]++;
			tmp[map[i][j]].push_back(make_pair(i,j));
		}
		
		else {
			map[i][j]=a[j-1];
		}
	}
}
while(flag)
{
flag=0;
for(i=1; i<=p; i++)  
{

	while(!tmp[i].empty())  // 각 플레이어가 가진 성의 위치 
	{
		x=tmp[i].back().first;
		y=tmp[i].back().second;
		Q.push(state(x,y,0));
		tmp[i].pop_back();
		max1=player[i];	  // 각 플레이의 이동 최대치  
	}

	while(!Q.empty())
	{
		x=Q.front().x;
		y=Q.front().y;
		cnt=Q.front().cnt;
		Q.pop();
		if(max1>cnt)  //최대치까지 퍼트려주기  
		{
		for(j=0; j<=3; j++)
		{
			xx=x+dx[j];
			yy=y+dy[j];
			     if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
			     {
			     	if(map[xx][yy]=='.'&&check[xx][yy]==0)
			     	{
			     		flag=1;
			     		map[xx][yy]=i;
			     		check[xx][yy]=1;
			     		ans[i]++;
			     		tmp[i].push_back(make_pair(xx,yy));
			     		Q.push(state(xx,yy,cnt+1));		
					 }				
				 }
		}
	}
	}
	
}
}

for(i=1; i<=p; i++)
{
	printf("%d ",ans[i]);
}

return 0;
}
