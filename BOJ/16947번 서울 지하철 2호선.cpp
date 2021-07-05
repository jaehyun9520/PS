#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue> 
using namespace std;
int n;
bool flag=0;
vector <int> node[3001];
int check[3001]={0};
int check1[3001]={0};

void BFS(int s)
{
	check[s]=1;   //순환선 중 하나  
	
	queue <int> Q;
	
	Q.push(s);
	
	
	while(!Q.empty())
	{
		int now=Q.front();
		Q.pop();
		
		for(int i=0; i<node[now].size(); i++)
		{
			if(check[node[now][i]]==0)  
			{
				check[node[now][i]]=1; 
				if(check1[node[now][i]]!=-1) // 다음번에 방문할 역이 순환선이 아닌경우 
				{
				   if(check1[now]==-1)  //현재 역이 순환선인 경우  
				   {
				   	check1[node[now][i]]=1;  //  거리는 1로  
				   }
				   
				   else if(check1[now]>0) {  // 현재역이 순환선이 아닌 경우  
				   	
				   	check1[node[now][i]]=check1[now]+1;  // 현재역의 거리 +1  
				   	
				   }
				}
				
				Q.push(node[now][i]);
			}
			
			
			
		}
		
		
		
	}
	
	
	
	
}




void DFS(int number)
{	

	if(flag==0)
	{
	for(int i=0; i<node[number].size(); i++)
	{
		if(check[node[number][i]]==0) //방문한적 없으면  
		{	  
			check[node[number][i]]=check[number]+1;  //현재 역의 방문값 +1 
			DFS(node[number][i]);
		    check[node[number][i]]=0;	
		 } 
		 
		else if(abs(check[number]-check[node[number][i]])>=2)  // 방문됐던 역에 다시 방문하려는 시도 
		{                                                      // +  방문값의 차가 2이상이면 순환선 
			
		
			flag=1;
		       
			for(int j=1; j<=n; j++)  
			{
				if(check[j]>=check[node[number][i]]&&check[j]<=check[number]) // 순환선 맨처음 방문값~ 맨 마지막 방문값  
				{
				
				check1[j]=-1;  // 이 값에 속하면 순환선으로 표시  
			    }
			}
		}
		
	}
}

	
}


int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int i,a,b;

cin>>n;

for(i=1; i<=n; i++)
{
	cin>>a>>b;
	node[a].push_back(b);
	node[b].push_back(a);
}

   check[1]=1;
	DFS(1);    // 순환선에 속하는 역들을 찾고 따로 체크 
	check[1]=0;


	
for(i=1; i<=n; i++)
{
 if(check1[i]==-1)	
	{
	
	BFS(i);  // BFS를 통해 각 역과 순환선 사이의 거리를 확인   
	break;
     }
}
	
for(int i=1; i<=n; i++)
{
	if(check1[i]==-1) cout<<"0 ";
	
	else
	cout<<check1[i]<<" "; 
}

return 0;
}
