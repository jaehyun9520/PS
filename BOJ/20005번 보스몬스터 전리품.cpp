#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int raidcheck[27]={0};  
int total=0; 
int servertime=0;
int ans=0;
struct state{
	
	int x;
	int y;
	int time;
	int who;
	state(int a, int b, int c,int d)
	{
		x=a; 
		y=b;
		time=c;
		who=d;
	 } 
};
int map[1001][1001]={0};
int check[1001][1001]={0};   
int damage[27]={0};
int main()
{	
//freopen("input.txt", "rt", stdin);
int i,j,n,m,p,hp,x,y,xx,yy,time,who;
char c;
queue <state> Q;
char a[1001];
scanf("%d %d %d",&m,&n,&p);

for(i=1; i<=m; i++)
{
	scanf("%s",a);
	for(j=1; j<=n; j++)
	{
		map[i][j]=a[j-1];
		
		
		
		if(map[i][j]=='B')
		{
			check[i][j]=1;
			Q.push(state(i,j,0,0));  // 보스를 큐에 넣어 움직여준다 
		 } 
	}
}

for(i=1; i<=p; i++)
{
	scanf(" %c %d",&c,&hp);
	

	damage[c-96]=hp;    // 각 플레이어의 데미지 기록  
 } 
scanf("%d",&hp);  
while(!Q.empty())
{
	
	x=Q.front().x;
	y=Q.front().y;
	time=Q.front().time;
	who=Q.front().who;    
	Q.pop();

	if(servertime<time)  

	{
		servertime++;
		if(hp>=1)
		{
		
		hp=hp-total;
	}
	
	}
	
		if(who!=0&&hp>0)
	{
		if(raidcheck[who-96]==0)
		{
		
			raidcheck[who-96]=1;
			total=total+damage[who-96];
		}
		who=0;
	}

if(hp>0)
{

	for(i=0; i<=3; i++)
	{
		xx=dx[i]+x;
		yy=dy[i]+y;
		
		if(xx>=1&&xx<=m&&yy>=1&&yy<=n)
	    {
	    	if(map[xx][yy]=='.'&&check[xx][yy]==0)    //빈공간  
	    	{
	    	
				check[xx][yy]=1;
	    		Q.push(state(xx,yy,time+1,0));
			}
			
			
			else if(map[xx][yy]>=97&&map[xx][yy]<=122&&check[xx][yy]==0)  // 플레이어를 만났을때 
			{
				check[xx][yy]=1;
				Q.push(state(xx,yy,time+1,map[xx][yy]));
			}
			
		}
	}
}
	
}


for(i=1; i<=26; i++)
{
	if(raidcheck[i]==1) ans++;  // 보스가 피가 남아있을때 레이드에 참여한 인원수  
}
printf("%d",ans);
return 0;
}
