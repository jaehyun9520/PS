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
	
	int x,  y, time, cnt;   // �࿭ ��ǥ  �������  CNT�� �ٷ������� ���۱��� �ǳԴ���  
	
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
	Q.push(state(1,1,0,0)); // ������(�߿�)  
	
	
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
				if(map[nx][ny]==1&&check[nx][ny]==0) //�Ϲ����� ��  
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
				
				else if(map[nx][ny]>=2&&cnt==0&&check[nx][ny]==0) //���۱��� ���  
				{
					if((time+1)%map[nx][ny]==0)  //�ٷ� �ǳμ� �ִ� �ð�  
					{	
						
						check[nx][ny]=1;
						Q.push(state(nx,ny,time+1,1));
 
					 }
					 
					else  {

					 	Q.push(state(x,y,time+1,0));  //�ǳμ������� ���ڸ����� �ð��� +1 

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
			
			if(cnt<=1)  // �����̸鼭 �����ΰ� �ƴ� ���  
			{           // M�� �ֱ⸦ ���� ���۱��� ���´�.  
			
				map[i][j]=m;
				BFS(); 	 // ��и��� ���࿡�� �����ϴ��� Ȯ�� 		  
				map[i][j]=0;
				 
				
			 } 			
						
		}
				
	}
		
}


cout<<ans;
return 0;
}
