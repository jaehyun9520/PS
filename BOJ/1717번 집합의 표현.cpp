#include<iostream>
#include<algorithm>



using namespace std;

int node[1000001]={0};   



int find(int a)  // 부모노드 찾기  
{
	if(node[a]==a) return a;  
	
	else return node[a]=find(node[a]);
}

void Union(int a, int b)   // 두 개의 노드가 속한 집합 합치기  
{
	a=find(a);
	b=find(b);
	
	if(a!=b)
	{
		node[a]=b;
	}
	
}

int main()
{
//freopen("input.txt", "rt", stdin);

int n,m,i,a,b,c;
scanf("%d %d",&n,&m);

for(i=0; i<=n; i++)  //초기화  
{
	node[i]=i;
}


for(i=1; i<=m; i++)
{
	scanf("%d %d %d",&a,&b,&c);
	
	if(a==0)
	{
		Union(b,c);
	}
	
	else
	{
		if(find(b)==find(c))
		  printf("YES\n");
		  
		  
		  else
		   printf("NO\n");
		
		
	}
}




return 0;

}
