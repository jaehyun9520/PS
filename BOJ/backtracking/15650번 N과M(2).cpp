#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int n,m;
int check[9];
int a[9];
int cnt=0;
void DFS(int x)
{
	if(cnt==m)
	{
		for(int i=1; i<=m; i++)
		{
			printf("%d ",a[i]);
			
		}
		printf("\n");
	}
	
	else
	{
		for(int j=x; j<=n; j++)
		{
			if(check[j]==0)
			{
				check[j]=1;
				cnt++;
				a[cnt]=j;
				DFS(j);
				check[j]=0;
				cnt--;
			}
			
		}
	}
	
}

int main(){
//freopen("input.txt", "rt", stdin);
scanf("%d %d",&n,&m);

DFS(1);
	return 0;
}
