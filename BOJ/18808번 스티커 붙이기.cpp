#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
using namespace std;
int notebook[41][41]={0}; 
int n,m; 
int sticker[11][11]={0};  
int sn,sm;   

 
void rotation()  //시계 방향 90도 회전  
{
	int tmp[11][11]={0};
	
	for(int i=1; i<=sn; i++)
	{
		
		for(int j=1; j<=sm; j++)
		{
			tmp[j][sn+1-i]=sticker[i][j];
			
			
		}
	}
	
	int tmp1=sn;
	sn=sm; 
	sm=tmp1;  
	
	for(int i=1; i<=sn; i++)
	{
		for(int j=1; j<=sm; j++)
		{
			sticker[i][j]=tmp[i][j];
		}
	}
	
	
	
	
}
 
 
 
bool check1(int x, int y)
{
	
	vector < pair < int , int > > record;
		
	for(int i=x; i<=x+sn-1; i++)
	{
		for(int j=y; j<=y+sm-1; j++)
		{

			if(sticker[i-x+1][j-y+1]==1)  
			{
			   
				if(notebook[i][j]==0)  //해당 위치에 스티커를 붙일수 있는지?? 
				{
				record.push_back({i,j});
			    }
				
				else //스티커 붙일수없음 
				{	
					return 0;   
					
				}
			}
			
			
			
		}
	}
	
	for(int i=0; i<record.size(); i++) // 노트북 배열에 기록  
	{
		notebook[record[i].first][record[i].second]=1;	
	}
	
	return 1; 
	
	
	
	
 } 

bool search()
{
	bool result=0;	
	for(int i=1; i<=n; i++)  //왼쪽 맨위부터 탐색  
	{
		for(int j=1; j<=m; j++)
		{
			  
			 
			if(i+sn-1<=n&&j+sm-1<=m)  // 범위를 벗어나지 않는다면? 
			{
				
				result=check1(i,j);  //스티커를 붙일수있는지 확인 1이 반환되면 붙인거 0이 반환되면 안된거 
		    }
			
			if(result) 
			{ 

				 return 0; // 0반환  
			}
			
		}
	}	
	return 1;  	
 } 

 
 

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,cnt,ans=0;
cin>>n>>m>>cnt;

for(i=1; i<=cnt; i++)
{
	cin>>sn>>sm; 
	
	for(int j=1; j<=sn; j++)
	{
		for(int k=1; k<=sm; k++)
		{
			cin>>sticker[j][k];
		}
	 }
	 
	 bool result=1;
	 int number=0; 
	 
	 while(result)  
	 {
	 	number++;
	 	result=search(); //현재 모양으로 스터커를 붙일수 있는가 확인 ( 붙였으면 0 못붙였으면 1 반환) 
		  
		  if(result==1) 
		  {
		  	rotation(); //시계 방향 90도 회전  
		  } 
		  
		  if(number==4)  // 0 90 180 270  4번 다 했는데도 안되면 버림 
		  break;
	 }
	
	
	  
	
	
}


for(int i=1; i<=n; i++)
{
	for(int j=1; j<=m; j++)
	{
		if(notebook[i][j]==1)
		{
			ans++;
		}
	}
}

cout<<ans;  

return 0;
}
