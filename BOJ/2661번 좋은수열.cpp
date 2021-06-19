#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
using namespace std;
int n;  // 구해야 하는 수열의 길이  
char ans[81]={0};  
char list[4]={'0','1','2','3'};
void DFS(int now)
{

	
	for(int i=0; i<now/2; i++)   // 수열 길이 (1 ~ 현재수열의 길이/2 )인 두개의 수열을 비교   
	{                             
	     bool flag=0;  	  // 동일한 것이 있는지 확인        
		
		for(int j=now; j>=now-i; j--)  
		{
		
			if(ans[j]!=ans[j-(i+1)]) 
			{                         
				flag=1;   // 하나라도 다르다면  다음길이의 수열 확인  
				break;
			}
			
		}
		if(flag==0) // 두개의 수열이 완전히 동일하면 좋은 수열이 아니니 중단  
		{
			return ; 
		 } 
		
	}

	if(n==now)  // 길이 n인 좋은수열 완성  
	{
		for(int i=1; i<=n; i++)
		{
			cout<<ans[i];
			
		 } 
		 exit(0);
	}
	
	
	else if(now<n)  
	{
		for(int i=1; i<=3; i++)  // 1 2 3 중 하나 넣기 
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
