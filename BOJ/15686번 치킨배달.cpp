#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int n,m;
vector < pair < int , int > > hs;
vector < pair < int , int > > pz;
int check[20];
int ans=2147000000;

void DFS(int L,int s)
{
	int sum=0;
	if(L==m)
	{
		for(int i=0; i<hs.size(); i++)
		{
			int x1=hs[i].first;
			int y1=hs[i].second;
			
			int value= 2147000000;
			for(int y=0; y<m; y++)
			{
				int x2=  pz[check[y]].first;
				int y2=  pz[check[y]].second;
				
			int tmp=abs(x1-x2)+abs(y1-y2);	
		      
		      if(tmp<value)
		      value=tmp;
		      
			}
			sum=sum+value;
			
		}
		if(ans>sum)
		ans=sum;
	}
	
	
	
	else 
	{
		for(int i=s; i<pz.size(); i++)
		{
			check[L]=i;
			DFS(L+1,i+1);
			
		}
	}
}



int main()
{
//freopen("input.txt", "rt", stdin);
int i,j,a;

scanf("%d %d",&n,&m);

for(i=1; i<=n; i++)
{
	for(j=1; j<=n; j++)
	{
		scanf("%d",&a);
		
		if(a==1)
		       hs.push_back(make_pair(i,j));
		       
		if(a==2)
		       pz.push_back(make_pair(i,j));
	}
}


DFS(0,0);
printf("%d",ans);


return 0;
}
