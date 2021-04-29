#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

struct state{   // ���غ���� ��ǥ, ��ϱ׷��� ������, ����������� ����  
	
	int x, y, size,cnt;  
	
	state(int a, int b, int c, int d)
	{
		x=a; y=b; size=c; cnt=d;
	}
	
	bool operator<(const state &b)const
	{
		if(size==b.size)          //������ ���� �켱�������  
		{
		    if(cnt==b.cnt)
			{
				if(x==b.x)
			{
				return y<b.y;	
			}
			
			
			else{
				return x<b.x;
			}
				
				
				}	
			
			else return cnt<b.cnt;
			
			
		}
		
		else return size<b.size;
	}
}; 



int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int map[21][21]={0};  
int check[21][21]={0};
int tmp[21][21]={0};  // �ݽð� 90�� �����϶� ����� 

queue < pair < int , int > > Q;  
priority_queue <state> PQ;  // ��ϱ׷��� �־��ִ� �켱���� ť 
vector < pair < int , int > > list; // ������ ��� �ִ°�(������ ����� �湮üũ Ǯ���ֱ�����..) 

int n;


void move()   //�߷� 
{
	int i,j;
	
	
	for(j=1; j<=n; j++)
	{
		for(i=n-1; i>=1; i--)
		{
			
			if(map[i][j]!=6&&map[i][j]!=-1)   
			{
				int k=i+1;
				int cnt=0;
				
				while(k<=n)
				{
					
					if(map[k][j]==6)
					{
						cnt++;
						k++;
					}
					else{  
						break;
					}
				}
				map[i+cnt][j]=map[i][j];
				if(cnt!=0)
				map[i][j]=6;
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
int i,j,m,color,size,x,y,nx,ny,ans=0,cnt;
int pointx,pointy;  
cin>>n>>m;  


for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		cin>>map[i][j];
	}
	
}

while(1)
{
	for(i=1; i<=n; i++) 
	{
		for(j=1; j<=n; j++)
		{
			if(map[i][j]>=1&&map[i][j]<=m&&check[i][j]==0)  //�湮�ȵ� �Ϲݺ���� �������  
			{
			
				size=1;  pointx=i; pointy=j,cnt=0;  //��ϻ����� 1 , ���غ����ǥ ����, ��������ϰ���=0 
				color=map[i][j]; //������ ������ ����  
				check[i][j]=1; 
				
				Q.push(make_pair(i,j));
				
				while(!Q.empty())
				{
					x=Q.front().first;
					y=Q.front().second;
					
					Q.pop();
					for(int k=0; k<=3; k++)
					{
						nx=x+dx[k];
						ny=y+dy[k];
						
						if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
						{
							if(map[nx][ny]==0||map[nx][ny]==color)
							{
								if(check[nx][ny]==0)
								{
								
									check[nx][ny]=1;
									size++;
									
									if(map[nx][ny]==0) //������ ����� �ٸ� ��ϱ׷��� ���鶧�� ���������� �湮üũ�� Ǯ������ ���� 
									{
									   list.push_back(make_pair(nx,ny));
									   cnt++;
								     }
								     
								     
									else if(map[nx][ny]==color)  //�Ϲݺ���� ��� ���غ�� ���ϱ�  
									{
										if(pointx>nx)
										{
											pointx=nx; pointy=ny;
									
										}
										
										else if(pointx==nx)
										{
											if(pointy>ny) {
												pointy=ny;
											}
										}
									}
								
									Q.push(make_pair(nx,ny)); 
								}
							}
						}
					}
					
				
					
				}
				for(int k=0; k<list.size(); k++)  //��������� �湮üũ Ǯ��  
				{
					check[list[k].first][list[k].second]=0;
				}
				list.clear();
				
				
				if(size>=2)  //��ϱ׷� ����� 2�̻��̸� �켱���� ť�� �־���  
				{              
				  PQ.push(state(pointx,pointy,size,cnt));
					
				}
				
				
				
				
			 } 
		}
	}

	if(PQ.empty()) // ��ϱ׷��� ������ ����  
	{

	break;  
     }
	else  
	{

	   ans+=PQ.top().size*PQ.top().size;  
        Q.push(make_pair(PQ.top().x,PQ.top().y)); 
        
        color=map[PQ.top().x][PQ.top().y]; 
        map[PQ.top().x][PQ.top().y]=6; 
        
        while(!PQ.empty()) PQ.pop();  
        
        while(!Q.empty())  //��� �׷� ���� (������� 6���� ǥ��)  
        {
        	x=Q.front().first; y=Q.front().second;
        	Q.pop();
        	
        	for(i=0; i<=3; i++)
        	{
        		nx=x+dx[i]; ny=y+dy[i];
        		
        		if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
        		{
        			if(map[nx][ny]==color||map[nx][ny]==0) 
					{
					
						map[nx][ny]=6; 
						Q.push(make_pair(nx,ny));
					 } 
				}
			}
        	
		}
  
    }
    
    
    move();  
		

	for(i=1; i<=n; i++)  // �ݽð� 90��  
	{
		for(j=1; j<=n; j++)
		{
			tmp[n-j+1][i]=map[i][j];
		}
	}

	for(i=1; i<=n; i++) 
	{
		for(j=1; j<=n; j++)
		{
			map[i][j]=tmp[i][j];
			check[i][j]=0;
		}
	}
	move(); 

}

cout<<ans;

return 0;
}
