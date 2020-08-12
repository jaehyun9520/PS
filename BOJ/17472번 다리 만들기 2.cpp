#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int node[7];


struct state{
	int x;
	int y;
	int direct;
	int distance;
	state(int a , int b, int c, int d)
	{
		x=a;
		y=b;
		direct=c;
		distance=d;
	}
};


struct edge{   
	
	int a;
	int b;
	int val;
	
	edge(int x, int y, int z)
	{
		a=x;
		b=y;
		val=z;
	}
	
	bool operator <(const edge &b)
	const { return val<b.val;}
};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};


int find(int a)
{
	if(node[a]==a) return a;
	
	else return node[a]=find(node[a]);
}

void Union(int a, int b)
{
	a=find(a);
	b=find(b);
	
	if(a!=b)
	{ 
	    node[a]=b;
	}
}


int main()
{
//freopen("input.txt", "rt", stdin);
int n,m,i,j,x,y,xx,yy,k,cnt=0,dir,dis,a,b,val,result=0;
queue <state> Q;
vector <edge> E;
scanf("%d %d",&n,&m);
int map[n+1][m+1];
int check[n+1][m+1]={0};
vector < pair < int , int > > island;
for(i=1; i<=n; i++)
{
	for(j=1; j<=m; j++)
	{
		scanf("%d",&map[i][j]);
	}
}


for(i=1; i<=n; i++)   // 섬 번호 붙여주기  
{
	for(j=1; j<=m; j++)
	{
		if(map[i][j]==1&&check[i][j]==0)
		{
			check[i][j]=1;
			cnt++;
			map[i][j]=cnt;
			island.push_back(make_pair(i,j));
			Q.push(state(i,j,0,0));
			
			
			while(!Q.empty())
			{
				x=Q.front().x;
				y=Q.front().y;
				Q.pop();
				for(k=0; k<=3; k++)
				{
					xx=x+dx[k];
					yy=y+dy[k];
					
					if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&check[xx][yy]==0&&map[xx][yy]==1)
					{
						check[xx][yy]=1;
						map[xx][yy]=cnt;
						
						Q.push(state(xx,yy,0,0));
					}
				}
				
			}
			
			
		}
	}
}


for(i=0; i<island.size(); i++)  // 각 섬을 이어주는 다리를 찾기 
{	
	a=island[i].first;
	b=island[i].second;
	check[a][b]=0;
	Q.push(state(a,b,-1,0));
	
	while(!Q.empty())
	{
	
		x=Q.front().x;
		y=Q.front().y;
		dir=Q.front().direct;
		dis=Q.front().distance;
		Q.pop();
		
	
		if(dir==-1)
		{
			for(k=0; k<=3; k++)
			{
				xx=x+dx[k];
				yy=y+dy[k];
				
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
				{
						
					if(map[a][b]==map[xx][yy]&&check[xx][yy]==1)
					{
					
						check[xx][yy]=0;
						Q.push(state(xx,yy,-1,0));
					}
					else if(map[xx][yy]==0)
					{
					
						Q.push(state(xx,yy,k,dis+1));
					}
				}
			}
		}
		
		else {
			   xx=x+dx[dir];
			   yy=y+dy[dir];
			   
			   if(xx>=1&&xx<=n&&yy>=1&&yy<=m)
			   {
			   	
						
			   
			   	
			   	  if(map[xx][yy]==0)
			   	  {
			   	  	Q.push(state(xx,yy,dir,dis+1));
			   	 
			   	  
					 }
					
					 
					 else if(map[xx][yy]!=0&&map[xx][yy]!=map[a][b]&&dis>1)
					 { 
					 
					 	
					 	E.push_back(edge(map[a][b],map[xx][yy],dis));
					 }
			   }
			
		}
		
	}
}

sort(E.begin(),E.end());

for(i=1; i<=cnt; i++)  // 부모노드 초기화  
{
	node[i]=i;
}


for(i=0; i<E.size(); i++)
{
	a=E[i].a;
	b=E[i].b;
	val=E[i].val;
	
	
	if(find(a)!=find(b))
	{
		Union(a,b);
		result+=val;
		
	}
}

for(i=1; i<=cnt; i++)
{
	if(find(1)!=find(i))   //  모든섬이 같은 부모노드를 가지는지 확인  
	{
		printf("-1");
		exit(0);
	}
}

printf("%d",result);

return 0;

}

