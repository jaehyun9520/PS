#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
using namespace std;
int n;  // ���ؾ� �ϴ� ������ ����  
char ans[81]={0};  
char list[4]={'0','1','2','3'};
void DFS(int now)
{

	
	for(int i=0; i<now/2; i++)   // ���� ���� (1 ~ ��������� ����/2 )�� �ΰ��� ������ ��   
	{                             
	     bool flag=0;  	  // ������ ���� �ִ��� Ȯ��        
		
		for(int j=now; j>=now-i; j--)  
		{
		
			if(ans[j]!=ans[j-(i+1)]) 
			{                         
				flag=1;   // �ϳ��� �ٸ��ٸ�  ���������� ���� Ȯ��  
				break;
			}
			
		}
		if(flag==0) // �ΰ��� ������ ������ �����ϸ� ���� ������ �ƴϴ� �ߴ�  
		{
			return ; 
		 } 
		
	}

	if(n==now)  // ���� n�� �������� �ϼ�  
	{
		for(int i=1; i<=n; i++)
		{
			cout<<ans[i];
			
		 } 
		 exit(0);
	}
	
	
	else if(now<n)  
	{
		for(int i=1; i<=3; i++)  // 1 2 3 �� �ϳ� �ֱ� 
		{
		
			ans[now+1]=list[i];  
		    DFS(now+1); 
		
		}
		
		
	}
	
	
}

int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

cin>>n;  

DFS(0);  


return 0;
}
