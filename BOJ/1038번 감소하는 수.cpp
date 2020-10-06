#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n; 
int list[11];
int number=-1;
int flag=0;

void DFS(int x, int cnt)  //X는 현재 몇개 뽑았는지 , CNT는 몇개뽑아야하는지  
{
	
	if(x==cnt)  
	{
		number++;
		if(number==n) 
		{
		
		for(int i=1; i<=cnt; i++)
		{
			printf("%d",list[i]);
		}
		flag=1;
	}
	}
	
	
	for(int i=0; i<=9; i++)
	{
		
			if(list[x]>i||x==0) //첫번째 뽑는 숫자거나  앞의 숫자보다 작은경우 더 진행  
			{
				list[x+1]=i;
				DFS(x+1,cnt);
			}
		
	}
	
	
	
	
}



int main()
{	
//freopen("input.txt", "rt", stdin);
scanf("%d",&n);
int i=1;

	for(i=1; i<=10; i++)
	{
		  DFS(0,i);  //1자리 수부터 10자리 수까지 감소하는 수로 뽑게 한다 .    
		   
	}
	
if(flag==0) printf("-1");

 

return 0;
}
