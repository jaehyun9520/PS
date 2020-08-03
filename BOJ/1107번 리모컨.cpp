#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>

int num[10]={0}; 
int count1=1;   
int n,m,tmp,i;
int c=100;  
int result=99999999;

void DFS(int number,int cnt, int digit )    // 현재 채널 수 , 버튼사용 수 , 현재채널의 자릿수  
{
	int i,tmp;

		if(result>abs(n-number)+cnt)
		{
			result=abs(n-number)+cnt;
		}

 if(number!=0&&digit<=5)  
 {
	 	
	for(i=0; i<=9; i++)
	{
		if(num[i]==0)
		{
			 tmp=number*10+i;
			DFS(tmp,cnt+1,digit+1);
		}
		
	
	
    }
}
}


using namespace std;

int main()
{
//freopen("input.txt", "rt", stdin);




scanf("%d",&n);

scanf("%d",&m);

for(i=1; i<=m; i++)
{
	scanf("%d",&tmp);
	num[tmp]=1;
}


tmp=n;
if(result>abs(n-c))
{
	result=abs(n-c);
	if(result==0)
	{
		printf("0");
		exit(0);
	}
	
 } 
while(tmp!=0)     //이동하려는 채널의 자릿수를 구하기  
{
	
		tmp=tmp/10;
		if(tmp!=0)
		{
			count1++;
		}
	
}



for(i=0; i<=9; i++)  // 사용할수있는 숫자버튼을 이용해서 경우의수    
{
	if(num[i]==0)
	{
	
	DFS(i,1,1);
    }
}

printf("%d",result);
return 0;

}

