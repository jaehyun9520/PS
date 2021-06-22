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



void BFS(int sx1, int sy1, int ex1, int ey1)  // �Ա� ��ǥ [1][sx1][sy1]  �ⱸ��ǥ[5][ex1][ey1] 
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

void rotation(int x, int number)  // �迭 ȸ��  
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
	
	
	if(cnt==5&&ans!=12)  //12�� 3���� �迭���� �Ա� -> �ⱸ ���� �ɸ��� �ִܰŸ�  
	{                    // �̹� 12�� �������� ������ �ʿ�   
	                    //cnt=5�̸� 2���� �迭 5���� 3���� �̷θ� �����
						// �迭 ���� ������ ȸ��(0,90,180,270)���� ������ 3���� �̷� 5!*4^5= 122880  
						//  �� �̷θ��� Ȯ������� �ϴ� �Ա� �ⱸ?  122880 *4=   491250
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
	   	 if(used[i]==0)  // ����ߴ��� Ȯ�� 
			{
				used[i]=1;   
				copy(cnt+1,i);	// 3���� �̷� ������ 2���� �迭�� �����Ұ�����? 
				           
				 for(int j=1; j<=4; j++)  // 0 90 180 270
				 {
						          
				rotation(cnt+1,j);  //ȸ��   
				
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
			cin>>input[i][j][k];  //5���� �迭 �Է�  
		}
	}
}


DFS(0);  // 3���� �̷� �����  

if(ans==2147000000) cout<<-1;

else
cout<<ans;
return 0;
}
