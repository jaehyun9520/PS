#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
using namespace std;

int ans=2147000000;

int maze[6][6][6]={0};
int input[6][6][6]={0};
bool used[6]={0};

int sx[4]={1,1,5,5};
int sy[4]={1,5,1,5};
int ex[4]={5,5,1,1};
int ey[4]={5,1,5,1};

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dz[2]={1,-1};


struct state{
	
	int z,  x,  y,  cnt;
	
	state(int a, int b, int c,  int d)
	{
		z=a; x=b; y=c;   cnt=d;
	}
};



void BFS(int sx1, int sy1, int ex1, int ey1)  // 입구 좌표 [1][sx1][sy1]  출구좌표[5][ex1][ey1] 
{
	bool check[6][6][6]={0};  
	
	queue <state> Q;
	
	check[1][sx1][sy1]=1;
	
	Q.push(state(1,sx1,sy1,0)); 
	
	
	while(!Q.empty())
	{
		int z=Q.front().z;
		int x=Q.front().x;
		int y=Q.front().y;
		int cnt=Q.front().cnt;
		Q.pop();
		
		
		for(int i=0; i<=3; i++) 
		{
			int nx=x+dx[i]; 
			int ny=y+dy[i];
			
			
			if(nx>=1&&nx<=5&&ny>=1&&ny<=5) 
			{
				if(maze[z][nx][ny]==1&&check[z][nx][ny]==0&&cnt<ans)
				{
					check[z][nx][ny]=1;
					
					if(z==5&&nx==ex1&&ny==ey1)
					{
						if(ans>cnt+1)  ans=cnt+1;
						return ;
					}
					
					
					Q.push(state(z,nx,ny,cnt+1));
				}
			}
		}
		
		for(int i=0; i<=1; i++)
		{
			int nz=z+dz[i];
			
			if(nz>=1&&nz<=5)
			{
				
				if(maze[nz][x][y]==1&&check[nz][x][y]==0&&cnt<ans)
				{
					check[nz][x][y]=1;
					
					if(nz==5&&x==ex1&&y==ey1)
					{
						if(ans>cnt+1)  ans=cnt+1;
						return ;
					}
					
					Q.push(state(nz,x,y,cnt+1));
					
					
				}
				
			}
			
		}
		
		
	 } 
	
		
	
	
 } 





void copy(int x, int y)    
{
	for(int i=1; i<=5; i++)
	{
		for(int j=1; j<=5; j++)
	    {
	    	maze[x][i][j]=input[y][i][j];
		}
	}
	
}

void rotation(int x, int number)  // 배열 회전  
{

		int tmp[6][6]={0};
	
	if(number==1) return ;   
	

	
	else{
		
		for(int i=1; i<=5; i++)
		{
			for(int j=1; j<=5; j++)
			{
				tmp[j][6-i]=maze[x][i][j]; 
				
			}
		}
		
		for(int i=1; i<=5; i++)
		{
			for(int j=1; j<=5; j++)
			{
				maze[x][i][j]=tmp[i][j];
			}
		}
		
		
	}
	
}



void DFS(int cnt)   
{
	
	
	if(cnt==5&&ans!=12)  //12는 3차원 배열에서 입구 -> 출구 까지 걸리는 최단거리  
	{                    // 이미 12가 나왔으면 진행할 필요   
	                    //cnt=5이면 2차원 배열 5개로 3차원 미로를 만든것
						// 배열 놓는 순서와 회전(0,90,180,270)까지 생각한 3차원 미로 5!*4^5= 122880  
						//  각 미로마다 확인해줘야 하는 입구 출구?  122880 *4=   491250
		for(int i=0; i<=3; i++)
		{
			
		
				
				if(maze[1][sx[i]][sy[i]]==1&&maze[5][ex[i]][ey[i]]==1) 
				{
					 BFS(sx[i],sy[i],ex[i],ey[i]);  
	
				 } 
				
				
			
		}
	}
	
	
	else if(cnt<5&&ans!=12)
	{
	   for(int i=1; i<=5; i++)  
	   {
	   	 if(used[i]==0)  // 사용했는지 확인 
			{
				used[i]=1;   
				copy(cnt+1,i);	// 3차원 미로 몇층에 2차원 배열을 복사할것인지? 
				           
				 for(int j=1; j<=4; j++)  // 0 90 180 270
				 {
						          
				rotation(cnt+1,j);  //회전   
				
				DFS(cnt+1); 
				
			     }
			     
			     used[i]=0;
				
				
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

for(int i=1; i<=5; i++)
{
	for(int j=1; j<=5; j++)
	{
		for(int k=1; k<=5; k++)
		{
			cin>>input[i][j][k];  //5개의 배열 입력  
		}
	}
}


DFS(0);  // 3차원 미로 만들기  

if(ans==2147000000) cout<<-1;

else
cout<<ans;
return 0;
}
