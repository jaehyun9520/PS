#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>



using namespace std;



struct state{
	int dis;
	int time;
	
	
	state(int a, int b)
	{
		dis=a;
		time=b;
	}
	
	
	bool operator <(const state &b)const
	{
		return time>b.time;
	}

};


priority_queue <state> PQ;
vector <int> visit(100001);


int main()
{
//freopen("input.txt", "rt", stdin);

int n,k,dis,time;
scanf("%d %d",&n,&k);

PQ.push(state(n,0));


while(!PQ.empty())
{
	dis=PQ.top().dis;
	time=PQ.top().time;
	visit[dis]=1;
	PQ.pop();
	
	
	if(dis==k)
	{
		printf("%d",time);
		exit(0);
		
	}
	
	else
	{
		if(dis+1>=0&&dis+1<=100000&&visit[dis+1]==0)
		{
			
			PQ.push(state(dis+1,time+1));
		}
		
		if(dis-1>=0&&dis-1<=100000&&visit[dis-1]==0)
		{
			
			PQ.push(state(dis-1,time+1));
		}
		
		if(dis*2>=0&&dis*2<=100000&&visit[dis*2]==0)
		{
			
			PQ.push(state(dis*2,time));
		}
	}
	
}
 
return 0;
}
