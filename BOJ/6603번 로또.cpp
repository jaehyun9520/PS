#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int k;
int list[14]={0};
int check[7]={0};

void DFS(int cnt, int x)  // 경우의 수 구하기  
{
	int i;

	if(cnt==6)  // 6개 다 뽑았으면 출력  
	{
		for(i=1; i<=6; i++)
		{
			printf("%d ",check[i]);
		}
		printf("\n");
	}
		
	else
	{
		
		for(i=x; i<=k; i++)
		{
			check[cnt+1]=list[i];  
			DFS(cnt+1,i+1);
		}
	}
}

int main()
{
//freopen("input.txt", "rt", stdin);
int i;
while(1)   // 0이 나올때까지 테스트케이스 반복 입력  
 { 

scanf("%d",&k); 

if(k==0)  // K가 0이면 테스트 케이스 종료  
  {
	break;
  }  

for(i=1; i<=k; i++)   // K개만큼의 수를 입력  
  {
	scanf("%d",&list[i]);
  }

DFS(0,1);   // K개의 수중에서 6개 뽑는 경우의수 (조합)  

printf("\n");
 }

return 0;
}
