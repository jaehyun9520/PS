#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;
int ans[1001]={0};   // 각 마을에서 파티가 열리는 x마을을 왔다갔다하는데 걸린 시간  

vector < pair < int , int > > node[1001];  // 간선 정보 
priority_queue < pair < int , int > > PQ;   

int n,m,x;    

void process(int start)
{
	vector <int> time(1001,21470000);
	int n,t,nextn,nt;   
	time[start]=0;
	PQ.push(make_pair(0,start));
	
	
	while(!PQ.empty())
	{
		t=-1*PQ.top().first;
		n=PQ.top().second; 
		PQ.pop(); 
			
	    	if(time[n]<t) continue; 

		if(start==x)  
		{
			ans[n]=ans[n]+t;
	
		 } 
		else
		{
			if(n==x) 
			{

			  ans[start]+=t;
			  break;
			  
		}
		}

		for(int i=0; i<node[n].size(); i++)
		{
			nextn=node[n][i].first;  
			nt=t+node[n][i].second;  
			                          
			                          
			if(time[nextn]>nt)  
			{
				
			time[nextn]=nt;

			PQ.push(make_pair(-1*nt,nextn));  
		     }
		}
		
		 
		
	}
	
	while(!PQ.empty())
	{
		PQ.pop();
	}
	
	
	
	
}



int main()
{
//freopen("input.txt", "rt", stdin);
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

int i,a,b,time,max=-1;



cin>>n>>m>>x;

for(i=1; i<=m; i++)
{
	cin>>a>>b>>time;
	node[a].push_back(make_pair(b,time));
}




for(i=1; i<=n ; i++)   
{
	process(i);	
}



for(i=1; i<=n; i++)
{
	if(max<ans[i]) max=ans[i];    
}

cout<<max;

return 0;
}
