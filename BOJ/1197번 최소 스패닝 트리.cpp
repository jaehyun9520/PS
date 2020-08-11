#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int node[10001];


struct edge{
	int node1;
	int node2;
	int val;
	
	edge(int x, int y, int z)
	{
		node1=x;
		node2=y;
		val=z;
	}
	
	bool operator<(const edge &b)
	const { return val<b.val;   }
};

int find(int a)   // 부모 노드 찾기  
{
	if(node[a]==a) return a;
	
	else return node[a]=find(node[a]);
}


void Union(int a, int b)   // 두개의 노드가 속한 집합 합치기  
{
	a=find(a);
	b=find(b);
	
	if(a!=b)  node[a]=b;
}


int main()
{
//freopen("input.txt", "rt", stdin);
int v,e,i,a,b,c,val;
long long result=0;
vector <edge> k;
scanf("%d %d",&v,&e);

for(i=1; i<=v; i++)   //  노드 초기화  
{
	node[i]=i;
}

for(i=1; i<=e; i++)
{
	scanf("%d %d %d",&a,&b,&c);
	
	k.push_back(edge(a,b,c));
}

sort(k.begin(),k.end());


for(i=0; i<k.size(); i++)
{
	a= k[i].node1;
	b= k[i].node2;
	val=k[i].val;
	
	if(find(a)!=find(b))
	{
		Union(a,b);
		result+=val;
	}
}

printf("%lli",result);

return 0;

}

