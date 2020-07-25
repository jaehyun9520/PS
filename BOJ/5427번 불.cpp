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
	int time;
	int what;
	
	state(int a, int b, int c, int d)
	{
		x=a;
		y=b;
		time=c;
		what=d;
		
	}
	
	
	
};

int main()
{
//freopen("input.txt", "rt", stdin);

int t=0,w=0,h=0,i=0,j=0,cnt=0,x=0,y=0,time=0,what=0,xx=0,yy=0,flag=0;
vector < vector < int > > map(1001, vector< int >(1001, 0));


scanf("%d",&t);
char a[1001];

queue <state> Q;
while(t!=cnt)
{
	flag=0;
	cnt++;
	scanf("%d %d",&w,&h);
	
	
	for(i=1; i<=h; i++)
	{
		scanf("%s",a);
		
		for(j=0; a[j]!='\0'; j++)
		{
			map[i][j+1]=a[j];
			
			if(a[j]=='@')
			{
				x=i;
				y=j+1;
			}
			
			if(a[j]=='*')
			{
				Q.push(state(i,j+1,0,1));
			}
		}
	}
	          Q.push(state(x,y,0,2));
	while(!Q.empty())
	{
		x=Q.front().x;
		y=Q.front().y;
		time=Q.front().time;
		what=Q.front().what;
		Q.pop();
		
		
		if(x==h||x==1||y==1||y==w)
		{
			if(what==2)
			{
			
			printf("%d\n",time+1);
			flag=1;
			break;
		}
		}
		
		for(i=0; i<=3; i++)
          {
            xx=x+dx[i];
			yy=y+dy[i];
			
			if(xx>=1&&xx<=h&&yy>=1&&yy<=w)
			{
				if(what==2&&map[xx][yy]=='.')
				{
					map[xx][yy]='@';
					Q.push(state(xx,yy,time+1,what));
					
				
				}
				
				if(what==1)
				 {
				 	if(map[xx][yy]=='.'||map[xx][yy]=='@')
					 {
					   
				 	map[xx][yy]='*';
				 	Q.push(state(xx,yy,time+1,what));
				 }
				 }
				  }  	
          	
				  }		
	}
	
	if(flag==0)
	{
		printf("IMPOSSIBLE\n");
	}
	
	while(!Q.empty())
	{
		Q.pop();
	}
	
}
return 0;
}
