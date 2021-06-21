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

 
void rotation()  //�ð� ���� 90�� ȸ��  
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
			   
				if(notebook[i][j]==0)  //�ش� ��ġ�� ��ƼĿ�� ���ϼ� �ִ���?? 
				{
				record.push_back({i,j});
			    }
				
				else //��ƼĿ ���ϼ����� 
				{	
					return 0;   
					
				}
			}
			
			
			
		}
	}
	
	for(int i=0; i<record.size(); i++) // ��Ʈ�� �迭�� ���  
	{
		notebook[record[i].first][record[i].second]=1;	
	}
	
	return 1; 
	
	
	
	
 } 

bool search()
{
	bool result=0;	
	for(int i=1; i<=n; i++)  //���� �������� Ž��  
	{
		for(int j=1; j<=m; j++)
		{
			  
			 
			if(i+sn-1<=n&&j+sm-1<=m)  // ������ ����� �ʴ´ٸ�? 
			{
				
				result=check1(i,j);  //��ƼĿ�� ���ϼ��ִ��� Ȯ�� 1�� ��ȯ�Ǹ� ���ΰ� 0�� ��ȯ�Ǹ� �ȵȰ� 
		    }
			
			if(result) 
			{ 

				 return 0; // 0��ȯ  
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
	 	result=search(); //���� ������� ����Ŀ�� ���ϼ� �ִ°� Ȯ�� ( �ٿ����� 0 ���ٿ����� 1 ��ȯ) 
		  
		  if(result==1) 
		  {
		  	rotation(); //�ð� ���� 90�� ȸ��  
		  } 
		  
		  if(number==4)  // 0 90 180 270  4�� �� �ߴµ��� �ȵǸ� ���� 
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
