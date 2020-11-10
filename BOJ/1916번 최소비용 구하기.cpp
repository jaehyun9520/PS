#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


struct edge {
	
	int node;
	int val;
	edge(int a, int b)
	{
		node=a; val=b;
	}
	
	bool operator<(const edge &b) const
	{
		return val>b.val;
	}
};


vector <int> dis(1001,2147000000);   // 출발도시에서 각 도시까지 드는 버스비용 
vector < pair < int, int > > list[1000]; // 각 도시에 연결된 도시와 버스비용 저장하는 인접리스트  
priority_queue <edge> PQ;
int check[1001];

int main()
{
//freopen("input.txt", "rt", stdin);	
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n,m,i,s,e,node1,node2,val,next;

cin>>n; cin>>m;

for(i=1; i<=m; i++)
{
	cin>>node1>>node2>>val;
	
	list[node1].push_back(make_pair(node2,val));
}

cin>>s>>e;

dis[s]=0; 
PQ.push(edge(s,0));

while(!PQ.empty())
{
	node1=PQ.top().node;
	val=PQ.top().val;
	PQ.pop();
	
	  if(check[node1]==0)
	  {
	  	check[node1]=1;
	  	
	  	if(node1==e) // 도착도시이면 값을 출력하고 종료  
		  {cout<<val; exit(0);}
		  
		for(i=0; i<list[node1].size(); i++)
		   {
			    node2=list[node1][i].first;  // 현재 도시 인접한 도시  
			    next=list[node1][i].second+val; //  
			    
			    if(next<dis[node2]) // dis배열에 기록된 버스비용보다  next가 작다면?  
			    {
			    	dis[node2]=next; //next값으로 갱신 
			    	PQ.push(edge(node2,next)); 
				}
		   }
		  
			  
	  	
	  }
}




return 0;
}
