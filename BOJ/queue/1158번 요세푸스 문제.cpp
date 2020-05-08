#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

queue <int> Q;
int list[5001];


int main()
{

//freopen("input.txt", "rt", stdin);
int n,k,i,cnt=1;

scanf("%d %d",&n,&k);

for(i=1; i<=n; i++)
{
	Q.push(i);
}

while(!Q.empty())
{
	for(i=1; i<k; i++)
	{
		Q.push(Q.front());
		Q.pop();
	}
	
	    list[cnt]=Q.front();
	    Q.pop();
	    cnt++;
	
}
	printf("<");
	
	for(i=1; i<cnt-1; i++)
	{
		printf("%d, ",list[i]);
	}
	
	printf("%d>",list[i]);
return 0;
}
