#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

    
	int arr[20]={0};

	int n,s,i,answer=0;

void DFS(int cnt,int x,int sum)  
{
	int i;
	

	if(cnt<n)
	{

	for(i=x; i<n; i++)   
	{
		 sum=sum+arr[i];
		    
			 if(sum==s) {
			 answer++;
 
		}
				 DFS(cnt+1,i+1,sum);
			 sum=sum-arr[i];
		
	}
	
}
	
}

int main()
{
	
	scanf("%d %d",&n,&s);
	
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]); 
	}
	
	
	DFS(0,0,0);
	
//freopen("input.txt", "rt", stdin);

printf("%d",answer);

return 0;


}
