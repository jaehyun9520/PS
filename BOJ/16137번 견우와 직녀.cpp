#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
using namespace std;
int map[11][11]={0};
int n,m,ans=2147000000; 

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

struct state{
	
	int x,  y, time, cnt;   // 행열 좌표  몇분인지  CNT는 바로이전에 오작교를 건넜는지  
	
	state(int a, int b, int c, int d)
	{
		x=a;
		y=b;
		time=c;
		cnt=d;
	} 
	
};



void BFS()
{
	int check[11][11]={0};
	

	queue <state> Q;
	check[1][1]=0;   
	Q.push(state(1,1,0,0)); // 시작점(견우)  
	
	
	while(!Q.empty())
	{
		int x=Q.front().x;
		int y=Q.front().y;
		int time=Q.front().time;
		int cnt=Q.front().cnt;
		Q.pop();
		
		
		for(int i=0; i<=3; i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
			{
				if(map[nx][ny]==1&&check[nx][ny]==0) //일반적인 땅  
				{
					if(nx==n&&ny==n)
					{
						ans=min(ans,time+1);
						
					}	
					else if(check[nx][ny]==0){
						
						check[nx][ny]=1;
						Q.push(state(nx,ny,time+1,0));
						
					}
			
				}
				
				else if(map[nx][ny]>=2&&cnt==0&&check[nx][ny]==0) //오작교인 경우  
				{
					if((time+1)%map[nx][ny]==0)  //바로 건널수 있는 시간  
					{	
						
						check[nx][ny]=1;
						Q.push(state(nx,ny,time+1,1));
 
					 }
					 
					else  {

					 	Q.push(state(x,y,time+1,0));  //건널수없으면 제자리에서 시간만 +1 

					 } 
				
				}				
			}		
		}		
	}	
}

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,j,k;
cin>>n>>m; 


for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		cin>>map[i][j];
	}
}


for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		if(map[i][j]==0)  
		{
			int cnt=0;
			
			for(k=0; k<=3; k++)
			{
				int nx=i+dx[k];
				int ny=j+dy[k];
				
				if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
				{
					if(map[nx][ny]==0)
					{
						cnt++;
					}
				}
				
				
			}
			
			if(cnt<=1)  // 절벽이면서 교차로가 아닌 경우  
			{           // M분 주기를 가진 오작교를 놓는다.  
			
				map[i][j]=m;
				BFS(); 	 // 몇분만에 직녀에게 도달하는지 확인 		  
				map[i][j]=0;
				 
				
			 } 			
						
		}
				
	}
		
}


cout<<ans;
return 0;
}
