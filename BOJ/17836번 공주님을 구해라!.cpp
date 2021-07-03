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
int check[101][101]={0};  //0�̸� �ѹ��� �湮���� ����
                          //1�̸� Į�� ���� ���·� �湮���� ����
						  //2�̸� Į�� �ִ� ���·� �湮���� ����  

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void BFS()
{
	queue <state> Q;	
	check[1][1]=1;  // ������(���)  
	
	Q.push(state(1,1,0,0));  // �� �� ��ǥ, �ð�, ���� ������ �ִ���  
		
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
				if(map[nx][ny]==0) //�����  
				{
					if(nx==n&&ny==m)  // �������� ���������� ����  
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
					else if(check[nx][ny]==0)  //�ѹ��� �湮���� ������  
					{
						if(sword==1) //���� ���������  
						{
							check[nx][ny]=2; // Į��� ������  
						}
						
						else if(sword==0)  //���� ������  
						{
							check[nx][ny]=1; // �׳� ������  
							
						}
						
						Q.push(state(nx,ny,time+1,sword)); 
						
					}
					
					else if(check[nx][ny]==1&&sword==1) // Į ���� �̹� �ѹ� �湮�߰�  
					                                    // Į ��� ��湮�ϴ� ���  
					{
					   check[nx][ny]=2; // Į�� ��� �湮�ߴٰ� �ٽ� ǥ��  
					   Q.push(state(nx,ny,time+1,sword)); 
					    
					 } 
						
				}
				
				
				else if(map[nx][ny]==2&&check[nx][ny]==0) //Į�� ���ΰ�  
				{
					check[nx][ny]=2; 
					
					Q.push(state(nx,ny,time+1,1));  
					
					
				}
				
				else if(map[nx][ny]==1&&check[nx][ny]==0&&sword==1) //������ ������ 
				{
					check[nx][ny]=2;   
					Q.push(state(nx,ny,time+1,sword));
				}
				
				
				
			}
			
		}						
	}	
	cout<<"Fail";  //�ƿ� �������� ���Ѱ�� 
		
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
