#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
using namespace std;

struct state{
	
	int x, y, time, sword;
	
	state(int a, int b, int c, int d)
	{
		x=a;
		y=b;
		time=c;
		sword=d;
	}
	
};

int n,m,t,ans=0;
int map[101][101]={0};
int check[101][101]={0};  //0이면 한번도 방문한적 없음
                          //1이면 칼이 없는 상태로 방문한적 있음
						  //2이면 칼이 있는 상태로 방문한적 있음  

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void BFS()
{
	queue <state> Q;	
	check[1][1]=1;  // 시작점(용사)  
	
	Q.push(state(1,1,0,0));  // 행 열 좌표, 시간, 검을 가지고 있는지  
		
	while(!Q.empty())
	{
		int x=Q.front().x;
		int y=Q.front().y;
		int time=Q.front().time;
		int sword=Q.front().sword;
		Q.pop();
		
		for(int i=0; i<=3; i++)
		{
			int nx=dx[i]+x;
			int ny=dy[i]+y;
			
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
			{
				if(map[nx][ny]==0) //빈공간  
				{
					if(nx==n&&ny==m)  // 공주한테 도달했으면 종료  
					{
						ans=time+1;
						
						if(ans<=t)
						{
							cout<<ans;
						}
						
						else
						{
							cout<<"Fail";
						}
						exit(0);
						
					}			
					else if(check[nx][ny]==0)  //한번도 방문한적 없을때  
					{
						if(sword==1) //검을 들고있으면  
						{
							check[nx][ny]=2; // 칼들고 지나감  
						}
						
						else if(sword==0)  //검이 없으면  
						{
							check[nx][ny]=1; // 그냥 지나감  
							
						}
						
						Q.push(state(nx,ny,time+1,sword)); 
						
					}
					
					else if(check[nx][ny]==1&&sword==1) // 칼 없이 이미 한번 방문했고  
					                                    // 칼 들고 재방문하는 경우  
					{
					   check[nx][ny]=2; // 칼을 들고 방문했다고 다시 표시  
					   Q.push(state(nx,ny,time+1,sword)); 
					    
					 } 
						
				}
				
				
				else if(map[nx][ny]==2&&check[nx][ny]==0) //칼이 놓인곳  
				{
					check[nx][ny]=2; 
					
					Q.push(state(nx,ny,time+1,1));  
					
					
				}
				
				else if(map[nx][ny]==1&&check[nx][ny]==0&&sword==1) //벽으로 막힌곳 
				{
					check[nx][ny]=2;   
					Q.push(state(nx,ny,time+1,sword));
				}
				
				
				
			}
			
		}						
	}	
	cout<<"Fail";  //아예 도달하지 못한경우 
		
}
int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

cin>>n>>m>>t;


for(int i=1; i<=n; i++)
{
	for(int j=1; j<=m; j++)
	{
		cin>>map[i][j];
	}
}

BFS(); 


return 0;
}
