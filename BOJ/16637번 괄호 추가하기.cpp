#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n, ans=-2147483640;
int number[11]={0};  // 피연산자는 최대 10개  
int o[10]={0};  // 연산자는 최대 9개
int check[10]={0};   // 조합만들기  



void DFS(int x)
{
	int i,total=number[1],tmp; // total= 수식의 합을 나타냄 맨처음 값은 가장 왼쪽의 피연산자 값  



for(i=1; i<=n/2; i++)
{
	printf("%d ",check[i]);
}
printf("\n");


	for(i=1; i<=n/2; i++)  // 수식 계산  
	{
		if(check[i]==0&&check[i+1]==0)   //   내 뒤에 연산자도 괄호가 없으면 그대로 계산    
		 {
			if(o[i]=='+')   total=total+number[i+1];
			else if(o[i]=='-')  total=total-number[i+1];
			else if(o[i]=='*')  total=total*number[i+1];     
		}  
		
		if(check[i]==1)  // 현재 연산자가 괄호를 사용했으면 먼저 계산 
		{
			if(o[i]=='+')   tmp=number[i]+number[i+1];
			else if(o[i]=='-')  tmp=number[i]-number[i+1];
			else if(o[i]=='*')  tmp=number[i]*number[i+1];
			
			if(o[i-1]=='+')   total=total+tmp;   // 그 뒤에 앞의 값과 계산  
			else if(o[i-1]=='-')  total=total-tmp;
			else if(o[i-1]=='*')  total=total*tmp;  
			
			
		}
		
		
	}

	if(ans<total)  ans=total;

	 for(i=x; i<=n/2; i++)
	 {
	 	if(check[i-1]==0&&check[i]==0) // 내앞의 연산자가 괄호를 썻는지 썻다면 나는 못씀, 안썻다면 쓸수있음  
	 	{
	 		check[i]=1;
	 		  DFS(i+1);
	 		check[i]=0;
		 }
	 	
	 }
	
}
int main()
{
//freopen("input.txt", "rt", stdin);
int i,p1=1,p2=1; 
char a[20];

scanf("%d",&n);

scanf("%s",a);

for(i=1; i<=n; i++)
{
	if(a[i-1]=='+'||a[i-1]=='-'||a[i-1]=='*')
	{
		o[p1++]=a[i-1];  // 연산자 저장    i번 연산자는 i번 피연산자와 i+1번 피연산자를 더해주게끔 설정 
	}
	else{
		number[p2++]=a[i-1]-48;   // 피연산자 저장 
	}
}


DFS(2);  // 첫번째 연산자는 괄호가 필요없다 생각하고 두번째 연산자부터 조합만들기  

printf("%d",ans);
return 0;
}
