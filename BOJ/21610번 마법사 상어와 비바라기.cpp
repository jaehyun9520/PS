#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int n;
int dx[9]={0,0,-1,-1,-1,0,1,1,1};  
int dy[9]={0,-1,-1,0,1,1,1,0,-1};
int map[51][51]={0};
int check[51][51]={0};
vector < pair < int , int > > cloud;   
vector < pair < int , int > > magic;   

void create()
{
	for(int i=1; i<=n; i++)  // �� ��ü Ž�� 
	{
		for(int j=1; j<=n; j++)
		{
			if(map[i][j]>=2&&check[i][j]==0)
			{
				map[i][j]-=2;
				cloud.push_back(make_pair(i,j));
			}
			
			if(check[i][j]==1)  
			check[i][j]=0;
			
		}
	}
	
	
}

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int m,i,j,d,s,x,y,cnt,nx,ny,ans=0;



cin>>n>>m;

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		cin>>map[i][j];
		
	}
}
cloud.push_back(make_pair(n,1));
cloud.push_back(make_pair(n,2));
cloud.push_back(make_pair(n-1,1));
cloud.push_back(make_pair(n-1,2));   


for(i=1; i<=m; i++)
{
	
	cin>>d>>s;
	
	for(j=0; j<cloud.size(); j++)  // ��ü ���� �̵�  
	{
		x=cloud[j].first; y=cloud[j].second;
		
		cnt=s%n;
		
		for(int k=1; k<=cnt; k++)
		{
			x=x+dx[d];
			y=y+dy[d];
			
			if(x==0) x=n;
			if(x==n+1) x=1;
			if(y==0) y=n;
			if(y==n+1) y=1;
		}
		

		map[x][y]++;  // ���� �̵� �� ������� �� �ڸ��� �� 1����  
		check[x][y]=1; // ������ ����� �ڸ��� ������ �ٽ� ����� �ȵǴ� ǥ��  
		magic.push_back(make_pair(x,y));  // ������ ���� ������ ����� ��ġ  
		
		
	}
	
	
	cloud.clear();  
	
	

for(int k=0; k<magic.size(); k++)  //�� ���� ���� ����  
  {
	x=magic[k].first; y=magic[k].second;
	cnt=0;
	for(int j=2; j<=8; j+=2)
	{
		nx=x+dx[j];
		ny=y+dy[j];
		
		if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&map[nx][ny]>=1)
		{
			cnt++;
		}
	}
	
	map[x][y]+=cnt; // �밢�� ���� Ȯ�� ��  �� ����  
	}
		 
		 magic.clear();
	
	

	 create();  // ���ο� ���� ���� 
	
	
}

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		ans+=map[i][j];
	}

}

cout<<ans;

return 0;
}
