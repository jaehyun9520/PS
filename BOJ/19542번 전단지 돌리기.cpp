#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n,s,d,y=0;
vector <int> node[100001];
int check[100001]={0};
queue <int> Q;


void DFS(int x, int cnt)  // x: 노드번호  cnt: 깊이  
{
    
	int next;
	
if(cnt>d)
   {

	y=1;   
	}	
	
else if(cnt<=d&&y==0)
	{
		for(int i=0; i<node[x].size(); i++)
		{
			next=node[x][i];
			
			if(check[next]==0&&y==0)
			{
				
			
				check[next]=1;
				DFS(next,cnt+1);
				check[next]=0;
			}
		}
}
 
		
		}	
		
	
	
	 




int main()
{
//freopen("input.txt", "rt", stdin);

int i,a,b,now,next,dis=0;
scanf("%d %d %d ",&n,&s,&d);



check[s]=1; // 시작위치  
Q.push(s);

for(i=2; i<=n; i++) // 노드 연결  
{
	scanf("%d %d",&a,&b);
	
	node[a].push_back(b);
	node[b].push_back(a);
}




while(!Q.empty())  // 현재 노드와 연결되어있는 노드 탐색  
{
	now=Q.front();
	if(now!=s)
	{
		
		dis++;
		
	}
	Q.pop();

	
	
	for(i=0; i<node[now].size(); i++)
	{
		next=node[now][i];
		if(check[next]==0)  // 방문했는지  
		{
			
		
			check[next]=1;
			y=0;
		
			DFS(next,1);  // 다음노드의 깊이가 몇인지  
	
		if(y==1)  // 깊이가 D(힘)보다 크면 직접 이동  
		{
		
		
			Q.push(next);
			
		}
			
		}
		
		
	}
	
}

printf("%d",dis*2);  // 돌아가는것까지 이동거리로 계산해야하니 *2  


return 0;

}

