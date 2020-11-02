#include<iostream>
#include<algorithm>
#include<vector>

int check[2000001];
int n;
int list[21];

void DFS(int x, int cnt,int sum)
{
	int i;

	if(sum>0) check[sum]=1; //만들어지는 부분수열의 합 체크  
	
	
	if(cnt<n)
	{
	
	for(i=x+1; i<=n; i++)  //부분수열 만들기 (조합)  
	{
		sum=sum+list[i];
		DFS(i,cnt+1,sum);
		sum=sum-list[i];
	}
}
}


using namespace std;
int main()
{
//freopen("input.txt", "rt", stdin);	
int i;
scanf("%d",&n);

for(i=1; i<=n; i++)
{
	scanf("%d",&list[i]);
}

DFS(0,0,0); 
i=1;
while(1) //1부터 시작해서 체크안된 숫자를 찾아주기  
{
	if(check[i]==0) 
	{
	printf("%d",i); 
	break;
}
else i++;
}

return 0;
}
